#include <opencv2/opencv.hpp>
#include <opencv2/ml.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
//#include <json/json.h>
#include <cmath>
using namespace cv;
using namespace cv::ml;
const std::vector<std::string> SIGNS = {
    "ERROR",
    "STOP",
    "TURN LEFT",
    "Stay Left",
    "Bump Ahead",
    "Speed Limit 50",
    "ONE WAY",
    "SPEED LIMIT",
    "OTHER"
};
int min_size_components = 300;
double similitary_contour_with_circle = 0.60;
const int SIZE1 = 32;
bool subscription_status_ins = true;
bool subscription_status = true;
static Mat contrastLimit(const cv::Mat& image) {
    Mat img_hist_equalized;
    cv::cvtColor(image, img_hist_equalized, cv::COLOR_BGR2YCrCb);
    std::vector<cv::Mat> channels;
    cv::split(img_hist_equalized, channels);
    cv::equalizeHist(channels[0], channels[0]);
    cv::merge(channels, img_hist_equalized);
    cv::cvtColor(img_hist_equalized, img_hist_equalized, cv::COLOR_YCrCb2BGR);
    return img_hist_equalized;
}
Mat LaplacianOfGaussian(const cv::Mat& image) {
    Mat LoG_image;
    cv::GaussianBlur(image, LoG_image, cv::Size(3, 3), 0);
    cv::Mat gray;
    cv::cvtColor(LoG_image, gray, cv::COLOR_BGR2GRAY);
    cv::Laplacian(gray, LoG_image, CV_8U, 3, 3, 2);
    cv::convertScaleAbs(LoG_image, LoG_image);
    return LoG_image;
}
Mat binarization(const cv::Mat& image) {
    cv::Mat thresh;
    cv::adaptiveThreshold(image, thresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C,
        cv::THRESH_BINARY, 11, 2);
    return thresh;
}
Mat removeSmallComponents(const cv::Mat& image, int threshold) {
    cv::Mat labels, stats, centroids;
    int nb_components = cv::connectedComponentsWithStats(image, labels, stats, centroids, 8);
    // Create an output image initialized to zero
    cv::Mat outputImage = cv::Mat::zeros(labels.size(), CV_8U);
    // Iterate through the connected components
    for (int i = 1; i < nb_components; i++) {
        int size = stats.at<int>(i, cv::CC_STAT_AREA);
        if (size >= threshold) {
            outputImage.setTo(255, labels == i);
        }
    }
    return outputImage;
}
cv::Mat preprocess_image(const cv::Mat& image) {
    cv::Mat img = contrastLimit(image);
    img = LaplacianOfGaussian(img);
    img = binarization(img);
    return img;
}
Mat removeOtherColor(const cv::Mat& img) {
    cv::Mat frame;
    cv::GaussianBlur(img, frame, cv::Size(3, 3), 0);
    cv::Mat hsv;
    cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
    // Define range of blue color in HSV
    //cv::Scalar lower_blue(100, 128, 0);
    //cv::Scalar upper_blue(215, 255, 255);
    // Threshold the HSV image to get only blue colors
    cv::Mat mask_blue;
    cv::inRange(hsv, cv::Scalar(100, 128, 0), cv::Scalar(215, 255, 255), mask_blue);
    // Define range of white color in HSV
    cv::Scalar lower_white(0, 0, 128);
    cv::Scalar upper_white(255, 255, 255);
    cv::Mat mask_white;
    cv::inRange(hsv, lower_white, upper_white, mask_white);
    // Define range of black color in HSV
    cv::Scalar lower_black(0, 0, 0);
    cv::Scalar upper_black(170, 150, 50);
    cv::Mat mask_black;
    cv::inRange(hsv, cv::Scalar(0, 0, 0), cv::Scalar(170, 150, 50), mask_black);
    // Combine masks
    cv::Mat mask_1, mask;
    cv::bitwise_or(mask_blue, mask_white, mask_1);
    cv::bitwise_or(mask_1, mask_black, mask);
    // Exclude dark clouds
    cv::Scalar lower_dark_cloud(0, 0, 30);
    cv::Scalar upper_dark_cloud(180, 255, 100);
    cv::Mat dark_cloud_mask, not_dark_cloud_mask;
    cv::inRange(hsv, cv::Scalar(0, 0, 30), cv::Scalar(180, 255, 100), dark_cloud_mask);
    cv::bitwise_not(dark_cloud_mask, not_dark_cloud_mask);
    cv::bitwise_and(mask, not_dark_cloud_mask, mask);
    // Include light gray clouds
    cv::Scalar lower_light_gray_cloud(0, 0, 150);
    cv::Scalar upper_light_gray_cloud(180, 30, 255);
    cv::Mat light_gray_cloud_mask;
    cv::inRange(hsv, cv::Scalar(0, 0, 150), cv::Scalar(180, 30, 255), light_gray_cloud_mask);
    cv::bitwise_or(mask, light_gray_cloud_mask, mask);
    // Exclude regions corresponding to green trees (assuming they are green)
    cv::Scalar lower_green(40, 40, 40);
    cv::Scalar upper_green(80, 255, 255);
    cv::Mat tree_mask, not_tree_mask;
    cv::inRange(hsv, cv::Scalar(40, 40, 40), cv::Scalar(80, 255, 255), tree_mask);
    cv::bitwise_not(tree_mask, not_tree_mask);
    cv::bitwise_or(mask, not_tree_mask, mask);
    // Bitwise-AND mask and original image (optional, not used in return)
    cv::Mat res;
    cv::bitwise_and(frame, frame, res, mask);
    return mask;
}
std::vector<std::vector<cv::Point>> findContour(const cv::Mat& image) {
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    // Find contours
    cv::findContours(image, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    return contours;
}
std::pair<bool, double> contourIsSign(const std::vector<cv::Point>& perimeter, const cv::Point& centroid, double threshold) {
    std::vector<double> distances;
    for (const auto& p : perimeter) {
        double distance = std::sqrt(std::pow(p.x - centroid.x, 2) + std::pow(p.y - centroid.y, 2));
        distances.push_back(distance);
    }
    double max_value = *std::max_element(distances.begin(), distances.end());
    std::vector<double> signature(distances.size());
    // Normalize distances to signature
    for (size_t i = 0; i < distances.size(); ++i) {
        signature[i] = distances[i] / max_value;
    }
    // Check signature of contour
    double temp = 0;
    for (const auto& s : signature) {
        temp += (1 - s);
    }
    temp /= signature.size();
    if (temp < threshold) {
        return { true, max_value + 2 };
    }
    else {
        return { false, max_value + 2 };
    }
}
cv::Mat cropSign(const cv::Mat& image, const Rect& coordinate) {
    int top = max(coordinate.y, 0);
    int bottom = min(coordinate.y + coordinate.height, image.rows);
    int left = max(coordinate.x, 0);
    int right = min(coordinate.x + coordinate.width, image.cols);
    return image(Rect(left, top, right - left, bottom - top)).clone();
}
std::pair<cv::Mat, cv::Rect> findLargestSign(const cv::Mat& image, const std::vector<std::vector<cv::Point>>& contours, double threshold, double distance_threshold) {
    double max_distance = 0;
    //std::vector<cv::Point> coordinate;
    cv::Rect coordinate;
    cv::Mat sign;
    //std::cout << "Size of contours: " << contours.size() << std::endl;
    for (size_t i = 0; i < contours.size(); ++i) {
        const auto& c = contours[i];
        cv::Moments M = cv::moments(c);
        if (M.m00 == 0) continue;
        int cX = static_cast<int>(M.m10 / M.m00);
        int cY = static_cast<int>(M.m01 / M.m00);
        //std::cout << "cX for " << i << " is: " << cX << std::endl;
        //std::cout << "cY for " << i << " is: " << cY << std::endl;
        bool is_sign;
        double distance;
       std::tie(is_sign, distance) = contourIsSign(c, cv::Point(cX, cY), 1.0 - threshold);
        if (is_sign && distance > max_distance && distance > distance_threshold) {
            max_distance = distance;
            /*coordinate.assign(c.begin(), c.end());
            int left = std::min_element(coordinate.begin(), coordinate.end(), [](const cv::Point& a, const cv::Point& b) { return a.x < b.x; })->x;
            int top = std::min_element(coordinate.begin(), coordinate.end(), [](const cv::Point& a, const cv::Point& b) { return a.y < b.y; })->y;
            int right = std::max_element(coordinate.begin(), coordinate.end(), [](const cv::Point& a, const cv::Point& b) { return a.x < b.x; })->x;
            int bottom = std::max_element(coordinate.begin(), coordinate.end(), [](const cv::Point& a, const cv::Point& b) { return a.y < b.y; })->y;
            std::cout << "left: " << left << std::endl;
            std::cout << "top: " << top << std::endl;
            std::cout << "right: " << right << std::endl;
            std::cout << "bottom: " << bottom << std::endl;
            cv::Rect roi(left - 2, top - 2, (right - left + 5), (bottom - top + 3));
            std::cout << "Co-ordinate type: " << typeid(coordinate).name() << std::endl;
            std::cout << "roi type: " << roi << std::endl;*/
            coordinate = cv::boundingRect(c);
            //std::cout << "Crd: " << coordinate << std::endl;
            coordinate.x -= 2;
            coordinate.y -= 2;
            coordinate.width += 3;  // right + 3, includes width adjustment
            coordinate.height += 1;  // bottom + 1, includes height adjustment
            sign = cropSign(image, coordinate);
        }
    }
    return std::make_pair(sign, coordinate);
}
cv::Ptr<cv::ml::SVM> load_model(const std::string& filename) {
    return cv::ml::SVM::load(filename);
}
Mat deskew(const Mat& img) {
    Moments m = moments(img);
    if (abs(m.mu02) < 1e-2) return img.clone();
    double skew = m.mu11 / m.mu02;
    Mat M = (Mat_<float>(2, 3) << 1, skew, -0.5 * SIZE1 * skew, 0, 1, 0);
    Mat warped;
    warpAffine(img, warped, M, Size(SIZE1, SIZE1), INTER_LINEAR | WARP_INVERSE_MAP);
    return warped;
}
HOGDescriptor get_hog() {
    Size winSize(20, 20); // Window size
    Size blockSize(10, 10); // Block size
    Size blockStride(5, 5); // Block stride
    Size cellSize(10, 10); // Cell size
    int nbins = 9; // Number of bins for histogram
    // Initialize the HOGDescriptor with required parameters
    HOGDescriptor hog(winSize, blockSize, blockStride, cellSize, nbins);
    return hog;
}
int getLabel(cv::Ptr<cv::ml::SVM> model, const Mat& data) {
    Mat gray;
    cvtColor(data, gray, COLOR_BGR2GRAY);
    Mat resized_img;
    resize(gray, resized_img, Size(SIZE1, SIZE1));
    // Deskew the image (assuming deskew function is implemented)
    Mat img_deskewed = deskew(resized_img);
    HOGDescriptor hog = get_hog();
    std::vector<float> hog_descriptors;
    hog.compute(img_deskewed, hog_descriptors);
    // Prepare the data for prediction
    Mat hog_mat(hog_descriptors, true); // Create a Mat from the vector
    hog_mat = hog_mat.reshape(1, 1); // Reshape for SVM input
    // Predict the label
    int response = static_cast<int>(model->predict(hog_mat));
    return response;
}
std::tuple<cv::Rect, cv::Mat, int, std::string> localization(const cv::Mat& image, int min_size_components,
    double similitary_contour_with_circle,
    cv::Ptr<cv::ml::SVM> model, int count, int current_sign_type) {
    cv::Mat original_image = image.clone();
    cv::Mat binary_image = preprocess_image(image);
    binary_image = removeSmallComponents(binary_image, min_size_components);
    //binary_image = binary_image & removeOtherColor(image);
    Mat mask = removeOtherColor(image);
    cv::bitwise_and(binary_image, binary_image, binary_image, mask);
    //cv::imshow("BINARY IMAGE", binary_image);
    std::vector<std::vector<cv::Point>> contours = findContour(binary_image);
    cv::Rect coordinate;
    cv::Mat sign;
    std::tie(sign, coordinate) = findLargestSign(original_image, contours, similitary_contour_with_circle, 15);
    std::string text = "";
    int sign_type = -1;
    if (!sign.empty()) {
        sign_type = getLabel(model, sign);
        std::cout << "Sign type: " << sign_type << std::endl;
        sign_type = (sign_type <= 8) ? sign_type : 8;
        text = SIGNS[sign_type];
        //std::cout << "Symbol name: " << text << std::endl;
    }
    if (sign_type > 0 && sign_type != current_sign_type) {
        cv::rectangle(original_image, coordinate, cv::Scalar(0, 255, 0), 1);
        cv::putText(original_image, text, cv::Point(coordinate.x, coordinate.y - 15),
            cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 255), 2, cv::LINE_4);
    }
    return { coordinate, original_image, sign_type, text };
}
int main() {
    /*cv::Mat image;
    image = cv::imread("C:/Users/pdm529913/Pictures/roadsigns2.jpg");*/
    auto model = load_model("D:/Model_SB/RSA/data_svm3.xml");
    //std::vector<std::vector<int>> consecutive_frames;
    double warning_threshold = 0.2;
    //cv::Ptr<cv::ml::SVM> model = load_model(".\\data_svm.dat");
    //std::vector<std::string> labels = load_labels(".\\labels.txt");
    cv::VideoCapture vidcap(0);  // Open the video capture from the default camera
    if (!vidcap.isOpened()) {
        std::cerr << "Error: Failed to open camera!" << std::endl;
        return -1;
    }
    double fps = vidcap.get(cv::CAP_PROP_FPS);
    int width = static_cast<int>(vidcap.get(cv::CAP_PROP_FRAME_WIDTH));
    int height = static_cast<int>(vidcap.get(cv::CAP_PROP_FRAME_HEIGHT));
    std::cout << "Height: " << height << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::time_t t = std::time(0);  // Get the current time for the filename
    std::tm* now = std::localtime(&t);
    char timestamp[80];
    strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", now);
    cv::VideoWriter out;
    if (subscription_status_ins) {
        //out.open("D://Save//record//front_adas_" + std::string(timestamp) + ".avi", cv::VideoWriter::fourcc('X', 'V', 'I', 'D'), fps, cv::Size(720, 480));
        std::cout << "Save started" << std::endl;
    }
    cv::TermCriteria termination(cv::TermCriteria::EPS | cv::TermCriteria::COUNT, 10, 1);
    cv::Rect roiBox;
    cv::Mat roiHist;
    bool success = true;
    double similitary_contour_with_circle = 0.60;  // Parameter
    int count = 0;
    int current_sign = -1;
    std::string current_text = "";
    double current_size = 0;
    int sign_count = 0;
    std::vector<std::vector<int>> coordinates;
    std::vector<int> position;
    int cooldown_duration = 7;
    double last_detection_time = 0;
    while (true) {
        cv::Mat frame;
        success = vidcap.read(frame);
        if (!success) {
            std::cerr << "Error: Failed to capture frame!" << std::endl;
            break;
        }
        // Call localization to detect and classify signs
        cv::Rect coordinate;
        cv::Mat image;
        int sign_type;
        std::string text;
        std::tie(coordinate, image, sign_type, text) = localization(frame, min_size_components, similitary_contour_with_circle, model, count, current_sign);
        if (!coordinate.empty()) {
            cv::rectangle(image, coordinate, cv::Scalar(255, 255, 255), 1);
        }
        int totalsign = subscription_status ? 0 : 8;  // If subscribed, count speed signs, otherwise all signs
        if (sign_type > 0 && (current_sign == -1 || sign_type != current_sign) && sign_type < totalsign) {
            current_sign = sign_type;
            current_text = text;
            int top = static_cast<int>(coordinate.y * 1.05);
            int left = static_cast<int>(coordinate.x * 1.05);
            int bottom = static_cast<int>((coordinate.y + coordinate.height) * 0.95);
            int right = static_cast<int>((coordinate.x + coordinate.width) * 0.95);
            position = { count, sign_type, coordinate.x, coordinate.y, coordinate.x + coordinate.width, coordinate.y + coordinate.height };
            cv::rectangle(image, coordinate, cv::Scalar(0, 255, 0), 1);
            cv::putText(image, text, cv::Point(coordinate.x, coordinate.y - 15), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 255), 2);

            // Define the top-left (tl) and bottom-right (br) points
            cv::Point tl(left, top);
            cv::Point br(right, bottom);
            cv::Mat roi = frame(Rect(tl.x, tl.y, br.x - tl.x, br.y - tl.y));  // Region of interest for tracking
            //cv::Mat roiImage = frame(roi);
            //cv::Mat roiHSV;
            //cv::cvtColor(roiImage, roiHSV, COLOR_BGR2HSV);
            //roiHist = cv::calcHist({ roi }, { 0 }, cv::Mat(), { 16 }, { 0, 180 });
            //cv::calcHist(&roiHSV, 1, 0, Mat(), roiHist, 1, {16}, {0, 180});
            cv::Mat roiHist;
            int histSize[] = { 16 };
            float hranges[] = { 0, 180 };
            const float* ranges[] = { hranges };
            cv::calcHist(&roi, 1, 0, Mat(), roiHist, 1, histSize, ranges);
            cv::normalize(roiHist, roiHist, 0, 255, cv::NORM_MINMAX);
            roiBox = cv::Rect(tl.x, tl.y, br.x - tl.x, br.y - tl.y);
        }
        else if (current_sign != -1) {
            cv::Mat hsv;
            cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
            cv::Mat backProj;
            int hueChannel = 0; // We are using the Hue channel (index 0)
            int histSize[] = { 16 }; // Example: Hue histogram with 16 bins
            float hranges[] = { 0, 180 }; // Hue ranges from 0 to 180 degrees
            const float* ranges[] = { hranges };
            cv::calcBackProject(&hsv, 1, &hueChannel, roiHist, backProj, ranges, 1);
            //cv::calcBackProject(&hsv, 1, 0, roiHist, backProj, {0, 180}, 1.0, true);
            // Track the sign
            cv::RotatedRect r = cv::CamShift(backProj, roiBox, termination);
            //std::vector<cv::Point> pts = cv::pointPolygonTest(r, cv::Point(0, 0), false);
            cv::Point2f pts[4];
            r.points(pts);
            // Convert points to integer coordinates
            std::vector<cv::Point> intPts(4);
            for (int i = 0; i < 4; ++i) {
                intPts[i] = Point(cvRound(pts[i].x), cvRound(pts[i].y));
            }
            // Calculate the top-left and bottom-right points from the corner points
            int s[4];
            for (int i = 0; i < 4; i++) {
                s[i] = intPts[i].x + intPts[i].y;
            }
            cv::Point tl, br;
            int minSum = INT_MAX, maxSum = INT_MIN;
            for (int i = 0; i < 4; i++) {
                if (s[i] < minSum) {
                    minSum = s[i];
                    tl = intPts[i];
                }
                if (s[i] > maxSum) {
                    maxSum = s[i];
                    br = intPts[i];
                }
            }
            // Calculate the size of the object (Euclidean distance between tl and br)
            double size = sqrt(pow(tl.x - br.x, 2) + pow(tl.y - br.y, 2));
            if (current_size < 1 || size < 1 || size / current_size > 30 || std::abs((tl.x - br.x) / (tl.y - br.y)) > 2 || std::abs((tl.x - br.x) / (tl.y - br.y)) < 0.5) {
                current_sign = -1;
            }
            else {
                current_size = size;
            }
            if (sign_type > 0) {
                position = { count, sign_type, tl.x, tl.y, br.x, br.y };
                cv::rectangle(image, cv::Point(tl.x, tl.y), cv::Point(br.x, br.y), cv::Scalar(0, 255, 0), 1);
                cv::putText(image, text, cv::Point(tl.x, tl.y - 15), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 255), 2);
            }
            else if (current_sign > 0) {
                position = { count, sign_type, tl.x, tl.y, br.x, br.y };
                cv::rectangle(image, cv::Point(tl.x, tl.y), cv::Point(br.x, br.y), cv::Scalar(0, 255, 0), 1);
                cv::putText(image, text, cv::Point(tl.x, tl.y - 15), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 255), 2);
            }
        }
        if (current_sign != -1) {
            sign_count++;
            coordinates.push_back(position);
            //last_detection_time = play_sound_for_sign(current_text, cooldown_duration, last_detection_time);
        }
        cv::imshow("Result", image);
        if (subscription_status_ins) {
            //out.write(image);  // Write frame to video file
        }
        count++;
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }
    if (subscription_status_ins) {
        std::cout << "File saved at D://Save//record//front_adas_" + std::string(timestamp) + ".avi" << std::endl;
    }
    else {
        std::cout << "You have not subscribed to Insurance Companion" << std::endl;
    }
    cv::destroyAllWindows();
    return(0);
}
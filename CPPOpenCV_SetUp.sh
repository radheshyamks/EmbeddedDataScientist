#!/bin/bash
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
#sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt-get install python3.5-dev python3-numpy libtbb2 libtbb-dev
#sudo add-apt-repository "deb http://security.ubuntu.com/ubuntu xenial-security main"
#sudo apt update
#sudo apt install libjasper1 libjasper-dev
sudo apt-get install libopencv-dev
# pkg-config --cflags opencv
sudo apt-get install libjpeg-dev libpng-dev libtiff5-dev libjasper-dev libdc1394-22-dev libeigen3-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev sphinx-common libtbb-dev yasm libfaac-dev libopencore-amrnb-dev libopencore-amrwb-dev libopenexr-dev libgstreamer-plugins-base1.0-dev libavutil-dev libavfilter-dev libavresample-dev
sudo -s
cd /opt
git clone https://github.com/Itseez/opencv.git
git clone https://github.com/Itseez/opencv_contrib.git
cd opencv
mkdir release
cd release
cmake -D BUILD_TIFF=ON -D WITH_CUDA=OFF -D ENABLE_AVX=OFF -D WITH_OPENGL=OFF -D WITH_OPENCL=OFF -D WITH_IPP=OFF -D WITH_TBB=ON -D BUILD_TBB=ON -D WITH_EIGEN=OFF -D WITH_V4L=OFF -D WITH_VTK=OFF -D BUILD_TESTS=OFF -D BUILD_PERF_TESTS=OFF -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -D OPENCV_EXTRA_MODULES_PATH=/opt/opencv_contrib/modules /opt/opencv/
make -j4
make install
ldconfig
exit
cd ~
pkg-config --modversion opencv

#g++ main.cpp -o output `pkg-config --cflags --libs opencv`
#gcc -ggdb `pkg-config --cflags opencv` -o `basename opencvtest.c .c` opencvtest.c `pkg-config --libs opencv`
#./opencvtest
sudo su
sudo apt-get install build-essential
sudo apt-get install libavformat-dev
sudo apt-get install ffmpeg
sudo apt-get install libcv2.3 libcvaux2.3 libhighgui2.3 python-opencv opencv-doc libcv-dev libcvaux-dev libhighgui-dev

PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig
export PKG_CONFIG_PATH

#include "opencv2/core/core_c.h"
#include "opencv2/core/core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/video.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/contrib/contrib.hpp"
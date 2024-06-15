#include <iostream>
// https://pythontutor.com/render.html#mode=display
class Radhe {
	private:
		int Age;
		float Weight, Height;
	public:
		void BMI( int a, float b, float c);
};
void Radhe :: BMI(int a, float b, float c){
		float X= ((Age) /(Weight+Height));
		std:: cout<<X<<std:: endl;
} 

int main(void)
{
	Radhe R;
	R.BMI(28, 58.9, 5.6);
}

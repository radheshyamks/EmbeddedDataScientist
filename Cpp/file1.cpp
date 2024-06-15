#include <iostream>
#include <stdio.h>
void fun(int&,int =0);
using namespace std;
int main(int argc, char* argv[])
{
	//auto x = new int[10];
	int x[10] = {0};
	for(auto i=0; i< 10; i++){
		*(x+i) = 10*(i+1);
	}
	//Range for loop
	// Pass by value
	// pass by reference
	// Pass by address
	int y=10;
	fun(y);
	cout<<y<<endl;
	std::cout<<&y<<std::endl;
	return 0;
}
//Pass by reference
void fun(int& k, int t){
	//do nothing;
	k++;
	std::cout<<t<<std::endl;
	std::cout<<&k<<std::endl;
}

app_remote_service_linux.c pp_thermal_app.c vx_pp_cc_dms_target.c main.c app_init.c app_iss_common.c pp_vx_rgbir_splitter.c
csf_thread_video_app_receive.c 
pp_rgb_ir_splitter_core_ov.c
pp_rgb_ir_splitter_core_st.c
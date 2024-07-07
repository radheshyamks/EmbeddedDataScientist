// #pragma once
#include<iostream>
using namespace std;



template<class T>
class p {
	T x;
	T y;
	
public:
	p();
    // p()=default;
	p(T, T);
	p(const p&);
	template<class Y>
	friend ostream& operator<<(ostream & out, const p<Y> &o);
};

template<class T>
p<T>::p() {
	x = y = 0;
}
template<class T>
p<T>::p(T a, T b) {
	x = a;
	y = b;
}
template<class T>
p<T>::p(const p& obj) {
	x = obj.x;
	y = obj.y;
}
template<class T>
ostream& operator<<(ostream & out, const p<T> &o) {
	out << "(" << o.x << "," << o.y << ")" << endl;
	return out;
}

int main(){
    p<int> obj;
    return 0;
}
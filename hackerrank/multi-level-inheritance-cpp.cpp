#include <iostream>
using namespace std;

class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n";
	}
};

class Isosceles : public Triangle{
	public:
		void isosceles(){
			cout<<"I am an isosceles triangle\n";
		}
};

class Equilateral : public Isosceles{
	public:
		void equilateral(){
			cout<<"I am an equilateral triangle\n";
		}
};

int main(){
	Equilateral eqr;
	eqr.equilateral();
	eqr.isosceles();
	eqr.triangle();
	return 0;
}
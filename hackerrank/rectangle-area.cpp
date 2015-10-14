#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Rectangle{
protected:
	int width,height;
public:
	void Input(){scanf("%d%d",&width,&height);}
	void Display(){printf("%d %d\n",width,height);}
};
class RectangleArea:public Rectangle{
public:
	void Display(){printf("%d\n",width*height);}
};

int main() {
	RectangleArea r_area;
	r_area.Input();
	Rectangle *r;
	r=&r_area;
	r->Display();
	r_area.Display();
	return 0;
}
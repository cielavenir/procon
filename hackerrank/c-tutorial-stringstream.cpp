#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
	int c;
	for(;~(c=getchar());)putchar(c==44?10:c);
}
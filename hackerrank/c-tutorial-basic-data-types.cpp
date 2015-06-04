#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int c;
	for(;~(c=getchar());)putchar(c==32?10:c);
	return 0;
}
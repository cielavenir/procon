#include <algorithm>
#include <string>
#include <cstdio>
int main(){
	int i=0;
	std::string s="0123456789";
	for(;i<999999;i++)std::next_permutation(s.begin(),s.end());
	puts(s.c_str());
}
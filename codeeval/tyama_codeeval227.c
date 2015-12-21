#include <stdio.h>
int main(){
	int c=0,s=0,i=0;
	for(;~(c=getchar());){
		if('0'<=c&&c<='9'){
			c-='0';
			s+=i%2 ? c : c*2;
			if(++i==16){
				puts(s%10?"Fake":"Real");
				s=i=0;
			}
		}
	}
	return 0;
}
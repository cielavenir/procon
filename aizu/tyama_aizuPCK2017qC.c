#include <stdio.h>
int zeller(int Y,int M,int D){if(++M<4)Y-=1,M+=12;int y=Y/100,z=Y%100;return (5*y+z+y/4+z/4+13*M/5+D-1)%7;}
char *W="sunmontuewedthufrisat";
int main(){
	int n;
	scanf("%d",&n);
	printf("%.*s\n",3,W+zeller(2017,9,n)*3);
}

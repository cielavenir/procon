#include <cstdio>
#include <algorithm>
int z[]={1,2,3},x[4],y[4];
main(){
	int f=0;
	for(;~scanf("(%d, %d), (%d, %d), (%d, %d), (%d, %d)\n",x,y,x+1,y+1,x+2,y+2,x+3,y+3);puts(f?"true":"false")){
		f=0;
		do{
			int x1=(x[0]-x[z[0]])*(x[0]-x[z[0]]),x2=(x[z[0]]-x[z[1]])*(x[z[0]]-x[z[1]]),x3=(x[z[1]]-x[z[2]])*(x[z[1]]-x[z[2]]),x4=(x[z[2]]-x[0])*(x[z[2]]-x[0]),x5=(x[0]-x[z[1]])*(x[0]-x[z[1]]);
			int y1=(y[0]-y[z[0]])*(y[0]-y[z[0]]),y2=(y[z[0]]-y[z[1]])*(y[z[0]]-y[z[1]]),y3=(y[z[1]]-y[z[2]])*(y[z[1]]-y[z[2]]),y4=(y[z[2]]-y[0])*(y[z[2]]-y[0]),y5=(y[0]-y[z[1]])*(y[0]-y[z[1]]);
			int z1=x1+y1,z2=x2+y2,z3=x3+y3,z4=x4+y4,z5=x5+y5;
			f|=z1==z2&&z2==z3&&z3==z4&&z1*2==z5;
		}while(std::next_permutation(z,z+3));
	}
}
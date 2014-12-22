#include <random>
#include <map>
#include <cstdio>
#include <ctime>
#include <unistd.h>
#define DICE 6
#define TRIAL 10000
using namespace std;
mt19937_64 engine((unsigned int)time(NULL)^(getpid()<<16));
uniform_real_distribution<double> distribution(0.0, 1.0);
double a[DICE];
int role(){
	double d=distribution(engine);
	for(int i=0;i<DICE;i++)if(d<a[i])return i+1;
	return DICE;
}
int main(){int T,i,L,S,x,y,c;for(scanf("%d",&T);T--;){
	scanf("%lf,%lf,%lf,%lf,%lf,%lf",a,a+1,a+2,a+3,a+4,a+5);
	for(i=1;i<6;i++)a[i]+=a[i-1];
	scanf("%d,%d",&L,&S);L+=S;
	map<int,int>l;
	map<int,int>::iterator it;
	for(;L--;)scanf("%d,%d",&x,&y),l[x]=y;
	for(L=S=y=0;L<TRIAL;L++){
		for(i=0,c=1;c<100&&i<=1000;i++){
			x=role();
			if(c+x>100)continue;
			c+=x;
			if((it=l.find(c))!=l.end())c=it->second;
		}
		if(i<=1000){
			S+=i;
			y++;
		}
	}
	printf("%d\n",S/y);
}return 0;}
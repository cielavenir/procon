//copied from koj0011
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
long long m[51][51];
int main(){
	string s;
	int i,a,b,q,x,y,X,Y;
	long long j,J=-999999999;
	//for(;~scanf("%d%d%d",&a,&b,&q);printf("%lld\n",j)){
		for(a=0;getline(cin,s);a++){
			istringstream ss(s);
			for(b=0;ss>>m[a+1][b+1];b++);
		}
		for(j=1;j<=a;j++)for(i=1;i<=b;i++)m[j][i]+=m[j-1][i];
		for(j=1;j<=a;j++)for(i=1;i<=b;i++)m[j][i]+=m[j][i-1];
		for(y=1;y<=a;y++)for(x=1;x<=b;x++)for(Y=y;Y<=a;Y++)for(X=x;X<=b;X++){
			j=m[Y][X]-m[y-1][X]-m[Y][x-1]+m[y-1][x-1];
			if(J<j)J=j;
		}
		cout<<J<<endl;
	//}
}
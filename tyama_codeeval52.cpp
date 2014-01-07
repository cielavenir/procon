#include <string>
#include <cstdio>
using namespace std;
string A[]={
	"",
	"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
	"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
};
string B[]={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
string txt(int x){
	string s;
	if(x/100)s+=A[x/100]+"Hundred";
	if(x%100<20)return s+A[x%100];
	return s+B[x/10%10-2]+A[x%10];
}
main(){
	int x,y;
	for(;~scanf("%d",&x);){
		//y=x/1000000000;
		//if(y)printf((txt(y)+"Billion").c_str());
		y=x/1000000%1000;
		if(y)printf((txt(y)+"Million").c_str());
		y=x/1000%1000;
		if(y)printf((txt(y)+"Thousand").c_str());
		y=x%1000;
		if(y)printf(txt(y).c_str());
		puts("Dollars");
	}
}
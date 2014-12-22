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
	if(x/100){
		s+=A[x/100]+' '+"Hundred";
		if(x%100)s+=' ';
	}
	if(x%100<20)return s+A[x%100]+' ';
	s+=B[x/10%10-2];
	if(x%10)s+=' ';
	return s+A[x%10]+' ';
}
int main(){
	long long x,y;
	scanf("%lld",&x);
	for(;~scanf("%lld",&x);){
		string s;
		y=x/1000000000000LL;
		if(y)s+=txt(y)+"Trillion ";
		y=x/1000000000%1000;
		if(y)s+=txt(y)+"Billion ";
		y=x/1000000%1000;
		if(y)s+=txt(y)+"Million ";
		y=x/1000%1000;
		if(y)s+=txt(y)+"Thousand ";
		y=x%1000;
		if(y)s+=txt(y);
		//puts("Dollars");
		if(x){
			puts(s.substr(0,s.size()-1).c_str());
		}else{
			puts("Zero");
		}
	}
}
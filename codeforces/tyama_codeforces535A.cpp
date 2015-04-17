#include <string>
#include <cstdio>

using namespace std;
string A[]={
	"",
	"one","two","three","four","five","six","seven","eight","nine","ten",
	"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"
};
string B[]={"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
string txt(int x){
	string s;
	if(x/100){
		s+=A[x/100]+'-'+"hundred";
		if(x%100)s+='-';
	}
	if(x%100<20)return s+A[x%100]+'-';
	s+=B[x/10%10-2];
	if(x%10)s+='-';
	return s+A[x%10]+'-';
}
int main(){
	long long x,y;
	for(;~scanf("%lld",&x);){
		string s;
		y=x/1000000000000LL;
		if(y)s+=txt(y)+"trillion-";
		y=x/1000000000%1000;
		if(y)s+=txt(y)+"billion-";
		y=x/1000000%1000;
		if(y)s+=txt(y)+"million-";
		y=x/1000%1000;
		if(y)s+=txt(y)+"thousand-";
		y=x%1000;
		if(y)s+=txt(y);
		if(x){
			puts(s.substr(0,s.size()-1).c_str());
		}else{
			puts("zero");
		}
	}
}
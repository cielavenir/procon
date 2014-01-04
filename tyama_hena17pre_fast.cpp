//http://qiita.com/Nabetani/items/dabe8ec57e0313229552
//http://nabetani.sakura.ne.jp/hena/ord17scheherazade/
#include <deque>
#include <cstdio>
#include <cmath>
bool palindrome(int n,int b){
	int n0=n,n1=0;
	for(;n0;n0/=b)n1=n1*b+n0%b;
	return n1==n;
}
int main(){
	int n,i;
	for(;~scanf("%d",&n);){
		if(n<3)puts("-");
		else{
			std::deque<int> result;
			for(i=sqrt(n-1);i>1;i--){
				if(palindrome(n,(n-1)/i))result.push_back((n-1)/i);
				if((n-1)/i!=i&&palindrome(n,i))result.push_front(i); // n-1 might be a square number
			}
			for(i=0;i<result.size();i++)printf("%d,",result[i]);
			printf("%d\n",n-1);
		}
		fflush(stdout);
	}
}
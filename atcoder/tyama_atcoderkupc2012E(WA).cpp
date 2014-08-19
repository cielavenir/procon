#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
	time_t timer=time(NULL);
	struct tm *t;
	srand(timer);
	int N,i=1,M=1,m=0;
	string s;
	cin>>N;
	for(;i<=N;i++){
		cin>>s;
		string::iterator e=unique(s.begin(),s.end());
		s.erase(e,s.end());
		int o=(int)count(s.begin(),s.end(),'o');
		if(m<o)m=o,M=i;
		if(o==N-1){
			for(i=0;i<1000;i++)printf("%d\n",M);
			return 0;
		}
	}

	if(N<10){
		for(i=0;i<1000;i++)printf("%d\n",rand()%N+1);
	}else{
		for(i=0;i<0;i++)printf("%d\n",N);
		for(;i<1000;i++)printf("%d\n",rand()%N+1);
	}
	//sleep(1);
}
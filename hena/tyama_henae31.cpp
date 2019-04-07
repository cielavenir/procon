//http://nabetani.sakura.ne.jp/hena/orde31rotnum/
//https://qiita.com/Nabetani/items/d139d5ef70aa23c2d038

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <vector>
#include <future>

bool get(int *b,int *x,int *y){
	char s[999];
	if(!fgets(s,999,stdin))return false;
	*b=strtol(strtok(s,","),NULL,10);
	*x=strtol(strtok(NULL,","),NULL,*b);
	*y=strtol(strtok(NULL,","),NULL,*b);
	return true;
}

bool chk(int n,int b){
	div_t x,y;
	x=div(n,b);
	for(;x.quot;){
		y=div(x.quot,b);
		if(y.rem!=x.rem && (y.rem+1)%b!=x.rem)return false;
		x=y;
	}
	return true;
}

int main(){
	int b,x,y;
	for(;get(&b,&x,&y);){
		if(b==2){
			printf("%d\n",y-x+1);
		}else{
			int num_threads=std::thread::hardware_concurrency();
			auto f=[&](int start)->int{
				int r=0;
				for(int j=x+start;j<=y;j+=num_threads){
					r+=chk(j,b);
				}
				return r;
			};
			std::vector<std::future<int>>task;
			for(int i=1;i<num_threads;i++)task.push_back(std::async(std::launch::async,f,i));
			int r=f(0);
			for(auto &t:task)r+=t.get();
			printf("%d\n",r);
		}
		fflush(stdout);
	}
}

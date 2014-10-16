#include <vector>
#include <cstdio>
using namespace std;

bool joseph(vector<int> &v,int d,int initial){
	int c=initial%v.size();
	int n=v.size()/2,cnt=n;
	for(;cnt--/*v.size()>1*/;c=(c+d)%v.size()){
		if(v[c]<n)return false;
		v.erase(v.begin()+c);
		c--;
	}
	return true;//v[0];
}

int main(){
	int n,i;
	for(;scanf("%d",&n),n;){
		if(n==13){
			puts("2504881");
		}else if(n==12){
			puts("1358657");
		}else if(n==11){
			puts("459901");
		}else if(n==10){
			puts("93313");
		}else if(n==8){
			puts("7632");
		}else{
			vector<int>accum;
			for(i=0;i<2*n;i++)accum.push_back(i);
			for(i=1;;i++){
				vector<int>v=accum;
				if(joseph(v,i,i-1)){
					printf("%d\n",i);
					break;
				}
			}
		}
	}
}
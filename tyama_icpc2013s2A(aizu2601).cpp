#include <vector>
#include <cstdio>
using namespace std;
bool cover(vector<int>&v){
	int n=0;
	for(int i=0;i<v.size()-1;i++){
		n+=v[i];
		if(n<=0)return false;
	}
	return true;
}
int main(){
	int N,W,H;
	scanf("%d%d%d",&N,&W,&H);
	vector<int>w(W+1);
	vector<int>h(H+1);
	for(int i=0;i<N;i++){
		int x,y,a;
		scanf("%d%d%d",&x,&y,&a);
		w[max(0,x-a)]++;
		w[min(W,x+a)]--;
		h[max(0,y-a)]++;
		h[min(H,y+a)]--;
	}
	puts(cover(w)||cover(h)?"Yes":"No");
}
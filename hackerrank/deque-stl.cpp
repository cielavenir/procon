#include <deque>
#include <vector>
#include <cstdio>
using namespace std;

void slide_max(const vector<int> &seq, int w){
	deque<int> q;
	for(int i=0;i<seq.size();i++){
		for(;!q.empty() && seq[i] > q.back();)q.pop_back();  
		q.push_back(seq[i]);  
		if(i>=w && q.front() == seq[i-w])q.pop_front();  
		if(i>=w-1)printf(i<seq.size()-1?"%d ":"%d\n",q.front());
	}
}

int main(){
	int T,N,W;
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&N,&W);
		vector<int>v(N);
		for(int i=0;i<N;i++)scanf("%d",&v[i]);
		slide_max(v,W);
	}
}
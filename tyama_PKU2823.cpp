#include <sstream>
#include <deque>
#include <vector>
#include <cstdio>
using namespace std;

void slide_min(const vector<int> &seq, int w){
	ostringstream ss;
	deque<int> q;
	int n=seq.size();
	for(int i=0;i<n;i++){
		for(;!q.empty() && seq[i] < q.back();)q.pop_back();  
		q.push_back(seq[i]);  
		if(i>=w && q.front() == seq[i-w])q.pop_front();  
		if(i>=w-1)ss<<q.front()<<(i<n-1?" ":"");
	}
	puts(ss.str().c_str());
}
void slide_max(const vector<int> &seq, int w){
	ostringstream ss;
	deque<int> q;
	int n=seq.size();
	for(int i=0;i<n;i++){
		for(;!q.empty() && seq[i] > q.back();)q.pop_back();  
		q.push_back(seq[i]);  
		if(i>=w && q.front() == seq[i-w])q.pop_front();  
		if(i>=w-1)ss<<q.front()<<(i<n-1?" ":"");
	}
	puts(ss.str().c_str());
}

int main(){
	int T,N,W;
	scanf("%d%d",&N,&W);
	vector<int>v(N);
	for(int i=0;i<N;i++)scanf("%d",&v[i]);
	slide_min(v,W);
	slide_max(v,W);
}
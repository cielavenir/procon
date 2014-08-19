//g++ -O3 -msse2 -o ksim tyama_rosalindKSIM.cpp
//This algorithm is O(kst). 3mins with clang++ -O3 -msse2.
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
typedef vector<int> vi;
//y is substr() retval
void alignment(vector<vi>&a, string &x, string y, int k){
	string tx,ty;
	int i,j;
	int ylen=a[0].size();
	for(i=1;i<a.size();i++){
		//for(j=1;j<a[0].size();j++){ //O(s2t)
		for(j=max(1,i-k);j<=min(ylen,i+k);j++){ //O(kst)
			a[i][j]=max(x[i-1]==y[j-1]?a[i-1][j-1]:(a[i-1][j-1]-1),max(a[i-1][j]-1,a[i][j-1]-1));
		}
	}
}
int main(){
	string s,t;
	int k;
	cin>>k>>s>>t;
	int slen=s.length(),tlen=t.length();
	vector<vi>a(slen+1,vi(slen+k+1)); //memory complexity is O(s2).
	int i,j;
	for(i=1;i<a.size();i++)fill(a[i].begin(),a[i].end(),-999),a[i][0]=a[i-1][0]-1;
	for(j=1;j<a[0].size();j++){a[0][j]=a[0][j-1]-1;}
	for(i=0;i<=tlen-slen+k;i++){
		alignment(a,s,t.substr(i,slen+k),k); //t.substr(i) -> t.substr(i,slen+k) : O(st2) -> O(s2t)
		for(j=max(0,slen-k);j<=min(slen+k,tlen-i);j++){
			if(a[slen][j]>=-k)cout<<(i+1)<<' '<<j<<endl;
		}
		cerr<<i<<endl;
	}
}
#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

int main(){
	string A,B,A1,B1;
	cin>>A1>>B1;

	//check 1: size
	if(A1.size()!=B1.size()){
		cout<<"NO"<<endl;
		return 0;
	}
	//check 2: type
	{
		map<char,int>ma;
		for(int i=0;i<A1.size();i++)ma[A1[i]]++;
		map<char,int>mb;
		for(int i=0;i<B1.size();i++)mb[B1[i]]++;
		for(auto it=ma.begin();it!=ma.end();++it){
			if(it->second!=mb[it->first]){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	//preprocess A,B
	int diff=0,same=0;
	for(int i=0;i<A1.size();i++){
		if(A1[i]!=B1[i]){
			A+=A1[i],B+=B1[i],diff++;
		}else if(same<27){
			//小文字アルファベットのみで構成されているから、
			//鳩の巣原理より、27文字残せば同じ文字が1組存在することになる
			A+=A1[i],B+=B1[i],same++;
		}
	}
	if(diff>6){
		cout<<"NO"<<endl;
		return 0;
	}
	
	//forward
	unordered_set<string> forward;
	for(int i=0;i<A.size()-1;i++)
		for(int j=i+1;j<A.size();j++)
			swap(A[i],A[j]),forward.insert(A),swap(A[i],A[j]);
	//backward
	unordered_set<string> backward;
	for(int i=0;i<B.size()-1;i++)
		for(int j=i+1;j<B.size();j++)
			swap(B[i],B[j]),backward.insert(B),swap(B[i],B[j]);
	for(auto it=forward.begin();it!=forward.end();++it){
		//この操作ってよく考えたら処理系依存なんですよね。g++/clang++では大丈夫のようですが。
		string &s=(string&)*it;
		for(int i=0;i<s.size()-1;i++)
			for(int j=i+1;j<s.size();j++){
			swap(s[i],s[j]);
			if(backward.find(s)!=backward.end()){
				cout<<"YES"<<endl;
				return 0;
			}
			swap(s[i],s[j]);
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
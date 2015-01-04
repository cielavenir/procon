#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define W 80

int main(){
	string line;
	for(;getline(cin,line);){
		string cur;
		int vsiz=0;
		vector<string>v;
		for(istringstream ss(line);ss>>cur;){
			if(vsiz+cur.size()>W){
				vsiz--;
				//print v
				int sep=v.size()-1;
				int pad=W-vsiz+sep;
				for(int i=0;i<sep;i++){
					cout<<v[i]<<string(pad/sep+(pad%sep>i),' ');
				}
				cout<<v[sep]<<endl;
				vsiz=0;
				v.clear();
			}
			vsiz+=cur.size()+1;
			v.push_back(cur);
		}
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<(i<v.size()-1?" ":"\n");
		}
	}
}
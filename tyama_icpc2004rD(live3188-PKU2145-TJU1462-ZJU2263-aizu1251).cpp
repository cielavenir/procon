#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
	int N,M;
	for(;cin>>N>>M,N;){
		string file;
		set<string>files;
		set<string>directories;
		for(;N--;){
			cin>>file;
			files.insert(file);
			for(int i=file.size()-1;i>=0;i--){
				if(file[i]=='/'){
					file.resize(i);
					directories.insert(file);
				}
			}
		}
		for(;M--;){
			bool fail=false;
			vector<string>v(2);
			for(int _=0;_<2;_++){
				int prev=1;
				cin>>file;
				if(directories.find(file)!=directories.end())file+="/";
				for(int i=1;i<=file.size();i++){
					if(file[i]=='/'||!file[i])if(prev!=i){
						if(file.substr(prev,i-prev)=="."){
						}else if(file.substr(prev,i-prev)==".."){
							int j=v[_].size()-1;
							for(;j>=0;j--){
								if(v[_][j]=='/'){
									v[_].resize(j);
									break;
								}
							}
							if(j<0){
								fail=true;
								break;
							}
						}else{
							v[_]+="/";
							v[_]+=file.substr(prev,i-prev);
							if(file[i]){
								if(directories.find(v[_])==directories.end()){
									fail=true;
									break;
								}
							}
						}
						prev=i+1;
					}
				}
				if(directories.find(v[_])!=directories.end())v[_]+="/index.html";
				if(files.find(v[_])==files.end())fail=true;
			}
			if(fail)cout<<"not found"<<endl;
			else if(v[0]==v[1])cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
}
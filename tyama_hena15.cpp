//http://qiita.com/Nabetani/items/cba03c96d1ea55f6e861
//http://nabetani.sakura.ne.jp/hena/ord15elebubo/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<unsigned int> split_int(string &str, const char *delim){
	vector<unsigned int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(strtoul(str.substr(0, cutAt).c_str(),NULL,16));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(strtoul(str.c_str(),NULL,16));
	}
	return result;
}
int main(){
	string line;
	int i,j;
	for(;getline(cin,line);){
		string s;
		vector<unsigned int>v=split_int(line,"/");
		vector<vector<int> >a(2);
		for(i=0;i<2;i++){
			a[i].resize(34);
			for(j=0;j<32;j++)a[i][j]=(v[i]>>(31-j))&1;
		}
		for(i=0;i<32;){
			if(!a[0][i]&&!a[1][i]){
				i++;
			}else if(a[0][i]&&a[1][i]){
				if(a[0][i+1]){
					if(a[0][i+2]){
						s+='N';
						i+=3;
					}else{
						s+='R';
						i+=2;
					}
				}else if(a[1][i+1]){
					if(a[1][i+2]){
						s+='U';
						i+=3;
					}else{
						s+='L';
						i+=2;
					}
				}
			}else if(a[0][i]){
				if(a[0][i+2]){
					s+='T';
					i+=3;
				}else{ //if a[1][i+2]
					s+='Z';
					i+=3;
				}
			}else{
				if(a[0][i+2]){
					s+='S';
					i+=3;
				}else{
					s+='J';
					i+=2;
				}
			}
		}
		cout<<s<<endl;
	}
}
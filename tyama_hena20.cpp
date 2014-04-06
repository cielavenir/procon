//http://qiita.com/Nabetani/items/5791f8ae1bb5d069a49b
//http://nabetani.sakura.ne.jp/hena/ord20meetime/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string &str, const char *delim){
	vector<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.push_back(str);
	}
	return result;
}

int get_hhmm(const char *s){
	return (s[0]-'0')*600 + (s[1]-'0')*60 + (s[2]-'0')*10 + (s[3]-'0');
}
void print_hhmm(int n){
/*
	putchar('0'+n/600);
	putchar('0'+n/60%10);
	putchar('0'+n/10%6);
	putchar('0'+n%10);
*/
	printf("%02d%02d",n/60,n%60);
}

int main(){
	string line;
	int i,j,k;
	for(;getline(cin,line);){
		vector<string> data=split(line,",");
		vector<int>A(24*60),B(24*60),I(24*60),J(24*60),Z(24*60);
		for(i=0;i<data.size();i++){
			vector<int> &v=data[i][0]=='A'?A:data[i][0]=='B'?B:data[i][0]=='I'?I:data[i][0]=='J'?J:Z;
			int start=get_hhmm(data[i].c_str()+1);
			int end=get_hhmm(data[i].c_str()+6);
			for(;start<end;start++)v[start]=1;
		}
		for(i=10*60;i<=17*60;i++){
			for(j=0;j<60;j++)if(A[i+j]||B[i+j]||!Z[i+j])break;
			if(j==60){
				for(j=0;j<60;j++)if(I[i+j])break;
				for(k=0;k<60;k++)if(J[i+k])break;
				if(j==60||k==60){
					print_hhmm(i);
					putchar('-');
					print_hhmm(i+60);
					break;
				}
			}
		}
		if(i>17*60)putchar('-');
		putchar('\n');
		fflush(stdout);
	}
}
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef pair<string,double> psd;

vector<string>A={
"Mary", "had", "a", "little", "lamb", "its", "fleece", "was", "white", "as", "snow", "And", "everywhere", "that", "Mary", "went", "the", "lamb", "was", "sure", "to", "go", "It", "followed", "her", "to", "school", "one", "day", "which", "was", "against", "the", "rule", "It", "made", "the", "children", "laugh", "and", "play", "to", "see", "a", "lamb", "at", "school", "And", "so", "the", "teacher", "turned", "it", "out", "but", "still", "it", "lingered", "near", "And", "waited", "patiently", "about", "till", "Mary", "did", "appear", "Why", "does", "the", "lamb", "love", "Mary", "so", "the", "eager", "children", "cry", "Why", "Mary", "loves", "the", "lamb", "you", "know", "the", "teacher", "did", "reply"
};

deque<string> split(string &str, const char *delim){
	deque<string> result;
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

int main(){
	string line;
	for(;getline(cin,line);){
		int n;
		deque<string>s;
		{
			deque<string>a=split(line,",");
			n=strtol(a[0].c_str(),NULL,10);
			s=split(a[1]," ");
		}
		deque<string>a;
		map<string,int>h;
		int i=0,sum=0;
		for(;i<n-1;i++)a.push_back(A[i]);
		for(;i<A.size();i++){
			if(a==s)h[A[i]]++,sum++;
			a.push_back(A[i]);
			a.pop_front();
		}
		vector<psd>b;
		for(auto &e:h){
			b.push_back({e.first,e.second*1.0/sum});
		}
		sort(b.begin(),b.end(),[](const psd &x,const psd &y){
			if(x.second>y.second)return true;
			if(x.second<y.second)return false;
			return x.first<y.first;
		});
		for(int i=0;i<b.size();i++){
			printf("%s,%.3f",b[i].first.c_str(),b[i].second);
			putchar(i<b.size()-1?';':'\n');
		}
	}
}
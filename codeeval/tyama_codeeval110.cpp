#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
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
string twenty[20]={
	"zero","one","two","three","four","five","six","seven","eight","nine",
	"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",
};
string ty[10]={
	"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety",
};
string convert(vector<string>&a,int start,int end){
	int size=end-start,i,r1=0,r2=0;
	if(size>1&&a[start+1]=="hundred"){
		for(i=0;i<10;i++){
			if(a[start]==twenty[i]){
				r1=i;
				start+=2;
				size-=2;
				break;
			}
		}
		assert(i<10);
	}
	for(;start<end;start++){
		for(i=0;i<20;i++)if(a[start]==twenty[i])r2+=i;
		for(i=2;i<10;i++)if(a[start]==ty[i])r2+=10*i;
	}
	ostringstream ss;
	ss<<setfill('0')<<setw(3)<<(r1*100+r2);
	return ss.str();
}
main(){
	string s,sign,result;
	int start,end,billion,million,thousand;
	for(;getline(cin,s);){
		vector<string>a=split(s," ");
		sign="";
		result="";
		billion=million=thousand=0;
		if(a[0]=="negative"){
			sign="-";
			a.erase(a.begin());
		}
		for(start=end=0;end<a.size();end++){
			if(a[end]=="billion"){
				billion=1;
				result+=convert(a,start,end);
				start=end+1;
			}
			if(a[end]=="million"){
				million=1;
				result+=convert(a,start,end);
				start=end+1;
			}
			if(a[end]=="thousand"){
				if(billion&&!million)result+="000";
				thousand=1;
				result+=convert(a,start,end);
				start=end+1;
			}
		}
		if(billion&&!million&&!thousand)result+="000000";
		if(million&&!thousand)result+="000";
		result+=convert(a,start,end);
		for(start=0;start<result.size();start++)if(result[start]!='0')break;
		result=result.substr(start);
		if(result=="")result="0";
		cout<<sign<<result<<endl;
	}
}
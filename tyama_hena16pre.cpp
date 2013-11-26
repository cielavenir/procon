//http://qiita.com/Nabetani/items/7be4bc2a3514bbfbfc15
//http://nabetani.sakura.ne.jp/hena/ord16lcove/
#include <iostream>
#include <string>
#include <set>
#include <cstdlib>
using namespace std;

set<int> split_int(string &str, const char *delim){
	set<int> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos ){
		if(cutAt > 0){
			result.insert(strtol(str.substr(0, cutAt).c_str(),NULL,10));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0){
		result.insert(strtol(str.c_str(),NULL,10));
	}
	return result;
}

main(){
	string line;
	int i,j,x,y,z,end;
	for(;getline(cin,line);){
		int Mx=0,My=0,mx=9,my=9,r=-1;
		set<int>s=split_int(line,",");
		if(s.size()==1){cout<<3<<endl;continue;}
		set<int>::iterator it=s.begin();
		for(;it!=s.end();it++){
			x=*it/10,y=*it%10;
			if(Mx<x)Mx=x;if(My<y)My=y;
			if(mx>x)mx=x;if(my>y)my=y;
		}
		if(s.find(mx*10+my)==s.end()){
			end=My;
			for(i=mx;i<=Mx;i++){
				for(j=my;j<=end;j++)if(s.find(i*10+j)!=s.end())break;
				end=j-1;
				if(r<(z=(j-my)*(i-mx+1)))r=z;
			}
		}
		if(s.find(Mx*10+my)==s.end()){
			end=My;
			for(i=Mx;i>=mx;i--){
				for(j=my;j<=end;j++)if(s.find(i*10+j)!=s.end())break;
				end=j-1;
				if(r<(z=(j-my)*(Mx-i+1)))r=z;
			}
		}
		if(s.find(mx*10+My)==s.end()){
			end=my;
			for(i=mx;i<=Mx;i++){
				for(j=My;j>=end;j--)if(s.find(i*10+j)!=s.end())break;
				end=j+1;
				if(r<(z=(My-j)*(i-mx+1)))r=z;
			}
		}
		if(s.find(Mx*10+My)==s.end()){
			end=my;
			for(i=Mx;i>=mx;i--){
				for(j=My;j>=end;j--)if(s.find(i*10+j)!=s.end())break;
				end=j+1;
				if(r<(z=(My-j)*(Mx-i+1)))r=z;
			}
		}
		r=(Mx-mx+1)*(My-my+1)-r;
		if(r>99)cout<<"-"<<endl;
		else cout<<r<<endl;
	}
}
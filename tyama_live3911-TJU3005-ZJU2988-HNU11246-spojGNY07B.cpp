#include <map>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
main(){
	map<string,pair<float,string> >m;
	m["kg"]=make_pair(2.2046,"lb");
	m["lb"]=make_pair(0.4536,"kg");
	m["l"]=make_pair(0.2642,"g");
	m["g"]=make_pair(3.7854,"l");
	float f;
	int i=0,n;
	string s;
	for(cin>>n;i<n;cout<<++i<<' '<<setprecision(4)<<fixed<<m[s].first*f<<' '<<m[s].second<<endl)cin>>f>>s;
}
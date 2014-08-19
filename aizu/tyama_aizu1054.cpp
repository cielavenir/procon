#include <vector>
#include <map>
#include <iostream>
#define M make_pair
#define F first
#define S second
using namespace std;
typedef vector<pair<
	pair<
		pair<int,int>,
		pair<int,int>
	>,string
> >links;
main(){
	int N,n,x,y,X,Y,cur;
	string s,t;
	for(;cin>>N>>x>>y;){
		map<string,links>m;
		vector<string>visit;
		for(cur=-1;N;N--){
			links v;
			for(cin>>s>>n;n;n--)cin>>x>>y>>X>>Y>>t,v.push_back(M(M(M(x,X),M(y,Y)),t));
			if(m[s]=v,cur==-1)visit.push_back(s),cur=0;
		}
		for(cin>>N;N;N--){
			if(cin>>s,s=="show")cout<<visit[cur]<<endl;
			if(s=="back"&&cur>0)cur--;
			if(s=="forward"&&cur<visit.size()-1)cur++;
			if(s=="click"){
				cin>>x>>y;
				links v=m[visit[cur]];
				for(n=0;n<v.size();n++){
					if(v[n].F.F.F<=x&&x<=v[n].F.F.S && v[n].F.S.F<=y&&y<=v[n].F.S.S){
						for(;cur<visit.size()-1;)visit.erase(visit.begin()+cur+1);
						visit.push_back(v[n].S);cur++;
					}
				}
			}
		}
	}
}
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
class union_find{
	int *parent,n;
	int root(int a){return parent[a]==a?a:(parent[a]=root(parent[a]));}
public:
	union_find(int _n){n=_n;parent=new int[n+1];for(int i=1;i<=n;i++)parent[i]=i;}
	~union_find(){delete []parent;}
	int same(int a,int b){return root(a)==root(b);}
	int unite(int a,int b){
		int x=root(a),y=root(b);//if(x==y)return 0;
		parent[x]=y;
		return 1;
	}
	int size(){
		set<int>s;
		for(int i=1;i<=n;i++)s.insert(root(i));
		return s.size();
	}
};
int edge[101];
main(){
	int i,N,M,K,S,a1,a2,s1,s2;
	vector<pair<int,pair<int,int> > >v,V;
	scanf("%d%d%d",&N,&M,&K);
	union_find un(N);
	for(i=0;i<M;i++){
		int f,t,c;
		scanf("%d%d%d",&f,&t,&c);
		edge[f]++,edge[t]++,v.push_back(make_pair(c,make_pair(f,t)));
		un.unite(f,t);
	}
	if((a1=a2=un.size())>=K){puts("0");return 0;}
	for(;S=v.size();){
		for(i=S-1;~i;i--){
			if(edge[v[i].second.first]==1||edge[v[i].second.second]==1){
				edge[v[i].second.first]--,edge[v[i].second.second]--;
				V.push_back(v[i]);
				v.erase(v.begin()+i);
			}
		}
		if(S==v.size())break;
	}
	sort(v.begin(),v.end()); //circuit
	sort(V.begin(),V.end()); //others
	s2=99999;
	for(s1=i=0;i<V.size()&&a1<K;a1++,i++){
		s1+=V[i].first;
	}
	if(a1<K)s1=99999;
	if(v.size()){ //false if circuit is 0
		s2=v[0].first;v.erase(v.begin());
		v.insert(v.end(),V.begin(),V.end());
		sort(v.begin(),v.end());
		for(i=0;i<v.size()&&a2<K;a2++,i++){
			s2+=v[i].first;
		}
	}
	printf("%d\n",min(s1,s2));
}
#include<set>
#include<cstdio>
int i,n,v[9999];main(){for(;scanf("%d",&n),n;){std::set<int>t;for(i=1;i<n;i++)v[i]=0,t.insert(i*i%n);for(std::set<int>::iterator s=t.begin(),S=s,T=t.end();s!=T;S=++s)for(;++S!=T;v[i>n/2?n-i:i]+=2)i=*S-*s;for(i=0;i<n/2;)printf("%d\n",v[++i]);}}
//C++11
//int i,n,v[9999];main(){for(;scanf("%d",&n),n;){std::set<int>t;for(i=1;i<n;i++)v[i]=0,t.insert(i*i%n);for(auto s=t.begin(),S=s,T=t.end();s!=T;S=++s)for(;++S!=T;v[i>n/2?n-i:i]+=2)i=*S-*s;for(i=0;i<n/2;)printf("%d\n",v[++i]);}}
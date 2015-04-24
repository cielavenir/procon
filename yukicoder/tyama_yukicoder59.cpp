#import<deque>
#import<cstdio>
main(){std::deque<int>v;int N,K,n;scanf("%d%d",&N,&K);for(;N--;){scanf("%d",&n);auto it=std::lower_bound(v.begin(),v.end(),n>0?n:-n);if(n>0&&v.end()-it<K)v.insert(it,n);if(n<0&&it!=v.end()&&*it==-n)v.erase(it);}printf("%d\n",v.size());}
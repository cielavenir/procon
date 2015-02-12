#import<stack>
#import<cstdio>
main(){int t;std::stack<int>S;for(scanf("%d",&t);~scanf("%d",&t);S.push(t))for(printf("%d\n",S.size());!S.empty()&&S.top()<t;)S.pop();}
#import<cstdio>
#import<vector>
#import<algorithm>
main(){for(int i,r,n,p,c;scanf("%d%d",&n,&r),n;){std::vector<int> v;for(i=n;i;i--)v.push_back(i);for(i=0;i<r;i++)scanf("%d%d",&p,&c),p--,std::rotate(v.begin(),v.begin()+p,v.begin()+p+c);printf("%d\n",v[0]);}}
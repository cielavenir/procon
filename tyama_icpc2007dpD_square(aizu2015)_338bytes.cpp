#import<cstdio>
#import<map>
#define I(M,A)for(i=1;i<=M;i++)scanf("%d",A+i),A[i]+=A[i-1];
main(){for(int n[1501],m[1501],o,a,b,i,j;scanf("%d%d",&a,&b),a;printf("%d\n",o)){std::map<int,int>z;*n=*m=o=0;I(a,n)I(b,m)for(i=0;i<=a;i++)for(j=0;j<=b;)z[n[i]+m[j++]]++;for(typeof(z.begin())p=z.begin();p!=z.end();)o+=p->second*(p++->second-1)/2;}}
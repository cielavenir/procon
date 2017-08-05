#import<vector>
#import<map>
#import<cstdio>
int main(){
	long long n,i=2,j,M=9999;std::map<long long,long long>h;
	std::vector<long long>v,T(M);
	for(;i<M;i++)if(!T[i])for(v.push_back(i*i*i),j=i*2;j<M;j+=M)T[j]=1;
	for(;~scanf("%lld",&n);j||(h[n]+=1),j=0)for(auto&e:v)for(;n>=e&&n%e==0;n/=e);
	for(auto&e:h)j=std::max(j,e.second);printf("%d\n",j);
}

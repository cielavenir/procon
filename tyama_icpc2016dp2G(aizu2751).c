#include <stdio.h>
#define M 5000000
#define MOD 1000000007
int inv[M],fact[M],factr[M];
int comb(int n,int k){
	if(k<0||n<k)return 0;
	return (long long)fact[n]*factr[k]%MOD*factr[n-k]%MOD;
}
int h(int n,int k){return comb(n+k-1,k);}
int main(){
	int a,b,c,sx,sy,i,d,w,r;
	for(i=0;i<M;i++)inv[i]=fact[i]=factr[i]=1;
	for(i=2;i<M;i++){
		inv[i]=(long long)(MOD-MOD/i)*inv[MOD%i]%MOD;
		fact[i]=(long long)fact[i-1]*i%MOD;
		factr[i]=(long long)inv[i]*factr[i-1]%MOD;
	}
	for(;scanf("%d%d%d%d%d",&a,&b,&c,&sx,&sy),a+b+c;){
		if(sx<sy || (sx==sy&&a<b)){
			a^=b,b^=a,a^=b;
			sx^=sy,sy^=sx,sx^=sy;
		}
		d=sx-sy,r=0;
		if(a==0){
			//xチームのほうが多く得点しているので、xチームが勝ち0ならばyチームも勝ち0でなければ不合理
			r=(b>0||sx!=sy) ? 0 : h(c,sx);
		}else if(b==0){
			r=h(a,d-a)*h(a+b+c,sx-d);
		}else{
			for(w=a>d+b?a:d+b;w<=sx;w++){
				r=((long long)h(a,w-a)*h(b,w-d-b)%MOD*h(a+b+c,sx-w)+r)%MOD;
			}
		}
		printf("%d\n",(int)((long long)r*comb(a+b+c,a)%MOD*comb(b+c,b)%MOD));
	}
	return 0;
}
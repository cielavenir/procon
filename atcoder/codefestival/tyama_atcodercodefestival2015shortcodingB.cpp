#import<cstdio>
struct u{
	int*p;
	int R(int a){return p[a]=p[a]==a?a:R(p[a]);} // p[a]= is not required if the time cost does not matter.
	u(int n){p=new int[n];for(;n--;)p[n]=n;}
	~u(){delete[]p;}
	int D(int a,int b){return R(a)-R(b);}
	int U(int a,int b){p[R(a)]=R(b);}
};
int main(){int N,t,x,y;scanf("%d%d",&N,&t);for(u z(N);~scanf("%d%d%d",&t,&x,&y);)x--,y--,t?puts(z.D(x,y)?"NO":"YES"):z.U(x,y);}
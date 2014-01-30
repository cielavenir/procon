#define C(a,b,c,d,e,f)(c-a)*(f-b)-(e-a)*(d-b)
char s[9];
//(1) 入力上限は10**8であるので、整数乗算で面積(sinθの正負)を出したい場合long longである必要がある
long long X[1999],Y[1999],Z[1999][1999],W[1999][1999],x,y,o,p,q;
N,T,flg1,flg2;
main(t,i,j,k){
	scanf("%d",&T);
	if(T>1000)exit(1); //sadly TLE for Level3
	for(t=0;t<T;t++){
		scanf("%s%lld%lld",s,&x,&y);
		if(*s=='M')X[N]=x,Y[N]=y,N++;
		else{
			for(i=0;i<N;i++)if(x==X[i]&&y==Y[i])goto danger;
			for(i=0;i<N;i++)for(j=i+1;j<N;j++){
				if((Z[i][j]=C(X[i],Y[i],X[j],Y[j],x,y))==0){
					//(2) 点i、点j、点(x,y)が一直線上にあると判定できるとき、
					//(x,y)が線分上に載っているかどうか判定するには、3点のX座標が全て等しい場合を例外扱いしなければならない。
					if(X[i]==X[j]){
						if((Y[i]<=y&&y<=Y[j])||(Y[j]<=y&&y<=Y[i]))goto danger;
					}else{
						if((X[i]<=x&&x<=X[j])||(X[j]<=x&&x<=X[i]))goto danger;
					}
				}
				Z[j][i]=-Z[i][j];
				W[i][j]=C(X[i],Y[i],X[j],Y[j],0,0);
				W[j][i]=-W[i][j];
			}
			for(i=0;i<N;i++)for(j=i+1;j<N;j++)for(k=j+1;k<N;k++){
				o=Z[i][j],p=Z[j][k],q=Z[k][i];
				flg1=(o^p)>0&&(p^q)>0;
				o=W[i][j],p=W[j][k],q=W[k][i];
				flg2=(o^p)>0&&(p^q)>0;
				if(flg1!=flg2)goto danger;
			}
			puts("SAFE");continue;
danger:
			puts("DANGER");
		}
	}
	exit(0);
}
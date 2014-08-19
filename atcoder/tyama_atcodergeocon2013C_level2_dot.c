#define C(x,y,a,b,c,d)(a-x)*(d-y)-(c-x)*(b-y)
#define D(x,y,a,b,c,d)(a-x)*(c-x)+(b-y)*(d-y)
char s[9];
//入力上限は10**8であるので、整数乗算で面積(sinθの正負)を出したい場合long longである必要がある
long long X[1999],Y[1999],Z[1999][1999],W[1999][1999],x,y,o,p,q;
main(){
	int N,T,flg1,flg2,t,i,j,k;
	scanf("%d",&T);
	if(T>2000)exit(1); //sadly TLE for Level3
	for(t=0;t<T;t++){
		scanf("%s%lld%lld",s,&x,&y);
		if(*s=='M')X[N]=x,Y[N]=y,N++;
		else{
			for(i=0;i<N;i++)if(x==X[i]&&y==Y[i])goto danger;
			for(i=0;i<N;i++)for(j=i+1;j<N;j++){
				if((Z[i][j]=C(x,y,X[i],Y[i],X[j],Y[j]))==0){
					// 点i、点j、点(x,y)が一直線上にあるとき、(x,y)が線分上に載っているかどうか判定するには内積が負であるかを見れば良い
					if(D(x,y,X[i],Y[i],X[j],Y[j])<0)goto danger;
				}
				Z[j][i]=-Z[i][j];
				W[i][j]=C(0,0,X[i],Y[i],X[j],Y[j]);
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
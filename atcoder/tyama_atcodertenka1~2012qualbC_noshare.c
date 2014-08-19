#define min(a,b) (a<b?a:b)
int M[2160];

int gettime(){
	int h,m;
	scanf("%02d:%02d",&h,&m);
	return h*60+m;
}

void set(int t1,int t2){
	for(;t1<t2;t1++)M[t1]++;
}

int main(){
	int N,t1,t2,i;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		t1=gettime(),t2=gettime();
		set(t1,t2);
		if(t1<720)set(t1+1440,min(t2+1440,2160));
	}
	for(t1=t2=0;t1<2160;t1++)
		if(M[t1]>t2)t2=M[t1];
	printf("%d\n",t2);
	exit(0);
}
#define M 10000
int table[M+1];
int f[M+1],prime[M+1];

void createtable(){
  int i,j;
  for(i=0;i<M;i++){
    int x=prime[i];
    table[x]++;
    for(j=i+1;;j++){
      x+=prime[j];
      if(x>M)break;
      table[x]++;
    }
  }
}

//https://code.google.com/p/teamscl/source/browse/trunk/3.%20Sieve%20of%20Eratosthenes%20in%20linear%20time.txt
int GenP(){
	int i,tot,p,tmp;
	tot=0;
	for(i=2;i<=M;++i)f[i]=i;
	for(p=2;p<=M;++p){
		if(f[p]==p)prime[tot++]=p;
		for(i=0;i<tot && prime[i]<=f[p];++i){
			tmp=prime[i]*p;
			if(tmp<=M){
				f[tmp]=prime[i];
			}else{
				break;
			}
		}
	}
}

int main(){
  int n;
  GenP();
  createtable();
  while(1){
    scanf("%d",&n);
    if(!n)return 0;
    printf("%d\n",table[n]);
  }
}
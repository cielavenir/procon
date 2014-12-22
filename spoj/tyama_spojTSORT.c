int v[1000001];
int main(){
	int i=0,j,n;
	scanf("%d",&n);
	for(;i<n;i++)scanf("%d",&j),v[j]++;
	for(i=0;i<1000001;i++)for(j=0;j<v[i];j++)printf("%d\n",i);
}
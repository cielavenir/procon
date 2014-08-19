v[999][4];main(i,j,n,c){for(;scanf("%d",&n),n;!c?puts("NA"):1){
for(i=0;i<n;i++)
	for(j=0;j<4;j++)scanf("%d",v[i]+j);
for(j=0;j<4;j++)scanf("%d",v[n]+j);
for(c=i=0;i<n;i++)
	if(v[i][1]<=v[n][0]&&v[i][2]<=v[n][1]&&v[i][3]<=v[n][2]&&v[i][1]*4+v[i][2]*9+v[i][3]*4<=v[n][3])
		printf("%d\n",v[i][0]),c++;
}exit(0);}
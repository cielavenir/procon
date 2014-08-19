void insertion_sort2(int *a, int N){ //wikipedia
	int i,j,t;
	for(j=0;j<N;j++)printf(j<N-1?"%d ":"%d\n",a[j]);
	for(i=1;i<N;i++){
		t = a[i];
		for(j=i; j>0 && a[j-1]>t; j--){
			a[j] = a[j-1];
		}
		a[j] = t;
		for(j=0;j<N;j++)printf(j<N-1?"%d ":"%d\n",a[j]);
	}
}
a[999],i;main(n){
	for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
	insertion_sort2(a,n);
	exit(0);
}
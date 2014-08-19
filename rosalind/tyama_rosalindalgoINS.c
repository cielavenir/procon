int insertion_sort2(int *a, int N){ //wikipedia
	int i,j,t,r=0;
	for(i=1;i<N;i++){
		t = a[i];
		for(j=i; j>0 && a[j-1]>t; j--){
			a[j] = a[j-1];r++;
		}
		a[j] = t;
	}
	return r;
}
a[999],i;main(n){
	for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
	printf("%d\n",insertion_sort2(a,n));
}
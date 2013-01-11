a[26];
main(i,f,s){
	for(;(i=getchar())>96;)a[i-97]++;
	for(s=f=i=0;i<26;i++){
		if(a[i]&1){if(f)puts("0"),exit(0);f=1;}
		a[i]/=2;
		s+=a[i];
	}
	long long r=1;
	for(;s;s--)r*=s;
	for(i=0;i<26;i++)for(;a[i];a[i]--)r/=a[i];
	printf("%lld\n",r);
	exit(0);
}
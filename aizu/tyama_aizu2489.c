char s[9];x,l,i;P(a){
	for(sprintf(s,"%d",a),l=strlen(s),x=0;x<l&s[x]==s[l-x-1];x++);
	return x==l;
}
main(n){for(scanf("%d",&n);;i++){
	if(P(n-i))printf("%d\n",n-i),exit(0);
	if(P(n+i))printf("%d\n",n+i),exit(0);
}}
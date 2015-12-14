int main(){
	int a,b,c,d,e,f,g,h,n,m;
	scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
	n=a*e+a/10*g+b*f+b/20*h;
	m=c*e+c/10*g+d*f+d/20*h;
	puts(n>m?"hiroshi":n<m?"kenjiro":"even");
	return 0;
}
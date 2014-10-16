#!/usr/bin/groovy
Scanner cin=new Scanner(System.in);
int n,k,m,r,i;
for(;;System.out.println((r+m)%n+1)){
	n=cin.nextInt();k=cin.nextInt();m=cin.nextInt();
	if(n==0)break;
	for(r=i=0;++i<n;r%=i)r+=k;
}
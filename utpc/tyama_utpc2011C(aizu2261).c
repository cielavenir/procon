char a[99],b[99];
int p,q,i,l,r;
#define f(x) (x=='('?')':x==')'?'(':x=='{'?'}':x=='}'?'{':x=='['?']':x==']'?'[':x)
int palindrome(){
	for(i=l=0;i<strlen(a);i++)
		if(p&1<<i)b[l++]=a[i];
	b[l]=0;
	l=strlen(b);
	for(i=0;i<l/2;i++)if(b[i]!=f(b[l-1-i]))return;
	if(b[i]!='w')return;
	r=l>r?l:r;
}
main(){
	scanf("%s",a);q=1<<strlen(a);
	for(p=1;p<q;p++)palindrome();
	printf("%d\n",r);exit(0);
}
#define q(x)(x<0x40?x^1:x)
char a[99];main(i,l,r){scanf("%s",a);l=strlen(a);for(r=i=0;i<l/2;i++)if(a[i]!=q(a[l-1-i]))r++;if((l%2)&&a[i]!='i'&&a[i]!='w')r++;printf("%d\n",r);exit(0);}
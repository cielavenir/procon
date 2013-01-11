l[10];main(v,V,i,s){for(;~scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d",l,l+1,l+2,l+3,l+4,l+5,l+6,l+7,l+8,l+9,&v,&V);printf("%d\n",i+1)){
for(i=s=0;i<10;i++)s+=l[i];
double t=s*1.0/(v+V),p=v*t-.1;
for(i=s=0;i<10;i++)if(s+=l[i],s>p)break;
}exit(0);}
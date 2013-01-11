v[20];char t[9],s[9],c;main(a,L,i,j,k){for(;scanf("%d%d",&a,&L),L;)
for(v[0]=a,k=1;;v[k++]=a){
for(sprintf(t,"%0*d",L,a),s[L]=i=0;i<L;s[i]=t[L-i-1],i++)for(j=1;j<L-i;j++)if(t[j]<t[j-1])c=t[j],t[j]=t[j-1],t[j-1]=c;
for(a=atoi(s)-atoi(t),i=0;i<k;i++)if(v[i]==a)break;
if(i<k){printf("%d %d %d\n",i,a,k-i);break;}
}exit(0);}
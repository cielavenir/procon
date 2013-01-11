a[8]={-2,-2,-1,-1,1, 1, 2,2};
b[8]={-1, 1,-2, 2,-2,2,-1,1};
z[5000];m[301][301];
main(c,i,f,g,s,p,q,x,y){
  for(scanf("%d",&c);c--;){
    scanf("%d%d%d%d%d",&s,&p,&q,&x,&y);
    memset(m,0xff,sizeof(m));
    z[0]=(p<<16)|q;
    m[p][q]=0;
    for(f=0,g=1;f!=g;){
      p=z[f]>>16;q=z[f]&0xffff;f=(f+1)%5000;
      for(i=0;i<8;i++)
        if(0<=p+a[i]&&p+a[i]<s&&0<=q+b[i]&&q+b[i]<s&&m[p+a[i]][q+b[i]]==-1)z[g]=((p+a[i])<<16)|(q+b[i]),g=(g+1)%5000,m[p+a[i]][q+b[i]]=m[p][q]+1;
      if(~m[x][y]){printf("%d\n",m[x][y]);break;}
    }
  }
}
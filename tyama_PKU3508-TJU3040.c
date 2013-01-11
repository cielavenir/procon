//Reference: http://www.shinko-keirin.co.jp/kosu/mathematics/kirinuki/kirinuki03-b.html#11
int x[1000001];
main(i,j,n,c,s,u,a){
  n=1;
  while(c=getchar()){
    if(c=='\n'){
      if(!x[1])break;
      printf("%d. ",i++);
      for(j=1,u=0,s=-1;j<n;j++)u+=s*x[j],s*=-1;
      u%=11;if(u<0)u+=11;
      a=11-u;
      if(a==11)puts("IMPOSSIBLE"); //920+92=1012... So a==10 is really possible.
      else{
        x[1]+=a*10;
        for(j=1;j<n;j++){x[j]+=x[j-1]*10;putchar(x[j]/11+'0');x[j]%=11;}
        puts("");
      }
      n=1;continue;
    }
    x[n++]=c-'0';
  }
}
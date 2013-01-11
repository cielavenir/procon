int main(){
  int q,d,n,p,c,i,j,k,l,x;
  loop:
    scanf("%d%d%d%d%d",&q,&d,&n,&p,&c);
    if(!c)return 0;
    for(i=q;i>=0;i--){
      j=k=l=0;
      x=i*25;
      if(x==c)goto succ;
      if(x>c)continue;
      if(d)
      for(j=1;j<=d;j++){
        x+=10;
        if(x==c)goto succ;
        if(x>c){x-=10;j--;break;}
      }
      if(j>d)j=d;
      if(n)
      for(k=1;k<=n;k++){
        x+=5;
        if(x==c)goto succ;
        if(x>c){x-=5;k--;break;}
      }
      if(k>n)k=n;
      if(p)
      for(l=1;l<=p;l++){
        x+=1;
        if(x==c)goto succ;
        if(x>c)break;
      }
    }

    printf("Cannot dispense the desired amount.\n");
    goto loop;

  succ:
    while(i&&l>=5&&(d-j)>=3){i--;l-=5;j+=3;}
    printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",i,j,k,l);
    goto loop;
}
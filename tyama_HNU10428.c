char s[250];
main(){
  int c,i=0;
  do{
    c=getchar();
    switch(c){
      case '\n': case -1:
        if(i)s[i]=0,puts(s),i=0;break;
      case '@': i=0;break;
      case '#': if(i>0)i--;break;
      default: s[i]=c;i++;
    }
  }while(~c);
  return 0;
}
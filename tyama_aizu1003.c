#define put() putchar(t[d-1][x%strlen(t[d-1])])
char *t[]={"',.!?","abcABC","defDEF","ghiGHI","jklJKL","mnoMNO","pqrsPQRS","tuvTUV","wxyzWXYZ"};
main(x,c,d){
  for(d=-1,x=-1;~(c=getchar());)
    if(c=='\n'){
      if(d)put();puts(""),d=-1,x=-1;
    }else if(c-=48){
      if(c==d)x++;
      else if(~x)put(),x=0;
      if(d==-1)x=0;
      d=c;
    }else{
      if(~d&&d)put(),x=-1;
      else putchar(' ');
      d=-1;
    }
  return 0;
}
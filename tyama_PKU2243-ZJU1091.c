#define between(a,x,b) ( ((a)<=(x))&&((x)<=(b)) )

char x[8][8]={
  {0,3,2,3,2,3,4,5},
  {3,4,1,2,3,4,3,4},
  {2,1,4,3,2,3,4,5},
  {3,2,3,2,3,4,3,4},
  {2,3,2,3,4,3,4,5},
  {3,4,3,4,3,4,5,4},
  {4,3,4,3,4,5,4,5},
  {5,4,5,4,5,4,5,6}
};

int abs(int i){return i<0 ? -i : i;}

int main(){
  char s1[3],s2[3];
  int a,b,c,d,i,j,r;
  while(1){
    if(scanf("%s %s",s1,s2)<0)return 0;
    a=s1[0]-'a',b=s2[0]-'a';
    c=s1[1]-'1',d=s2[1]-'1';
    i=b-a,j=d-c;
    r=x[abs(i)][abs(j)];
    if(abs(i)==1&&abs(j)==1){
      //printf("%d %d %d %d %d %d",a,b,c,d,i,j);
      if(between(0,a+i*2,7)&&between(0,c-j,7)||between(0,c+j*2,7)&&between(0,a-i,7))r=2;
    }
    printf("To get from %s to %s takes %d knight moves.\n",s1,s2,r);
  }
}
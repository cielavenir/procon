int main(i,a,b){
  char *x[4]={"Bogey","Par","Birdie","Eagle"};
  while(scanf("%d%d",&a,&b),a){
    printf("Hole #%d\n%s.\n\n",i,b==1?"Hole-in-one":a-b<-1?"Double Bogey":a-b>2?"Double Eagle":x[a-b+1]);
    i++;
  }
}
main(){
int i,n;float x,y;
scanf("%d",&n);
for(i=0;i<n;){
scanf("%f%f",&x,&y);
printf("Property %d: This property will begin eroding in year %d.\n",++i,(int)(0.0314159*(x*x+y*y))+1);
}
printf("END OF OUTPUT.");
}
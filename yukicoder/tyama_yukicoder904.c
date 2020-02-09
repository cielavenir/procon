m,c,d,x,y;
main(){
for(scanf("%d",&x);~scanf("%d%d",&x,&y);c+=x,d+=y)if(m<x+y)m=x+y;
x=0;if(x<d-c)x=d-c;if(x<m-c)x=m-c;
printf("%d\n",d-x+1);
}

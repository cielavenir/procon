int G(x,y){return y?G(y,x%y):x;}
main(x,y,z,t,f){for(;scanf("%d%d",&x,&y),y;printf("%d %d\n",z>f?z:f,t)){
y/=G(x,y);
for(z=0;y%2==0;y/=2)z++;
for(f=0;y%5==0;y/=5)f++;
if(y==1)t=0;else{x=1;t=0;do{x=x*10%y;t++;}while(x!=1);}
}exit(0);}
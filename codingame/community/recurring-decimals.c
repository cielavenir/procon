//aizu0113
int G(x,y){return y?G(y,x%y):x;}
main(Y,x,y,z,t,f){for(;~scanf("%d",&y);){
x=1;Y=y;y/=G(x,y);
for(z=0;y%2==0;y/=2)z++;
for(f=0;y%5==0;y/=5)f++;
if(z>f)f=z;
if(y==1)t=0;else{z=1;t=0;do{z=z*10%y;t++;}while(z!=1);}
printf("0.");
for(z=0;z<f+t;z++){
if(z==f&&t)putchar('(');
putchar(x*10/Y+48),x=x*10%Y;
if(z==f+t-1&&t)putchar(')');
}
puts("");
}exit(0);}

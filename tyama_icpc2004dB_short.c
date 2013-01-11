T[20][20],X,Y,p,q,i;
#define t T[y][x]
void R(x,y){(0<=x&&x<X&&0<=y&&y<Y&&t)?t=0,i++,R(x-1,y),R(x+1,y),R(x,y-1),R(x,y+1):0;}
main(x,y){for(;scanf("%d%d",&X,&Y),X;i=0,R(p,q),printf("%d\n",i))
for(i=0;i<X*Y;i++)switch(x=i%X,y=i/X,getchar()){
	case 10:i--;break;
	case'@':p=x;q=y;
	case'.':t=1;break;
	case'#':t=0;
}exit(0);}
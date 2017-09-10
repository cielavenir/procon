int zeller(int Y,int M,int D){if(++M<4)Y-=1,M+=12;int y=Y/100,z=y%100;return (21*y/4+5*z/4+13*M/5+D)%7;}
char *W[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
main(m,d){for(;scanf("%d%d",&m,&d),m;)puts(W[zeller(2004,m,d)]);exit(0);}

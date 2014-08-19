#define E(n,e)else if(!(k&n))for(x=0;x<5;x++)puts(k&1<<(e+x)?"1":"2");
#define K(n)||(k&n)==n
i,k;main(x){for(;;i++){scanf("%d",&x);if(!x)exit(0);k+=1<<(5*x+i);if(i==4){if((k&992&&k&31744&&k&1015808)K(992)K(31744)K(1015808))for(x=5;x--;)puts("3");E(992,10)E(31744,15)E(1015808,5)k=0,i=-1;}}}
//f(n){return __builtin_clz(n)+__builtin_ctz(n)==31;}
//f(n){return (n&-n)==n;}H;main(W){scanf("%d%d",&H,&W);H=!printf("%lld\n",(1LL<<64-__builtin_clzll(1LL*H*W-1))-(!f(W)||f(H)||f(H+1)?1:W));}
H;main(W){scanf("%d%d",&H,&W);H=!printf("%lld\n",(1LL<<64-__builtin_clzll(1LL*H*W-1))-((W&-W)-W||(H&-H)==H||(H+1&-H-1)==H+1?1:W));}
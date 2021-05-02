triangle(w,h,i){
  for(w=0;w<h;w++,puts("")){
    for(i=0;i<h-w-1;i++)putchar(' ');
    for(i=0;i<w*2+1;i++)putchar('*');
  }
}

parallelogram(w,h,i){
  for(;h--;puts("")){
    for(i=0;i<h;i++)putchar(' ');
    for(i=0;i<w;i++)putchar('*');
  }
}

rectangle(w,h,i){
  for(;h--;puts(""))
    for(i=0;i<w;i++)putchar('*');
}

main(n,w,h,i){
  for(;scanf("%d",&n),~n;puts("")){
    if(n==1){scanf("%d",&h);triangle(w,h,i);}
    if(n==2){scanf("%d%d",&w,&h);parallelogram(w,h,i);}
    if(n==3){scanf("%d%d",&w,&h);rectangle(w,h,i);}
  }
}
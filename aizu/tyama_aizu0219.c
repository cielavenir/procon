a[10];main(i,j,x){
for(;scanf("%d",&j),j;){
memset(a,0,40);
for(i=0;i<j;i++)scanf("%d",&x),a[x]++;
for(j=0;j<10;puts(""),j++)if(!a[j])putchar('-');else for(i=0;i<a[j];i++)putchar('*');
}}
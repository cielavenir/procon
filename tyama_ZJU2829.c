#define MAX 220000
#define MAX2 100000

char table1[MAX+1];
int table2[MAX2+1];

void createtable(){
  int i,j=1;
  for(i=3;i<=MAX;i+=3)
    table1[i]=1;
  for(i=5;i<=MAX;i+=5)
    table1[i]=1;
  for(i=3;j<=MAX2;i++)
    if(table1[i])table2[j++]=i;
}

main(n){createtable();for(;~scanf("%d",&n);printf("%d\n",table2[n]));}
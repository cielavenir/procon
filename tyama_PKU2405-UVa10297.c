// http://d.hatena.ne.jp/Ozy/20060822
// on UVa 10297 return 0 is required.

/*no longer AC using cbrt (ToT) */
int main(D,V){
while(scanf("%d%d",&D,&V),D)
printf("%.3f\n",exp(log(D*D*D-V/.5235988)/3));
}
char t[]="BHISO""ECRTM""GWYVA""LUZDN""FJKPQX";
char x[]="ABCDE""FGHIJ""KLMNO""PQRST""UVWXYZ";
int m[]={
	1,22,22,0,
	11,14,14,25,3,0,
	3,13,1,25,13,0,
	3,14,14,18,19,21,2,0,
	1,13,0,
	24,19,18,21,19,2,17,13,0,
	6,13,17,15,7,1,19,-1
};
int index(c){return strchr(x,c)-x;}
main(i,j,k){
for(j=0;j<27;j++){
	for(i=0;~m[i];i++){
		if(m[i]){
			int c=t[m[i]-1];
			for(k=0;k<j;k++)c=t[index(c)];
			putchar(c);
		}else putchar(' ');
	}
	putchar('\n');
}
exit(0);
}
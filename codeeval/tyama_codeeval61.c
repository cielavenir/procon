char t[]="BHISO""ECRTM""GWYVA""LUZDN""FJKPQX";
int m[]={
	1,22,22,0,
	11,14,14,25,3,0,
	3,13,1,25,13,0,
	3,14,14,18,19,21,2,0,
	1,13,0,
	24,19,18,21,19,2,17,13,0,
	6,13,17,15,7,1,19,-1
};
main(i){
	for(i=0;~m[i];i++)
		if(m[i])putchar(strchr(t,m[i]+65)-t+65);
		else putchar(' ');
	putchar('\n');
exit(0);}
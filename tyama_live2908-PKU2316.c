a[10],i,l;
main(c){
puts("Program 1 by team 0");
	for(;~(c=getchar());)c==10?(l=l>i?l:i,i=0):(a[i++]+=c-'0');
	for(i=-1;++i<l;)putchar(a[i]%10+'0');
puts("\nEnd of program 1 by team 0");return 0;
}
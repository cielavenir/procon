//gcj2012 qualA
char *T="ynficwlbkuomxsevzpdrjgthaq",*p;
main(i,c){for(;~(c=getchar());putchar((p=strchr(T,c))?97+(p-T):c));}
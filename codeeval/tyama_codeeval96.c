#include <ctype.h>
#include <stdio.h>
main(c){for(;~(c=getchar());)putchar(islower(c)?toupper(c):tolower(c));}
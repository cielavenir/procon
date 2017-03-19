char z[9];
main(){
	gets(z);
	putchar(z[2]^(12*(*z==68)));
}

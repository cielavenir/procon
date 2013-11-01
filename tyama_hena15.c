//http://qiita.com/Nabetani/items/cba03c96d1ea55f6e861
//http://nabetani.sakura.ne.jp/hena/ord15elebubo/
#include <stdio.h>
unsigned int v[2];
int a[2][34];
int main(){
	int i,j;
	for(;~scanf("%08x/%08x",v,v+1);){
		for(i=0;i<2;i++){
			for(j=0;j<32;j++)a[i][j]=(v[i]>>(31-j))&1;
		}
		for(i=0;i<32;){
			if(!a[0][i]&&!a[1][i]){
				i++;
			}else if(a[0][i]&&a[1][i]){
				if(a[0][i+1]){
					if(a[0][i+2]){
						putchar('N');
						i+=3;
					}else{
						putchar('R');
						i+=2;
					}
				}else if(a[1][i+1]){
					if(a[1][i+2]){
						putchar('U');
						i+=3;
					}else{
						putchar('L');
						i+=2;
					}
				}
			}else if(a[0][i]){
				if(a[0][i+2]){
					putchar('T');
					i+=3;
				}else{ //if a[1][i+2]
					putchar('Z');
					i+=3;
				}
			}else{
				if(a[0][i+2]){
					putchar('S');
					i+=3;
				}else{
					putchar('J');
					i+=2;
				}
			}
		}
		puts("");fflush(stdout);
	}
}
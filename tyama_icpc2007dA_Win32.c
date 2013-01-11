#include <windows.h>

int get(){
  DWORD dw;
  int ret=0;
  char s[2]="\0\0";
  while(1){
    ReadFile(GetStdHandle(STD_INPUT_HANDLE),s,1,&dw,NULL);
    if(s[0]=='\n'||s[0]==' ')break;
    if(s[0]<'0'&&'9'<s[0])continue;
    ret=ret*10+s[0]-'0';
  }
  return ret;
}

int pow10(int n){int r=1;for(;n;n--)r*=10;return r;}

void put(int n){
  DWORD dw;
  int i,f=0,x=9;
  char s[2]="\0\0";
  for(;x>=0;x--){
    if( (i=n/pow10(x)%10)||f ){
      s[0]=i+'0';f=1;
      WriteFile(GetStdHandle(STD_OUTPUT_HANDLE),s,1,&dw,NULL);
    }
  }
  WriteFile(GetStdHandle(STD_OUTPUT_HANDLE),"\n",1,&dw,NULL);
}

int main(){
	int i, n, s, ma, mi, sum;
	while(1){
		ma=0; mi=1000; sum=0;
		//scanf("%d", &n);
		n=get();
		if(!n)return 0;
		for(i=0;i<n;i++){
			//scanf("%d", &s);
			s=get();
			ma=max(ma, s);
			mi=min(mi, s);
			sum+=s;
		}
		//printf("%d\n", (sum-ma-mi)/(n-2));
		put((sum-ma-mi)/(n-2));
	}
}
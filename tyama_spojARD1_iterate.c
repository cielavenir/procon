#define BASE 100000000
int main(){
	long long a=0,b=1,x,i=0;
	for(;i<20;i++){
		printf("{%lld,%lld,%lld},\n",a,b,(a+i*4+3)%123456789);
		x=b;
		b=(a+b)%123456789;
		a=x;
	}
}
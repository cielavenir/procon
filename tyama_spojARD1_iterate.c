#define BASE 100000000
int main(){
	long long a=-1,b=1,c=4,d=12,x,i=0;
	for(;i<100000000000;i++){
		c=(b+c)%123456789;
		d=(c+d)%123456789;
		x=b;
		b=(a+b)%123456789;
		a=x;
		if(i%100000000==0)printf("{%lld,%lld,%lld,%lld},\n",a,b,c,d);
	}
}
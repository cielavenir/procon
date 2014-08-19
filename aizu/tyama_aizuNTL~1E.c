int r0,r1,r2,a0=1,a1=0,a2,b0=0,b1=1,b2,q1;
int main(){
	scanf("%d%d",&r0,&r1);
	for(;r1>0;){
		q1 = r0 / r1;
		r2 = r0 % r1;
		a2 = a0 - q1*a1;
		b2 = b0 - q1*b1;
		r0 = r1, r1 = r2;
		a0 = a1, a1 = a2;
		b0 = b1, b1 = b2;
	}
	printf("%d %d\n",a0,b0);
	return 0;
}
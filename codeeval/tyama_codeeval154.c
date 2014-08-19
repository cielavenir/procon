unsigned int head[8192];
int main(){
	int a1,b1,c1,d1,a2,b2,c2,d2;
	int readlen,ihl,i;
	for(;~scanf("%d.%d.%d.%d %d.%d.%d.%d",&a1,&b1,&c1,&d1,&a2,&b2,&c2,&d2);){
		for(i=0;i<20;i++)scanf("%02x",head+i);
		readlen=(head[2]<<8)|head[3];
		ihl=head[0]&0xf;
		for(;i<readlen;i++)scanf("%02x",head+i);
		head[12]=a1,head[13]=b1,head[14]=c1,head[15]=d1;
		head[16]=a2,head[17]=b2,head[18]=c2,head[19]=d2;
		int sum=0;
		for(i=0;i<ihl*2;i++)if(i!=5){
			sum+=(head[2*i+0]<<8)|head[2*i+1];
			if(sum>65535)sum+=sum>>16,sum&=65535;
		}
		sum=(~sum)&65535;
		head[10+0]=(sum>>8)&255;
		head[10+1]=sum&255;
		for(i=0;i<ihl*4;i++)printf(i<ihl*4-1?"%02x ":"%02x\n",head[i]);
	}
	return 0;
}
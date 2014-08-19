int check(int a[12]){ //adapted from rummy card game :p
	int i=1;
	for(;i<10;i++){
		a[i]%=3;
		if(a[i]>0){
			if(a[i+1]-a[i]<0 || a[i+2]-a[i]<0)return 0;
			a[i+1]-=a[i];a[i+2]-=a[i];a[i]=0;
		}
	}
	return 1;
}

int main(){
	char S[16];
	for(;~scanf("%s",S);){
		int x[12],y[12],i=0,j,count=0;
		memset(x,0,sizeof(x));
		for(;i<13;i++)x[S[i]-'0']++;
		for(i=1;i<10;i++){
			if(x[i]>3)continue;
			x[i]++;
			for(j=1;j<10;j++){ //head is j?
				if(x[j]<2)continue;
				memcpy(y,x,sizeof(x));
				y[j]-=2;
				if(check(y)){
					if(count)putchar(' ');
					printf("%d",i);
					count++;
					break;
				}
			}
			x[i]--;
		}
		puts(count?"":"0");	
	}
	return 0;
}
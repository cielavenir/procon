int main(){
	int H,M,S,h,m,s;
	for(;~scanf("%d:%d:%d %d:%d:%d",&H,&M,&S,&h,&m,&s);){
		S+=3600*H+60*M;
		s+=3600*h+60*m;
		s=s>S?s-S:S-s;
		printf("%02d:%02d:%02d\n",s/3600,s/60%60,s%60);
	}
	return 0;
}
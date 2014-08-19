int days(int y,int m,int d){
	if(m<3)m+=12,y--;
	return 365*y+y/4-y/100+y/400+306*(m+1)/10+d-429;
}
int main(){
	int y,m,d;
	scanf("%d%d%d",&y,&m,&d);
	printf("%d\n",days(2014,5,17)-days(y,m,d));
	return 0;
}
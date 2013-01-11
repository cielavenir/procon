#define between(a,x,b) ((a)<=(x)&&(x)<(b))

char table[10000];
int x,y,i,f;

void check(a,b){
	int _f=0;
	if(!between(0,a,x)||!between(0,b,y))return;
	if(!table[b*100+a])return;
	table[b*100+a]=0;

	if(!f){i++;f=_f=1;}
	check(a-1,b-1);
	check(a-1,b);
	check(a-1,b+1);
	check(a,b-1);
	check(a,b+1);
	check(a+1,b-1);
	check(a+1,b);
	check(a+1,b+1);
	if(_f){f=0;}
}

int main(){
	char c;
	int j,k;

		scanf("%d %d",&y,&x);

		i=0;
		for(j=0;j<x*y;j++){
			int _x=j%x, _y=j/x;
			do scanf("%c",&c); while(c=='\n');
			switch(c){
				case '.': table[_y*100+_x]=0; break;
				case 'W': table[_y*100+_x]=1; break;
			}
		}

		for(j=0;j<y;j++)
			for(k=0;k<x;k++)
				check(k,j);
		printf("%d\n",i);

	return 0;
}
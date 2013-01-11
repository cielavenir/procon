//2004b
//071115 2225-2257

#define between(a,x,b) ((a)<=(x)&&(x)<(b))

char table[400];
int x,y,cx,cy,i;

void saiki(a,b){
	if(between(0,a,x)&&between(0,b,y)&&!table[b*20+a]){
		table[b*20+a]=1;
		i++;
		saiki(a-1,b);saiki(a+1,b);saiki(a,b-1);saiki(a,b+1);
	}
}

int main(){
	char c;
	while(1){
		scanf("%d %d",&x,&y);
		if(!x&&!y)break;
		for(i=0;i<x*y;i++){
			int _x=i%x, _y=i/x;
			do scanf("%c",&c); while(c=='\n');
			switch(c){
				case '@': cx=_x;cy=_y;
				case '.': table[_y*20+_x]=0; break;
				case '#': table[_y*20+_x]=1; break;
			}
		}
		i=0;
		saiki(cx,cy);
		printf("%d\n",i);
	}
	return 0;
}
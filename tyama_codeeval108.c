char m[10][11];
main(){
	int i,j,C,r=0,c=0,ins=0;
	for(i=0;i<10;i++)for(j=0;j<10;j++)m[i][j]=' ';
	for(;~(C=getchar());){
		if(C=='^'){
			C=getchar();
			if(C=='c'){
				for(i=0;i<10;i++)for(j=0;j<10;j++)m[i][j]=' ';
			}else if(C=='h'){
				r=c=0;
			}else if(C=='b'){
				c=0;
			}else if(C=='d'){
				if(r<9)r++;
			}else if(C=='u'){
				if(r>0)r--;
			}else if(C=='l'){
				if(c>0)c--;
			}else if(C=='r'){
				if(c<9)c++;
			}else if(C=='e'){
				for(j=c;j<10;j++)m[r][j]=' ';
			}else if(C=='i'){
				ins=1;
			}else if(C=='o'){
				ins=0;
			}else if(C=='^'){
				if(ins)for(j=9;j>c;j--)m[r][j]=m[r][j-1];
				m[r][c++]=C;
				if(c==10)c=9;
			}else{
				r=C-'0';
				c=getchar()-'0';
			}
		}else{
			if(C!='\n'){
				if(ins)for(j=9;j>c;j--)m[r][j]=m[r][j-1];
				m[r][c++]=C;
				if(c==10)c=9;
			}
		}
	}
	for(i=0;i<10;i++){
		for(j=9;j>=0&&m[i][j]==' ';j--)m[i][j]=0;
		puts(m[i]);
	}
}
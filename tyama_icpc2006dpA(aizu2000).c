char s[2];m[21][21];
main(n,x,y,c){for(;scanf("%d",&n),n;){
for(memset(m,0,sizeof(m));n--;m[x][y]=1)scanf("%d%d",&x,&y);
for(scanf("%d",&n),x=y=10;n--;)for(scanf("%s%d",s,&c),m[x][y]=0;c--;m[x][y]=0)*s=='W'?x--:*s=='E'?x++:*s=='S'?y--:y++;
for(x=0;x<21;x++)for(y=0;y<21;y++)if(m[x][y])goto z;
z:puts(x-21?"No":"Yes");
}exit(0);}
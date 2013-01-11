int map[16][3];

int main(){
  int i,j,s,r,x;
  int c[3];

  for(i=0;i<16;i++)
    for(j=0;j<3;j++)
      scanf("%d",map[i]+j);
  while(1){
    for(i=0;i<3;i++)
      scanf("%d",c+i);
    if(*c==-1)return 0;
    s=27000000;
    for(i=0;i<16;i++){
      x=(map[i][0]-c[0])*(map[i][0]-c[0])+(map[i][1]-c[1])*(map[i][1]-c[1])+(map[i][2]-c[2])*(map[i][2]-c[2]);
      if(x<s){s=x;r=i;}
    }
    printf("(%d,%d,%d) maps to (%d,%d,%d)\n",c[0],c[1],c[2],map[r][0],map[r][1],map[r][2]);
  }
}
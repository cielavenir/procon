//DDR

int judge(int state, char *str){
  int l=strlen(str),i=0;
  for(;i<l;i++){
    switch(str[i]){
      case 'L': if(!(state==2||state==4||state==6))return 0;state=1;break;
	  case 'R': if(!(state==1||state==3||state==5))return 0;state=2;break;
      case 'U': if(!(state==1||state==5)){if(!(state==2||state==6))return 0;state=3;}else state=4;break;
	  default:  if(!(state==1||state==3)){if(!(state==2||state==4))return 0;state=5;}else state=6;break;
    }
  }
  return 1;
}

int isacceptable(char *str){
  switch(str[0]){
    case 'L': return judge(1,str+1);
	case 'R': return judge(2,str+1);
	case 'U': return judge(3,str+1)?1:judge(4,str+1);
	default:  return judge(5,str+1)?1:judge(6,str+1);
  }
}

int main(){
  int n; char str[100001];
  scanf("%d",&n);
  for(;n;n--){
    scanf("%s",str);
	printf("%s\n",isacceptable(str)?"Yes":"No");
  }
  return 0;
}
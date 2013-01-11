char *haab[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char *tzolkin[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int getm(char *p){
  int i=0;
  for(;;i++)if(!strcmp(p,haab[i]))return i;
}

int main(){
  int n;
  char m[6];
  int d,y,x;
  scanf("%d",&n);
  printf("%d\n",n);
  for(;n;n--){
    scanf("%d. %s %d",&d,m,&y);
    x=y*365+getm(m)*20+d;
    printf("%d %s %d\n",x%13+1,tzolkin[x%20],x/260);
  }
  return 0;
}
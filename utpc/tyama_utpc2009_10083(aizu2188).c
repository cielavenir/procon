main(c,d,_d,x,i,j){
  char n[1001],u[51];
  for(x=d=-1,i=0;(c=getchar())!=' ';i++){
    if(c=='.'){i--;_d=d=i;continue;}
    if(x<0&&c!='0')x=i;
    n[i]=c;
  }
  if(d==-1)_d=d=i-1;

  scanf("%s",u);
if(!strcmp(u,"yotta"))d+=24;
if(!strcmp(u,"zetta"))d+=21;
if(!strcmp(u,"exa"))d+=18;
if(!strcmp(u,"peta"))d+=15;
if(!strcmp(u,"tera"))d+=12;
if(!strcmp(u,"giga"))d+=9;
if(!strcmp(u,"mega"))d+=6;
if(!strcmp(u,"kilo"))d+=3;
if(!strcmp(u,"hecto"))d+=2;
if(!strcmp(u,"deca"))d+=1;
if(!strcmp(u,"yocto"))d+=-24;
if(!strcmp(u,"zepto"))d+=-21;
if(!strcmp(u,"ato"))d+=-18;
if(!strcmp(u,"femto"))d+=-15;
if(!strcmp(u,"pico"))d+=-12;
if(!strcmp(u,"nano"))d+=-9;
if(!strcmp(u,"micro"))d+=-6;
if(!strcmp(u,"milli"))d+=-3;
if(!strcmp(u,"centi"))d+=-2;
if(!strcmp(u,"deci"))d+=-1;
  if(d!=_d)scanf("%s",u);

  putchar(n[x]);
  if(x+1<i)putchar('.');
  for(j=x+1;j<i;j++)
    putchar(n[j]);
  printf(" * 10^%d %s\n",d-x,u);
  return 0;
}
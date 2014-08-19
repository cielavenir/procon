main(n,h,m){double H,M;
for(scanf("%d",&n);n--;puts(M<30?"alert":M<90?"warning":"safe")){
scanf("%02d:%02d",&h,&m);
M=m*6;H=h*30+m/2.0;M-=H;
if(M<0)M=-M;if(M>180)M=360-M;
}exit(0);}
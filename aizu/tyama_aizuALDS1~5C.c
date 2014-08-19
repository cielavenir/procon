double p;
drawKoch(int level, double x1, double y1, double x2, double y2){
	if(level==0){printf("%f %f\n",x2,y2);return;}
	double x_first=(x1*2+x2)/3,x_second=(x1+x2*2)/3,y_first=(y1*2+y2)/3,y_second=(y1+y2*2)/3;
	double x_third=(x_second-x_first)*cos(p/3)-(y_second-y_first)*sin(p/3)+x_first;
	double y_third=(x_second-x_first)*sin(p/3)+(y_second-y_first)*cos(p/3)+y_first;
	drawKoch(level-1,x1,y1,x_first,y_first);
	drawKoch(level-1,x_first,y_first,x_third,y_third);
	drawKoch(level-1,x_third,y_third,x_second,y_second);
	drawKoch(level-1,x_second,y_second,x2,y2);
}
main(n){p=atan(1)*4;scanf("%d",&n);puts("0 0");drawKoch(n,0,0,100,0);exit(0);}
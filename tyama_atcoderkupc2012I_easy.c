#include <stdio.h>
#include <math.h>
main(){
	double w,h,theta1,theta2,theta3,z;
	int e;
	scanf("%lf%lf%d",&w,&h,&e);
	if(e>0)exit(1);
	printf("? %.12f %.12f\n",-w,-h);fflush(stdout);
	scanf("%lf",&theta1);
	if(theta1<1e-9){
		printf("? %.12f %.12f\n",-w,h);fflush(stdout);
		scanf("%lf",&theta1);theta1=-theta1;
		theta1*=M_PI/180;
		printf("? %.12f %.12f\n",w,h);fflush(stdout);
		scanf("%lf",&theta2);theta2=-theta2;theta2=180-theta2;
		theta2*=M_PI/180;
		theta3=M_PI-theta1-theta2;
		z=sin(theta2)*2*w/sin(theta3);
		printf("! %.12f %.12f\n",z*cos(theta1)-w,-z*sin(theta1)+h);
	}else{
		theta1*=M_PI/180;
		printf("? %.12f %.12f\n",w,-h);fflush(stdout);
		scanf("%lf",&theta2);theta2=180-theta2;
		theta2*=M_PI/180;
		theta3=M_PI-theta1-theta2;
		z=sin(theta2)*2*w/sin(theta3); //(-w,-h)からtheta1(rad)、斜辺の長さz
		printf("! %.12f %.12f\n",z*cos(theta1)-w,z*sin(theta1)-h);
	}
	exit(0);
}
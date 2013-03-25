main(i,z){
	double p=atan(1)*4,r;
	for(;scanf("%lf",&r),r;){
		for(i=0;i<999999;i++){
			z=(int)(p*i);
			if(p-r<z*1.0/i){printf("%d/%d\n",z,i);break;}
			if((z+1)*1.0/i<p+r){printf("%d/%d\n",z+1,i);break;}
		}
	}
	exit(0);
}
//t;q(i,a,b,d,r){for(i=a;i<=b;i++)t=r*i,d?q(a,a,b,d-1,t):printf("%d\n",t);}
//main(a,b,d){for(;scanf("%d%d%d",&a,&b,&d),d;puts(""))q(a,a,b,d-1,1);exit(0);}

//t;q(i,a,b,d,r){for(i=a;i<=b;i++)t=r*i,d?q(a,a,b,d-1,t):printf("%d\n",t);}
stC,stVr[40],stVi[40];
main(a,b,d,f){f=0;
	for(;scanf("%d%d%d",&a,&b,&d),d;){
		if(f)puts("");f=1;
		stC=stVr[0]=1;
		//for(i=0;i<40;i++)
		while(stC){
stackup:
		stVi[stC]=a;
stackdown:
			for(;stVi[stC]<=b;){
//printf("---%d %d %d\n",stC,stVi[stC],d);
				stVr[stC]=stVr[stC-1]*stVi[stC]++;
				if(stC==d)printf("%d\n",stVr[stC]);else {stC++;goto stackup;}
			}
			stC--;if(!stC)break;
			goto stackdown;
		}
	}
	exit(0);
}
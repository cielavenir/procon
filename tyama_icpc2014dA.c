#include <stdio.h>
int main(){
	int before,after;
	int cost_with_tax;
	for(;scanf("%d%d%d",&before,&after,&cost_with_tax),cost_with_tax;){
		int ma=0,x;
		int cost1_with_tax,cost1_without_tax;
		int cost2_with_tax,cost2_without_tax;
		for(cost1_with_tax=1;cost1_with_tax<=cost_with_tax/2;cost1_with_tax++){
			cost1_without_tax=ceil(cost1_with_tax*100.0/(100+before));
			cost2_with_tax=cost_with_tax-cost1_with_tax;
			cost2_without_tax=ceil(cost2_with_tax*100.0/(100+before));
			x=cost1_without_tax*(100+before)/100+cost2_without_tax*(100+before)/100;
			if(x!=cost_with_tax)continue;
			x=cost1_without_tax*(100+after)/100+cost2_without_tax*(100+after)/100;
			if(ma<x)ma=x;
		}
		printf("%d\n",ma);
	}
	return 0;
}
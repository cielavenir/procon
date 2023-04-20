// https://twitter.com/Nabetani/status/1450713468714172420

// see also:
// https://qiita.com/cielavenir/items/3d2e16ab87d8ddba44b0
// https://github.com/cielavenir/cpp_libraries/blob/master/binarysearch/binarysearch.hpp

unsigned int count_float(float a, float b){
	if(a > b){
		float t=a;
		a=b;
		b=t;
	}
	if(0<=a && 0<=b){
		return (unsigned int)(*((int*)&b) - *((int*)&a));
	} else if(a<=0 && b<=0){
		a = -a;
		b = -b;
		return (unsigned int)(*((int*)&a) - *((int*)&b));
	} else {
		// a<=0 && 0<=b
		a = -a;
		return (unsigned int)(*((int*)&b) + *((int*)&a));
	}
}

unsigned long long count_double(double a, double b){
	if(a > b){
		double t=a;
		a=b;
		b=t;
	}
	if(0<=a && 0<=b){
		return (unsigned long long)(*((long long*)&b) - *((long long*)&a));
	} else if(a<=0 && b<=0){
		a = -a;
		b = -b;
		return (unsigned long long)(*((long long*)&a) - *((long long*)&b));
	} else {
		// a<=0 && 0<=b
		a = -a;
		return (unsigned long long)(*((long long*)&b) + *((long long*)&a));
	}
}

int main(){
	printf("%u\n", count_float(-1e-30, 1e-31));
	printf("%u\n", count_float(-1.23, 4.56));
	printf("%u\n", count_float(0, 1));
	printf("%llu\n", count_double(-1.23, 4.56));
	printf("%llu\n", count_double(0, 1));
}

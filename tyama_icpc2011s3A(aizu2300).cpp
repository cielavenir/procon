// http://photon.poly.edu/~hbr/boost/combinations.html
#include <algorithm>
using namespace std;
template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first1,
	BidirectionalIterator last1,
	BidirectionalIterator first2,
	BidirectionalIterator last2)
{
	if(( first1 == last1 ) || ( first2 == last2 ))return false;
	BidirectionalIterator m1 = last1;
	BidirectionalIterator m2 = last2; --m2;
	while(--m1 != first1 && !(* m1 < *m2 ));
	bool result = (m1 == first1 ) && !(* first1 < *m2 );
	if(!result){
		while( first2 != m2 && !(* m1 < * first2 ))++first2;
		first1 = m1;
		iter_swap(first1 , first2 );
		++ first1;
		++ first2;
	}
	if(( first1 != last1 ) && ( first2 != last2 )){
		m1 = last1 ; m2 = first2 ;
		while(( m1 != first1 ) && (m2 != last2 )){
			iter_swap (--m1 , m2 );
			++m2;
		}
		reverse(first1 , m1);
		reverse(first1 , last1);
		reverse(m2 , last2);
		reverse(first2 , last2);
	}
	return !result;
}
template <class BidirectionalIterator>
bool next_combination (BidirectionalIterator first,
	BidirectionalIterator middle,
	BidirectionalIterator last)
{return next_combination(first , middle , middle , last);}

#include <vector>
#include <cstdio>
int main(){
	int i,j,n,m;
	double f,f0;
	scanf("%d%d",&n,&m);
	if(m<2){puts("0");return 0;}
	vector<vector<double> >a;
	for(i=0;i<n;i++){
		vector<double>v;
		for(j=0;j<3;j++){
			scanf("%lf",&f);
			v.push_back(f);
		}
		a.push_back(v);
	}
	vector<int>v;
	for(i=0;i<n;i++)v.push_back(i);
	f=0;
	do{
		f0=0;
		for(i=0;i<m-1;i++)for(j=i+1;j<m;j++){
			f0+=(a[v[i]][0]-a[v[j]][0])*(a[v[i]][0]-a[v[j]][0])+(a[v[i]][1]-a[v[j]][1])*(a[v[i]][1]-a[v[j]][1])+(a[v[i]][2]-a[v[j]][2])*(a[v[i]][2]-a[v[j]][2]);
		}
		if(f<f0)f=f0;
	}while(next_combination(v.begin(), v.begin()+m, v.end()));
	printf("%f\n",f);
}
#include <vector>
#include <algorithm>
#include <cstdio>
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

int main(){
	int n,r=0;
	scanf("%d",&n);
	vector<int> v(n);
	for(int i=0;i<n;i++)scanf("%d",&v[i]);
	sort(v.begin(),v.end());
	do{
		do{
			int s=0;
			for(int i=0;i<n/2;i++)s+=v[i]^v[i+n/2];
			r=max(s,r);
		}while(next_permutation(v.begin()+n/2,v.end()));
	}while(next_combination(v.begin(),v.begin()+n/2,v.end()));
	printf("%d\n",r);
}

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

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <numeric>
int main(){
	int N,M,P,Q,R;
	cin>>N>>M>>P>>Q>>R;
	vector<pair<pair<int,int>,int> >w(R);
	for(int i=0;i<R;i++){
		int x,y,r;
		cin>>x>>y>>r;
		w[i]=make_pair(make_pair(x-1,y-1),r);
	}
	vector<int>female(N);
	iota(female.begin(),female.end(),0);
	int r=0;
	do{
		set<int>females;
		for(int i=0;i<P;i++)females.insert(female[i]);
		vector<int>s(M);
		for(int i=0;i<R;i++){
			if(females.find(w[i].first.first)!=females.end()){
				s[w[i].first.second]+=w[i].second;
			}
		}
		sort(s.begin(),s.end(),greater<int>());
		int z=0;
		for(int i=0;i<Q;i++)z+=s[i];
		if(r<z)r=z;
	}while(next_combination(female.begin(),female.begin()+P,female.end()));
	cout<<r<<endl;
}

#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

// http://photon.poly.edu/~hbr/boost/combinations.html
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

int primes[10000000];
char s[9],s0[9];
int main(){
	int N,K,L,i,j,k;
	for(i=2;i<10000000;i++)if(!primes[i])for(j=i*2;j<10000000;j+=i)primes[j]=1;
	scanf("%d%d%d",&N,&K,&L);
	int z=1;
	for(i=0;i<N-1;i++)z*=10;
	for(i=z;i<z*10;i++){
		sprintf(s,"%d",i);
		vector<int>digits(N);
		iota(digits.begin(),digits.end(),0);
		do{
			strcpy(s0,s);
			int l=0,fail=0;
			for(j='0';j<='9';j++){
				for(k=0;k<K;k++)s0[digits[k]]=j;
				if(s0[0]!='0'&&!primes[strtol(s0,NULL,10)]){
					l+=1;
				}else{
					fail+=1;
				}
				if(10-fail<L)break;
			}
			if(l>=L){
				int f=0;
				for(j='0';j<='9';j++){
					for(k=0;k<K;k++)s0[digits[k]]=j;
					if(s0[0]!='0'&&!primes[strtol(s0,NULL,10)]){
						if(f)printf(" ");
						printf("%d",strtol(s0,NULL,10));
						f++;
						if(f==L)break;
					}
				}
				puts("");
				return 0;
			}
		}while(next_combination(digits.begin(),digits.begin()+K,digits.end()));
	}
}
// 6 3 8
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

///
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
///

const int VERTEX=3;
int solve(int num,const string &cdata){
	//鍋谷さんがどうしても引数はconstにすべきとおっしゃっているので、constを潰すという邪悪なことをしますww
	//cdataがソートされていれば、関数開始時と終了時で中身は変化しません。
	//わかってやるなら良いのです。きっとww
	//[追記]てかnext_combination()を持ちだしている時点でこの問題はC++向きではないと結論付けるべきだったのかもしれない。
	string &data=(string &)cdata;
	set<vector<int> >se;
	do{
		vector<int>v;
		for(int i=0;i<VERTEX;i++)v.push_back((data[(i+1)%VERTEX]-data[i]+num)%num);
		vector<int>mi=v;
		for(int i=0;i<VERTEX;i++){
			rotate(v.begin(),v.begin()+1,v.end());
			mi=min(mi,v);
		}
		se.insert(mi);
	}while(next_combination(data.begin(),data.begin()+VERTEX,data.end()));
	return se.size();
}

int main(int argc,char **argv){
	string id,data;
	int num,answer;
	for(;cin>>id>>num>>data>>answer;){
		//if(id[0]!='T')break;
		//カンマを削る
		for(int i=0;i<data.size();i+=2)data[i/2]=data[i];
		data.resize(data.size()/2+1);
		if(solve(num,data)!=answer)cout<<id<<endl;
	}
}
/*
【解答】
166,200,250,333,400,500,600,666,750,800,833
【感想・工夫した点など】
点集合を整数座標に変換し、3つ組を列挙、距離に変換。辞書順最小となる回転をsetで管理した。
なお、min_element()にrotateするのは、1,7,1といった距離の場合にただしく動作しないので使えなかった。

［追記1］
・VERTEXはconst intにしました。
#以前試したら要素数がconst intな配列が作成できなかった気がしたのですが、今見たら大丈夫でした。。
・seの定義からsize算出までの部分を別関数に分けました。
・for文にcinを入れている関係で、dataを別スコープに切り出すことができません。なので処理が非常に悩ましいのですが、
string dataから直接カンマを削ってresize()することにしました。
なお、next_combination()にdataを渡すので、solve()のdataはconstを付けられません。solve()の後でdataが元に戻っているかはコンパイラからは判断できないので、コード側で担保するしかありません--;;;
【言語と処理系】
C++
clang++ Apple LLVM 6.0 or g++-mp-4.8
※llvm-g++-4.2だとどういうわけかcout<<idがコンパイルエラーになるが、clang++ -stdlib=libstdc++は問題なく動作する。
【ソースコード】
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
public:
	vector<vector<int> >a;
	Matrix(){}
	Matrix(const Matrix &o):a(o.a){}
	Matrix& operator +=(const Matrix &o){
		for(int y=0;y<a.size();y++)for(int x=0;x<a[y].size();x++)a[y][x]+=o.a[y][x];
		return *this;
	}
	Matrix operator +(const Matrix &o){
		return Matrix(*this)+=o;
	}
};

int main () {
	int cases,k;
	cin >> cases;
	for(k=0;k<cases;k++) {
		Matrix x;
		Matrix y;
		Matrix result;
		int n,m,i,j;
		cin >> n >> m;
		for(i=0;i<n;i++) {
			vector<int> b;
			int num;
			for(j=0;j<m;j++) {
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		for(i=0;i<n;i++) {
			vector<int> b;
			int num;
			for(j=0;j<m;j++) {
				cin >> num;
				b.push_back(num);
			}
			y.a.push_back(b);
		}
		result = x+y;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				cout << result.a[i][j] << " ";
			}
			cout << endl;
		}
	}  
	return 0;
}
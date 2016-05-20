#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--){
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
		cout<<nouppercase<<setw(0)<<showbase<<hex<<(long long)A<<endl;
		cout<<right<<setw(15)<<setprecision(2)<<showpos<<fixed<<setfill('_')<<B<<endl;
		cout<<uppercase<<setprecision(9)<<noshowpos<<scientific<<C<<endl;
	}
	return 0;
}
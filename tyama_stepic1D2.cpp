#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main(){
	int i=0,k,c=0;
	string t,s="aactctatacctcctttttgtcgaatttgtgtgatttatagagaaaatcttattaactgaaactaaaatggtaggtttggtggtaggttttgtgtacattttgtagtatctgatttttaattacataccgtatattgtattaaattgacgaacaattgcatggaattgaatatatgcaaaacaaacctaccaccaaactctgtattgaccattttaggacaacttcagggtggtaggtttctgaagctctcatcaatagactattttagtctttacaaacaatattaccgttcagattcaagattctacaacgctgttttaatgggcgttgcagaaaacttaccacctaaaatccagtatccaagccgatttcagagaaacctaccacttacctaccacttacctaccacccgggtggtaagttgcagacattattaaaaacctcatcagaagcttgttcaaaaatttcaatactcgaaacctaccacctgcgtcccctattatttactactactaataatagcagtataattgatctga";
	t="atgatcaag";
	k=t.size();
	for(i=0;i<s.size()-k;i++){
		if(s.substr(i,k)==t)c++;//cout<<(i+1)<<endl;
	}
	t="cttgatcat";
	k=t.size();
	for(i=0;i<s.size()-k;i++){
		if(s.substr(i,k)==t)c++;//cout<<(i+1)<<endl;
	}
	cout<<c<<endl;
}
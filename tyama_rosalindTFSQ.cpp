//Just a port of my fastq2fasta command.
//Every infobiomaticians should make their own implementation, right?
#include <iostream>
#include <string>
using namespace std;
int main(){
	string id,seq,qualid,qual;
	for(;getline(cin,id);){
		if(!getline(cin,seq)||!getline(cin,qualid)||!getline(cin,qual)){
			cerr<<"fastq is truncated"<<endl;
			return 1;
		}
		//todo: need to support folding
		int end_of_id=id.find_first_of(' ');
		if(end_of_id==string::npos)end_of_id=id.length();
		cout<<'>'<<id.substr(1,end_of_id-1)<<endl;
		cout<<seq<<endl;
	}
	return 0;
}
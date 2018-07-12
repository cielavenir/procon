import std.format;
import std.stdio;
import std.parallelism;
import core.stdc.stdio;
void main(){
	int []A;
	int _N;
	for(;~scanf("%d",&_N)&&_N;)A~=_N;
	string []R;
	R.length=A.length;
	foreach(i, ref N; parallel(A)){
		int head=1,tail=1,s=0;
		for(;;){
			for(;s<N;tail++)s+=tail;
			for(;s>N;head++)s-=head;
			if(s==N){R[i]=format("%d %d",head,tail-head);break;}
		}
	}
	foreach(i, ref r;R)writeln(r);
}

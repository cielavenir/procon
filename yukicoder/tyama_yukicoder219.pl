#!/usr/bin/perl
#その他行きでおｋ☆ ToT
#提出が安定しない…
local $/;
open(my $fh,'| g++ -xc++ -std=c++11 -ozzz - -lquadmath');
print $fh <DATA>;
close($fh);
open($fh,'| ./zzz');
print $fh <STDIN>;
close($fh);
unlink('zzz');

__END__
#include <vector>
#include <algorithm>
#include <cstdio>
#include <quadmath.h>
using namespace std;
int main(){
    vector<__float128>t(101);
    for(int i=10;i<101;i++)t[i]=log10q(__float128(i));
    int N;
    for(scanf("%d",&N);N--;){
        long long A,B;
        scanf("%lld%lld",&A,&B);
        __float128 result=log10q(__float128(A))*B;
        long long Z=result;
        result-=Z-1;
        auto it=upper_bound(t.begin(),t.end(),result);--it;
        int X=distance(t.begin(),it);
        printf("%d %d %lld\n",X/10,X%10,Z);
    }
}
#!/usr/bin/xpce -f
:- prompt(_,'').

calc(R,I,N,K,RET) :- I=:=N -> RET is R; II is I+1,calc((R+K) mod I,II,N,K,RET).
main2(0,_,_) :- halt,!.
main2(N,K,M) :- calc(0,1,N,K,R),RR is (R+M) mod N+1,format("~w\n",[RR]),main.
main :- readln(A),nth0(0,A,N),nth0(1,A,K),nth0(2,A,M),main2(N,K,M).
:- initialization(main).
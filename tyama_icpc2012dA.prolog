#!/usr/bin/xpce -f
:- prompt(_,'').

y(Y,M,Q) :- Y mod 3=:=0 -> Q is 0; Q is (M-1) // 2.
z(Y,M,D,R) :- y(Y,M,Q),R is 196471-(Y-1)*195-(Y-1) // 3*5-(M-1)*20+Q-D.
main2(0) :- halt,!.
main2(X) :- readln(A),nth0(0,A,Y),nth0(1,A,M),nth0(2,A,D),z(Y,M,D,R),format("~w\n",[R]),XX is X-1,main2(XX).
main :- readln([X]),main2(X).
:- initialization(main).
#!/usr/bin/xpce -f
sum(0,MA,MI,S,Z,R) :- R is ((S-MA-MI) div (Z-2)).
sum(N,MA,MI,S,Z,R) :- readln([X]),M is N-1,sum(M,max(MA,X),min(MI,X),S+X,Z,R).
main2(0) :- halt,!.
main2(N) :- sum(N,0,1000,0,N,R),format("~w\n",R),readln([X]),main2(X).
main :- readln([X]),main2(X).
:- initialization(main).
fib(20,_,_).
fib(N,A,B) :- M is N+1,format(",~d",[B]),fib(M,B,A+B).
main :- write(0),fib(1,0,1),halt.
:- initialization(main).
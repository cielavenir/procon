#!/usr/bin/escript

-module(prog).
-export([main/0]).

calc(R,I,N,K) ->
	if
		I==N -> R;
		I/=N -> calc((R+K) rem I,I+1,N,K)
	end.

main() ->
	X=io:get_line(standard_io,""),
	A=array:from_list(string:tokens(string:strip(X,right,10)," ")),
	N=list_to_integer(array:get(0,A)),
	K=list_to_integer(array:get(1,A)),
	M=list_to_integer(array:get(2,A)),
	if
		N==0 -> true;
		N/=0 -> io:format("~w\n",[(calc(0,1,N,K)+M) rem N+1]),main()
	end.
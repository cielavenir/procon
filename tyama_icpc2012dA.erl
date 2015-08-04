#!/usr/bin/escript

-module(prog).
-export([main/0]).

main2(N) -> if
	N/=0 ->
		X=io:get_line(standard_io,""),
		A=array:from_list(string:tokens(string:strip(X,right,10)," ")),
		Y=list_to_integer(array:get(0,A)),
		M=list_to_integer(array:get(1,A)),
		D=list_to_integer(array:get(2,A)),
		io:format("~w\n",[196471-((Y-1)*195)-trunc((Y-1)/3)*5-(M-1)*20+(if Y rem 3=:=0 -> 0; true -> trunc((M-1)/ 2) end)-D]),main2(N-1);
	N=:=0 -> true
	end.

main() ->
	X=io:get_line(standard_io,""),
	N=list_to_integer(string:strip(X,right,10)),
	main2(N).
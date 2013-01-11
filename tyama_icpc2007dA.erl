#!/usr/bin/escript
getint() ->
	X=io:get_line(standard_io, ""),
	list_to_integer(string:substr(X,1,length(X)-1)).
sum(N,MA,MI,S,Z) ->
	if
		N==0 -> trunc((S-MA-MI)/(Z-2));
		N/=0 -> X=getint(),sum(N-1,max(MA,X),min(MI,X),S+X,Z)
	end.
main2(N) ->
	if
		N==0 -> true;
		N/=0 -> io:format("~w\n",[sum(N,0,1000,0,N)]),main2(getint())
	end.
main(_) ->	main2(getint()).
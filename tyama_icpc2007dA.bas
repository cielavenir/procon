' tested with ActiveBasic4
#console
Open "A" for input as #1
do
	dim n,i,s,ma,mi,x as Integer
	Input #1, n
	if n=0 then exit do
	s=0:ma=0:mi=1000
	for i=1 to n
		Input #1, x
		s=s+x
		if ma<x then ma=x
		if mi>x then mi=x
	next
	Print Int((s-ma-mi)/(n-2))
loop
Close #1
end
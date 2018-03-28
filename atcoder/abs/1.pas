program ABC086A;
uses StrUtils;
var
	a,b: integer;
begin
	read(a);
	read(b);
	writeln(ifThen(a*b mod 2>0,'Odd','Even'));
end.

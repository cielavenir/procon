program practiceA;
uses SysUtils;
var
	a,b,c: integer;
	s: string;
begin
	read(a); // readlnにする必要はない
	read(b);
	readln(c);
	readln(s);
	writeln(IntToStr(a+b+c)+' '+s);
end.

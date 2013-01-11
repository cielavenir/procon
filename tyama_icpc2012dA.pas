{$apptype console} //Delphi
program DomesticA;
var n,i,y,m,d,r: integer;
begin
readln(n);
for i:=1 to n do begin
	readln(y,m,d);
	y:=y-1;m:=m-1;
	r:=0;
	if(y mod 3<>2) then r:=m div 2;
	writeln(196471-y*195-y div 3*5-m*20+r-d);
end;
end.
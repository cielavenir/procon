{$apptype console} //Delphi
program RegionalA;
var i,n,k,m,r: integer;
begin
while true do begin
	readln(n,k,m);
	if n=0 then break;
	r:=0
	for i:=1 to n-1 do r:=(r+k) mod i;
	writeln((r+m) mod n+1);
end;
end.
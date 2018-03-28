program ABC083B;
var 
	n,a,b,r,i,j,s: integer;
begin
	read(n);
	read(a);
	read(b);
	r:=0;
	for i:=1 to n do begin
		s:=0;
		j:=i;
		while j>0 do begin
			s:=s+(j mod 10);
			j:=j div 10;
		end;
		if (a<=s) and (s<=b) then begin
			r:=r+i;
		end;
	end;
	writeln(r);
end.

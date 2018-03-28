program ABC087B;
var
	a,b,c,x,i,j,k,r: integer;
begin
	read(a);
	read(b);
	read(c);
	read(x);
	r:=0;
	for i:=0 to x div 500 do begin
		for j:=0 to (x-500*i) div 100 do begin				k:=x-500*i-100*j;
			if (k mod 50=0) and (c>=k div 50) and (a>=i) and (b>=j) then begin
				r:=r+1;
			end;
		end;
	end;
	writeln(r);
end.

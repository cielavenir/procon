program ABC081A;
var
	s: string;
    c,i: integer;
begin
	read(s);
    c:=0;
    for i:=1 to 3 do begin
		if s[i]='1' then begin
			c:=c+1;
		end;
	end;
	writeln(c);
end.

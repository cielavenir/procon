program ABC049C;
uses StrUtils;
var
	T: array[0..3] of string = ('dream','dreamer','erase','eraser');
	s: string;
	i,c,l,k: integer;
begin
	for i:=0 to 3 do begin
		T[i]:=ReverseString(T[i]);
	end;
	readln(s);
	s:=ReverseString(s);
	c:=0;
	l:=Length(s);
	while c<l do begin
		k:=-1;
		for i:=0 to 3 do begin
			if copy(s,c+1,Length(T[i]))=T[i] then begin
				k:=Length(T[i]);
			end;
		end;
		if k<0 then begin
			writeln('NO');
			exit;
		end;
		c:=c+k;
	end;
	writeln('YES');
end.

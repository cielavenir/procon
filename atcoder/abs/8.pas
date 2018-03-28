program ABC085C;
uses SysUtils;
var
	n,y,i,j,k: integer;
begin
	read(n);
	read(y);
	for i:=0 to n do begin
		for j:=0 to n-i do begin
			k:=n-i-j;
			if i*1000+j*5000+k*10000=y then begin
				writeln(IntToStr(k)+' '+IntToStr(j)+' '+IntToStr(i));
				exit;
			end;
		end;
	end;
	writeln('-1 -1 -1');
end.

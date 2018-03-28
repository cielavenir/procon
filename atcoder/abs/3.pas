program ABC081B;
var
	i,n,x,r,r0: longint;
	arr: array of integer;
begin
	r:=1<<29;
	read(n);
	SetLength(arr,n);
	for i:=0 to n-1 do begin
		read(arr[i]);
	end;
	for i:=0 to n-1 do begin
		r0:=0;
		x:=arr[i];
		while x mod 2 < 1 do begin
			r0:=r0+1;
			x:=x div 2;
		end;
		if r>r0 then begin
			r:=r0;
		end;
	end;
	writeln(r);
end.

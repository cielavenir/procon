program ABC086C;
var
	i,n,t,x,y: integer;
	t0,x0,y0,dt,dx,dy: integer;
begin
	read(n);
	t:=0;
	x:=0;
	y:=0;
	for i:=1 to n do begin
		read(t0);
		read(x0);
		read(y0);
		dt:=t0-t;
		dx:=x0-x;
		dy:=y0-y;
		if (dx+dy>dt) or ((dt-dx-dy) mod 2>0) then begin
			writeln('No');
			exit;
		end;
		t:=t0;
		x:=x0;
		y:=y0;
	end;
	writeln('Yes');
end.

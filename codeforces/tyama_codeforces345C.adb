with Ada.Text_IO, Ada.Integer_Text_IO;
procedure codeforces345C is
n,y0,y,z,m,d,r:integer;
begin
	Ada.Integer_Text_IO.Get(n);
	r:=0;
	for i in 1..n loop
		Ada.Integer_Text_IO.Get(y0);
		Ada.Integer_Text_IO.Get(m);m:=-m;
		Ada.Integer_Text_IO.Get(d);d:=-d;
		m:=m+1;
		if m<4 then
			y0:=y0-1;
			m:=m+12;
		end if;
		y:=y0/100;
		z:=y0 mod 100;
		if (5*y+z+y/4+z/4+13*m/5+d-1) mod 7=5 and d=13 then
			r:=r+1;
		end if;
	end loop;
	Ada.Integer_Text_IO.Put(r,width=>1);
	Ada.Text_IO.New_line;
end codeforces345C;
-- gnat compile tyama_icpc2012dA.adb
-- gnatbind -x tyama_icpc2012dA.ali
-- gnatlink tyama_icpc2012dA.ali

with Ada.Text_IO, Ada.Integer_Text_IO;
procedure icpc2012dA is
n,y,m,d,r:integer;
begin
	Ada.Integer_Text_IO.Get(n);
	for i in 1..n loop
		Ada.Integer_Text_IO.Get(y);
		Ada.Integer_Text_IO.Get(m);
		Ada.Integer_Text_IO.Get(d);
		y:=y-1;m:=m-1;
		r:=0;
		if y mod 3 /= 2 then
			r:=m/2;
		end if;
		Ada.Integer_Text_IO.Put(196471-y*195-y/3*5-m*20+r-d,width=>1);
		Ada.Text_IO.New_line;
	end loop;
end icpc2012dA;
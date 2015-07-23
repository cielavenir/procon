-- gnat compile tyama_icpc2007rA.adb
-- gnatbind -x tyama_icpc2007rA.ali
-- gnatlink tyama_icpc2007rA.ali

with Ada.Text_IO, Ada.Integer_Text_IO;
procedure icpc2007rA is
i,r,n,k,m:integer;
begin
	loop
		Ada.Integer_Text_IO.Get(n);
		Ada.Integer_Text_IO.Get(k);
		Ada.Integer_Text_IO.Get(m);
		r:=0;
		for i in 1..n-1 loop
			r:=(r+k) mod i;
		end loop;
		Ada.Integer_Text_IO.Put((r+m) mod n+1,width=>1);
		Ada.Text_IO.New_line;
	end loop;
end icpc2007rA;
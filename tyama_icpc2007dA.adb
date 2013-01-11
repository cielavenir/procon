-- gnat compile tyama_icpc2007dA.adb
-- gnatbind -x tyama_icpc2007dA.ali
-- gnatlink tyama_icpc2007dA.ali

with Ada.Text_IO, Ada.Integer_Text_IO;
procedure icpc2007dA is
n,s,ma,mi,sum:integer;
begin
  loop
    ma:=0;mi:=1000;sum:=0;
    Ada.Integer_Text_IO.Get(n);
    if n=0 then exit; end if;
    for i in 1..n loop
      Ada.Integer_Text_IO.Get(s);
      if ma<s then ma:=s; end if;
      if mi>s then mi:=s; end if;
      sum:=sum+s;
    end loop;
    Ada.Integer_Text_IO.Put((sum-ma-mi)/(n-2),width=>1);
    Ada.Text_IO.New_line;
  end loop;
end icpc2007dA;
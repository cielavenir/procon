-- ghdl -a tyama_icpc2007dA.vhdl
-- ghdl -e icpc2007da
-- ghdl -r icpc2007da <A or ./icpc2007da <A

-- gvhdl tyama_icpc2007dA.vhdl
-- ./tyama_icpc2007dA -q -cmd "q;" <A

use std.textio.all;
entity icpc2007da is end icpc2007da;
architecture Z of icpc2007da is
begin
	process
		variable n,s,ma,mi,sum:integer;
		variable L: line;
		begin
		loop
			ma:=0;mi:=1000;sum:=0;
			readline(input,L);read(L,n);
			if n=0 then exit; end if;
			for i in 1 to n loop
				readline(input,L);read(L,s);
				if ma<s then ma:=s; end if;
				if mi>s then mi:=s; end if;
				sum:=sum+s;
			end loop;
			write(L,(sum-ma-mi)/(n-2)); --integer'image
			writeline(output,L);
		end loop;
		wait;	
	end process;
end Z;
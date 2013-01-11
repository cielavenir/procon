-- ghdl -a tyama_icpc2012dA.vhdl
-- ghdl -e icpc2012da
-- ghdl -r icpc2012da <AA or ./icpc2012da <AA

-- gvhdl tyama_icpc2012dA.vhdl
-- ./tyama_icpc2012dA -q -cmd "q;" <AA

use std.textio.all;
entity icpc2012da is end icpc2012da;
architecture Z of icpc2012da is
begin
	process
		variable n,i,y,m,d,r: integer;
		variable L: line;
		begin
		readline(input,L);read(L,n);
		for i in 1 to n loop
			readline(input,L);
			read(L,y);read(L,m);read(L,d);
			y:=y-1;m:=m-1;
			r:=0;
			if y mod 3 /= 2 then
				r:=m/2;
			end if;
			write(L,196471-y*195-y/3*5-m*20+r-d); --integer'image
			writeline(output,L);
		end loop;
		wait;	
	end process;
end Z;
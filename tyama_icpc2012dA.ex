#!/usr/bin/env elixir
defmodule ICPC2012dA do
	def main2(n) do
		if n>0 do
			a=String.split(IO.chardata_to_string(IO.gets(''))," ")
			y=elem Integer.parse(Enum.at(a,0)),0
			m=elem Integer.parse(Enum.at(a,1)),0
			d=elem Integer.parse(Enum.at(a,2)),0
			IO.puts 196471-((y-1)*195)-div(y-1,3)*5-(m-1)*20+(if rem(y,3)==0 do 0 else div(m-1,2) end)-d
			main2(n-1)
		end
	end
	def main() do
		n=elem Integer.parse(IO.gets('')),0
		main2(n)
	end
end
ICPC2012dA.main
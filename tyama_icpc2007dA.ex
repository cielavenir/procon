#!/usr/bin/env elixir
defmodule ICPC2007dA do
	def sum(0,ma,mi,s,z) do
		trunc (s-ma-mi)/(z-2)
	end
	def sum(n,ma,mi,s,z) do
		x=elem Integer.parse(IO.gets('')),0
		sum n-1,Enum.max([ma,x]),Enum.min([mi,x]),s+x,z
	end
	def main2(0) do
	end
	def main2(n) do
		IO.puts sum n,0,1000,0,n
		main2 elem Integer.parse(IO.gets('')),0
	end
	def main() do
		main2 elem Integer.parse(IO.gets('')),0
	end
end
ICPC2007dA.main
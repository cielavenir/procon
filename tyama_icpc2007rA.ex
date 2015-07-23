#!/usr/bin/env elixir
defmodule ICPC2007rA do
	def calc(r,i,n,k) do
		if i==n do
			r
		else
			calc(rem(r+k,i),i+1,n,k)
		end
	end
	def main() do
		a=String.split(IO.chardata_to_string(IO.gets(''))," ")
		n=elem Integer.parse(Enum.at(a,0)),0
		k=elem Integer.parse(Enum.at(a,1)),0
		m=elem Integer.parse(Enum.at(a,2)),0
		if n != 0 do
			IO.puts rem(calc(0,1,n,k)+m,n)+1
			main
		end
	end
end
ICPC2007rA.main
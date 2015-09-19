module Player
	sub Main()
		while True
			dim name as String
			dim n as integer=Console.ReadLine()
			dim mi as double=9999999
			for i as integer=0 to n-1
				dim inputs as String()=Console.ReadLine().Split(" ")
				dim enemy as String=inputs(0)
				dim dist as double=inputs(1)
				if mi>dist
					mi=dist
					name=enemy
				end if
			next
			Console.WriteLine(name)
		end while
	end sub
end module
module Player
	sub Main()
		while True
			Dim enemy1 as String
			enemy1 = Console.ReadLine() ' name of enemy 1
			Dim dist1 as Integer
			dist1 = Console.ReadLine() ' distance to enemy 1
			Dim enemy2 as String
			enemy2 = Console.ReadLine() ' name of enemy 2
			Dim dist2 as Integer
			dist2 = Console.ReadLine() ' distance to enemy 2
			Console.WriteLine(iif(dist1<dist2,enemy1,enemy2))
		end while
	end sub
end module
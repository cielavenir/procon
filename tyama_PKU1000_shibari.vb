module x
	sub main
		dim c as new collection
		try
			do
				for each s as string in Console.ReadLine().Trim().Split()
					c.add(cint(s))
				next
				Console.WriteLine(int(aggregate m in c.oftype(of integer) take c.count into sum(m)))
				c.clear()
			loop
		catch
		end try
	end sub
end module
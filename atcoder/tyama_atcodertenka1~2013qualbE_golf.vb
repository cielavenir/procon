module qualbE
    sub Main(ByVal args() as String)
		dim i as integer
		Console.WriteLine("100")
		Console.WriteLine("1 0")
		for i=0 to 97
			Console.WriteLine(String.Format("{0} 0",99-i))
		next
		Console.WriteLine("0 0")
	end sub
end module
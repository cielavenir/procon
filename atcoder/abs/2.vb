module ABC081A
	sub Main(ByVal args() as String)
		dim s as string
		dim c,i as integer
		s=Console.ReadLine()
		c=0
		for i=0 to 2
			if s(i)="1"c then 'thenはなくても良い
				c=c+1
			end if
		next
		Console.WriteLine(c)
	end sub
end module

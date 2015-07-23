module YukiCoder9001
	dim SIZE as integer=9999999
	dim z(SIZE-1) as byte
	dim input_count as integer=0

	function myget() as integer
		dim r as integer
		while 48<=z(input_count) andalso z(input_count)<=57
			r=r*10+z(input_count)-48
			input_count+=1
		end while
		input_count+=1
		return r
	end function
	function mygetC() as integer
		input_count+=1
		return z(input_count-1)
	end function

	sub Main()
		Console.OpenStandardInput().Read(z,0,SIZE)
		Console.Write(myget()+myget())
		Console.Write(chr(32))
		dim c as integer=mygetC()
		while c>0
			Console.Write(chr(c))
			c=mygetC()
		end while
	end sub
end module
' http://qiita.com/Nabetani/items/23ebddb44f0234e7fb15
' http://nabetani.sakura.ne.jp/hena/ord28spirwa/

imports System
imports System.Runtime.InteropServices

module Hena28
	<DllImport("c", CallingConvention := CallingConvention.Cdecl)>
	overloads shared function scanf(format as string, byref a as integer, byref b as integer, byref c as integer, byref d as integer, byref e as long) as integer
	end function

	sub Main()
		dim dir as string="ESWN"
		dim n,e,s,w as integer
		dim days as long
		while scanf("%d,%d,%d,%d:%lld",n,e,s,w,days)=5
			days+=1
			dim l as integer()=new integer(){e,s,w,n}
			dim f as boolean=true
			dim i as integer=0
			while f
				dim x as integer()=new integer(){l(i mod 4)+iif(i mod 4=0,1,0),(i\4+1)*2,l(i mod 4)-iif(i mod 4=3,1,0)}
				for j as integer=0 to 2
					if days-x(j)<0
						Console.WriteLine(dir((i+j) mod 4))
						f=false
						exit for
					end if
					days-=x(j)
				next
				i+=1
			end while
			Console.Out.Flush()
		end while
	end sub
end module
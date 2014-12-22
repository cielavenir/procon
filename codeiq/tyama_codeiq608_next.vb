imports System
imports System.Collections.Generic
module CodeIQRoute
	function next_permutation(of T as IComparable(of T))(ByRef a as List(of T),optional ByVal _n as integer?=Nothing) as boolean
		dim n as integer=if(_n.HasValue,_n,a.Count)
		if n<0 orelse a.Count<n
			return false
		end if
		dim i as integer
		a.Reverse(n,a.Count-n)
		for i=a.Count-2 to 0 step -1
			if a(i).CompareTo(a(i+1))<0
				exit for
			end if
		next
		if i<0
			a.Reverse(0,a.Count)
			return false
		end if
		dim k as integer=i
		for i=a.Count-1 to k+1 step -1
			if a(k).CompareTo(a(i))<0
				exit for
			end if
		next
		dim l as integer=i
		dim z as T=a(k):a(k)=a(l):a(l)=z
		a.Reverse(k+1,a.Count-(k+1))
		return true
	end function

	const N=6
	sub Main(ByVal args() as String)
		dim r,i as integer
		dim e0 as List(of integer)=new List(of integer)()
		dim f0 as List(of integer)=new List(of integer)()
		for i=0 to N-1
			e0.Add(0)
			f0.Add(0)
		next
		for i=0 to N-1
			e0.Add(1)
			f0.Add(1)
		next
		e0.Sort()
		f0.Sort()
		dim e as integer()=new integer(N*2){}
		dim f as integer()=new integer(N*2){}
		do
			for i=0 to N*2-1
				e(i+1)=e(i)+e0(i)
			next
			do
				for i=0 to N*2-1
					f(i+1)=f(i)+f0(i)
					if e(i)=f(i) andalso e(i+1)=f(i+1)
						exit for
					end if
				next
				if i=N*2
					r+=1
				end if
			loop while next_permutation(f0)
		loop while next_permutation(e0)
		Console.WriteLine(r)
	end sub
end module
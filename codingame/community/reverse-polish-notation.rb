#!/usr/bin/ruby
st=[]
gets
begin
	gets.chomp.split.each{|e|
		if e=='ADD'
			raise if st.size<2
			a,b=st.pop(2)
			st.push(a+b)
		elsif e=='SUB'
			raise if st.size<2
			a,b=st.pop(2)
			st.push(a-b)
		elsif e=='MUL'
			raise if st.size<2
			a,b=st.pop(2)
			st.push(a*b)
		elsif e=='DIV'
			raise if st.size<2
			a,b=st.pop(2)
			st.push(a/b)
		elsif e=='MOD'
			raise if st.size<2
			a,b=st.pop(2)
			st.push(a%b)
		elsif e=='POP'
			raise if st.size<1
			st.pop
		elsif e=='DUP'
			raise if st.size<1
			st.push(st[-1])
		elsif e=='SWP'
			raise if st.size<2
			a,b=st.pop(2)
			st.push(b)
			st.push(a)
		elsif e=='ROL'
			raise if st.size<4
			st.pop
			a,b,c=st.pop(3)
			st.push(b)
			st.push(c)
			st.push(a)
		else
			st.push(e.to_i)
		end
	}
rescue Exception=>e
	if e.is_a?(ZeroDivisionError)
		st<<'ERROR'
	else
		st=['ERROR']
	end
end
puts st*' '
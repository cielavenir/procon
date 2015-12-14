#!/usr/bin/ruby
F10=[1,0]
F01=[0,1]
2.upto(44){|i|
	F10[i]=F10[i-1]+F10[i-2]
	F01[i]=F01[i-1]+F01[i-2]
}
X,Y,Z=gets.split.map(&:to_i).sort
_x,_y,_z = X==Y ? Y==Z ? [1,Y,Z] : [Y,Z,X] : [X,Y,Z]
r=[Float::INFINITY,Float::INFINITY]
(0..44).each{|i|
	(0..44).each{|j|
		x=F10[i]
		y=F01[i]
		z=F10[j]
		w=F01[j]
		det=x*w-y*z
		x,y,z,w=w,-y,-z,x
		a=x*_x+y*_y
		b=z*_x+w*_y
		next if det==0
		if det<0
			det=-det
			a=-a
			b=-b
		end
		if a%det==0&&b%det==0&&a>0&&b>0
			a/=det
			b/=det
			f=[a,b]
			if f.include?(_z) || lambda{
				(2..1/0.0).each{|i|
					f[i]=f[i-1]+f[i-2]
					break if f[i]>=_z
				}
				_z==f[-1]
			}.call
				r=[r,[a,b]].min
			end
		end
	}
}
puts r[0].to_f.finite? ? r*' ' : -1
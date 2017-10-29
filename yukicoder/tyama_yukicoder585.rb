#!/usr/bin/ruby
R=[]
class Array
def rotR(r,n)
	R<<'R %d %d'%[r,n]
	a=self.dup;a[r]=a[r].rotate(-n);a
end
def rotD(c,n)
	R<<'C %d %d'%[c,n]
	a=self.transpose;a[c]=a[c].rotate(-n);a.transpose
end
def search(n)
	self.size.times{|y|self[y].size.times{|x|return [x,y] if self[y][x]==n}}
end
def sw(c)
	k=self.size-1;self.rotD(c,1).rotR(k,1).rotD(c,3).rotR(k,2).rotD(c,1).rotR(k,1).rotD(c,3).rotR(k,1)
end
end
m=$<.map{|e|e.chomp.chars.map{|c|c.ord-65}}
mss=(m.size-1)*m[0].size
mse=mss+m[0].size
mss.times{|i|
	sx,sy=m.search i
	ty,tx=i.divmod m[0].size
	if sx==tx
		next if sy==ty
		m=m.rotR sy,1
		sx=-~sx%m[0].size
	end
	if sy==ty
		m=m.rotD(sx,1).rotD(tx,1).rotR(sy+1,(tx-sx)%m[0].size).rotD(sx,m.size-1).rotD(tx,m.size-1)
	else
		m=m.rotD(tx,sy-ty).rotR(sy,(tx-sx)%m[0].size).rotD(tx,m[0].size-sy+ty)
	end
}
#以下の処理は4x4専用
sx0,sy0=m.search mss
sx1,sy1=m.search mss+1
(sx0-sx1)%4==1&&m=m.sw(sx0+1)
(sx0-sx1)%4==2&&m=m.sw(sx1+1)
sx,sy=m.search mss
sx!=0&&m=m.rotR(3,4-sx)
sx0,sy0=m.search mss+2
sx0!=2&&m.sw(0)
p R.size
puts R

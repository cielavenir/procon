#!/usr/bin/ruby
def egcd(x,y)
	return [x,1,0] if y==0
	g,a,b=egcd(y,x%y)
	[g,b,a-x/y*b]
end

a,b=gets.split.map(&:to_i).sort
gets
if b==0
	p $<.count{|e|
		x,y=e.split.map(&:to_i)
		x==0&&y==0
	}
else
	g,z1,z2=egcd(a,b)
	a/=g
	b/=g
	g0,g1,g2=egcd(2*a,2*b)
	p $<.count{|e|
		x,y=e.split.map(&:to_i)
		next if x%g!=0 || y%g!=0
		x/=g
		y/=g
		z=b*b-a*a
		w=z2*x*a+z1*x*b-y
		if -w%z.gcd(g0)==0
=begin
			_,k1,k2=egcd(z,g0)
			e=0
			f=0
			n=w*k1%g0+g0*e
			m=(z*n+w)/g0
			_d=g1*m+2*b*f
			_b=g2*m-2*a*f
			_a=z1*x+b*n-_b
			_c=z2*x-a*n-_d
			raise if (_a+_b)*a+(_c+_d)*b!=x
			raise if (_c-_d)*a+(_a-_b)*b!=y
			p [_a,_b,_c,_d]
=end
			true
		else
			false
		end
	}
end

__END__
- P,Qがどちらも0の場合はX==0とY==0だけを数えます。
- 簡単のため、P,Qの最大公約数を単位とする座標に変換します。X,Yが変換できなければ弾きます。
- ここで、各方向に進む回数をa,b,c,dと置くと、

```
(a+b)P+(c+d)Q==X - (1)
(c-d)P+(a-b)Q==Y - (2)
```

- となります。
- α=a+b、β=c+dとおきます。
- αP+βQ==1を満たす(α,β)を拡張ユークリッド互除法で求めます。
  - 代表値を(z1,z2)とすると、式(1)を満たすのは、α=z1*X+Q*n、β=z2*X-P*nとなります。
- 式(2)を`(β-2d)P+(α-2b)Q==Y`と変形し、αとβを代入して、整理します。`2*P*d+2*Q*b==(Q*Q-P*P)*n+z2*X*P+z1*X*Q-Y`となります。
- この不定方程式において、 **整数解(d,b)を持つようなnが存在する** ことが問題が求める条件となります。
  - ここで、上で媒介変数表示により変数を一個減らしたことが効いてきます。
- `(Q*Q-P*P)*n+z2*X*P+z1*X*Q-Y`が`gcd(2*P,2*Q)`の倍数であることが条件ですので、`-(z2*X*P+z1*X*Q-Y)%gcd(Q*Q-P*P,gcd(2*P,2*Q))==0`を判定します。
- なお、このnを用いてd,bを拡張ユークリッド互除法から求めることで、a,cも求まりますので、原点から何回で目標に到達するかを実際に計算することも可能です。
  - プログラムにおいてeとfが可変。abs(a)+abs(b)+abs(c)+abs(d)が最小となるようなe,fを求めるのもまた一興かと(やってませんが)。
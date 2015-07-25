#!/usr/bin/ruby
#coding:utf-8
H,W=gets.split.map(&:to_f).sort
X=Math.hypot(H,W)
φ=Math.asin(W/X)
ψ=Math.asin(H/X)
gets.to_i.times{
	y,x=gets.split.map(&:to_f).sort
	if y<H
		puts :NO
	elsif W<=x
		puts :YES
	else
		θ=Math.asin(y/X)-ψ
		puts X*Math.sin(θ+φ)<x ? :YES : :NO
	end
}

__END__
三角関数の合成公式
https://ja.wikipedia.org/wiki/%E4%B8%89%E8%A7%92%E9%96%A2%E6%95%B0%E3%81%AE%E5%85%AC%E5%BC%8F%E3%81%AE%E4%B8%80%E8%A6%A7#.E5.90.88.E6.88.90.E5.85.AC.E5.BC.8F
w1=wcosθ+hcos(90-θ)=wcosθ+hsinθ=Xsin(θ+φ)
h1=hcosT+wcos(90-T)=hcosθ+wsinθ=Xsin(θ+ψ)
where
X=hypot(w,h)
φ=asin(w/X)
ψ=asin(h/X)
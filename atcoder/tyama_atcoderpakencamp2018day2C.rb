#!/usr/bin/ruby
n,*a=`dd`.split.map &:to_i
p (1..n).find{|i|
b=a.each_slice(i).to_a
b.shift.zip(*b).all?{|e|(e.compact-[0]).uniq.size<2}
}
__END__
3
1 0 2

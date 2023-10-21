#!/usr/bin/ruby
# require 'facets/array/unique_permutation'
class Array
  def unique_permutation(n=self.size)
    return to_enum(:unique_permutation,n) unless block_given?
    return if n<0||self.size<n
    a=self.sort # sort is O(nlogn), so I believe this is not so costly. (Also sort is not destructive)
    yield a[0,n]
    loop{
      a=a[0,n]+a[n..-1].reverse
      k=(a.size-2).downto(0).find{|i|a[i]<a[i+1]}
      break if !k
      l=(a.size-1).downto(k+1).find{|i|a[k]<a[i]}
      a[k],a[l]=a[l],a[k]
      a=a[0,k+1]+a[k+1..-1].reverse
      yield a[0,n]
    }
  end
end
				   
N,M=`dd`.split.map(&:to_i)
A=[*0...3*N]
h={}
([*0...N]*3).unique_permutation{|e|
	h[A.group_by.with_index{|_,i|e[i]}.values] = 1
}
p h.count{|k,v|k.all?{|e|e[1]/3!=e[0]/3 && e[2]/3!=e[1]/3 && e[2]/3!=e[0]/3}}

__END__
0
0
36
1296
132192

no OEIS entry :rofl:

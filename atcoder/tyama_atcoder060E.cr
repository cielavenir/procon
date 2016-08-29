#!/usr/bin/env crystal
struct Range(B, E)
  #Perform binary search
  #Based on Marc-André Lafortune's Ruby backports implementation, ported by @cielavenir

  def bsearch
    #return to_enum(:bsearch) unless block_given?
    from = self.begin
    to   = self.end
    unless from.is_a?(Int) && to.is_a?(Int)
      # Float support is currently dropped
      raise "can't do binary search for #{from.class}"
    end

    midpoint = 0 # placeholder
    #convert = ->{ (pointerof(midpoint) as Pointer(Int64)).value }
    convert = ->{ midpoint }

    to -= 1 if excludes_end?
    satisfied = nil
    while from <= to
      midpoint = (from + to)/2
      result = yield(cur = convert.call)
      case result
      when Int
        return cur if result == 0
        result = result < 0
      when Float
        return cur if result == 0
        result = result < 0
      when true
        satisfied = cur
      when nil, false
        # nothing to do
      else
        raise "wrong argument type #{result.class} (must be numeric, true, false or nil)"
      end

      if result
        to = midpoint - 1
      else
        from = midpoint + 1
      end
    end
    satisfied
  end
end

N=gets.not_nil!.to_i
A=gets.not_nil!.split.map(&.to_i)
L=gets.not_nil!.to_i
Q=gets.not_nil!.to_i
M=Array.new(N){[0]*17}+[[N]*17]
(N-1).times{|i|M[i][0]=((0...N).bsearch{|j|A[j]>A[i]+L}||N)-1}
M[N-1][0]=N
(N-1).downto(0){|i|
	1.upto(16){|j|M[i][j]=M[M[i][j-1]][j-1]}
}
Q.times{
	x,y=gets.not_nil!.split.map(&.to_i).sort
	x-=1
	y-=1
	s=1
	16.downto(0){|i|
		if M[x][i]<y
			x=M[x][i]
			s+=1<<i
		end
	}
	p s
}
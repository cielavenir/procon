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
      midpoint = (from + to)//2
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

class Array(T)
  def bsearch
    idx=(0...self.size).bsearch{|i|yield self[i]}
    idx ? self[idx] : nil
  end
  def bsearch_index
    (0...self.size).bsearch{|i|yield self[i]}
  end
end

def checkio(data)
	result=0
	se=[] of Tuple(Int64,Int64)
	data.each{|e|
		l,r=e
		right_idx=(0...se.size).bsearch{|i|
			x={l,0}<=>se[i]
			x<=0
		}||se.size #l <= se[right][0]
		if right_idx>0
			left_idx=right_idx-1
			if l<=se[left_idx][1]+1 # overlap with left
				l=se[left_idx][0]
				r=[r,se[left_idx][1]].max
				result-=se[left_idx][1]-se[left_idx][0]+1
				se.delete_at(left_idx)
				right_idx-=1
			end
		end
		while right_idx<se.size && se[right_idx][0]<=r # overlap with right
			r=[r,se[right_idx][1]].max
			result-=se[right_idx][1]-se[right_idx][0]+1
			se.delete_at(right_idx)
		end
		result+=r-l+1
		se.insert(right_idx,{l,r})
	}
	return result
end

dic={} of Int64 => Array(Tuple(Int64,Int64))
n,d,t=gets.not_nil!.split.map(&.to_i64)
gets.not_nil!.split.map(&.to_i64).each{|e|
	mod=e%d
	dic[mod]||=[] of Tuple(Int64,Int64)
	dic[mod]<<{(e-mod)//d-t,(e-mod)//d+t}
}
r=0_i64
dic.each{|k,v|r+=checkio(v)}
p r
while gets
n=$_.to_i;d=[*0...n]
gets.split.map(&:to_i).each{|e|d=d[n/2..-1].each_slice(e).to_a.zip(d[0...n/2].each_slice(e).to_a).flatten[0...n]}
p d[n-1]
end
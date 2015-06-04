hackerrank.store(543121,100)
hackerrank.select!{|k,v|k.is_a?(Integer)}
hackerrank.reject!{|k,v|k%2==0}
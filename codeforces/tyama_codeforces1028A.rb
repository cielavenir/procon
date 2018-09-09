#!/usr/bin/ruby
$<.each_with_index{|e,i|
j=e.index('B')
if j;c=e.count('B')/2+1;puts [i-1+c,j+c]*' ';break;end
}

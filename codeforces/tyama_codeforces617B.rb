#!/usr/bin/ruby
gets;s=gets.tr(" \n","").sub(/^0+/,'').sub(/0+$/,'');p s==''?0:s.scan(/0+/).map{|e|e.size+1}.reduce(1,:*)
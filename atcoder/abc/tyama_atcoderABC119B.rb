#!/usr/bin/ruby
gets;p$<.map{|e|a=e.split;a[0].to_f*(a[1]=='BTC'?380000:1)}.reduce :+

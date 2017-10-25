#!/usr/bin/ruby
s=gets;a=%w(Danil Olya Slava Ann Nikita).select{|e|s.index e};puts a.size==1&&s.scan(a[0]).size==1?:YES: :NO

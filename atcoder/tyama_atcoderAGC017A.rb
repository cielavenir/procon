#!/usr/bin/ruby
eval"X,Y,*A="+`dd`.split*?,;p 1.<<A.any?(&:odd?)?~-X : Y>0?-1:X

#!/usr/bin/ruby
s=0;gets.split.each{|e|s^=e.to_i%4};puts s>0?:Taro: :Jiro
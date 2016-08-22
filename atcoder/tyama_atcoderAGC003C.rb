#!/usr/bin/ruby
#互いに異なるので重複処理は手抜きする
z=0...gets.to_i;a=z.sort_by{gets.to_i};p z.count{|i|a[i]+i&1>0}/2
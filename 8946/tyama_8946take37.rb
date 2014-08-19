#!/usr/bin/ruby
#coding:utf-8
raise 'Ruby 1.9+ is required' if RUBY_VERSION<'1.9'
list='いろはにほへとちりぬるをわかよたれそつねならむうゐのおくやまけふこえてあさきゆめみしゑひもせすん'
list=list.chars.each_slice(7).to_a

#上の句
#もののふの　よろいのそでを　かたしきて
#下の句
key='まくらにちかき はつかりのこゑ'.split
enc='くこらかにのちかかゑきこにのらゑくのきかにかきり'
puts enc.chars.each_slice(2).map{|e|list[key[0].index e[0]][key[1].index e[1]]}*''
# われのけしんのなをもうせ => 毘沙門天
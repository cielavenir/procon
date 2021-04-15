#!/usr/bin/ruby
#coding:utf-8
a,b,c=gets.split(',').map(&:to_i)
puts '合計点:%d'%[a+b+c]
puts '平均点:%.1f'%[(a+b+c)/3.0]

#!/usr/bin/ruby
n,t=gets.split.map &:to_i;puts$<.map{|e|e.split.map &:to_i}.select{|a,b|b<=t}.map{|a,b|a}.min||:TLE

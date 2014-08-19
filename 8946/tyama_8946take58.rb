#!/usr/bin/ruby
#coding:utf-8
raise 'Ruby 1.9+ is required' if RUBY_VERSION<'1.9'
T='1234567890-^qwertyuiopasdfghjkl;:]zxcvbnm,./_'
S='ぬふあうえおやゆよわほへたていすかんなにらせちとしはきくまのりれけむつさそひこみもねるめ'
#puts 'もにんちきにみらのいみそくらなとくらつちにそくにてらもにのちのちくらなとくにのにしいる'.chars.map{|e|T[S.index e]}*''
# => miyaginokenchoushozaichiwomikakahoushikide.
puts 'sendai'.chars.map{|e|S[T.index e]}*''
# => といみしちに
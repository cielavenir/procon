#!/usr/bin/ruby
N,A,B=$<.read.split.map &:to_i;puts N>A&&(N%-~A+A-B==0||A<B)?:Aoki: :Takahashi
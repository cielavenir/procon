#!/usr/bin/env runghc
import System.Cmd
main=system("ruby -e 'def dfs(row,col,n,k);return if n==0;k.times{|i|A[row-i][col,1]=\"1\";A[row-k-i][col-i-1,1]=\"1\";A[row-k-i][col+i+1,1]=\"1\"};dfs(row-2*k,col-k,n-1,k/2);dfs(row-2*k,col+k,n-1,k/2);end;;A=63.times.map{\"_\"*100};N=gets.to_i;dfs(62,49,N,16);A.each{|e|puts e};'")
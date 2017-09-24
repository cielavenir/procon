#!/usr/bin/ruby
N,M,K=gets.split.map &:to_i
puts (0..N).any?{|k|x=K-k*M;y=N-2*k;y==0?x==0:(l=x/y;x%y==0&&0<=l&&l<=M)}?:Yes: :No

__END__
k(M-l)+(N-k)l=K
kM+Nl-2kl=K
(N-2k)l=K-kM

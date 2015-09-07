#!/usr/bin/ruby
T=DATA.map(&:chomp)
H,M=$<.map(&:to_i)
if M==0
	puts T[H].split[0]+" o' clock"
elsif M<=30
	puts T[M]+' past '+T[H].split[0]
else
	puts T[60-M]+' to '+T[H%12+1].split[0]
end
__END__

one minute
two minutes
three minutes
four minutes
five minutes
six minutes
seven minutes
eight minutes
nine minutes
ten minutes
eleven minutes
twelve minutes
thirteen minutes
fourteen minutes
quarter
sixteen minutes
seventeen minutes
eighteen minutes
nineteen minutes
twenty minutes
twenty one minutes
twenty two minutes
twenty three minutes
twenty four minutes
twenty five minutes
twenty six minutes
twenty seven minutes
twenty eight minutes
twenty nine minutes
half
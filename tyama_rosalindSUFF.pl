#!/usr/bin/perl
# < rosalind_suff.txt perl tyama_rosalindSUFF.pl | ruby tyama_rosalindSUFF.rb > suff.ans
use strict;
use warnings;
use Tree::Suffix;
my $str=<>;
chomp($str);
my $tree=Tree::Suffix->new($str);
$tree->dump;
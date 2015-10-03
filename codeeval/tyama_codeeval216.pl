#!/usr/bin/perl
use strict;
use warnings;
use feature qw(say);

my %table=('read'=>4,'write'=>2,'grant'=>1);
my @orig_perm=(7,3,0,6,2,4,5,1,5,3,7,1,6,0,2,4,2,6);
while(<>){
	chomp;
	my @line=split(' ',$_);
	my @perm=@orig_perm;
	for my $arg(@line){
		my @arg=split('=>',$arg);
		my $user_num=int(substr($arg[0],5))-1;
		my $file_num=int(substr($arg[1],5))-1;
		my $action=$table{$arg[2]};
		if(($perm[$user_num*3+$file_num]&$action)==0){goto fail;}
		if($action==1){
			$action=$table{$arg[3]};
			$user_num=int(substr($arg[4],5))-1;
			$perm[$user_num*3+$file_num]|=$action;
		}
	}
	say 'True';next;
fail:
	say 'False';
}
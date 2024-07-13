#!/usr/bin/ruby
S=DATA.read
M=10**9+7
BSE=5000000
def f(n)
	if n>=M
		0
	elsif false
		r=1
		n.times{|i|
			r=r*(i+1)%M
			p r if (i+1)%BSE==0
		}
		r
	else
		d,n=n.divmod BSE
		r=S.split.map(&:to_i)[d]
		n.times{|i|
			r=r*(d*BSE+i+1)%M
		}
		r
	end
end
k=gets.to_i
if k%2>0
	p 0
	exit
end
p f(k)*f(k/2).pow(M-2,M)**2%M
__END__
1
974067448
682498929
598816162
491101308
586350670
76479948
463847391
723816384
172827403
67347853
407719831
27368307
606322308
625544428
1669644
199888908
534491822
888050723
884343068
927880474
112249297
281863274
770511792
661224977
935080803
623534362
797848181
970055531
232253360
261384175
659224434
195888993
509096183
66404266
785113347
547665832
996122673
109838563
34538816
933245637
911398531
724691727
114985663
368925948
464456846
268838846
938269070
136026497
564758715
112390913
167240465
135498044
889410460
217544623
996097969
419363534
607730875
500780548
651081062
668123525
563432246
128487469
318951960
30977140
93940075
522049725
559947225
309058615
624577416
386027524
716986954
189239124
179518046
148528617
529726489
940567523
473718967
917084264
105419548
429277690
937409008
996164327
418537348
358655417
775305697
568392357
392838702
780072518
596737944
462639908
843321396
275105629
432030917
909210595
321685608
99199382
5003231
703397904
863250534
733333339
180898306
97830135
864869025
608823837
46819124
256141983
491415383
141827977
688809790
696628828
457469634
637939935
502297454
811575797
48053248
848924691
26011548
131772368
271198437
724464507
510650790
272814771
564188856
326159309
44135644
456152084
816929577
903466878
218107212
92255682
196345098
769795511
407518072
373745190
147050765
606241871
666493603
825871994
561011609
957939114
765215899
435887178
201339230
852304035
469928208
663307737
414236650
375297772
211487466
217598709
676526196
624148346
439411911
671734977
644050694
624500515
715264908
748510389
819801784
203191898
340030191
423951674
331910086
629786193
341080135
672850561
684748812
814362881
60625018
823845496
175638827
116667533
163928347
256473217
393556719
627655552
687265514
245795606
36292292
586445753
953634340
172114298
260466949
193781724
756154604
778983779
49031023
83868974
954913
315103615
346966053
965785236
321900901
492741665
532702135
377329025
847645126
847549272
3258987
698611116

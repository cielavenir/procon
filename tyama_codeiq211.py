#!/usr/bin/python
#coding:utf-8
import nltk
#nltk.download() #Download Corpora -> names
from nltk.corpus import names
freq=nltk.ConditionalFreqDist(
	(name[-1],fileid)
	for fileid in names.fileids()
	for name in names.words(fileid))
print "WordEnding,female.txt,male.txt"
for e in freq.conditions():
	print "%s,%d,%d" % (e,freq[e]['female.txt'],freq[e]['male.txt'])
'''
男性
n(478)
e(468)
y(332)
女性
a(1773)
e(1432)
y(461)

男性はnで終わり、女性はaで終わる事が多い。
eで終わるのが男女ともに多いのは、eが「aを[ei]と読ませる」ために使われることが多いからと考えられる。
yは子音の後ろにも母音の後ろにもつくことができるので汎用性が高いといえる。
'''
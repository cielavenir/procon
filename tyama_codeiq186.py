#!/usr/bin/python
#coding:utf-8
import nltk
#import re
#nltk.download() #Download Corpora -> gutenberg
from nltk.corpus import gutenberg
#words1 = [w.lower() for w in gutenberg.words('austen-sense.txt')]
#words2 = [w for w in words1 if re.sub(r'[^a-z]','',w)==w]
words2 = [w.lower() for w in gutenberg.words('austen-sense.txt') if w.isalpha()] ###
freq=nltk.FreqDist(words2)
s = len(words2)
for e in freq.keys():
  print "%s,%d,%f" % (e,freq[e],float(freq[e])/s*100)

'''
keys = freq.keys() ###
values = freq.values() ###
#s=sum(freq.values())
s=sum(values) ### len(words2)
for i in range(len(freq)):
  #print "%s,%d,%f" % (freq.keys()[i],freq.values()[i],float(freq.values()[i])/s*100)
  print "%s,%d,%f" % (keys[i],values[i],float(values[i])/s*100) ###
'''
#冠詞、前置詞、代名詞、接続詞が多い
#主人公であるelinorとmarianneも多く出現する
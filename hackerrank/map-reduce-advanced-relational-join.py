#!/usr/bin/python
import sys
from collections import OrderedDict
class MapReduce:
	def __init__(self):
		self.intermediate = OrderedDict()
		self.result = []

	def emitIntermediate(self, key, value):
		self.intermediate.setdefault(key, [])
		self.intermediate[key].append(value)

	def emit(self, value):
		self.result.append(value) 

	def execute(self, data, mapper, reducer):
		for record in data:
			mapper(record)

		for key in self.intermediate:
			reducer(key, self.intermediate[key])

		self.result.sort()
		for item in self.result:
			print item

mapReducer = MapReduce()

def mapper(record):
	a=record.strip().split(',')
	if a[0]=='Department':
		mapReducer.emitIntermediate(a[1],a[2])
	if a[0]=='Employee':
		mapReducer.emitIntermediate(a[2],'$'+a[1])

def reducer(key, list_of_values):
	a=sorted(list_of_values)
	name=a[0][1:]
	for e in a[1:]:
		mapReducer.emit((key,name,e))
	
if __name__ == '__main__':
	inputData = []
	for line in sys.stdin:
		inputData.append(line)
	mapReducer.execute(inputData, mapper, reducer)
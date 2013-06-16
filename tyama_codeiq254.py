#!/usr/bin/python
#coding: utf-8
import sys

import scipy
import pylab
import numpy as np
import scipy.cluster.hierarchy as sch
import scipy.spatial.distance as ssd
import matplotlib.cm as cm

def hcluster(fname):
	# タブ区切りの数値データを読み込んで、numpy.ndarrayを用意します。
	data = np.loadtxt(sys.argv[1])
	fig = pylab.figure(figsize=(16,9))
	rl = len(data)
	D = np.zeros([rl,rl])

	# 距離行列を計算します。以下の3行をまとめて書き換えても構いません。その場合は、[(2)]として解答してください。
	for i in range(rl):
		for j in range(rl):
			D[i,j] = ssd.cosine(data[i],data[j])
	ax1 = fig.add_axes([0.1,0.1,0.2,0.6])
	ax1.set_axis_off()	

	# いろいろな方法を試してみるのがよいかもしれません。
	Y = sch.linkage(data,method='ward',metric='euclidean')
	#Y = sch.linkage(D,method='complete',metric='cosine')

	# デンドログラムを描画します
	Z1 = sch.dendrogram(Y, orientation='right') 
	axmatrix = fig.add_axes([0.3,0.1,0.6,0.6])
	idx1 = Z1['leaves']
	idx1.reverse()

	# クラスタリングの結果が反映されるように行ごとのデータを並べ替えます。
	reordered_matrix = [data[idx1[i]] for i in range(len(data))]
	im = axmatrix.matshow(reordered_matrix, aspect='auto', cmap=pylab.cm.bwr)

	# 目盛りを削除しておきます
	axmatrix.set_xticks([])
	axmatrix.set_yticks([])

	# カラーバーを表示します
	axcolor = fig.add_axes([0.91,0.1,0.02,0.6])
	pylab.colorbar(im, cax=axcolor)
	#fig.show()
	fig.savefig('254.pdf')

if __name__ == '__main__':
	hcluster(sys.argv[1])
#!/usr/bin/Rscript
library(igraph)
args <- commandArgs(trailingOnly=TRUE)
if(length(args)<1){
	cat("Usage: 325.R karate.GraphML\n")
	quit()
}
g <- read.graph(args[1], format='graphml')

#Q1
name=V(g)$name
faction=V(g)$Faction
cat("Nodes (name, faction)\n")
print(matrix(c(name,faction),ncol=2,byrow=F))
#      [,1]       [,2]
# [1,] "Mr Hi"    "1"
# [2,] "Actor 2"  "1"
# [3,] "Actor 3"  "1"
# [4,] "Actor 4"  "1"
# [5,] "Actor 5"  "1"
# [6,] "Actor 6"  "1"
# [7,] "Actor 7"  "1"
# [8,] "Actor 8"  "1"
# [9,] "Actor 9"  "2"
#[10,] "Actor 10" "2"
#[11,] "Actor 11" "1"
#[12,] "Actor 12" "1"
#[13,] "Actor 13" "1"
#[14,] "Actor 14" "1"
#[15,] "Actor 15" "2"
#[16,] "Actor 16" "2"
#[17,] "Actor 17" "1"
#[18,] "Actor 18" "1"
#[19,] "Actor 19" "2"
#[20,] "Actor 20" "1"
#[21,] "Actor 21" "2"
#[22,] "Actor 22" "1"
#[23,] "Actor 23" "2"
#[24,] "Actor 24" "2"
#[25,] "Actor 25" "2"
#[26,] "Actor 26" "2"
#[27,] "Actor 27" "2"
#[28,] "Actor 28" "2"
#[29,] "Actor 29" "2"
#[30,] "Actor 30" "2"
#[31,] "Actor 31" "2"
#[32,] "Actor 32" "2"
#[33,] "Actor 33" "2"
#[34,] "John A"   "2"

weight=E(g)$weight
edges=get.edges(g,E(g))
edges_name=apply(edges, 1:ncol(edges), FUN=function(e){name[e]})
cat("Edges (source target weight)\n")
print(cbind(edges_name,weight))
# [1,] "Actor 2"  "Mr Hi"    "4"
# [2,] "Actor 3"  "Mr Hi"    "5"
# [3,] "Actor 4"  "Mr Hi"    "3"
# [4,] "Actor 5"  "Mr Hi"    "3"
# [5,] "Actor 6"  "Mr Hi"    "3"
# [6,] "Actor 7"  "Mr Hi"    "3"
# [7,] "Actor 8"  "Mr Hi"    "2"
# [8,] "Actor 9"  "Mr Hi"    "2"
# [9,] "Actor 11" "Mr Hi"    "2"
#[10,] "Actor 12" "Mr Hi"    "3"   
#[11,] "Actor 13" "Mr Hi"    "1"   
#[12,] "Actor 14" "Mr Hi"    "3"   
#[13,] "Actor 18" "Mr Hi"    "2"   
#[14,] "Actor 20" "Mr Hi"    "2"   
#[15,] "Actor 22" "Mr Hi"    "2"   
#[16,] "Actor 32" "Mr Hi"    "2"   
#[17,] "Actor 3"  "Actor 2"  "6"   
#[18,] "Actor 4"  "Actor 2"  "3"   
#[19,] "Actor 8"  "Actor 2"  "4"   
#[20,] "Actor 14" "Actor 2"  "5"   
#[21,] "Actor 18" "Actor 2"  "1"   
#[22,] "Actor 20" "Actor 2"  "2"   
#[23,] "Actor 22" "Actor 2"  "2"   
#[24,] "Actor 31" "Actor 2"  "2"   
#[25,] "Actor 4"  "Actor 3"  "3"   
#[26,] "Actor 8"  "Actor 3"  "4"   
#[27,] "Actor 9"  "Actor 3"  "5"   
#[28,] "Actor 10" "Actor 3"  "1"   
#[29,] "Actor 14" "Actor 3"  "3"   
#[30,] "Actor 28" "Actor 3"  "2"   
#[31,] "Actor 29" "Actor 3"  "2"   
#[32,] "Actor 33" "Actor 3"  "2"   
#[33,] "Actor 8"  "Actor 4"  "3"   
#[34,] "Actor 13" "Actor 4"  "3"   
#[35,] "Actor 14" "Actor 4"  "3"   
#[36,] "Actor 7"  "Actor 5"  "2"   
#[37,] "Actor 11" "Actor 5"  "3"   
#[38,] "Actor 7"  "Actor 6"  "5"   
#[39,] "Actor 11" "Actor 6"  "3"   
#[40,] "Actor 17" "Actor 6"  "3"   
#[41,] "Actor 17" "Actor 7"  "3"   
#[42,] "Actor 31" "Actor 9"  "3"   
#[43,] "Actor 33" "Actor 9"  "3"   
#[44,] "John A"   "Actor 9"  "4"   
#[45,] "John A"   "Actor 10" "2"   
#[46,] "John A"   "Actor 14" "3"   
#[47,] "Actor 33" "Actor 15" "3"   
#[48,] "John A"   "Actor 15" "2"   
#[49,] "Actor 33" "Actor 16" "3"   
#[50,] "John A"   "Actor 16" "4"   
#[51,] "Actor 33" "Actor 19" "1"   
#[52,] "John A"   "Actor 19" "2"   
#[53,] "John A"   "Actor 20" "1"   
#[54,] "Actor 33" "Actor 21" "3"   
#[55,] "John A"   "Actor 21" "1"   
#[56,] "Actor 33" "Actor 23" "2"   
#[57,] "John A"   "Actor 23" "3"   
#[58,] "Actor 26" "Actor 24" "5"   
#[59,] "Actor 28" "Actor 24" "4"   
#[60,] "Actor 30" "Actor 24" "3"   
#[61,] "Actor 33" "Actor 24" "5"   
#[62,] "John A"   "Actor 24" "4"   
#[63,] "Actor 26" "Actor 25" "2"   
#[64,] "Actor 28" "Actor 25" "3"   
#[65,] "Actor 32" "Actor 25" "2"   
#[66,] "Actor 32" "Actor 26" "7"   
#[67,] "Actor 30" "Actor 27" "4"   
#[68,] "John A"   "Actor 27" "2"   
#[69,] "John A"   "Actor 28" "4"   
#[70,] "Actor 32" "Actor 29" "2"   
#[71,] "John A"   "Actor 29" "2"   
#[72,] "Actor 33" "Actor 30" "4"   
#[73,] "John A"   "Actor 30" "2"   
#[74,] "Actor 33" "Actor 31" "3"   
#[75,] "John A"   "Actor 31" "3"   
#[76,] "Actor 33" "Actor 32" "4"   
#[77,] "John A"   "Actor 32" "4"   
#[78,] "John A"   "Actor 33" "5"   

#Q2
E(g)$width <- weight
V(g)$label <- ''
#V(g)$color <- rainbow(2)[faction] #実際の派閥に合わせてノードを塗りたい場合コメントアウト
#pdf('codeiq325.pdf')
#plot.igraph(g)
#dev.off()

#Q3、Q4
faction<-faction-1
#faction
# [1] 0 0 0 0 0 0 0 0 1 1 0 0 0 0 1 1 0 0 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1
#派閥が予測されるとき、割り当てられる番号は不定である。従って、(今回の派閥の数は2なので)c(0,1)について順列を取り、
#その一致率の最大を取らなければならない。
#が、順列はRの標準ライブラリには存在しない。今回は2つなのでビット反転で間に合わせることにする。
faction2<-(faction-1)*-1 #1を引いて-1を掛けると1とのxorになる
#faction2
# [1] 1 1 1 1 1 1 1 1 0 0 1 1 1 1 0 0 1 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0
#この時、max(length(membership[membership==faction]),length(membership[membership==faction2]))が【一致数】となる。

#以下、1は2(派閥の数)-1の意味である。length(data$merges-1)回の操作により予測する派閥の数が2つになる。
data<-edge.betweenness.community(g)
membership<-community.to.membership(g,data$merges, steps=length(data$merges[,1])-1)$membership
stopifnot(length(membership)==length(faction))
print(max(length(membership[membership==faction]),length(membership[membership==faction2]))/length(faction)*100)
#94.11765
#edge.betweenness.community()の一致率は94%である

data<-walktrap.community(g)
membership<-community.to.membership(g,data$merges, steps=length(data$merges[,1])-1)$membership
stopifnot(length(membership)==length(faction))
print(max(length(membership[membership==faction]),length(membership[membership==faction2]))/length(faction)*100)
#100
#walktrap.community()の一致率は100%である

data<-fastgreedy.community(g)
membership<-community.to.membership(g,data$merges, steps=length(data$merges[,1])-1)$membership
stopifnot(length(membership)==length(faction))
print(max(length(membership[membership==faction]),length(membership[membership==faction2]))/length(faction)*100)
#100
#fastgreedy.community()の一致率は100%である

#フィードバック後修正:spinglass.community()は派閥の数を指定することが可能である。
membership<-spinglass.community(g,spins=2)$membership-1
stopifnot(length(membership)==length(faction))
print(max(length(membership[membership==faction]),length(membership[membership==faction2]))/length(faction)*100)
#100
#spinglass.community()の一致率は100%である

#派閥の数が決まっている時はcommunity.to.membership()が必要である。従って以下の手法は使用することができない。
#leading.eigenvector.community(g)
#multilevel.community(g)
#optimal.community(g)
#label.propagation.community(g)
#infomap.community(g)
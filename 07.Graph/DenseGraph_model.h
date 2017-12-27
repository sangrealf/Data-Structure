﻿#ifndef INC_03_VERTEX_ADJACENT_ITERATOR_DENSEGRAPH_H
#define INC_03_VERTEX_ADJACENT_ITERATOR_DENSEGRAPH_H


#include<iostream>
#include<cstdio>
#include<vector>
#include<cassert>
using namespace std;

//定义稠密图 
class DenseGraph{

private:
	int n,m;
	bool directed;
	vector<vector<bool> > g;
public:
	DenseGraph(int n,bool directed){
		this->n=n;
		this->m=0;
		this->directed=directed;
		for(int i=0;i<n;i++)
			g.push_back(vector<bool>(n,false));
	}
	~DenseGraph(){
		
	}
	
	int V(){
		return n;
	}
	int E(){
		return m;
	}
	
	void addEdge(int v,int w){
		assert(v>=0&&v<n);
		assert(w>=0&&w<n);
		//判断是否已经有边
		if(hasEdge(v,w))
			return;
			
		g[v][w]=true;
		if(!directed)		//无向图反向加边 
			g[w][v]=true;
		m++;
	}
	
	//判断是否有边
	bool hasEdge(int v,int w){		//邻接矩阵处理平行边问题有优势 
		assert(v>=0&&v<n);			//O(1) 
		assert(w>=0&&w<n);
		return g[v][w];
	} 
	
	class adjIterator{
	
	private:
		DenseGraph &G;
		int v;
		int index;
	public:
		adjIterator(DenseGraph &graph,int v):G(graph){
			this->v=v;
			this->index=-1;		//
		}
		
		int begin(){		//index值为此行第一个值为true的元素 
			
			index=-1;
			return next(); 
			
		}
		
		int next(){
			for(index+=1;index<G.V();index++)
				if(G.g[v][index])
					return index;
			return -1;
		}
		
		bool end(){
			return index>=G.V();
		}
		
		
	}; 
	
};

#endif //INC_03_VERTEX_ADJACENT_ITERATOR_DENSEGRAPH_H

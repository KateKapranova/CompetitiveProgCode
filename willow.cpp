//willow problem
//n times Dijkstra: all sources shortest path problem (ASSP)

#include <bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	int nodes;
	cin>>nodes;
	
	vector<list<pair<int,int>>> edges (nodes);
	
	int from,to,cost;
	for(int i=0;i<nodes-1;i++){
		cin>>from>>to>>cost;
		edges[from].push_back(make_pair(to,cost));
		edges[to].push_back(make_pair(from,cost));		
	}
	
	
	//sanity check for data structure
	/*for (auto& elem: edges){
		for (auto& el: elem){
			cout<<el.first<<" "<<el.second<<endl;}
	}*/
	
	
	//n times Dijkstra
	
	unsigned long maxDist= 0; unsigned long maxElem;
	
	for (int n=0;n<nodes;n++){
		vector<int> distance (nodes,200000000);
		vector<bool> visited(nodes,false);
	
		distance[n]=0;
		queue<int> q;
		q.push(n);
		visited[n]=true;
		int actual;
		
		while (q.size()){
			actual = q.front();
			q.pop();
			for (int i=0;i<edges[actual].size();i++){
				for (auto& elem: edges[actual]){
					to=elem.first;
					cost=elem.second;
					if (visited[to]==false){
						q.push(to);
						visited[to]=true;
						if (distance[to]>distance[actual]+cost){
							distance[to]=distance[actual]+cost;
						}
					}
					else {continue;}
				}	
				
			}
		}
		
		maxElem=*max_element(distance.begin(),distance.end());
		if (maxElem>maxDist){maxDist=maxElem;}
	}
		
	cout<<maxDist<<endl; 
		
	return 0;
}

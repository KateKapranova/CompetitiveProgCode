//willow problem
//tree diameter problem
//observation: farthest distance in a tree is most likely to be between two leafs
//idea: start bFS in node 0 and find the node X which is the farthest from node 0 (in terms of path weight sum)
//start BFS again from the node X and find the farthest node Y from node X. Output the sum path between X and Y.
//outcome: CORRECT

#include <bits/stdc++.h>

using namespace std;


//help function BFS
int BFS(vector<list<pair<int,int>>>& edges, int source, queue<int>& q, vector<int>& visited, vector<unsigned long>& distance){
	pair<int,int> help; int to, cost,current; unsigned long dist = 0;
	vector<unsigned long> parent(visited.size(),0);
	
	q.push(source);
	//cout<<"push on queue "<<source<<endl;
	visited[source]=1;
	
	while(q.size()){
		
		current = q.front();
		//cout<<"current: "<<current<<endl;
		q.pop();
			
		for(auto& el: edges[current]){
			help=el;
			
			to=help.first; //cout<<"to:"<<to<<endl;
			//cout<<"found adjacent node: "<<to<<endl;
			cost=help.second; //cout<<"cost:"<<cost<<endl;
						
			if (visited[to]==0) {
				visited[to]=1;
				parent[to]=current;
				distance[to]=cost+distance[current];
				q.push(to);
			}
		}
	}
	
	for (int i=0;i<distance.size();i++){
		if (dist<distance[i]){
			dist=distance[i];
			to=i;
		}
	}
	return to;
}


int main(){
	ios::sync_with_stdio(false);
	
	int nodes;
	cin>>nodes;
	
	vector<list<pair<int,int>>> edges (nodes);
	
	int from,to,cost;
	for(int i=0;i<nodes-1;i++){
		cin>>from>>to>>cost ;
		edges[from].push_back(make_pair(to,cost));
		edges[to].push_back(make_pair(from,cost));		
	}
	
	queue<int> q;
	vector<int> visited(nodes,0);
	vector<unsigned long> distance(nodes,0);
	vector<int> visited1(nodes,0);
	vector<unsigned long> distance1(nodes,0);
	int farthestNode;
	
	//find fartherst node from node 0 (in terms of edge weight sum not hops)
	farthestNode=BFS(edges,0,q,visited,distance);
	farthestNode=BFS(edges,farthestNode,q,visited1,distance1);
	
		
	cout<<*max_element(distance1.begin(),distance1.end());

	return 0;
}

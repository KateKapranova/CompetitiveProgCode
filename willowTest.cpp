//willow problem
//tree diameter problem
//observation: farthest distance in a tree is most likely to be between two leafs
//idea: start DFS in any leaf and save the biggest distance to another leaf

//outcome: 

#include <bits/stdc++.h>

using namespace std;


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
	
	stack<int> s;
	vector<int> visited(nodes,0);
	int maxDist=0;int localDist=0; int current; pair<int,int> help; int count;
	
	for(int i=0;i<nodes;i++){
		//find any leaf
		if(edges[i].size()==1){
			//start DFS
			s.push(i);
			
			visited[i]=1;
			
			while(s.size()){
				
				current = s.top();
				cout<<"current: "<<current<<endl;
				
				count=0;
				for(auto& el: edges[current]){
					count+=1;
					help=el;
					to=help.first; cout<<"to:"<<to<<endl;
					cost=help.second; cout<<"cost:"<<cost<<endl;
					//we found another leaf
					if (visited[to]==0 && edges[to].size()==1){
						cout<<"test1"<<endl;
						visited[to]=1;
						localDist+=cost;
						if (localDist>maxDist){maxDist=localDist;}
						cout<<"localDist: "<<localDist<<endl;
						localDist=0;
						break;
					}
					else if (visited[to]==0){
						cout<<"test2"<<endl;
						cout<<"push the neighbour on stack: "<<help.first<<endl;
						s.push(to);
						visited[to]=1;
						localDist+=cost;
						cout<<"localDist: "<<localDist<<endl;
						break;
					}
					//else{
					if (visited[to]==1 && count==edges[current].size()){
						cout<<"test3"<<endl;
						cout<<"pop: "<<s.top()<<endl;
						s.pop();
					}
				}
			}
			break;
		}
	}
	
	cout<<maxDist;

	return 0;
}

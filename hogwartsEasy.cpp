//hogwartsTest Easier Version without edge updates
//correct test run

#include <bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(false);
	int questions, numberEdges;
	string from,to; string source="Gryffindor-Common-Room";string destination; int weight;
	cin>>questions>>numberEdges;
	set<string> nodeNum;
	unordered_multimap<string,pair<string,int>> ways;
	for (int i=0;i<numberEdges;i++){
		cin>>from>>to>>weight;
		ways.insert(make_pair(from,make_pair(to,weight)));
		//ways[from]=make_pair(to,weight);
		nodeNum.insert(from);
		nodeNum.insert(to);
	}
	
	pair<string,int> helpW;
	//output of ways:
	/*cout<<"output of ways:"<<endl;
	for(auto& w: ways){
		helpW=w.second;
		cout<<"from: "<<w.first<<" to: "<<helpW.first<<" weight: "<<helpW.second<<endl;
	}
	cout<<endl;*/
	
	
	//crazy transfer from set to map through vector
	vector<string> nodes(nodeNum.begin(),nodeNum.end());
	//roomMap maps from room name to fixed index associated with a room
	map<string,int> roomMap;
	for(int k=0;k<nodes.size();k++){
		roomMap[nodes[k]]=k;
	}
	
	//main part
	for(int k=0;k<questions;k++){
		cin>>destination;
		
		//initialise distance vector
		vector<int> distance(nodeNum.size(),200000000);
		distance[roomMap[source]]=0;
		
		//vector visited holds the bool value reflecting if a node has been visited
		vector<bool> visited(nodeNum.size(),false);
		
		//priority queue with reversed ordering
		priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> q;
		//priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> testQ;
		
		q.push(make_pair(0,source));
		//cout<<"iter "<<k+1<<" SOURCE: "<<source<<" DEST: "<<destination<<endl;
		
		if(nodeNum.count(destination)==0){
			cout<<"impossible"<<endl;
			continue;
		}
		
		//Disktra algorithm
		
		//pair actual is for queue; pair help is for map ways
		pair<int,string> actual; int newDist; pair<string,int> help;
		while(q.size()){
			actual=q.top();
			
			if (visited[roomMap[actual.second]]==true){
				//cout<<"this one is popped: "<<actual.second<<endl;
				q.pop();
				
				continue;
			}
			visited[roomMap[actual.second]]=true;
			//cout<<"visited: "<<actual.second<<endl;
			q.pop();
			
			for (auto& room: ways){
				//cout<<"sanity check: "<<"room 1: "<<room.first<<" help 1: "<< help.first<<endl;
				help=room.second;
				
				if (help.first==actual.second){
					//cout<<"possible match "<<room.first<<endl;
					newDist=distance[roomMap[help.first]]+help.second;
					//cout<<"new possible distance "<<newDist<<"bw"<<room.first<<actual.second<<endl;
					if (newDist<distance[roomMap[room.first]]){
						//cout<<"BOOM!"<<endl;
						distance[roomMap[room.first]]=newDist;
						//cout<<"new distance of "<<room.first<<" "<<newDist<<endl;
						q.push(make_pair(newDist,room.first));
						
						
					}
				}
				
				if (room.first==actual.second){
					//cout<<"possible match "<<help.first<<endl;
					newDist=distance[roomMap[room.first]]+help.second;
					//cout<<"new distance: "<<newDist<<"bw"<<room.first<<help.first<<endl;
					if (newDist<distance[roomMap[help.first]]){
						distance[roomMap[help.first]]=newDist;
						//cout<<"new distance of "<<help.first<<" "<<newDist<<endl;
						q.push(make_pair(newDist,help.first));
						
					}
				}
				
			}
			/*
			testQ=q;
			cout<<"testQ: "<<endl;
			pair<int,string> testP;
			while(testQ.size()){
				testP=testQ.top();
				cout<<testP.first<<" "<<testP.second<<endl;
				testQ.pop();
			}*/
			
		}
		//cout<<"distance to destination:"<<endl;
		//cout<<distance[roomMap[destination]]<<endl;
		if (distance[roomMap[destination]]==200000000){
			cout<<"impossible"<<endl;
		}
		else{
			cout<<distance[roomMap[destination]]<<endl;
			source=destination;
		}
		//cout<<"NEW TEST CASE"<<endl;
	}
	return 0;
}
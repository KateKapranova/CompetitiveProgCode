//hogwartsTest 
//second implementation attempt

#include <bits/stdc++.h>
using namespace std;

struct Edges{
	string fromNode;
	string toNode;
	int weight;
};

int main(){
	ios::sync_with_stdio(false);
	int testCase,changed;
	string destination,start="Gryffindor-Common-Room";
	string from,to; int weight;
	//outer loop which deals with test cases
	cin>>testCase;
	for (int i=0;i<testCase;i++){
		cin>>destination;
		cout<<"My start: "<<start<<" My destination: "<<destination<<endl;
		cin>>changed;
		//map keeping track of the names of the rooms and assigned indeces
		map<string,int> nameIndex;
		//inner loop dealing with a particular test case
		int nodeCounter=0;
		vector<Edges> ways(changed);
		for (int k=0;k<changed;k++){
			cin>>from>>to>>weight;
			ways[k].fromNode=from;
			ways[k].toNode=to;
			if (weight==0){changed=changed-1;k=k-1;continue;}
			ways[k].weight=weight;
			if (nameIndex.count(from)==0){
				//if key from doesn't exist
				nameIndex[from]=nodeCounter;
				nodeCounter+=1;
			}
			if (nameIndex.count(to)==0){
				//if key to doesn't exist
				nameIndex[to]=nodeCounter;
				nodeCounter+=1;
			}
			//output ways
			
		}
		cout<<"contents of ways vector:"<<endl;
		for(int i=0; i<ways.size();i++){
			cout<<ways[i].fromNode<<" "<<ways[i].toNode<<" "<<ways[i].weight<<endl;
		}
		
		cout<<"contents of NameIndex map:"<<endl;
		for(auto& l: nameIndex){
			cout<<l.first<<" "<<l.second<<endl;
		}
		
		cout<<"size of map: "<<nameIndex.size()<<endl;
		cout<<"nodeCounter: "<<nodeCounter<<endl;
		
		vector<int> distance(nodeCounter,200000000);
		distance[nameIndex[start]]=0;
		
		cout<<"contents of vector distance:"<<endl;
		for(int z=0;z<nodeCounter;z++){
			cout<<distance[z]<<endl;
		}
		
		//priority queue with reversed ordering
		priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> q;
		for (auto& mapElem: nameIndex){
			/*if (mapElem.first!=start){
				q.push(make_pair(200000000,mapElem.first));
				continue;
			}*/
			q.push(make_pair(0,start));
		}
		/*
		cout<<"priority queue contents: "<<endl;
		pair<int,string> testPair;
		for(int x=0;x<nodeCounter;x++){
			testPair=q.top();
			q.pop();
			cout<<testPair.first<<" "<<testPair.second<<endl;
		}*/
		
		
		pair<int,string> actual; int newDist;
		while(q.size()){
			actual=q.top();
			cout<<"top pair: "<<actual.first<<" "<<actual.second<<endl;
			q.pop();
			for (int m=0;m<changed;m++){
				if (ways[m].fromNode==actual.second){
					cout<<"hit!"<<endl;
					newDist=distance[nameIndex[ways[m].fromNode]]+ways[m].weight;
					cout<<"new distance: "<<newDist<<endl;
					if (newDist<distance[nameIndex[ways[m].toNode]]){
						distance[nameIndex[ways[m].toNode]]=newDist;
						q.push(make_pair(newDist,ways[m].toNode));
					}
				}
				if (ways[m].toNode==actual.second){
					newDist=distance[nameIndex[ways[m].toNode]]+ways[m].weight;
					if (newDist<distance[nameIndex[ways[m].fromNode]]){
						distance[nameIndex[ways[m].fromNode]]=newDist;
						q.push(make_pair(newDist,ways[m].fromNode));
					}
				}
				
			}
		}
		cout<<"contents of distance after: "<<endl;
		for(int y=0;y<distance.size();y++){
			cout<<distance[y]<<endl;
		}
		
		cout<<"distance to destination:"<<endl;
		cout<<distance[nameIndex[destination]]<<endl;
		start=destination;
		cout<<"END OF TEST CASE"<<endl;
		
	}
	return 0;

}
//teams problem
//outcome: time limit

#include <bits/stdc++.h>

using namespace std;

struct Teams{
	int id;
	int age;
	int skill;
};

//sorts vector ageSkill by age in descending order, then by skill in ascending order and then by id in descending order
bool sortAge (Teams& i, Teams& j) {
	return (i.age < j.age) || ((i.age==j.age) && (i.skill>j.skill)) || ((i.age==j.age && i.skill==j.skill && i.id<j.id));
	}

int main(){
	ios::sync_with_stdio(false);
	int n, contest,age,skill,minAge,maxAge;
	int first=0;int second=0;int third=0;int low,high;
	int skill1=0;int skill2=0; int skill3=0;
	
	cin>>n>>contest;
	vector<Teams> ageSkill (n);
	for (int i=0;i<n;i++){
		cin>>age>>skill;
		ageSkill[i].id=i+1;
		ageSkill[i].age=age;
		ageSkill[i].skill=skill;
	}
	
	sort(ageSkill.begin(),ageSkill.end(),sortAge);
	//test output
	/*for(int a=0;a<n;a++){
		cout<<"id "<<ageSkill[a].id<<" age "<< ageSkill[a].age<<" skill "<<ageSkill[a].skill<<endl;
    }*/
	
	for(int j=0;j<contest;j++){
		cin>>minAge>>maxAge;
		//cout<<minAge<<endl;
		first=0;second=0;third=0;
		skill1=0;skill2=0;skill3=0;
		
		for(int i=0;i<n;i++){
			if (ageSkill[i].age>=minAge){
				low=i;
				break;
			}
		}
		for(int k=n-1;k>=0;k--){
			if (ageSkill[k].age<=maxAge){
				high=k;
				break;
			}
		}
		//cout<<low<<endl;
		for(int x=low;x<=high;x++){
			//cout<<first<<" "<<second<<" "<<third<<" "<<endl;
			//cout<<skill1<<" "<<skill2<<" "<<skill3<<" "<<endl;
			
			if (ageSkill[x].skill>skill1){
				//cout<<"test1"<<endl;
				third=second;
				skill3=skill2;
				second=first;
				skill2=skill1;
				skill1=ageSkill[x].skill;
				first = ageSkill[x].id;
				continue;
			}
			else if (ageSkill[x].skill>skill2){
				//cout<<"test3"<<endl;
				third=second;
				skill3=skill2;
				
				skill2=ageSkill[x].skill;
				second = ageSkill[x].id; 
				continue;
			}
			else if (ageSkill[x].skill>skill3){
				//cout<<"test5"<<endl;
				skill3=ageSkill[x].skill;
				third = ageSkill[x].id;
				continue;
			}
			cout<<first<<" "<<second<<" "<<third<<" "<<endl;
		}
		
		if (first==0 or second ==0 or third==0){
		cout<< "-1"<<endl;
		continue;
		}
		
		cout<<first<<" "<<second<<" "<<third<<" "<<endl;
		
	}
	
	
		
	return 0;
}

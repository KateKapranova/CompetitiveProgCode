//teams problem
//sort the vector of structs and greedily find the best match
//outcome: CORRECT

#include <bits/stdc++.h>

using namespace std;

struct Teams{
	int id;
	int age;
	int skill;
};

//sorts vector ageSkill by skill in descending order and then by id in ascending order
bool sortAge (Teams& i, Teams& j) {
	return (i.skill > j.skill) || ((i.skill==j.skill) && (i.id<j.id));
	}

int main(){
	ios::sync_with_stdio(false);
	int n, contest,age,skill,minAge,maxAge;
	int first, second, third;//int low,high;
	bool setF, setS, setT; int k;
		
	cin>>n>>contest;
	vector<Teams> ageSkill (n);
	for (int i=0;i<n;i++){
		cin>>age>>skill;
		ageSkill[i].id=i+1;
		ageSkill[i].age=age;
		ageSkill[i].skill=skill;
	}
	
	vector<pair<int,int>> contestAge(contest);
	for (int i=0;i<contest;i++){
		cin>>minAge>>maxAge;
		contestAge[i]=make_pair(minAge,maxAge);
	}
	
	sort(ageSkill.begin(),ageSkill.end(),sortAge);
	//test output
	/*for(int a=0;a<n;a++){
		cout<<"id "<<ageSkill[a].id<<" age "<< ageSkill[a].age<<" skill "<<ageSkill[a].skill<<endl;
    }
	
	for(int c=0;c<contest;c++){
		minAge=contestAge[c].first;maxAge=contestAge[c].second;
		cout<<minAge<<" "<<maxAge<<'\n';
	}*/
	
	
	for(int c=0;c<contest;c++){
		first=0;second=0;third=0;
		setF=false;setS=false;setT=false;
		minAge=contestAge[c].first;maxAge=contestAge[c].second;
		k=-1;
		while (!(first&&second&&third)){
			if (k<n){k=k+1;} else{break;}
			//cout<<"iteration k="<<k<<endl;
			if (ageSkill[k].age>=minAge && ageSkill[k].age<=maxAge && setF==false){
				
				first=ageSkill[k].id;
				//cout<<"set first as "<<first<<endl;
				setF=true;
				continue;
			}
			else if (ageSkill[k].age>=minAge && ageSkill[k].age<=maxAge && setS==false){
				second=ageSkill[k].id;
				//cout<<"set second as "<<second<<endl;
				setS=true;
				continue;
			}
			else if (ageSkill[k].age>=minAge && ageSkill[k].age<=maxAge && setT==false){
				third=ageSkill[k].id;
				//cout<<"set third as "<<third<<endl;
				setT=true;
				break;
			}
			
			
			
		}
		if (!(first&&second&&third)){
		cout<< "-1"<<endl;
		continue;
		}
		
		cout<<first<<" "<<second<<" "<<third<<" "<<'\n';
	}
	
		
	return 0;
}

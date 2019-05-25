//exam: dynamic programming
//input: width, height
//for each row: values


#include <bits/stdc++.h>
using namespace std;

//initialise the memoization map
//it keeps track of the sum of two elements where key is a pair of two numbers and value is their sum
//each element of weight matrix is referred to by a unique token
//unique token is calculate by formula: column + row*number of elements in a row
map<pair<int,int>,int> memo;


//fromIndexToToken transition function
int fitt(int r,int c,int numCols){
	return c+r*numCols;
}

//help function to calculate the max sum
int dynProg(int **array,int rows,int cols, int numCols){
	//base case
	if (rows==0){
		return array[0][cols];
	}
	//case of first column
	else if (cols==0){
		
		//place for memoization
		//return max(array[rows][0]+dynProg(array,rows-1,cols,numCols),array[rows][0]+dynProg(array,rows-1,cols+1,numCols));
		if (!memo.count({fitt(rows,0,numCols),fitt(rows-1,cols,numCols)})){
			memo[{fitt(rows,0,numCols),fitt(rows-1,cols,numCols)}]=array[rows][0]+dynProg(array,rows-1,cols,numCols);
		}
		if (!memo.count({fitt(rows,0,numCols),fitt(rows-1,cols+1,numCols)})){
			memo[{fitt(rows,0,numCols),fitt(rows-1,cols+1,numCols)}]=array[rows][0]+dynProg(array,rows-1,cols+1,numCols);
		}
		return max(memo[{fitt(rows,0,numCols),fitt(rows-1,cols,numCols)}],memo[{fitt(rows,0,numCols),fitt(rows-1,cols+1,numCols)}]);
	}
	//case of last column
	else if(cols==numCols-1){
		//return max(array[rows][cols]+dynProg(array,rows-1,cols,numCols),array[rows][cols]+dynProg(array,rows-1,cols-1,numCols));
		if (!memo.count({fitt(rows,cols,numCols),fitt(rows-1,cols,numCols)})){
			memo[{fitt(rows,cols,numCols),fitt(rows-1,cols,numCols)}]=array[rows][cols]+dynProg(array,rows-1,cols,numCols);
		}
		if (!memo.count({fitt(rows,cols,numCols),fitt(rows-1,cols-1,numCols)})){
			memo[{fitt(rows,cols,numCols),fitt(rows-1,cols-1,numCols)}]=array[rows][cols]+dynProg(array,rows-1,cols-1,numCols);
		}
		return max(memo[{fitt(rows,cols,numCols),fitt(rows-1,cols,numCols)}],memo[{fitt(rows,cols,numCols),fitt(rows-1,cols-1,numCols)}]);
	}
	//case: inbetween columns
	else{
		//return max({array[rows][cols]+dynProg(array,rows-1,cols,numCols),array[rows][cols]+dynProg(array,rows-1,cols-1,numCols),array[rows][cols]+dynProg(array,rows-1,cols+1,numCols)});
		if (!memo.count({fitt(rows,cols,numCols),fitt(rows-1,cols,numCols)})){
			memo[{fitt(rows,cols,numCols),fitt(rows-1,cols,numCols)}]=array[rows][cols]+dynProg(array,rows-1,cols,numCols);
		}
		if (!memo.count({fitt(rows,cols,numCols),fitt(rows-1,cols-1,numCols)})){
			memo[{fitt(rows,cols,numCols),fitt(rows-1,cols-1,numCols)}]=array[rows][cols]+dynProg(array,rows-1,cols-1,numCols);
		}
		if (!memo.count({fitt(rows,cols,numCols),fitt(rows-1,cols+1,numCols)})){
			memo[{fitt(rows,cols,numCols),fitt(rows-1,cols+1,numCols)}]=array[rows][cols]+dynProg(array,rows-1,cols+1,numCols);
		}
		return max({memo[{fitt(rows,cols,numCols),fitt(rows-1,cols,numCols)}],memo[{fitt(rows,cols,numCols),fitt(rows-1,cols-1,numCols)}],memo[{fitt(rows,cols,numCols),fitt(rows-1,cols+1,numCols)}]});
	}
}	



int main(){
	ios::sync_with_stdio(false);
	int row,col,dummy;
	cin>>col>>row;
	
	
	//pointer to 2D array
	int **A= new int*[row];
	
	//pointer initialisation
	for(int i=0;i<row;i++){
		A[i]=new int[col];
	}
	
	//initialise matrix storing the values of chocolate pieces
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			cin>>dummy;
			A[i][j]=dummy;
		}
	}
	
	
	
	//code to solve the problem
	//find the best sum for each element in the top row
	int maxSum=0; int interim;
	for (int k=0;k<col;k++){
		interim=dynProg(A,row-1,k,col);
		if (interim>maxSum){maxSum=interim;}
	}
	
	cout<<maxSum<<endl;
	/*
	cout<<"memo table output:"<<endl;
	pair<int,int> help;
	for(auto& el: memo){
		help=el.first;
		cout<<help.first<<" "<<help.second<<" "<<el.second<<endl;
	}
	
	
	//matrix output
	
	cout<<"matrix output: "<<endl;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			
			cout<< chocolate[i][j]<< " ";
		}
		cout<<endl;
	}*/
		
	return 0;
}
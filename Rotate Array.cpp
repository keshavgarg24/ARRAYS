You are given a square matrix ‘Mat’ of size ‘N’. You need to rotate ‘Mat’ by 90 degrees in the clockwise direction.

1) Brute approach 
it includes declaring an empty array and mapping it with the actual array to get the results 

2) Optimal approach

Code 


#include<vector>

void rotateMatrix(vector<vector<int>> &mat){
	int n = mat.size();
	// transpsoing the matrix 
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			swap(mat[i][j], mat[j][i]);
		}
	}

	// reversing every row 
	for(int i = 0; i < n; i++){
		reverse(mat[i].begin(), mat[i].end());
	}
}





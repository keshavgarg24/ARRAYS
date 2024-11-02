Problem statement
You are given a matrix 'MATRIX' of dimension 'N' x 'M'. Your task is to make all the elements of row 'i' and column 'j' equal to 0 if any element in the ith row or jth column of the matrix is 0.
Note:
1) The number of rows should be at least 1.
2) The number of columns should be at least 1.

1) Brute Approach - We will iterrate over the matrix and mark all the rows of element zeros as -1 ands then in another iteration , we will mark all the -1 as 0 

Code 


#include <bits/stdc++.h> 
using namespace std;

void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    for(int j = 0; j < m; j++) {
        if(matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    for(int i = 0; i < n; i++) {
        if(matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Replace all -1s with 0
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

2) Better approach _ we will take row array and column array and mark them and using mark them in the actual matrix after marking the arrays 

Code 

#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	int col[m] = {0};
	int row[n] = {0};
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(matrix[i][j] == 0){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if( row[i] || col[j]){
				matrix[i][j] = 0;
			}
		}
	}
	return matrix;
}


3) Optimal Approach 





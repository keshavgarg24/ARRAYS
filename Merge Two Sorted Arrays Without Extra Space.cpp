Problem statement
Given two non-decreasing sorted arrays, ‘A’ and ‘B’, having ‘N’ and ‘M’ elements, respectively.

You must merge these arrays, ‘A’ and ‘B’, into a sorted array without using extra space. Of all the 'N + M' sorted elements, array 'A' should contain the first 'N' elements, and array 'B' should have the last 'M' elements.

Note:
You must perform the merge operation in place and must not allocate any extra space to merge the two arrays.
For example:
When ‘N’ = 4, ‘A’ = {1, 4, 5, 7} and ‘M’ = 3, ‘B’ = {2, 3, 6}. 
We can merge these two arrays into {1, 2, 3, 4, 5, 6, 7} (The elements of ‘A’ are {1, 2, 3, 4} ).
Hence, the answer is {1, 2, 3, 4, 5, 6, 7}.


1) Brute - We will take two pointers and put them in another third arrays and then put them back in the two arrays 

Code 

#include<vector>

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size();
	int m = b.size();
	vector<long long> c;
	int left = 0;
	int right = 0;
	int ind = 0;
	while(left < n && right < m){
		if(a[left] <= b[right]){
			c[ind] = a[left];
			left++;
			ind++;
		}
		else{
			c[ind] = b[right];
			right++;
			ind++;
		}
	}
	while(left<n){
		c[ind] = a[left];
			left++;
			ind++;
	}
	while(right<m){
		c[ind] = b[right];
			right++;
			ind++;
	}

	for(int i = 0; i< n+m; i++){
		if(i<n){
			a[i] = c[i];
		}
		else{
			b[i-n] = c[i];
		}
	}
}


2) Optimal - We sawp the smallest element of the second array with the largest element of the first array and then sort them individually 

Code 

#include <bits/stdc++.h>
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	int n = a.size();
	int m = b.size();
	int left = n-1;
	int right = 0;
	while( left>=0 && right<m){
		if(a[left] > b[right]){
			swap(a[left], b[right]);
			left--;
			right++;
		}
		else{
			break;
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
}








Problem statement
You are given an array 'a' of 'n' integers.
A majority element in the array ‘a’ is an element that appears more than 'n' / 2 times.
Find the majority element of the array.
It is guaranteed that the array 'a' always has a majority element.

1) Brute Approach - taking count of each element in the array 

Code 
int arr;
int n = arr.size():
for(int i = o ; i <n; i++){
  int cnt = 0;
  for(int j = 0; j<n; j++){
    if(arr[i] == arr[j]){
      cnt++;}
    if (cnt > n/2) return arr[i]
  }
return -1;}

2) Better approach - hashing 

Code 
#include<bits/stdc++.h>
int majorityElement(vector<int> v) {
	int n = v.size();
	map<int,int> mpp;
	for(int i = 0; i<n; i++){
		mpp[v[i]]++;
	}
	for(auto it:mpp){
		if(it.second > n/2){
			return it.first;
		}
	}
	return -1;
}

3) Optimal Approach 

Code 
int majorityElement(vector<int> v) {
	// MOORE'S VOTING ALGORITHM
	int n = v.size();
	int el;
	int cnt = 0;
	for(int i = 0; i<n; i++){
		if(cnt == 0){
			cnt = 1;
			el = v[i];
		}
		else if(v[i] == el){
			cnt++;
		}
		else{
			cnt--;
		}
	}
	// FOR VERIFICATION IF THE ELEMENT FOUND IS MAXIMUM COUNT OR NOT 
	int ans = 0;
	for(int i = 0; i<n; i++){
		if(v[i] == el) ans++;
	}
	if(ans > n/2){
		return el;
	}
	return -1;
}

// EXPLANATION 
First for loop (Finding a candidate for the majority element): This loop uses Moore's Voting Algorithm to find a candidate for the majority element. Here's how it works:
The variable cnt keeps track of a "vote count" for the current element el (candidate).
Initially, cnt = 0, so the algorithm assumes the first element v[0] as a candidate (el = v[0]).
For each subsequent element in the vector:
If the vote count (cnt) is 0, the algorithm switches the candidate to the current element (v[i]).
If the current element is the same as the candidate (v[i] == el), the vote count (cnt) is incremented.
If the current element is different from the candidate (v[i] != el), the vote count is decremented.
The key idea here is that the algorithm reduces the count when it encounters elements that differ from the candidate, thus "canceling out" non-majority elements.

Second for loop (Verifying the candidate): After the first loop, the candidate el might not necessarily be the majority element (i.e., it could be the most frequent element but still not appear more than n / 2 times). To confirm whether the candidate is indeed the majority element:
A second loop counts how many times the candidate el appears in the vector.
If the count of occurrences (ans) is greater than n / 2, it means the candidate is the majority element, so it returns el.
If the count is not greater than n / 2, it returns -1, indicating that there is no majority element.





    

  

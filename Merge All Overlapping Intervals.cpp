Ninja is playing with intervals. He has an array of intervals called ‘Arr’ having ‘N’ intervals.

However, he doesn’t like overlapping intervals. So you must help Ninja by merging all the overlapping intervals in ‘Arr’ and return an array of non-overlapping intervals.


1) Brute - Sort the intervals and then check for the last element of the intervals if it is the part of the next interval , broaden the currnet interval 

Code 

#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	int n = arr.size();
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	for(int i = 0; i<n; i++){
		int start = arr[i][0];
		int end = arr[i][1];

		if(!ans.empty() && end<=ans.back()[1]){
			continue;
		}

		for(int j = i+1; j<n; j++){
			if(end >= arr[j][0]){
				end = max(end, arr[j][1]);
			}
			else{
				break;
			}
		}
        ans.push_back({start, end});
        }
	return ans;
}


2) Optimal - We try to do it in a single iteration by just initialsising a new interval when the number of next interval first element is greater than the previous one last element

Code 

#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	int n = arr.size();
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	for(int i = 0; i<n; i++){
		if(ans.empty() || arr[i][0] > ans.back()[1]){
			ans.push_back(arr[i]);
		}
		else{
			ans.back()[1] = max(ans.back()[1], arr[i][1]);
		}
    }
	return ans;
}





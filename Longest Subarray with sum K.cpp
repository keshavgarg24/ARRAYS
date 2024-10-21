 1) Longest Subarray With Sum K - The array conatins only positive elements and or zeros 
Approach - using a sliding window approach where we use two pointers to find the sum by shifting both th epointers forward when required.

Code 
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();
    int right = 0; int left = 0;
    long long sum = a[0];
    int maxLen = 0;
    while(right<n){
        while(left<=right && sum>k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right-left+1);
        }
        right++; //you were initially on the 0th index , so you will first have to move to the right and then add to the sum 
        if(right<n) sum += a[right];
    }  
    return maxLen;  

2) the array contain both positive and negative elements 
Approach - We use map and  iterate over the array and add the elemenst to find the sum , if the desried sum is found we return the maxLen 
and thewe find if the aarray has remaing sum equal to the sum if it does exist we return the len 

map_name.find(value)-> This function returns an iterator to the element with the key `value` if it is present in the map. If the key is not found, it returns an iterator to `map_name.end()`.
map_name.end()-> This function returns an iterator one past the last element of the map. If your map has a size of 4 (indexing from 0 to 3), `map_name.end()` will give you an iterator representing index 4, which is beyond the last element.
if(map.find(value) != map.end())-> This line was a real pain in my ass so basically this line checks whether the key `value` is present in the map. If `map.find(value)` does not equal `map.end()`, it means the key is found in the map.similarly , if `map.find(value)` equals `map.end()`, the key is not present in the map.

Code 
#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    map<int, int> summedMap;
    int n = nums.size();
    int sum = 0;
    int maxLen = 0;
    for(int i = 0; i<n; i++){
        sum += nums[i];
        if(sum == k){
            maxLen = max(maxLen, i+1); // zero based indexing 
        }
        int remSum = sum - k;
        if(summedMap.find(remSum) != summedMap.end()){ // if it finds the remaining sum in the array , it returns 1
            int len = i - summedMap[remSum];
            maxLen = max(maxLen, len);
        }
        if(summedMap.find(sum) == summedMap.end()){
            summedMap[sum] = i;
        }
    }
    return maxLen;
}





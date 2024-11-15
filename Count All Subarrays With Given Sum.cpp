roblem statement
You are given an integer array 'arr' of size 'N' and an integer 'K'.
Your task is to find the total number of subarrays of the given array whose sum of elements is equal to k.
A subarray is defined as a contiguous block of elements in the array.
Example:
Input: ‘N’ = 4, ‘arr’ = [3, 1, 2, 4], 'K' = 6

Output: 2

1) Brute - find all teh subrray and compare the sume using three nested for loops 

Code 



int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int sum = 0;
            for(int k = i; k <= j; k++){
                sum = sum + arr[k];
            }
            if(sum == k){
                cnt++;
            }
        }
    }
    return cnt;
}


2) better - we do not need to accumulate the whole for calculating sum using third nested loop 

Code 


int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += arr[j];
            if(sum == k){
                cnt++;
            }
        }
    }
    return cnt;
}


3) Optimal - We use prefixSum and use a hashmap to store prefixsum as key and its count as value

Code 


int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    unordered_map<int,int> mpp;
    mpp[0] = 1;
    int n = arr.size();
    int preSum = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        preSum += arr[i];
        int rem = preSum - k;
        cnt += mpp[rem];
        mpp[preSum] += 1;
    }
    return cnt;
}













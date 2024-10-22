1) Brute Approach - finding all the subarrays 

Code
int maxSumSubarray(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;  // Initialize to the smallest possible value
    
    // First loop to set the starting point of the subarray
    for (int i = 0; i < n; i++) {
        // Second loop to set the ending point of the subarray
        for (int j = i; j < n; j++) {
            int currentSum = 0;
            // Third loop to calculate the sum of subarray from index i to j
            for (int k = i; k <= j; k++) {
                currentSum += arr[k];
            }
            // Update maxSum if currentSum is larger
            maxSum = max(maxSum, currentSum);
        }
    }
    
    return maxSum;
} 


2) Better Approach - No need to check for each of the sum 

Code 
int maxSumSubarray(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;  // Initialize to the smallest possible value
    
    // Outer loop for the starting point of the subarray
    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        // Inner loop for the ending point of the subarray
        for (int j = i; j < n; j++) {
            currentSum += arr[j];  // Calculate sum of the subarray from i to j
            maxSum = max(maxSum, currentSum);  // Update maxSum if currentSum is larger
        }
    }
    
    return maxSum;
}


3) Optimal Approach -   KADANE'S ALGORITHM

  Code 
  long long maxSubarraySum(vector<int> arr, int n)
{
    long long sum = 0, maxi = LONG_MIN;
    for(int i = 0; i<n; i++){
        sum += arr[i];

        if(sum > maxi){
            maxi = sum;
        }
        else if(sum<0){
            sum = 0;
        }
    }
    if(maxi < 0){
        maxi = 0;
    }
    return maxi;
}


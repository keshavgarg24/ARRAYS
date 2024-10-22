Problem statement
There is an array ‘A’ of size ‘N’ with an equal number of positive and negative elements.
Without altering the relative order of positive and negative numbers, you must return an array of alternative positive and negative values.
Note:
Start the array with a positive number. 

1) Brute Approach 

Code
vector<int> alternateNumbers(vector<int>&a) {
    int n = a.size();
    vector<int> posi;
    vector<int> nega;
    vector<int> res;
    for(int num : a){
        if(num > 0){
            posi.push_back(num);
        }
        else{
            nega.push_back(num);
        }
    }
    for(int i = 0; i < n/2; i++){
        res.push_back(posi[i]);
        res.push_back(nega[i]);
    }
    return res;
}

2) Optimal Approach - with O(N) time complexity and O(N) space 

Code 
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      int n = nums.size(); 
      vector<int> ans(n, 0);
      int posi = 0;
      int negi = 1;
      for(int i = 0; i<n; i++){
        if(nums[i] > 0){
            ans[posi] = nums[i];
            posi += 2;
        }
        else{
            ans[negi] = nums[i];
            negi += 2;
        }
      } 
      return ans;
    }
};



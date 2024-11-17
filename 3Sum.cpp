Problem statement
You are given an array ‘ARR’ containing ‘N’ integers.

Return all the unique triplets [ARR[i], ARR[j], ARR[k]] such that i != j, j != k and k != i and their sum is equal to zero.

Example:
Input: ‘N’ = 5 
'ARR' =  [-1, -1, 2, 0, 1] 

Output: 
-1 -1 2
-1 0 1


1) Brute - USing three nested for loops , we will find all the triplets and store the unqiue triplets in a list 

Code 

#include<bits/stdc++.h> 
vector<vector<int>> triplet(int n, vector<int> &arr)
{
   set<vector<int>> st;
   for(int i = 0; i<n; i++){
       for(int j = i+1; j<n; j++){
           for(int k = j+1; k<n; k++){
               if(arr[i] + arr[j] + arr[k] == 0){
                   vector<int> temp = {arr[i], arr[j], arr[k]};
                   sort(temp.begin(), temp.end());
                   st.insert(temp);
               }
           }
       }
   }
   vector<vector<int>> ans(st.begin(), st.end());
   return ans;
}



2) Better - using a hashmap to store the value of third element istead of using the third fpr loop 

Code 

#include <bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
   set<vector<int>> st;
   for(int i = 0; i<n; i++){
       set<int> hashset;
       for(int j = i+1; j<n; j++){
           int third = - (arr[i] + arr[j]);
           if(hashset.find(third) != hashset.end()){
               vector<int> temp = {arr[i], arr[j], third};
               sort(temp.begin(), temp.end());
               st.insert(temp);
           }
           hashset.insert(arr[j]);
       }
   }
   vector<vector<int>> ans(st.begin(), st.end());
   return ans;
}


3) Optimal - We sort the arrays first and use a two ppointer approach and move them such that no two elements are taken same in one itertion 

Code 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++){
            if( i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0){
                    j++;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        } 
        return ans;
    }
};







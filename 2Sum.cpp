We have to return if there exist two elemest whose sum is equal to the target elemet and if yes , return their indexes 

1) Brute approach 
 We would check for each element to find the sum and this would also be checked for eahc element

Code
int arr = [];
int target;
int n = arr.size();
for(int i = 0; i < n; i++)
  for(int j = i+1; j < n; j++)
    if(arr[i] + arr[j] == target)
      return i,j;
    else
      return -1;

2) Better Approach 
  using hashmaps to store the key as numbers and value as indexes and check fot the remianing number required to from target at each 
 number from the hashmap 

Code 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int num = nums[i];
            int more = target - num;
            if(mpp.find(more) != mpp.end()){
                return {mpp[more], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};

3) Optimal Approach
  This approach uses Two poiters approach i.e. greedy approach and it is used when we cannot use hashmaps , it has almost the same 
time complexity as the better aproach but it takes more space to return the indexes because we first have to store the indexes.

  Code 
  string read(int n, vector<int> book, int target)
{
   int left = 0;
   int right = n-1;
   sort(book.begin(), book.end());
   while(left<right){
       int sum = book[left] + book[right];
       if(sum == target){
           return "YES";
       }
       else if(sum < target) left++;
       else right--;
   } 
   return "NO";
}

    


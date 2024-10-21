1) The brute approach would consider using a sorting algo like merge sort which uses O(NlogN) time compelexity and an extra space 
of O(N)

2) The Better approach whould consider single iteration and taking count of each of elemenst and than manually overwriting the 
elements in the arrays by running the three loops till their counts. 
  it takes O(2N) time complexity 

Code 
#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    int cnt1=0, cnt2=0, cnt3 = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] == 0) cnt1++;
        else if(arr[i] == 1) cnt2++;
        else cnt3++;
    }
    for(int i = 0; i<cnt1; i++) arr[i]=0;
    for(int i = cnt1; i<cnt1+cnt2; i++) arr[i]=1;
    for(int i = cnt1+cnt2; i<n; i++) arr[i]=2;
}

3) Optimal Approach - DUTCH NATIONAL FLAG ALGO ( uses three pointers )
  
  Code 
  #include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}


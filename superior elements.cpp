Problem statement
There is an integer array ‘a’ of size ‘n’.
An element is called a Superior Element if it is greater than all the elements present to its right
You must return an array all Superior Elements in the array ‘a’.
Note:
The last element of the array is always a Superior Element. 
Example
Input: a = [1, 2, 3, 2], n = 4
Output: 2 3

1) Brute approach - ysing two for loops 

Code 

vector<int> superiorElements(vector<int>&a) {
    vector<int> ans;
    int n = a.size();
    for(int i = 0; i<n; i++){
        bool leader = true;
        for(int j = i+1; j<n; j++){
            if(a[i] <= a[j]){
                leader = false;
                break;
            }
        }
        if(leader == true){
            ans.push_back(a[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

2) Optimal approach - We will comapre the current element with max element for the rest of the elements only 

Code 

vector<int> superiorElements(vector<int>&a) {
    vector<int> ans;
    int n = a.size();
    int maxi = INT_MIN;
    for(int i = n-1; i>=0; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }
    return ans;
}


Problem statement
There is an integer array ‘A’ of size ‘N’.
A sequence is successive when the adjacent elements of the sequence have a difference of 1.
You must return the length of the longest successive sequence.
Note:
You can reorder the array to form a sequence. 

1) Brute Force - It includes using two for loops to store and keep track of it 


2) Better Approach - We first sort the array and then keep track of the last smaller indexes 

Code 

int longestSuccessiveElements(vector<int>&a) {
   sort(a.begin(), a.end());
   int n = a.size();
   int maxi = 1;
   int last = INT_MIN;
   int cnt = 0;
   for(int i = 0; i<n; i++){
       if(a[i] - 1 == last){
           cnt += 1;
           last = a[i];
       }
       else if(last != a[i]){
           cnt = 1;
           last = a[i];
       }
       maxi = max(maxi, cnt);
    }
    return maxi;
}


3) Better Approach - we use unoreder set 

Code 

int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    if(n == 0) return 0;
    int maxi = 1;
    unordered_set<int> st;
    for(int i = 0; i<n ; i++){
        st.insert(a[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){ // if the previous i.e. last element does not exist , it starts counting 
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){ // if the next element is found
                cnt = cnt + 1;
                x = x + 1; // we move to next elements and increase count till the sequence is maintained 
            }
            maxi = max(maxi, cnt);
        }
    }
    return maxi;
}







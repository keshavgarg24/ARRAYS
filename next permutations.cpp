Problem statement
You are given an array ‘a’ of ‘n’ integers.
You have to return the lexicographically next to greater permutation.
Note:
If such a sequence is impossible, it must be rearranged in the lowest possible order.
Example:
Input: 'a' = [1, 3, 2]
Output: 2 1 3
Explanation: All the permutations of [1, 2, 3] are [[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1], ]. Hence the next greater permutation of [1, 3, 2] is [2, 1, 3].


Code 

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size();
    int ind = -1;
    for(int i = n-2; i>=0; i--){
        if(A[i] < A[i+1]){
            ind = i; // finding the index at which there is a break point
            break;
        }
    }
    if( ind == -1){
        reverse(A.begin(), A.end());
        return A; // edge case when the permutation is the last possible
    }
    for(int i = n-1; i>ind; i--){
        if(A[i] > A[ind]){
            swap(A[ind], A[i]); // swapping the just bigger element with the index element 
            break;
        }
    }
    reverse(A.begin() + ind + 1, A.end()); // placing the rest elements in decreasing order 
    return A;
}

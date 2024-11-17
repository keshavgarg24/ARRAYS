Problem statement
Given an array ‘A’ of ‘N’ integers, find the majority elements of the array.
A majority element in an array ‘A’ of size ‘N’ is an element that appears more than floor(N / 3) times.
Note: The floor function returns the number rounded down to the nearest integer.
Note: Return the array of majority elements in sorted order.
Example:
Input: ‘N’ = 9 ‘A’ = [2, 2, 1, 3, 1, 1, 3, 1, 1]

Output: 1


1) Brute 

Code 

std::vector<int> majorityElement(std::vector<int> v) {
    int n = v.size();
    std::list<int> ls; // Use std::list to temporarily store elements

    for (int i = 0; i < n; i++) {
        // Check if the list is empty or does not contain the current element
        if (ls.empty() || ls.front() != v[i]) {
            int cnt = 0; // Initialize cnt inside the loop
            for (int j = 0; j < n; j++) {
                if (v[i] == v[j]) {
                    cnt++;
                }
            }
            if (cnt > floor(n / 3)) {
                ls.push_back(v[i]); // Add element to the list
            }
        }
    }

    // Convert the list to a vector before returning
    std::vector<int> result(ls.begin(), ls.end());
    return result;
}


2) Better - We use a hashmap to store the number and count as key and value and the number is added in the answer list as soon as its count is equal to n/3 times 

Code 

vector<int> majorityElement(vector<int> v) {
  int n = v.size();
  vector<int> ls;
  map<int, int> mpp;
  int mine = (int)(n / 3) + 1;

  for (int i = 0; i < n; i++){
	  mpp[v[i]] ++;
	  if(mpp[v[i]] == mine){
		  ls.push_back(v[i]);
	  }
	  if(ls.size() == 2) break;
   }
   sort(ls.begin(), ls.end());
   return ls;
}


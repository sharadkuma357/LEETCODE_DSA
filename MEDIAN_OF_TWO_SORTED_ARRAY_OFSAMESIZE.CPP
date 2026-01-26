// C++ Code to find Median of two Sorted Arrays of 
// Same Size using Sorting

#include <bits/stdc++.h>
using namespace std;

// Function to find the median of two sorted arrays of equal size
double getMedian(vector<int>& a, vector<int>& b) {
  
    // Concatenate
    vector<int> c(a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    // Sort the concatenated array
    sort(c.begin(), c.end());
    
    // Calculate and return the median
    int n = c.size();
  	
    int mid1 = n / 2;
    int mid2 = mid1 - 1;
	return (c[mid1] + c[mid2]) / 2.0;
}

int main() {
    vector<int> a = { 1, 12, 15, 26, 38 };
    vector<int> b = { 2, 13, 17, 30, 45 };

    cout << getMedian(a, b) << endl;
    return 0;
}

// CONCATENATE THE TWO ARRAY AND USE SORTING 

// --------------------------------------------
// C++ Code to find Median of two Sorted Arrays of 
// Same Size using Merge of Merge Sort

#include <bits/stdc++.h>
using namespace std;

// Function to find the median of two sorted arrays 
// of equal size
float getMedian(vector<int>& a, vector<int>& b) {
  	
  	int n = a.size();
    int i = 0, j = 0;
    int count;
  
    // m1 to store element at index n of merged array
    // m2 to store element at index (n - 1) of merged array
    int m1 = -1, m2 = -1;

    // Loop till n
    for (count = 0; count <= n; count++) {
        m2 = m1;
      
        // If both the arrays have remaining elements
        if (i < n && j < n) {
            if (a[i] > b[j])
                m1 = b[j++];
            else
                m1 = a[i++];
        }
        else if (i < n)
            m1 = a[i++];

        else 
            m1 = b[j++];
    }

    return (m1 + m2) / 2.0;
}

int main() {
    vector<int> a = { 1, 12, 15, 26, 38 };
    vector<int> b = { 2, 13, 17, 30, 45 };

    cout << getMedian(a, b) << endl;
    return 0;
}

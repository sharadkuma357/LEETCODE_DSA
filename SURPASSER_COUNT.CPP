#include <iostream>
#include <vector>
using namespace std;

vector<int> findSurpasser(vector<int> &arr) {
    int n = arr.size();
    // array to store surpasser counts
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        // Find surpasser for arr[i]
        int count = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i])
                count++;
        }
       
        res[i] = count; 
    }
    return res;
}

int main() {
    vector<int> arr = {2, 7, 5, 3, 8, 1};
    vector<int> res = findSurpasser(arr);    
    for (int count : res) 
        cout << count << " ";
  
    return 0;
}
// ITERATE OVER THE ARRAY FOR I,J 
// IF(I<J &&ARR[I]<ARR[J]):COUNT++
// STORE COUNT IN RESULT ARRAY FOR EVERY ELE 
// RETURN RES.
// ----------------------------------------------

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Merge function to sort the array and update surpasser counts
int merge(vector<int> &arr, int lo, int mid, int hi, 
                            unordered_map<int, int> &m) {
  
    int n1 = mid - lo + 1;
    int n2 = hi - mid;
    vector<int> left(n1), right(n2); 
    
    // Copy data into temporary arrays left[] and right[]
    for (int i = 0; i < n1; i++)
        left[i] = arr[lo + i]; 
        
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j]; 

    int i = 0, j = 0, k = lo;
    
    // Merging two halves
    while (i < n1 && j < n2) {
      
        // All elements in right[j..n2] are greater than left[i]
        // So add n2 - j, in surpasser count of left[i]
        if (left[i] < right[j]) {
            m[left[i]] += n2 - j;  
            arr[k++] = left[i++];
        } 
        else {
            arr[k++] = right[j++];
        }
    }

    // Copy remaining elements of left[] if any
    while (i < n1)
        arr[k++] = left[i++];

    // Copy remaining elements of right[] if any
    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(vector<int> &arr, int lo, int hi, 
               unordered_map<int, int> &m) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        
        // Sort left and right half
        mergeSort(arr, lo, mid, m); 
        mergeSort(arr, mid + 1, hi, m);
        
        // Merge them
        merge(arr, lo, mid, hi, m);  
    }
}

vector<int> findSurpasser(vector<int>& arr) {
    int n = arr.size();
    
    // Map to store surpasser counts
    unordered_map<int, int> m;
    
    // Duplicate array to perform merge Sort
    // so that orginial array is not modified
    vector<int> dup = arr;  

    mergeSort(dup, 0, n - 1, m);  

    // Store surpasser counts in result array
    // in the same order as given array
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = m[arr[i]]; 
    
    return res;
}

int main() {
    vector<int> arr = {2, 7, 5, 3, 8, 1};
    vector<int> res = findSurpasser(arr);  
    for (int count : res)
        cout << count << " ";
    return 0;
}

// A HASHMAP IS CREATED AND MERGESORT FUNCTION IS USED 
// ALL ARRAY ELEMENT IS BROKEN DOWN AND MERGED 
// DURING THIS MERGING PROCESS HASHMAP KEEP COUNT OF ALL SURPASSER ELEMENT 
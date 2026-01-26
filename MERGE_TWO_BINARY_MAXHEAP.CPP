// C++ Program to merge two binary max heaps

#include <bits/stdc++.h>
using namespace std;

// function to merge max heaps
vector<int> mergeHeaps(vector<int>& a, vector<int>& b,
                       int n, int m)
{
    // Max Heap to store all the elements
    priority_queue<int> maxHeap;

    // Insert all the elements of first array
    for (int i = 0; i < n; i++) {
        maxHeap.push(a[i]);
    }

    // Insert all the elements of second array
    for (int i = 0; i < m; i++) {
        maxHeap.push(b[i]);
    }

    vector<int> merged;
    // Push all the elements from the max heap
    while (!maxHeap.empty()) {
        merged.push_back(maxHeap.top());
        maxHeap.pop();
    }
    return merged;
}

int main()
{
    // Sample Input
    vector<int> a = { 10, 5, 6, 2 };
    vector<int> b = { 12, 7, 9 };
    int n = a.size(), m = b.size();

    vector<int> merged = mergeHeaps(a, b, n, m);

    for (int i = 0; i < n + m; i++)
        cout << merged[i] << " ";
    return 0;
}

// CREATE A MAX HEAP AND ADD ALL ELEMENT IN THE MAX HEAP THEN GET IT IN VECTOR

// --------------------------------------------------------------------------------

// C++ program to merge two max heaps

#include <bits/stdc++.h>
using namespace std;

// Standard heapify function to heapify a
// subtree rooted under idx. It assumes
// that subtrees of node are already heapified.
void maxHeapify(vector<int>& arr, int n, int idx)
{
    // Find largest of node and its children
    if (idx >= n)
        return;

    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int max = idx;
    if (l < n && arr[l] > arr[idx])
        max = l;
    if (r < n && arr[r] > arr[max])
        max = r;

    // Put maximum value at root and
    // recur for the child with the
    // maximum value
    if (max != idx) {
        swap(arr[max], arr[idx]);
        maxHeapify(arr, n, max);
    }
}

// Builds a max heap of given arr[0..n-1]
void buildMaxHeap(vector<int>& arr, int n)
{
    // building the heap from first non-leaf
    // node by calling max heapify function
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Merges max heaps a[] and b[] into merged[]
vector<int> mergeHeaps(vector<int>& a, vector<int>& b,
                       int n, int m)
{
    // Copy elements of a[] and b[] one by one
    // to merged[]
    vector<int> merged(n + m, 0);
    for (int i = 0; i < n; i++)
        merged[i] = a[i];
    for (int i = 0; i < m; i++)
        merged[n + i] = b[i];

    // build heap for the modified array of
    // size n+m
    buildMaxHeap(merged, n + m);
    return merged;
}

// Driver's code
int main()
{
    // Sample Input
    vector<int> a = { 10, 5, 6, 2 };
    vector<int> b = { 12, 7, 9 };

    int n = a.size();
    int m = b.size();

    // Function call
    vector<int> merged = mergeHeaps(a, b, n, m);

    for (int i = 0; i < n + m; i++)
        cout << merged[i] << " ";

    return 0;
}
// BUILD AN VECTOR AND ADD ALL ELEMENT IN VECTOR 
// BUILD A MAX HEAP AND GET ELEMENT IN RES VECTOR 
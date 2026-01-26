#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>   

using namespace std;

int sumBetween(vector<int>& arr, int k1, int k2)
{
    // Sort the vector
    sort(arr.begin(), arr.end());

    // Sum elements between k1-th and k2-th smallest
    return accumulate(arr.begin() + k1, arr.begin() + k2 - 1, 0);
}

// Driver program
int main()
{
    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    int k1 = 3, k2 = 6;

    cout << sumBetween(arr, k1, k2);

    return 0;
}

// SORT AND GET ELEMENT BY INDEX

// -------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void minheapify(vector<int>& a, int index, int heapSize)
{
    int small = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    if (l < heapSize && a[l] < a[small])
        small = l;

    if (r < heapSize && a[r] < a[small])
        small = r;

    if (small != index) {
        swap(a[small], a[index]);
        minheapify(a, small, heapSize);
    }
}

int sumBetweenK1K2(vector<int>& arr, int k1, int k2)
{
    int heapSize = arr.size();
    int ans = 0;

    // Build the min-heap
    for (int i = (heapSize / 2) - 1; i >= 0; i--) {
        minheapify(arr, i, heapSize);
    }

    // Adjust for 0-based indexing
    k1--;
    k2--;

    // Step 1: Extract minimum k1 times (skip these elements)
    for (int i = 0; i <= k1; i++) {
        arr[0] = arr[heapSize - 1];
        heapSize--;
        minheapify(arr, 0, heapSize);
    }


    for (int i = k1 + 1; i < k2; i++) {
        ans += arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        minheapify(arr, 0, heapSize);
    }

    return ans;
}

// Driver function
int main()
{
    vector<int> arr = {20, 8, 22, 4, 12, 10, 14};
    int k1 = 3, k2 = 6;

    cout << sumBetweenK1K2(arr, k1, k2);

    return 0;
}

// CREATE A MIN HEAP OF SIZE K1 AND K2 AND GET ELEMENT

// ----------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
long long sumBetweenTwoKth(long long A[], long long N,
                           long long K1, long long K2)
{
    // Using max heap to find K1'th and K2'th smallest
    // elements
    priority_queue<long long> maxH;

    // Using this for loop we eliminate the extra elements
    // which are greater than K2'th smallest element as they
    // are not required for us

    for (int i = 0; i < N; i++) {

        maxH.push(A[i]);

        if (maxH.size() > K2) {
            maxH.pop();
        }
    }
    // popping out the K2'th smallest element
    maxH.pop();

    long long ans = 0;
    while (maxH.size() > K1) {

        ans += maxH.top();
        maxH.pop();
    }

    return ans;
}

int main()
{
    long long arr[] = { 20, 8, 22, 4, 12, 10, 14 };
    long long k1 = 3, k2 = 6;
    long long n = sizeof(arr) / sizeof(arr[0]);
    cout << sumBetweenTwoKth(arr, n, k1, k2);
    return 0;
}
// CREATE A MAX HEAP AND ADD ELEMENT AND GET RESULT
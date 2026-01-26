#include <iostream>     
#include <vector>       
#include <algorithm>     
using namespace std;

int kthLargest(vector<int>& arr, int k) {

    int n = arr.size();

    vector<int> prefixSum(n + 1);
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    vector<int> subarraySums;
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            subarraySums.push_back(prefixSum[j] - prefixSum[i]);
        }
    }

    sort(subarraySums.begin(), subarraySums.end(),
         greater<int>());

    return subarraySums[k - 1];
}

int main() {
    vector<int> arr = {20, -5, -1};
    int k = 3;
    cout << kthLargest(arr, k);
    return 0;
}

// IN THIS prefixSum[j] - prefixSum[i] GIVES THE SUM OF ALL SUBSETS OF ARRAY.

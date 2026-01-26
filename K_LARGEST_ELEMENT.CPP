#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kthLargest(vector<int> &arr, int k) {
    int n = arr.size();

    
    vector<int> sums;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            sums.push_back(sum);
        }
    }

    sort(sums.begin(), sums.end(), greater<int>());

    
    return sums[k - 1];
}

int main() {
    vector<int> arr = {20, -5, -1};\
    int k = 3;
    cout << kthLargest(arr, k);
    return 0;
}

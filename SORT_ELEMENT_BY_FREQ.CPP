#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> sortByFreq(vector<int> &arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());//1

    vector<vector<int>> freq;

    auto comp = [&](vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    };//3

    for(int i = 0; i < n; i++) {//4

        int cnt = 1;
        while(i < n - 1 && arr[i] == arr[i + 1]) {
            cnt++;
            i++;
        }

        freq.push_back({cnt, arr[i]});
    }
    
    sort(freq.begin(), freq.end(), comp);//5

    vector<int> ans;

    for(int i = 0; i < freq.size(); i++) {//6
        for(int j = 0; j < freq[i][0]; j++) {
            ans.push_back(freq[i][1]);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {5, 5, 4, 6, 4};
    vector<int> ans = sortByFreq(arr);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}

//   USING SORTING(N*LOGN) AND O(N) 
// 2 IT TAKES THE SIZE OF ARRAY AND SORT IT ACCORDINGLY
// 3 COMP IS USED TO COMPARE THE ELEMENT COUNT IF IT IS SAME THEN LESS ELEMENT IS RETURNED
// 4 GET THE NUMBER OF COUNT AND PUSH IT WITH THE ELEMENT 
// 5 SORT THE FREQ WITH COMP FUNCTION
// 6 FREQ ELEMENT ARE PUSHED TO ANS VECTOR THE NUMBER OF TIMES COUNT IS STORED IN FREQ
#include <bits/stdc++.h>
using namespace std;

vector<int> sortByFreq(vector<int> &arr) {
    int n = arr.size();
    
    unordered_map<int, int> mp;
    
    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }//1

    vector<vector<int>> freq;//2
    
    auto comp = [&](vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    };

    for(auto i : mp) {
        freq.push_back({i.second, i.first});
    }//2
        
    sort(freq.begin(), freq.end(), comp);//3

    vector<int> ans;

    for(int i = 0; i < freq.size(); i++) {
        for(int j = 0; j < freq[i][0]; j++) {
            ans.push_back(freq[i][1]);
        }//4
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

//1 THE ARRAY IS PASSED TO THE HASHMAP AND IT IS ELEMENT AND FREQ IS NOTED
// 2A VECTOR IS CREATED AND ELE AND FREQ IS UPDATED
// 3SORT THE FREQ WITH COMP(MORE ELEMENT COUNT WILL BE FIRST THEN SMALLER ELEMENT ID PLACED)
// 4PUSHBACK ELEMENT OF FREQ NUMBER OF TIMES IN ANS VECTOR
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> mergeArrays(vector<vector<int>>& mat) {
    vector<int> res;

    for (const auto& vec : mat) {
        for (int val : vec)
            res.push_back(val);
    }

    sort(res.begin(), res.end());

    return res;
}

int main() {
    vector<vector<int>> mat = {{1, 3, 5, 7},
                              {2, 4, 6, 8}, 
                              {0, 9, 10, 11}};
                              
    vector<int> res = mergeArrays(mat);
    for (int val : res) {
        cout << val << " ";
    }

    return 0;
}

// EVERY ELEMEN OF MATRIX IS PUSHED INTO ARRAY AND THEN SORTED

#include <iostream>
#include <vector>
using namespace std;

vector<int> concat(vector<int> &a, vector<int> &b) {
    int i = 0, j = 0;
    int n1 = a.size(), n2 = b.size();
    vector<int> c;
    c.reserve(n1 + n2);

    while (i < n1 && j < n2) {
        if (a[i] < b[j])
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
    }

    // Add remaining elements of first array
    while (i < n1)
        c.push_back(a[i++]);

    // Add remaining elements of second array
    while (j < n2)
        c.push_back(b[j++]);

    return c;
}


vector<int> merge(vector<vector<int>> &mat, int lo, int hi) {
        
    if (lo == hi)
        return mat[lo];

    
    int mid = (lo + hi) / 2;
    
    vector<int> left = merge(mat, lo, mid);

    vector<int> right = merge(mat, mid + 1, hi);
    
    return concat(left, right);
}

vector<int> mergeArrays(vector<vector<int>> &mat) {
    int k = mat.size();
    if (k == 0)
        return {};
    return merge(mat, 0, k - 1);
}

int main() {
    
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {0, 9, 10, 11}
    };

    int k = mat.size();

    vector<int> res = mergeArrays(mat);

    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}
// USED MERGE SORT

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> mergeArrays(vector<vector<int>> &mat){
    int k = mat.size();
    
    vector<int> output;

    // Min-heap: {value, {array index, element index}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> minHeap;

    // Push first element of each array
    for (int i = 0; i < k; ++i){
        
        if (!mat[i].empty()){
            minHeap.push({mat[i][0], {i, 0}});
        }
    }

    // Merge all elements
    while (!minHeap.empty()){
        
        auto top = minHeap.top();
        minHeap.pop();

        int val = top.first;
        int i = top.second.first;
        int j = top.second.second;

        output.push_back(val);

        // Push next element from same array
        if (j + 1 < mat[i].size()){
            
            minHeap.push({mat[i][j + 1], {i, j + 1}});
        }
    }

    return output;
}

int main(){
    
    vector<vector<int>> mat= {{1, 3, 5, 7}, 
                               {2, 4, 6, 8},
                               {0, 9, 10, 11}};

    vector<int> result = mergeArrays(mat);
    for (int x : result){
        
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

//USED MIN HEAP
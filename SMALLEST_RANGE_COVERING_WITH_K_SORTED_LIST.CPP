#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> findSmallestRange(vector<vector<int>>& mat) {
    
    int k = mat.size();         
    int n = mat[0].size();   

    vector<int> ptr(k, 0);

    int minRange = INT_MAX;
    int start = -1, end = -1;

    while (true) {

        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        int minRow = -1;

        for (int i = 0; i < k; i++) {

            if (ptr[i] == n) {//1
                return {start, end};
            }

            if (mat[i][ptr[i]] < minVal) {//2
                minVal = mat[i][ptr[i]];
                minRow = i;
            }

            if (mat[i][ptr[i]] > maxVal) {//3
                maxVal = mat[i][ptr[i]];
            }
        }

        if (maxVal - minVal < minRange) {//4
            minRange = maxVal - minVal;
            start = minVal;
            end = maxVal;
        }

        ptr[minRow]++;
    }

    return {start, end};
}

int main() {

    vector<vector<int>>mat = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}
    };

    vector<int> res = findSmallestRange(mat);

    cout << res[0] << " " << res[1];

    return 0;
}

// IN THIS 2D MATRIX IS PASSED TO THE FUNCTION AND MATRIX SIZE AND ROW SIZE IS CALCULATED  
// VARIABLE ARE MADE MINVAL MAXVAL N RANGE THREE POINTER ARE MADE ON THREE ARRAY OF MATRIX 
// 1:CHECK FOR END CONDITION 
// 2:CHECK FOR LEAST VALUE 
// 3:CHECK FOR MAX VALUE
// 4:DIFFERENCE IS CALCULATED FOR EVALUATION WITH RANGE START AND END IS UPDATED
// FOR LOOP RUN FOR 3 TIMES FOR AMOUNT OF ROWS IN MATRIX


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


class Node {
public:
    int val, row, col;

    Node(int v, int r, int c) {
        val = v;
        row = r;
        col = c;
    }

    
    bool operator>(const Node& other) const {
        return val > other.val;
    }
};

vector<int> findSmallestRange(vector<vector<int>>& mat) {
    int N = mat.size();        
    int K = mat[0].size();   
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    int maxVal = INT_MIN;

    for (int i = 0; i < N; i++) {
        pq.push(Node(mat[i][0], i, 0));
        maxVal = max(maxVal, mat[i][0]);
    }

    int minRange = INT_MAX, minEl = 0, maxEl = 0;

    while (true) {
        Node curr = pq.top(); pq.pop();
        int minVal = curr.val;

        if (maxVal - minVal < minRange) {
            minRange = maxVal - minVal;
            minEl = minVal;
            maxEl = maxVal;
        }
        
        if (curr.col + 1 == K) break;

        int nextVal = mat[curr.row][curr.col + 1];
        pq.push(Node(nextVal, curr.row, curr.col + 1));
        maxVal = max(maxVal, nextVal);
    }

    return {minEl, maxEl};
}

int main() {
    vector<vector<int>> mat = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}
    };

    vector<int> result = findSmallestRange(mat);
    cout << result[0] << " " << result[1];

    return 0;
}

// IT TAKES FIRST ELEMENT OF EACH ARRAY AND PUT IT IN MINHEAP 
// MAXVAL IS CALCULATED
//  MIN VALUE IS CALCULATED FROM MINHEAP RANGE IS CALCULATED 
// NEXT ELEMENT IS PUSHED INTO MINHEAP AND LOOP CONTINUES.
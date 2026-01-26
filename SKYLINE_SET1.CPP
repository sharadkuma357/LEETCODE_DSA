#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> getSkyline(vector<vector<int>>& build) {
    vector<int> points;//3

    
    for (auto& b : build) {
        points.push_back(b[0]);
        points.push_back(b[1]);
    }//3

    //4
    sort(points.begin(), points.end());

    vector<pair<int, int>> res;
    int prev = 0;//5

    for (int x : points) {
        int maxH = 0;

        // Check which buildings cover the 
        // current x and get the max height
        for (auto& b : build) {
            int l = b[0], r = b[1], h = b[2];
            if (l <= x && x < r) {
                maxH = max(maxH, h);
            }
        }

        // Add to result if height has changed
        if (res.empty() || maxH != prev) {
            res.push_back({x, maxH});
            prev = maxH;
        }
    }

    return res;
}

int main() {
    vector<vector<int>> build = {
        {2, 9, 10},
        {3, 6, 15},
        {5, 12, 12}
    };//1

    vector<pair<int, int>> skyline = getSkyline(build);//2

    for (auto& p : skyline) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }

    cout << endl;
    return 0;
}

// 1 THE CODE TAKES THE VECTOR IN PASS IT IN FUNCTION WHICH 2 PASS IT IN VECTOR MEMORT IN NAME SKYLINE
// 3 THE VECTOR TAKES THE RIGHT AND LEFT CORDINATES AND PUSH IT INTO MEMORY SAPCE POINT VECTOR 
// 4 SORT ALL THE POINTS
// 5 CREATE A VECTOR RES N VARIBLE PREV
// 6 FOR EVERY POINT ITERATED WE ITERATE OVER BUILD POINT TO CHECK IF EACH POINT LYING BETWEEN LEFT AND RIGHT MAXHEIGHT THEN HEIGHT IS 
// UPDATED 
//7 IF RES IS EMPTY || MAXHEIGHT IS CHANGED : THEN ADD POINT AND HEIGHT TO RES PREV IS UPDATED.
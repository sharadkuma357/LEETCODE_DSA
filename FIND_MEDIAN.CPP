#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<double> getMedian(vector<int> &arr) {
    vector<double> res;

    res.push_back(arr[0]);

    for (int i = 1; i < arr.size(); i++) {
        int j = i - 1;
        int num = arr[i];

        while (j >= 0 && arr[j] > num) {//*
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num;
        
        int len = i + 1;
        double median;

        if (len % 2 != 0) {
            median = arr[len / 2];
        }
        else {
            median = (double)(arr[(len / 2) - 1] + arr[len / 2]) / 2;
        }

        res.push_back(median);
    }
    
    return res;
}

int main() {
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> res = getMedian(arr);
    cout << fixed << setprecision(2);
    
    for (double median: res) 
        cout << median << " ";
    return 0;
}

// FIRST ELEMENT IS PUSHED INTO ARRAY 
// NEXT ELEMENT IS INSERTED INTO CORRECT PLACE DUE TO * CODE
// MEDIAN IS PUSHED BACK TO RESULT
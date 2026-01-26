#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

vector<double> getMedian(vector<int> &arr) {
    
    // Max heap to store the smaller half of numbers
    priority_queue<int> leftMaxHeap;
    
    // Min heap to store the greater half of numbers
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    
    vector<double> res;
  
    for (int i = 0; i < arr.size(); i++) {
        
        // Insert new element into max heap
        leftMaxHeap.push(arr[i]);
        
        // Move the top of max heap to min heap to maintain order
        int temp = leftMaxHeap.top();
        leftMaxHeap.pop();
        rightMinHeap.push(temp);
      
        // Balance heaps if min heap has more elements
        if (rightMinHeap.size() > leftMaxHeap.size()) {
            temp = rightMinHeap.top();
            rightMinHeap.pop();
            leftMaxHeap.push(temp);
        }
        
        // Compute median based on heap sizes
        double median;
        
        if (leftMaxHeap.size() != rightMinHeap.size())
            median = leftMaxHeap.top();
        else
            median = (double)(leftMaxHeap.top() + rightMinHeap.top()) / 2;
        
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

// TWO HEAP ARE CREATED LEFTMAXHEAP AND RIGHTMINHEAP 
// FIRST ELEMENT IS PUSHED INTO LEFT HEAP 
// IF SIZE OF RIGHT HEAP IS GREATER THAN LEFT THEN IT IS ELE PASSED TO LEFT.
// IF SIZE OF BOTH HEAP EQUAL THEN MEDIAN IS MEAN OF BOTH 
// IF SIZE IS UNEQUAL THEN MAX ELEMENT TOP WILL HAVE MEDIAN.
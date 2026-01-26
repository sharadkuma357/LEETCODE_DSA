#include <bits/stdc++.h>
using namespace std;

void printLargest(vector<int> seq)
{
    int n = seq.size();
    vector<int> res(n); // Stores result

    // Insert all elements into a priority queue
    priority_queue<int> pq; 
    for (int i = 0; i < n; i++) 
        pq.push(seq[i]);    

    // Fill Up res[] from left to right
    for (int i = 0; i < n; i++) {
        int d = pq.top();
        pq.pop();
        if (d != seq[i] || i == n - 1) {
            res[i] = d;
        } else {

            // New Element popped equals the element 
            // in original sequence. Get the next
            // largest element
            res[i] = pq.top();
            pq.pop();
            pq.push(d);
        }
    }

    // If given sequence is in descending order then 
    // we need to swap last two elements again
    if (res[n - 1] == seq[n - 1]) {
        res[n - 1] = res[n - 2];
        res[n - 2] = seq[n - 1];
    }

    printf("\nLargest Derangement \n");
    for (int i = 0; i < n; i++) 
        printf("%d ", res[i]);
}

// Driver code
int main()
{
    vector<int> seq = { 92, 3, 52, 13, 2, 31, 1 }; 
    printLargest(seq);
    return 0;
}

// IT STATES THAT NO ELEMENT SHOULD BE AT SAME PLACE 
//  IF NEW ELEMENT IS NOT IN SEQUENCE OR AT LAST THEN INSERT IT IN RES VECTOR
// IF IT IS EQUAL TO SEQ VECTOR GET OTHER ELEMENT IN RES VECTOR AND PUSH D ELEMENT IN QUEUE
// IF LAST ELEMENT IS AT CORRECT PLACE THEN MISPLACE THE LAST TWO ELEMENT OF VECTOR
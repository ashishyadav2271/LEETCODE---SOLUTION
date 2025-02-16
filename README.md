






this is my second question on leetcode 
DAY 2
LEETCODE - 622 ( Design Circular Queue)
SOlution
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        q.resize(k);
        cnt=0;
        sz=k;
        headIdx=0;
    }
    bool enQueue(int value) {
        if(isFull())return false;
        q[(headIdx+cnt)%sz]=value;
        cnt+=1;
        return true;    
    }
    bool deQueue() {
         if(isEmpty())return false;
        headIdx=(headIdx+1)%sz;
        cnt -=1;
        return true;     
    }
    int Front() {
        if(isEmpty())return -1;
        return q[headIdx];
    }
    int Rear() {
        if(isEmpty())return -1;
        return q[(headIdx+cnt-1)%sz];
    }
    bool isEmpty() {
        return cnt==0;
    }
    bool isFull() {
        return cnt==sz;
    }
    private:
    int cnt,sz,headIdx;
    vector<int>q;
};
 Description about the solution 
 Circular Queue in C++ 🚀
This repository contains an efficient implementation of a circular queue using a fixed-size vector. The queue supports standard operations with O(1) time complexity for insertion, deletion, and access.

Features
✅ enQueue(int value) → Inserts an element (returns false if full).
✅ deQueue() → Removes the front element (returns false if empty).
✅ Front() → Returns the front element (-1 if empty).
✅ Rear() → Returns the last element (-1 if empty).
✅ isEmpty() / isFull() → Checks queue status.

Complexity Analysis
Time Complexity → O(1) for all operations.
Space Complexity → O(k), where k is the queue size.


this is my third question on leetcode 
DAY 3
LEETCODE - 3066 (Minimum Operation To Exceed Threshold Value II)
SOlution
class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        vector<int> b;
        for (int i = 0, j = 0, count = 0, x, y;; ++count) {
            if (i < a.size() && (j >= b.size() || a[i] <= b[j]))
                x = a[i++];
            else
                x = b[j++];
            if (x >= k)
                return count;
            if (i < a.size() && (j >= b.size() || a[i] <= b[j]))
                y = a[i++];
            else
                y = b[j++];
            long t = 2L * x + y; // test overflow
            b.push_back(t < k ? (int)t : k);
        }
        return -1;
    }
};
Description About The Problem
Title: Minimum Operations to Reach at Least K

Description:
This C++ solution finds the minimum number of operations required to ensure that the smallest element in the array is at least K. The approach involves:

Sorting the array to process elements in increasing order.
Using a priority queue-like merging technique with an auxiliary vector to generate new elements.
Repeatedly selecting the two smallest values, applying the formula 2 * x + y, and inserting the result back until the smallest element reaches K.
This ensures an optimal and efficient approach to solving the problem. 🚀

You can modify or expand the description as needed! Let me know if you need a README template for GitHub. 😊

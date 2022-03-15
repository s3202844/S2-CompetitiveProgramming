#include <iostream>
#include <stack>
#include <queue>
#include <exception>
#include <algorithm>

using namespace std;

int main() {
    int N;
    while (cin >> N) {
        bool isStack=true, isQueue=true, isPriorityQueue=true;
        stack<int> Stack;
        deque<int> Queue;
        priority_queue<int> PriorityQueue;
        while (N) {
            int a, b;
            cin >> a >> b;
            if (a == 1) {
                Stack.push(b);
                Queue.push_back(b);
                PriorityQueue.push(b);
            }
            else if (a == 2) {
                if (Stack.size() == 0) {
                    isStack = false;
                    isQueue = false;
                    isPriorityQueue = false;
                }
                else {
                    int c = Stack.top();
                    if (c!=b) {
                        isStack = false;
                    }
                    c = Queue.front();
                    if (c!=b) {
                        isQueue = false;
                    }
                    c = PriorityQueue.top();
                    if (c!=b) {
                        isPriorityQueue = false;
                    }
                    Stack.pop();
                    Queue.pop_front();
                    PriorityQueue.pop();
                }
            }
            if (!isStack && !isQueue && !isPriorityQueue) {
                break;
            }
            N--;
        }
        if (!isStack && !isQueue && !isPriorityQueue) {
            cout << "impossible" << endl;
        }
        else if (isStack && !isQueue && !isPriorityQueue) {
            cout << "stack" << endl;
        }
        else if (!isStack && isQueue && !isPriorityQueue) {
            cout << "queue" << endl;
        }
        else if (!isStack && !isQueue && isPriorityQueue) {
            cout << "priority queue" << endl;
        }
        else {
            cout << "not sure" << endl;
        }
    }
}
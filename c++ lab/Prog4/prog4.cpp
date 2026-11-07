
#include <iostream>
#include <stack>
#include <queue>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

template <class T>
class MyStack
{
private:
    T data[10000];
    int top;

public:
    MyStack()
    {
        top = -1;
    }

    void push(T value)
    {
        if (top < 9999)
            data[++top] = value;
    }

    void pop()
    {
        if (top >= 0)
            top--;
    }
};

template <class T>
class MyQueue
{
private:
    T data[10000];
    int front, rear;

public:
    MyQueue()
    {
        front = 0;
        rear = -1;
    }

    void enqueue(T value)
    {
        if (rear < 9999)
            data[++rear] = value;
    }

    void dequeue()
    {
        if (front <= rear)
            front++;
    }
};

int main()
{
    const int N = 10000;

    // Custom Stack Benchmark
    auto start = high_resolution_clock::now();
    MyStack<int> myStack;

    for (int i = 0; i < N; i++)
        myStack.push(i);

    for (int i = 0; i < N; i++)
        myStack.pop();

    auto end = high_resolution_clock::now();

    auto customStackTime =
    duration_cast<microseconds>(end - start);

    // STL Stack Benchmark
    start = high_resolution_clock::now();
    stack<int> stlStack;

    for (int i = 0; i < N; i++)
        stlStack.push(i);

    for (int i = 0; i < N; i++)
        stlStack.pop();

    end = high_resolution_clock::now();

    auto stlStackTime =
    duration_cast<microseconds>(end - start);

    // Custom Queue Benchmark
    start = high_resolution_clock::now();
    MyQueue<int> myQueue;

    for (int i = 0; i < N; i++)
        myQueue.enqueue(i);

    for (int i = 0; i < N; i++)
        myQueue.dequeue();

    end = high_resolution_clock::now();

    auto customQueueTime =
    duration_cast<microseconds>(end - start);

    // STL Queue Benchmark
    start = high_resolution_clock::now();
    queue<int> stlQueue;

    for (int i = 0; i < N; i++)
        stlQueue.push(i);

    for (int i = 0; i < N; i++)
        stlQueue.pop();

    end = high_resolution_clock::now();

    auto stlQueueTime =
    duration_cast<microseconds>(end - start);

    // ORIGINAL OUTPUT - UNCHANGED

    cout << "Custom Stack Time: "
         << customStackTime.count()
         << " microseconds" << endl;

    cout << "STL Stack Time: "
         << stlStackTime.count()
         << " microseconds" << endl;

    cout << "Custom Queue Time: "
         << customQueueTime.count()
         << " microseconds" << endl;

    cout << "STL Queue Time: "
         << stlQueueTime.count()
         << " microseconds" << endl;

    // ADDITIONAL FEATURE 1: PERFORMANCE WINNER

    cout << "\n========== PERFORMANCE WINNER ==========" << endl;

    cout << "Stack: ";

    if (customStackTime < stlStackTime)
        cout << "Custom Stack is faster." << endl;
    else if (customStackTime > stlStackTime)
        cout << "STL Stack is faster." << endl;
    else
        cout << "Both have equal execution time." << endl;

    cout << "Queue: ";

    if (customQueueTime < stlQueueTime)
        cout << "Custom Queue is faster." << endl;
    else if (customQueueTime > stlQueueTime)
        cout << "STL Queue is faster." << endl;
    else
        cout << "Both have equal execution time." << endl;

    // ADDITIONAL FEATURE 2: MEMORY ESTIMATION

    cout << "\n========== MEMORY ESTIMATION ==========" << endl;

    cout << "Custom Stack Array Memory: "
         << sizeof(int) * 10000 << " bytes" << endl;

    cout << "Custom Queue Array Memory: "
         << sizeof(int) * 10000 << " bytes" << endl;

    cout << "Custom Stack Object Size: "
         << sizeof(myStack) << " bytes" << endl;

    cout << "Custom Queue Object Size: "
         << sizeof(myQueue) << " bytes" << endl;

    // ADDITIONAL FEATURE 3: AVERAGE OPERATION TIME

    cout << "\n========== OPERATION ANALYSIS ==========" << endl;

    cout << fixed << setprecision(4);

    cout << "Custom Stack Average Time: "
         << (double)customStackTime.count() / (2 * N)
         << " microseconds per operation" << endl;

    cout << "STL Stack Average Time: "
         << (double)stlStackTime.count() / (2 * N)
         << " microseconds per operation" << endl;

    cout << "Custom Queue Average Time: "
         << (double)customQueueTime.count() / (2 * N)
         << " microseconds per operation" << endl;

    cout << "STL Queue Average Time: "
         << (double)stlQueueTime.count() / (2 * N)
         << " microseconds per operation" << endl;

    cout << "\nTotal Operations Performed: "
         << 4 * N * 2 << endl;

    cout << "Benchmark Analysis Completed Successfully!" << endl;

    return 0;
}

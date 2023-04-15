// Objective : Studying and understanding the concepts of Queues
// Working with the queues
#include <iostream>
#include <queue>
using namespace std;

#define M 10
// Implement a queue using simple array
class Queue
{
private:
    int arr[M];
    int front;
    int rear;

public:
    Queue()
    {
        for (int i = 0; i < M; i++)
        {
            arr[i] = 0;
        }
        front = -1;
        rear = -1;
    }
    void push(int x)
    {
        if (rear < M - 1)
        {
            rear++;
            arr[rear] = x;
        }
        else
        {
            cout << "Queue overflow" << endl;
        }
    }
    void pop()
    {
        if (rear != front)
        {
            front++;
            if (rear == front)
            {
                front = rear = -1;
            }
        }
        else
        {
            cout << "Queue underflow" << endl;
        }
    }
    int front()
    {
        if (front != rear)
        {
            return arr[front];
        }
        else
        {
            return -1;
        }
    }
    int back()
    {
        if (front != rear)
        {
            return arr[rear];
        }
        else
        {
            return -1;
        }
    }
    bool empty()
    {
        return (front == rear) ? true : false;
    }
    int size()
    {
        return rear - front;
    }
};
class sirQueue
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
    sirQueue()
    {
        size = 1001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void enqueue(int x)
    {
        if (rear == size)
        {
            cout << "Queue is full" << endl;
        }
        else
        {
            arr[rear] = x;
            rear++;
        }
    }
    int dequeue()
    {
        if (front == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = rear = 0;
            }
            return ans;
        }
    }
    bool isEmpty()
    {
        return (front == rear) ? true : false;
    }
    int Front()
    {
        return (!isEmpty()) ? arr[front] : -1;
    }
};

// implement a queue using linked list

int main()
{
    queue<int> q;
    q.push(10);
    q.push(10);
    cout << q.size() << endl;
    cout << q.empty() << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.push(5);

    return 0;
}
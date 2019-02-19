#include <iostream>
#include <climits>

using namespace std;

struct QueueStruct {
    int front;
    int rear;
    int* ptr;
    int q_size;
};
class Queue  {
    struct QueueStruct q;
public:
    Queue() {
        q.front = -1;
        q.rear = -1;
        q.q_size = 0;
        q.ptr = NULL;
    }

    Queue(int n) {
        q.front = -1;
        q.rear = -1;
        q.q_size = n;
        q.ptr = new int[n];
    }

    bool underflow() {
        return (q.front == -1 || q.front > q.rear);
    }

    bool overflow() {
        return q.rear == q.q_size;
    }

    void enqueue(int x) {
        if (!overflow()) {
            if(q.front == -1)
                q.front++;
            q.ptr[++q.rear] = x;
            cout << "Inserted: " << x << endl;
        } else
            cout << "Overflow" << endl;
    }

    int dequeue() {
        if (!underflow()) {
            cout << "Deleted: " << q.ptr[q.front] << endl;
            return q.ptr[q.front++];
        }
        cout << "Underflow" << endl;
        return INT_MIN;
    }

    void display() {
        cout << "Queue Elements: ";
        if (!underflow()) {
            for (int i = q.front; i <= q.rear; i++)
                cout << q.ptr[i] << " ";
            cout << endl;
        } else
            cout << "Empty Queue" << endl;
    }

    ~Queue() {
        delete [] q.ptr;
    }
};

int main() {
    Queue q(10);
    q.dequeue();
    q.enqueue(21);
    q.enqueue(22);
    q.enqueue(9);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
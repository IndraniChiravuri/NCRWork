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
        q.front = 0;
        q.rear = -1;
        q.q_size = 0;
        q.ptr = NULL;
    }

    Queue(int n) {
        q.front = 0;
        q.rear = -1;
        q.q_size = n;
        q.ptr = new int[n];
    }

    void enqueue(int x) {
        if ((q.front == 0 && q.rear == q.q_size - 1) || (q.front > 0 && q.rear == q.front - 1) )
            cout << "Overflow" << endl;
        else if (q.rear == q.q_size - 1 && q.front > 0) {
            q.rear = 0;
            q.ptr[q.rear] = x;
        } else if ((q.front == 0 && q.rear == -1) || (q.rear != q.front -1) )
            q.ptr[++q.rear] = x;
    }

    int dequeue() {
        if (q.front == 0 && q.rear == -1) {
           cout << "Underflow" << endl;
           return INT_MIN;
        }
        int ret;
        if (q.front == q.rear) {
            ret = q.ptr[q.front];
            q.front = 0;
            q.rear = -1;
        } else if(q.front == q.q_size -1) {
            ret = q.ptr[q.front];
            q.front = 0;
        } else {
            ret = q.ptr[q.front];
            q.front++;
        }
        return ret;
    }

    void display() {
        if (q.rear == -1)
            cout << "Empty Queue" << endl;
        else {
            cout << "Queue Elements: ";
            if (q.front <= q.rear) {
                for (int i = q.front; i <= q.rear; i++)
                    cout << q.ptr[i] << " ";
            } else {
                for (int i = q.front; i < q.q_size; i++)
                    cout << q.ptr[i] << " ";
                for (int i = 0; i <= q.rear; i++)
                    cout << q.ptr[i] << " ";
            }
            cout << endl;
        }
    }

    ~Queue() {
        delete [] q.ptr;
    }
};

int main() {
    Queue q(3);
    q.dequeue();
    q.enqueue(21);
    q.enqueue(22);
    q.enqueue(9);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(10);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}
class MyCircularQueue {
    int *arr;
    int size;
    int front, rear;
    int count; // To keep track of the number of elements in the queue

public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
        count = 0;
    }

    bool enQueue(int value) {
        // Check if the queue is full
        if (isFull()) {
            return false;
        }

        // Check if the queue is empty
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size; // Circular increment
        }

        arr[rear] = value;
        count++;
        return true;
    }

    bool deQueue() {
        // Check if the queue is empty
        if (isEmpty()) {
            return false;
        }

        // Remove the element at the front
        if (front == rear) {
            front = rear = -1; // Queue is now empty
        } else {
            front = (front + 1) % size; // Circular increment
        }

        count--;
        return true;
    }

    int Front() {
        // Check if the queue is empty
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int Rear() {
        // Check if the queue is empty
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return count == size;
    }
};

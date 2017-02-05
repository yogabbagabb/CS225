#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;

void testStack()
{
    cout << "Testing Stack..." << endl;
    Stack<int> intStack;
    for (int i = 1; i <= 10; i++) {
        intStack.push(i);
    }
    cout << intStack.peek() << endl;
    while (!intStack.isEmpty()) {
        cout << intStack.pop() << " ";
    }

    cout << endl;
}

void testQueue()
{
    cout << "Testing Queue..." << endl;
    Queue<int> intQueue;
    for (int i = 1; i <= 10; i++) {
        intQueue.enqueue(i);
    }
    cout << intQueue.peek() << endl;
    while (!intQueue.isEmpty()) {
        cout << intQueue.dequeue() << " ";
    }

    cout << endl;

    for (int i = 0; i < 5; i++)
    {
      intQueue.enqueue(i);
      intQueue.enqueue(i+2);
      cout << "just dequeued" << intQueue.dequeue() << endl;
      intQueue.enqueue(i+4);
      intQueue.dequeue();
    }

    while (!intQueue.isEmpty()) {
        cout << intQueue.dequeue() << " ";
    }

    cout << endl;
}

int main()
{
    testStack();
    testQueue();
    return 0;
}

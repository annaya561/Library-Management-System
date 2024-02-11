#include <bits/stdc++.h>
using namespace std;
#define size 10

// class array
class Array
{
private:
    int arr[size];
    static int i;

public:
    void push(int);
    void pop(int);
    
    void display();
};

int Array::i = 0;

void Array::push(int x)
{
    arr[i] = x;
    i++;
}

void Array::pop(int x)
{
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == x)
        {
            for (int j = i; j < 5; j++)
                cout << " " << endl;
        }
    }
}

void Array::display()
{
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " " << endl;
}

// class stack
class Stack
{
private:
    int stk[size];
    static int top;

public:
    int push(int);
    int pop();
    bool isEmpty();
    bool isFull();
    int stkTop();
};

int Stack::top = -1;

bool Stack::isFull()
{
    top == size ? true : false;
}

bool Stack::isEmpty()
{
    top == -1 ? true : false;
}

int Stack::push(int x)
{
    if (isFull())
        return 0;
    else
    {
        top++;
        stk[top] = x;
    }
}

int Stack::pop()
{
    if (isEmpty())
        return 0;
    else
    {
        cout << stk[top] << endl;
        top--;
    }
}

int Stack::stkTop()
{
    return stk[top];
}

// class queue
class Queue
{
private:
    int que[size];
    static int front;
    static int rear;

public:
    int push(int);
    int pop();
    bool isEmpty();
    bool isFull();
};

int Queue::front = -1;
int Queue::rear = -1;

bool Queue::isFull()
{
    front == rear &&front != -1 ? true : false;
}

bool Queue::isEmpty()
{
    front == rear &&front == -1 ? true : false;
}

int Queue::push(int x)
{
    if (isFull())
        return 0;
    else
    {
        rear;
        que[rear] = x;
    }
}

int Queue::pop()
{
    if (isEmpty())
        return 0;
    else
    {
        front++;
        cout << que[front] << endl;
    }
}

// class Linked List
class LinkedList
{
private:
    int head;

public:
    int data;
};

int main()
{
    Stack stk;
    Queue que;
    Array Arr;
    LinkedList LL;
    int t;
    cout << "Enter the number of operations you want to perform : ";
    cin >> t;

    do
    {
        cout << "Select the Data Structure - " << endl;
        cout << "1.Array" << endl;
        cout << "2.Stack" << endl;
        cout << "3.Queue" << endl;
        cout << "4.Linkedlist" << endl;
        cout << "5.Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice)
        {
        // For array
        case 1:
            cout << "1.push " << endl;
            cout << "2.pop " << endl;
            cout << "3.display" << endl;
            cout << "4.Exit" << endl;
            int choice1;
            cin >> choice1;
            switch (choice1)
            {
            case 1:
                cout << "Enter number to push :";
                int n;
                cin >> n;
                Arr.push(n);
                break;
            case 2:
                cout << "Rank of element to delete : " << endl;
                break;
            case 3:
                int temp = que.pop();
                cout << temp << " is popped " << endl;
                break;
            case 4:
                break;
            }
            break;

        // For stack
        case 2:
            cout << "1.push" << endl;
            cout << "2.pop" << endl;
            cout << "3.Stack Top" << endl;
            cout << "4.Stack Top" << endl;
            cout << "5.Exit" << endl;
            int choice2;
            cin >> choice2;
            switch (choice2)
            {
                int temp;
            case 1:
                cout << "Enter number to push :";
                int n;
                cin >> n;
                stk.push(n);
                break;
            case 2:
                temp = stk.pop();
                cout << temp << " is popped " << endl;
                break;
            case 3:
                temp = stk.stkTop();
                cout << temp << " is stack Top " << endl;
                break;
            //  default:
            case 4:
                break;
            }
            break;

        // For Queue
        case 3:
            cout << "1.push" << endl;
            cout << "2.pop" << endl;
            cout << "3.Exit" << endl;
            int choice3;
            cin >> choice3;
            switch (choice3)
            {
            case 1:
                cout << "Enter number to push :";
                int n;
                cin >> n;
                que.push(n);
                break;
            case 2:
                int temp = que.pop();
                cout << temp << " is popped " << endl;
                break;
            //  default:
            case 3:
                break;
            }
            break;

        // linked list
        /*case 4:
            cout << "1.push in front" << endl;
            cout << "2.pop" << endl;
            cout << "3.print linked list" << endl;
            cout << "4.Exit" << endl;
            int choice4;
            cin >> choice4;
            switch (choice4)
            {
            case 1:
                break;
            //default:
              //  break;
            }
            break;
            */
        default:
            break;
        }
    } while (t != 0);
}
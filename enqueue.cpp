#include<iostream>
using namespace std;

int queue[20], n;
int r = -1, f = -1;

void enquefront(int ele) {
    if ((f == 0 && r == n - 1) || (f == r + 1)) {
        cout << "Queue is full" << endl;
    } 
    else if (f == -1 && r == -1)
     {
        f = r = 0;
        queue[f] = ele;
    } 
    else if (f == 0) 
    {
        f = n - 1;
        queue[f] = ele;
    } 
    else {
        f--;
        queue[f] = ele;
    }
}

void enquerear(int ele) {
    if ((f == 0 && r == n - 1) || (f == r + 1)) {
        cout << "Queue is full" << endl;
    } 
    else if (f == -1 && r == -1) {
        f = r = 0;
        queue[r] = ele;
    }
     else if (r == n - 1) {
        r = 0;
        queue[r] = ele;
    } 
    else {
        r++;
        queue[r] = ele;
    }
}

void dequeuefront() {
    if (r == -1 && f == -1) {
        cout << "Queue is empty" << endl;
    } 
    else if (f == r) {
        cout << "Dequeued element: " << queue[f] << endl;
        f = r = -1;
    } 
    else if (f == n - 1) {
        cout << "Dequeued element: " << queue[f] << endl;
        f = 0;
    } 
    else {
        cout << "Dequeued element: " << queue[f] << endl;
        f++;
    }
}

void dequeuerear() {
    if (r == -1 && f == -1) {
        cout << "Queue is empty" << endl;
    }
     else if (f == r) {
        cout << "Dequeued element: " << queue[r] << endl;
        f = r = -1;
    } 
    else if (r == 0) {
        cout << "Dequeued element: " << queue[r] << endl;
        r = n - 1;
    } 
    else {
        cout << "Dequeued element: " << queue[r] << endl;
        r--;
    }
}

void display() {
    if (f == -1 && r == -1) {
        cout << "Queue is empty" << endl;
    } 
    else {
        int i = f;
        cout << "Queue elements: ";
        while (i != r) {
            cout << queue[i] << " ";
            i = (i + 1) % n;
        }
        cout << queue[r] << endl;
    }
}

int main() {
    int ch, k, ele;
    cout << "Enter the size of Queue: ";
    cin >> n;

    do {
        cout << "Menu\n1.Enqueue from front\n2.Enqueue from rear\n3.Dequeue from front\n4.Dequeue from rear\n5.Display\n6.Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the element to enqueue from front side: ";
                cin >> ele;
                enquefront(ele);
                break;
            case 2:
                cout << "Enter the element to enqueue from rear side: ";
                cin >> ele;
                enquerear(ele);
                break;
            case 3:
                dequeuefront();
                break;
            case 4:
                dequeuerear();
                break;
            case 5:
                cout << "Display" << endl;
                display();
                break;
            case 6:
                exit(0);
            default:
                cout << "Wrong option" << endl;
        }
        cout << "If you want to continue enter 1: ";
        cin >> k;
    } while (k == 1);

    return 0;
}


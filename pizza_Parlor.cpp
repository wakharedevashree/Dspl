/*#include<iostream>
#include<string>
using namespace std;
int queue[30],r=-1,f=-1,ele;
string type[30];

void enqueue(int n,int ele,string pizza_type){
    if(r==n-1){
        cout<<"order is full"<<endl;
    }
    else{
        r++;
        queue[r]=ele;
        type[r]=pizza_type;
        cout<<"Placed Ordered is "<<pizza_type<<" pizza with order no "<<ele<<endl;
    }
}

void dequeue(int n,string pizza_type){
    if(r==f){
        cout<<"order is empty"<<endl;
    }
    else{
        f++;
        ele=queue[f];
        pizza_type=type[f];
        cout << "served order is  :" << ele << " : " << pizza_type<<"Pizza" << endl;
}
}

void display(int n){
    int i;
    if(f==r){
        cout<<"Nothing for Placed and served"<<endl;
    }
    else{
         cout<<"Served Pizzas are :"<<endl;
        for(i=f+1;i<=r;i++){
           cout<<queue[i]<< ":"<<type[i]<<endl;
        }
    }
}

int main(){
    int ch,k,n;
    string pizza_type;
    cout<<"Enter the maximum no of orders the pizza parlor takes :";
    cin>>n;
    do{
        cout<<"Menu\n1.Place the order\n2.Served the order\n3.Display the current orders\n4.Exit\nEnter your Choice:";
        cin>>ch;
        switch(ch){
            case 1:cout<<"Enter the number for placed order:";
                   cin>>ele;
                   cout<<"Pizza Type:";
                   cin >> pizza_type;
                   enqueue(n, ele, pizza_type);
                   break;
            case 2:
                dequeue(n, pizza_type);
                break;
            case 3:display(n);
                   break;
            case 4:break;
            default:cout<<"wrong Choice"<<endl;

        }
       cout<<"If you want to continue for placing and serving order ,enter 1:";
       cin>>k;
    }while (k==1);
    
    
    return 0;
}*/



#include<iostream>
#include<string>
using namespace std;

class Pizza{
    public:
    int id;
    float price;
    string pizza_type;
     
         int queue[30], r, f, ele;
         string type[30];
         float pizza_price[30];
        Pizza(){
        r=-1;
        f=-1;
     }
    public:
    void details(){
        cout<<"Enter the id of pizza:";
        cin>>id;
        cout<<"Enter the type of Pizza:";
        cin>>pizza_type;
        cout<<"Enter the price of Pizza:";
        cin>>price;
    }
    void display()
    {
       
        int i,n;
        if (f == r)
        {
            cout << "Nothing for Placed and served" << endl;
        }
        else
        {
            cout << "Served Pizzas are :" << endl;
            for (i = f + 1; i <= r; i++)
            {
                cout << queue[i] << ":" << type[i] <<pizza_price[i]<< endl;
            }
        }
    }
    void enqueue(int n, int ele, string pizza_type,float price)
    {
        
        if (r == n - 1)
        {
            cout << "order is full" << endl;
        }
        else
        {
            r++;
            queue[r] = ele;
            type[r] = pizza_type;
            pizza_price[r]=price;
            cout << "Placed Ordered is " << type[r] << " pizza with order no " << queue[r] << endl;
            cout << "Price of Pizza is :" << pizza_price[r] << endl;
        }
    }

    void dequeue()
    {
        
        if (r == f)
        {
            cout << "order is empty" << endl;
        }
        else
        {
            f++;
            cout << "served order is  :" << queue[f] << " : " << type[f] << "Pizza" << "Price is :" << pizza_price[f] << endl;
        }
    }

};

int main()
{
    Pizza p;
    int ch, k, n, ele;
    string pizza_type;
    float price;

    cout << "Enter the no of order that pizza parlor can take: ";
    cin >> n;

    do
    {
        cout << "\nMenu:\n1. Place the order\n2. Serve the order\n3. Display the current orders\n4. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            p.details();
            p.enqueue(n, p.id, p.pizza_type, p.price);
            break;
        case 2:
            p.dequeue();
            break;
        case 3:
            p.display();
            break;
        case 4:
            break;
        default:
            cout << "Wrong choice! Please try again." << endl;
        }

        cout << "If you want to continue for placing and serving orders, enter 1: ";
        cin >> k;

    } while (k == 1);

    return 0;
}
/*#include <iostream>
using namespace std;

class PizzaParlorQueue
{
private:
    int front, rear;
    int maxOrders;
    int *orders;

public:
    PizzaParlorQueue(int maxOrders)
    {
        this->maxOrders = maxOrders;
        orders = new int[maxOrders];
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull()
    {
        return (rear == maxOrders - 1);
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }

    // Add an order to the queue
    void placeOrder(int order)
    {
        if (isFull())
        {
            cout << "Order queue is full. Cannot take more orders." << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear++;
        orders[rear] = order;
        cout << "Order " << order << " placed successfully!" << endl;
    }

    // Serve the first order in the queue
    void serveOrder()
    {
        if (isEmpty())
        {
            cout << "No orders to serve!" << endl;
            return;
        }
        cout << "Order " << orders[front] << " is being served." << endl;
        front++;
    }

    // Display current orders in the queue
    void displayOrders()
    {
        if (isEmpty())
        {
            cout << "No orders in the queue." << endl;
            return;
        }
        cout << "Current orders in the queue: ";
        for (int i = front; i <= rear; i++)
        {
            cout << orders[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free up dynamically allocated memory
    ~PizzaParlorQueue()
    {
        delete[] orders;
    }
};

int main()
{
    int M, choice, order;

    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> M;

    PizzaParlorQueue parlor(M);

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Place Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter order number to place: ";
            cin >> order;
            parlor.placeOrder(order);
            break;
        case 2:
            parlor.serveOrder();
            break;
        case 3:
            parlor.displayOrders();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice, try again!" << endl;
        }
    } while (choice != 4);

    return 0;
}*/

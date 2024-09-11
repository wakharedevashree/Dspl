#include<iostream>
using namespace std;
int queue[30],r=-1,f=-1,ele;

void enqueue(int n,int ele){
    if((r+1)%n==f){
        cout<<"Queue is full"<<endl;
    }
    else if(f==-1 && r==-1){
        r=0;
        f=0;
        queue[r]=ele;
        
    }
    else{
       r=(r+1)%n;
        queue[r]=ele;
    }
}

void dequeue(int n){
    if(r==-1 && f==-1){
        cout<<"Queue is empty"<<endl;
    }
    else if(r==f){
        cout<<"Deleted elemnt is ele :"<<queue[f]; 
        r=-1;
        f=-1;
}
else{
    ele=queue[f];
    cout<<"Deleted elemnt is ele :"<<ele; 
    f=(f+1)%n;
}
}

void display(int n){
    int i;
    if(f==-1 && r==-1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        i=f;
        while(i!=r){
            cout<<queue[i]<<" ";
            i=(i+1)%n;
        }
        cout<<queue[r]<<endl;
    }
}

int main(){
    int ch,k,n;
    cout<<"Enter the size of Queue:";
    cin>>n;
    do{
        cout<<"Menu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your Choice:";
        cin>>ch;
        switch(ch){
            case 1:cout<<"Enter the element in Queue:";
                   cin>>ele;
                   enqueue( n, ele);
                   break;
            case 2:dequeue(n);
                   break;
            case 3:display(n);
                   break;
            case 4:break;
            default:cout<<"wrong Choice"<<endl;

        }
       cout<<"\nIf you want to continue enter 1:";
       cin>>k;
    }while (k==1);
    
    
    return 0;
}
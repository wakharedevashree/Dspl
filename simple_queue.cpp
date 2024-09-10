#include<iostream>
using namespace std;
int queue[30],r=-1,f=-1,ele;

void enqueue(int n,int ele){
    if(r==n-1){
        cout<<"Queue is full"<<endl;
    }
    else{
        r++;
        queue[r]=ele;
        
    }
}

void dequeue(int n){
    if(r==f){
        cout<<"Queue is empty"<<endl;
    }
    else{
        f++;
        ele=queue[f];
        cout<<"Deleted elemnt is ele :"<<ele;
    
    
}
}

void display(int n){
    int i;
    if(f==r){
        cout<<"Queue is empty"<<endl;
    }
    else{
        for(i=f+1;i<=r;i++){
           cout<<queue[i]<<" "<<endl;
        }
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
       cout<<"If you want to continue enter 1:";
       cin>>k;
    }while (k==1);
    
    
    return 0;
}
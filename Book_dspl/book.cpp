#include<iostream>
#include<string>
using namespace std;

class Book{
    public:
   string name;
   float price;
   public:
   void details(){
    cout<<"Enter the name of Book:";
    cin>>name;
    cout<<"Enter the price of Book";
    cin>>price;
   }

   void display(){
    cout<<name<<"\t"<<price<<endl;
   }

   void sort(Book b[],int n){
      int i,j;
      for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(b[j].price>b[j+1].price){
                Book temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
      }
      cout<<"Sorted Books By price is:"<<endl;
      for(i=0;i<n;i++){
        cout<<b[i].name<<"\t"<<b[i].price<<endl;
      }
   }

   void duplicate_by_array(Book b[],int n){
        int flag=0,i,j;
        Book newArray[10];
        int newsize=0;
        for(i=0;i<n;i++){
           for(j=0;j<newsize;j++){
              if(b[i].price==newArray[j].price && b[i].name==newArray[j].name){
                flag=1;
                break;
              }
           }

           if(flag==0){
            newArray[newsize]=b[i];
            newsize++;
           }
        }

        cout<<"Books Without duplicate book and price are:";
        for(i=0;i<n;i++){
            cout << b[i].name << "\t" << b[i].price << endl;
        }

   }

   void duplicate(Book b[],int n){
           int newindex=0;
           int flag=0,i,j;
           for(i=0;i<n;i++){
            for(j=0;j<newindex;j++){
                if(b[i].price==b[j].price && b[i].name==b[j].name){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                b[newindex]=b[i];
                newindex++;
            }
           }
           n=newindex;
           cout << "Books Without duplicate book and price are:";
           for (i = 0; i < n; i++)
           {
               cout << b[i].name << "\t" << b[i].price << endl;
           }
   }


   void greater_500(Book b[],int n){
    int i,count=0;
    float more_price[10];
    string more_name[10];
    for(i=0;i<n;i++){
        if(b[i].price>=500){
          more_price[count] = b[i].price;
          more_name[count] = b[i].name;
          count++;
        }
    }
    cout<<"Books are more than 500 are:";
    for (i = 0; i < count; i++)
    {
        cout << more_price[i] << "\t" << more_name[i] << endl;
    }
   }
};

int main(){
    Book b[20];
    int k,ch,temp1,i,n=0;
    do{
cout<<"Menu\n1.Get details\n2.display\n3.sorting\n4.duplicates bu array\n5.duplicate\n6.500\n7.exit\nEnter your Choice:";
cin>>ch;
 switch(ch){
    case 1:cout<<"Enter the no of book :";
           cin>>temp1;
           for(i=0;i<n+temp1;i++){
               b[i].details();
           }
           n=n+temp1;
           break;
    case 2:cout<<"Name\tPrice"<<endl;
            for(i=0;i<n;i++){
                b[i].display();
            }
            break;
    case 3:b[i].sort(b,n);
             break;
    case 4:b[i].duplicate_by_array(b,n);
             break;
    case 5:b[i].duplicate(b,n);
             break;
    case 6:b[i].greater_500(b,n);
            break;
    case 7:break;
    default:cout<<"Wrong Choice"<<endl; 
 }
 cout<<"If you want to contiue Enter 1:";
 cin>>k;
    } while(k==1);
    return 0;
}
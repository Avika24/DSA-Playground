#include <iostream>
using namespace std;
void Array();
void Stack();
void Queue();
void LinkedList();
void insert_ll();
void delete_ll();
void traverse_ll();
void insert_arr(int arr[],int &n);
void delete_arr(int arr[],int&n);
void display_arr(int arr[], int&n);
void push();
void pop();
void peek();
void enqueue();
void dequeue();
void display_queue();
int main() {
    bool running= true;
    int choice;
    while(running){
    cout<< "Please select data structures operation:\n1. Array\n2. Stack\n3. Queue\n4. Linked List\n5. Exit\n";
    cin>> choice;
        switch(choice){
         case 1: Array();
                 break;
         case 2: Stack();
                 break;
         case 3: Queue();
                break;
         case 4: LinkedList();
                 break;
         case 5: running = false;
                 break;
         default: cout<<"Invalid Input";
                  break;
        }}
    return 0;
        }
void Array() {
    int n;
    int choice;
    bool running= true;
    cout<<"Enter array length:\n";
    cin>>n;
    int* arr= new int[n + 50];
    cout<<"Enter array elements:\n";
    for (int i=0;i<n;i++){
    cin>>arr[i];
    }
    while (running){
    cout<< "Please select operation:\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
    cin>>choice;
    switch(choice){
    case 1: insert_arr(arr,n);
        break;
    case 2: delete_arr(arr,n);
        break;
    case 3: display_arr(arr,n);
         break;
    case 4: running=false;
         break;
    default: cout<<"Invalid input";
           break;
    }}
  delete[] arr;
}

void push() {}
void pop() {}
void peek() {}

void enqueue() {}
void dequeue() {}
void display_queue() {}

void insert_ll() {}
void delete_ll() {}
void traverse_ll() {}
void Stack() {
    int choice;
    bool running= true;
    while (running){
    cout<< "Please select operation:\n1. Push\n2. Pop\n3. Peek\n4. Exit\n";
    cin>>choice;
    switch(choice){
    case 1: push();
        break;
    case 2: pop();
        break;
    case 3: peek();
         break;
    case 4: running=false;
         break;
    default: cout<<"Invalid input";
           break;
    }
    }
}
void Queue() {
    int choice;
    bool running= true;
    while (running){
    cout<< "Please select operation:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
    cin>>choice;
    switch(choice){
    case 1: enqueue();
        break;
    case 2: dequeue();
        break;
    case 3: display_queue();
         break;
    case 4: running=false;
         break;
    default: cout<<"Invalid input";
           break;
    }
    }
}
void LinkedList(){
    int choice;
    bool running= true;
    while (running){
    cout<< "Please select operation:\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\n";
     cin>>choice;
    switch(choice){
    case 1: insert_ll();
        break;
    case 2: delete_ll();
        break;
    case 3: traverse_ll();
         break;
    case 4: running=false;
         break;
    default: cout<<"Invalid input";
           break;
    }}
}
void insert_arr(int arr[], int &n){
int ele, pos;
cout<<"Enter element to be inserted:\n";
cin>>ele;
cout<<"Enter postion to be inserted:\n";
cin>>pos;
if (pos<1 || pos > n+1){
    cout<<"Invalid Position.\n";
    return;
}
for(int i=n;i >=pos; i--){
 arr[i]=arr[i-1];}
arr[pos-1]=ele;
n++;
cout<<"Element Inserted.\n";
}
void delete_arr(int arr[], int &n) {
cout<<"Enter position to delete element.\n";
int pos;
cin>>pos;
if ( pos<1 || pos>n){
    cout<<"Invalid Position.\n";
    return;
}
for (int i=pos; i<n; i++){
    arr[i-1]=arr[i];
}
n--;
cout<<"Element Deleted\n";
}
void display_arr(int arr[], int &n) {
for (int i=0;i<n;i++){
    cout<<arr[i]<<"\t";
}
cout<<"\n";
}


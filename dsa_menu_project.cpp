#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
int *stackArr;
int capacity;
int top = -1;
Node* front= nullptr;
Node* rear= nullptr;
Node* head = nullptr;
int currsize=0; 
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
void display_stack();
void enqueue();
void dequeue();
void display_queue();
int main() {
    bool running= true;
    int choice;
    cout<<"====================================\n";
    cout<<"     DATA STRUCTURES PLAYGROUND     \n";
    cout<<"====================================\n";
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
    cout<<"\n===== ARRAY OPERATIONS =====\n";
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

void Stack() {
    int choice;
    bool running= true;
    cout<<"\n===== STACK OPERATIONS =====\n";
    cout<<"Enter stack capacity:\n";
    cin>>capacity;
    stackArr= new int[capacity];
    top=-1;
    while (running){
    cout<< "Please select operation:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
    cin>>choice;
    switch(choice){
    case 1: push();
        break;
    case 2: pop();
        break;
    case 3: peek();
         break;
    case 4: display_stack();
         break;
    case 5: running=false;
         break;
    default: cout<<"Invalid input";
           break;
    }
    }
    delete[] stackArr;
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
    cout<<arr[i]<<" ";
}
cout<<"\n";
}
void push() {
int x;
if (top == capacity - 1){
    cout<<"Stack overflow.\n";
    return;
}
cout<<"Enter element to push\n";
cin>>x;
stackArr[++top]=x;
cout<<"Element pushed.\n";
}
void pop() {
if(top==-1){
    cout<<"Stack Underflow.\n";
    return;
}
cout<<"Popped element: "<<stackArr[top--]<<endl;
}
void peek() {
if (top==-1){
    cout<<"Stack is empty.\n";
    return;
}
cout<<"Top element:"<<stackArr[top]<<endl;
}
void display_stack(){
    if (top==-1){
        cout<<"Stack is empty.\n";
        return;
    }
    for (int i=top; i>=0; i--){
        cout<<"| "<<stackArr[i]<<" |\n";
    }
    cout<<"----\n";
}
void enqueue() {
int x;
cout<<"Enter element to enqueue:\n";
cin>>x;
Node* node = new Node;
node->data = x;
node->next= nullptr;
if (front==nullptr){
    front=rear=node;
}
else {
    rear->next=node;
    rear=node;
}
currsize++;
cout<<"Element inserted.\n";
}
void dequeue() {
if (front == nullptr){
    cout<<"Queue underflow.\n";
    return;
}
Node *temp= front;
cout<<"Removed element:"<<temp->data<<endl;
front = front->next;
if (front==nullptr){
    rear=nullptr;
}
delete temp;
currsize--;
}
void display_queue() {
if (front == nullptr){
    cout<<"Queue is empty.\n";
    return;
}
Node* temp = front;
while(temp != nullptr){
    cout<<temp->data<<" ";
    temp = temp->next;
}
cout<<endl;
}

void insert_ll() {
int pos, val;
cout<<"Enter position:\n";
cin>>pos;
cout<<"Enter value:\n";
cin>>val;
if(pos<1){
cout<<"Invalid position.\n";
return;
}
Node* newNode= new Node;
newNode->data= val;
newNode->next = nullptr;

if(pos==1){
    newNode->next=head;
    head=newNode;
    return;
}
if(head == nullptr && pos > 1){
    cout<<"Position out of range.\n";
    return;
}
Node* curr = head;
for(int i=1; i<pos-1 && curr != nullptr; i++){
    curr = curr->next;
}
if (curr== nullptr){
    cout<<"Position out of range.\n";
    return;
}
newNode->next= curr->next;
curr->next= newNode;
cout<<"Node inserted.\n";
}

void delete_ll() {
int pos;
cout<<"Enter position to delete.\n";
cin>>pos;
if(head==nullptr){
    cout<<"Linked list is empty.\n";
    return;}
if (pos==1){
Node* temp = head;
head = head->next;
delete temp;
cout<<"Node deleted.\n";
return;
}
Node* curr = head;
for (int i=1; i<pos-1 && curr->next!=nullptr; i++){
    curr = curr->next;
}
if(curr->next==nullptr){
    cout<<"Position out of range.\n";
    return;
}
Node* temp= curr->next;
curr->next= temp->next;
delete temp;
cout<<"Node deleted.\n";
}
void traverse_ll() {
if (head==nullptr){
    cout<<"Linked List is empty.\n";
    return;
}
Node* temp = head;
while (temp!=nullptr){
    cout<<temp->data<<" -> ";
    temp= temp->next;
}
cout<<"NULL\n";
}
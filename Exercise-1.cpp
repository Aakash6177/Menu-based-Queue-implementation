#include<iostream>
using namespace std;

class MyQueue{
public:
  int front, rear;
  int size;
  int capacity;
  double *q;
public:
  MyQueue(){
    front = -1;
    rear = -1;
    q = nullptr;
  }
  MyQueue(int capacity){
    front = -1;
    rear = -1;
    q = new double[capacity];

  }
  ~MyQueue(){
    delete []q;
  }
  bool isFull(){
    if(rear == 4){
      return true;
    }
    else{
      return false;
    }
  }
  bool isEmpty(){
    if(front == -1 && rear == -1){
      return true;
    }
    else{
      return false;
    }
  }
  void Enqueue(double x){
    if(isFull()){
      cout<<"Queue is full"<<endl;
      return;
    }
    else if(isEmpty()){
      rear = 0;
      front = 0;
      q[rear] = x;
    }
    else{
      rear ++;
      q[rear] = x;
    }
  }
  double Dequeue(){
    double x;
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
      return 0;
    }
    else if(front == rear){
      x = q[front];
      q[front] = 0;
      rear  = -1;
      front = -1;
      return x;
    }
    else{
      x = q[front];
      q[front] = 0;
      front++;
      return x;
    }
  }
  double Front(){
    return q[front];
  }
  double Rear(){
    return q[rear];
  }
  void DisplayQueue(){
    cout<<rear - front +1;
    }

  void DisplayAll(){
    for(int i=0;i<5;i++){
      cout<<q[i]<<" ";
    }
  }

};

int main(){
int option, value;
MyQueue q1(5);

do{
  cout<<"What option do you weant to perform? select Option number. Enter 0 to exit"<<endl;
  cout<<"1. Enqueue()"<<endl;
  cout<<"2. Dequeue()"<<endl;
  cout<<"3. isEmpty()"<<endl;
  cout<<"4. isFull()"<<endl;
  // cout<<"5. Count()"<<endl;
  cout<<"5. DisplayQueue()"<<endl;
  cout<<"6. DisplayAll()"<<endl;
  cout<<"7. Front()"<<endl;
  cout<<"8. Rear()"<<endl;
  cout<<"9. Clear Screen"<<endl;
  cin>>option;
switch (option) {
  case 0:
    break;
  case 1:
    cout<<"Enqueue operation \nEnter the item to insert in the Queue"<<endl;
    cin>>value;
    q1.Enqueue(value);
    break;

  case 2:
    cout<<"Dequeue function called  "<<q1.Dequeue()<<endl;
    break;
  case 3:
    if(q1.isEmpty()){
      cout<<"Queue is empty "<<endl;
    }
    else{
      cout<<"Queue is not empty"<<endl;
    }
    break;
  case 4:
    if(q1.isFull()){
      cout<<"Queue is full"<<endl;
    }
    else{
      cout<<"Queue is not full"<<endl;
    }
    break;
  // case 5:
  //   cout<<"Conunt function called \n Number of items in Queue "<<q1.count()<<endl;
  //   break;
  case 5:
    cout<<"Number of items in Queue ";
    q1.DisplayQueue();
    cout<<endl;
    break;
  case 6:
    cout<<"DisplayAll function called \nElements in the Queue are: ";
    q1.DisplayAll();
    cout<<endl;
    break;
  case 7:
    cout<<"Front Function called: "<<q1.Front()<<endl;
    break;
  case 8:
    cout<<"Rear Function called: "<<q1.Rear()<<endl;
    break;
  case 9:
    system("clear");
    break;
  default:
    cout<<"Invalid Input"<<endl;
   }
}

while(option != 0);

  return 0;
}

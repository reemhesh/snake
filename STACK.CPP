
#include<iostream.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>

class Stack{

 int size;
 int *st;
 int tos;

 static int counter;

 public:


 Stack(int s){

 counter++;

 cout<<"this is stack object created:  " <<counter<<endl;

 size=s;

 st=new int[size];


 tos=0;

 }

 //prototypes

 void push(int);

 int pop();

 Stack(Stack &x);

 ~Stack();

 int Stack::getCounter();
//  void printStack();

  friend void viewContent1(Stack x);
  friend void viewContent2(Stack &x);
  friend void viewContent3(Stack *x);


//  = operater assign pss by val
Stack & operator = (const  Stack &s);
};//class

 void Stack::push(int n){

  if(tos==size){

  cout<<"the stack full" <<endl;


 }else{

   st[tos]=n;

   tos++;

 }
}
  int Stack::pop(){

  int retVal;

  if(tos==0){

  cout<<"the stack is empty"<<endl;

  }
  else{

  tos--;
  retVal=st[tos];

  }
   return retVal;
  }

   void viewContent1(Stack x){

   int i;
   cout<<"pss by val:\n";

   for(i=0;i<x.tos;i++){

   cout<<x.st[i]<<endl;

   }   }
 void viewContent2(Stack &x){

   int i;
   cout<<"pss by ref:\n";

   for(i=0;i<x.tos;i++){

   cout<<x.st[i]<<endl;

   }

  }
  void viewContent3(Stack *x){

   int i;
   cout<<"pss by Address:\n";

   for(i=0;i<x->tos;i++){

   cout<<x->st[i]<<endl;

   }

  }

 //---copy constructor
  Stack::Stack(Stack &x){

   cout<<"copy constructor"<<endl;

   this->size=x.size;

   this->tos=x.tos;

   this->st=new int[size];

   int i;

   for(i=0;i<tos;i++){

   this->st[i]=x.st[i];

   }
   counter++;
   }

//  = operater assign pss by val
Stack & Stack::operator = (const Stack &s){

  int i;
  delete[]this->st;
  this->tos=s.tos;
  this->size=s.size;
  this->st=new int[size];
  for(i=0;i<tos;i++){

   this->st[i]=s.st[i];

  }
  return *this;
}

 //--destructor with keep dynamic allocation
 Stack::~Stack(){
 int i;

 for(i=0;i<size;i++){

 st[i]=0;

 }

 delete []st;

 counter--;

 cout<<"this is stack object destroyed  " <<counter<<endl;

 }

 //----
 int Stack::getCounter(){

 return counter;

 }

int Stack::counter=0;



void main(){

clrscr();
Stack s1(3);
s1.push(1);
s1.push(2);
s1.push(3);

Stack s2(3);
s2.push(8);
s2.push(9);
s2.push(7);

Stack s3(3);

s3=s1=s2;

viewContent2(s3);



getch();
}











/*
  void Stack::printStack(){

  int i;

  if(tos==0) cout<<"the Stack is empty"<<endl;

   else{

	for(i=tos-1;i>=0;i--){

	cout<<st[i]<<" ";

	}
	cout<< endl;
  }

  }
*/
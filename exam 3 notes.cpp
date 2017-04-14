#include <iostream>
#include <list>
#include <queue>
#include <ctime>

using namespace std;


//QUEUE STUFF

template <class T>
class Queue{
	list<T> data;
public:
	void push(T newitem){ data.push_back(newitem); }
	T pop();
	T& top(){ return *data.begin(); }
	T top()const { return *data.begin(); }
	bool isEmpty()const { return data.begin() == data.end(); }
	void clear(){ data.clear(); }
};

template <class T>
T Queue<T>::pop(){
	T retval = top();
	data.pop_front();
	return retval;
}

template <class T>
class VQueue{
	T* data;
	int start;//location of the oldest element
	int end; //location of the newest element
	int size; //number of elements in the queue
	int capacity; //capacity of the dynamic array
public:
	VQueue();
	virtual ~VQueue(){ delete[] data; }
	VQueue(const VQueue& rhs) : data(nullptr){ *this = rhs; }
	T& top(){ return data[start]; }
	T top()const{ return data[start]; }
	bool isEmpty()const{ return size == 0; }
	int numOfElements()const{ return size; }

	VQueue& operator=(const VQueue& rhs);
	void push(const T& newdata);
	T pop();
};
template <class T>
VQueue<T>& VQueue<T>::operator=(const VQueue& rhs){
	if (this == &rhs)
		return *this;
	delete[] data;
	if (rhs.size >= 5)
		capacity = rhs.size+1;
	else
		capacity = 5;
	data = new T[capacity];
	if (rhs.start == -1){
		start = end = -1;
		size = 0;
		return;
	}
	start = 0;
	int i = rhs.start;
	size = 0;
	do{
		data[size++] = rhs.data[i++];
		if (i == rhs.capacity)
			i = 0;
	} while (i != rhs.end);
	data[size++] = rhs.data[i]; //copy the last element
	end = size - 1;
}

template <class T>
void VQueue<T>::push(const T& newdata){
	size++;
	if (start == -1){ //special case for an empty queue
		start = end = 0;
		data[start] = newdata;
		return;
	}
	end++;
	if (end == capacity)
		end = 0;
	data[end] = newdata;
	if (size == capacity) {//time to grow!!!
		int newsize = size * 2;
		T* temp = new T[newsize];
		int tempcount = 0;
		int i = start;
		do{
			temp[tempcount++] = data[i++];
			if (i == capacity)
				i = 0;
		} while (i != start);
		delete[] data;
		data = temp; 
		start = 0;
		end = tempcount - 1;
		capacity = newsize;
	}
}
template <class T>
T VQueue<T>::pop(){
	if (size == 0)
		return T();
	T retval = top();
	size--;
	start++;
	if (start == capacity) //ran off the end here
		start = 0;
	if (isEmpty())
		start = end = -1;
	return retval;
}

template <class T>
VQueue<T>::VQueue(){
	capacity = 5;
	size = 0;
	start = -1;
	end = -1;
	data = new T[capacity];
}

int main(){
	VQueue<int> vq;
	srand(time(NULL));
	int val = 0;
	for (int i = 0; i < 10; i++){
		int pushes = rand() % 20;
		int pops = rand() % 20;
		if (pops > pushes)
			swap(pushes, pops);
		for (int j = 0; j < pushes; j++)
			vq.push(val++);
		for (int j = 0; j < pops; j++)
			cout << vq.pop() << endl;
		cout << "***********looping******" << endl;
	}
}


/* Queue - Circular Array implementation in C++*/
#include<iostream>
using namespace std; 
#define MAX_SIZE 101  //maximum size of the array that will store Queue. 

// Creating a class named Queue.
class Queue
{
private:
	int A[MAX_SIZE];
	int front, rear; 
public:
	// Constructor - set front and rear as -1. 
	// We are assuming that for an empty Queue, both front and rear will be -1.
	Queue()
	{
		front = -1; 
		rear = -1;
	}

	// To check wheter Queue is empty or not
	bool IsEmpty()
	{
		return (front == -1 && rear == -1); 
	}

	// To check whether Queue is full or not
	bool IsFull()
	{
		return (rear+1)%MAX_SIZE == front ? true : false;
	}

	// Inserts an element in queue at rear end
	void Enqueue(int x)
	{
		cout<<"Enqueuing "<<x<<" \n";
		if(IsFull())
		{
			cout<<"Error: Queue is Full\n";
			return;
		}
		if (IsEmpty())
		{ 
			front = rear = 0; 
		}
		else
		{
		    rear = (rear+1)%MAX_SIZE;
		}
		A[rear] = x;
	}

	// Removes an element in Queue from front end. 
	void Dequeue()
	{
		cout<<"Dequeuing \n";
		if(IsEmpty())
		{
			cout<<"Error: Queue is Empty\n";
			return;
		}
		else if(front == rear ) 
		{
			rear = front = -1;
		}
		else
		{
			front = (front+1)%MAX_SIZE;
		}
	}
	// Returns element at front of queue. 
	int Front()
	{
		if(front == -1)
		{
			cout<<"Error: cannot return front from empty queue\n";
			return -1; 
		}
		return A[front];
	}
	/* 
	   Printing the elements in queue from front to rear. 
	   This function is only to test the code. 
	   This is not a standard function for Queue implementation. 
	*/
	void Print()
	{
		// Finding number of elements in queue  
		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
			cout<<A[index]<<" ";
		}
		cout<<"\n\n";
	}
};
int main()
{
	/*Driver Code to test the implementation
	  Printing the elements in Queue after each Enqueue or Dequeue 
	*/
   Queue Q; // creating an instance of Queue. 
   Q.Enqueue(2);  Q.Print();  
   Q.Enqueue(4);  Q.Print();  
   Q.Enqueue(6);  Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Enqueue(8);  Q.Print();
}


//FUNCTOR STUFF

class lessThanOnAge;

class Person{
	string name;
	int age;
	double salary;
public:
	Person(string newname = "", int newage = 0, int newsalary = 0) :name(newname), age(newage), salary(newsalary){}
	int getAge() const{ return age; }
	string getName() const{ return name; }
	double getSalary() const{ return salary; }
	void printInfo()const{ cout << "Name=" << name << " Age=" << age << " Salary=" << salary << endl; }
	friend class lessThanOnAge;
};

class lessThanOnAge{ //functor used for sorting
public:
	bool operator()(const Person& a, const Person& b){
		return a.age < b.age;
	}
};
class lessThanOnSalary{ //functor used for sorting
public:
	bool operator()(const Person& a, const Person& b){
		return a.getSalary() < b.getSalary();
	}
};

template <class T, class S>
void insertionSort(vector<T>& v, int start, int end, S comparator){ //O(N^2)
	for (int i = start + 1; i <= end; i++){
		T temp = v[i];
		int j = i;
		for (j = i; j > 0 && comparator(temp,v[j - 1]); j--)
			v[j] = v[j - 1];
		v[j] = temp;
	}
}

template <class T, class S>
void quicksort(vector<T>& v, int start, int end, S comparator){
	if ((start + 10) > end){
		insertionSort(v, start, end, comparator);
		return;
	}
	int center = (start + end) / 2;
	if (comparator(v[center],v[start]))  //begin median-of-three partitioning
		swap(v[center], v[start]);
	if (comparator(v[end], v[start]))
		swap(v[end], v[start]);
	if (comparator(v[end], v[center]))
		swap(v[end], v[center]);

	T pivot = v[center];
	swap(v[center], v[end - 1]);
	int i = start;
	int j = end - 1;
	for (;;){
		while (comparator(v[++i], pivot)){}
		while (comparator(pivot, v[--j])){}
		if (i < j)
			swap(v[i], v[j]);
		else
			break;
	}
	swap(v[i], v[end - 1]);//Move pivot into its final position!

	quicksort(v, start, i - 1, comparator);
	quicksort(v, i + 1, end, comparator);

}

template <class T>
void quicksort(vector<T>& v){
	quicksort(v, 0, v.size() - 1);
}

class findWealthyDrinkers{
public:
	bool operator()(const Person& p){
		if (p.getAge() >= 21 && p.getSalary() >= 100000)
			return true;
		return false;
	}
};

template <class T>
vector<Person> matchesSearch(vector<Person> v, T comparator){
	vector<Person> retval;
	for (Person p : v)
		if (comparator(p) == true)
			retval.push_back(p);
	return retval;
}

bool lessThanOnName(const Person& a, const Person& b){
	return a.getName() < b.getName();
}

enum HAIR_COLOR{BROWN,BLOND,GREY,WHITE,BLACK,RED};

void printInfo(Person arr[], int size){
	if (size <= 0)
		return;
	arr->printInfo();
	printInfo(arr + 1, size - 1);
}

int fib(int n){
	if (n > 2)
		return fib(n - 1) + fib(n - 2);
	return 1;
}
int binarySearch(vector<int> v, int start, int end, int toFind){
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	if (v[mid] == toFind)
		return mid;
	else if (v[mid] > toFind)
		return binarySearch(v, start, mid - 1, toFind);
	else
		return binarySearch(v, mid + 1, end, toFind);
}

void printBinary(int n){
	if (n < 2)
		cout << n;
	else{
		printBinary(n / 2);
		cout << n % 2;
	}
}

void printOct(int n){
	if (n < 8)
		cout << n;
	else{
		printOct(n / 8);
		cout << n % 8;
	}
}

const char HEX_LETTERS[] = "0123456789ABCDEF";
void printHex(int n){
	if (n < 16)
		cout << HEX_LETTERS[n];
	else{
		printHex(n / 16);
		cout << HEX_LETTERS[n % 16];
	}

}

int main(){
	printHex(255);
	cout << endl;
	return 0;

	HAIR_COLOR h = BLOND;
	vector<Person> v;

	for (int i = 0; i < v.size(); i++)
		cout << i << endl;

	v.push_back(Person("James Dolittle", 29, 25000));
	v.push_back(Person("Claryssa Santana", 20, 1000000));
	v.push_back(Person("John Dough", 40, 200000));

	lessThanOnAge sorter;
	insertionSort(v, 0, v.size() - 1, sorter);

	for (Person p : v)
		p.printInfo();

	insertionSort(v, 0, v.size() - 1, lessThanOnName);
	cout << endl << endl;
	for (Person p : v)
		p.printInfo();

	vector<Person> wealthyDrinkers = matchesSearch(v, findWealthyDrinkers());
	cout << "The list of wealthy drinkers:" << endl;
	for (Person p : wealthyDrinkers)
		p.printInfo();
}



//HW3

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Flight{
public:
	int flightNum;
	int flightTime;
	string originCode;
	string destCode;
}

template <class T, class U>
vector<T> find(vector<T>& flights, U functor, T targetFlight){
   vector<T> fVec;
   for (T aFlight : flights)
       if (functor(aFlight, targetFlight))
           fVec.push_back(aFlight);
   return fVec;
}

class equalByDeparture{
public:
   bool operator()(Flight flight1, Flight flight2){
       if (flight1.departureCity == flight2.departureCity)
           return true;
       return false;
   }
};

class equalByDestination{
public:
   bool operator()(Flight flight1, Flight flight2){
       if (flight1.originCode == flight2.destCode)
           return true;
       return false;
   }
};

void maxOutdegree(vector<Flight>flights){
   int max = 0;
   string retFlight;
   equalByDeparture functor;
   for (Flight f : flights){
       vector<Flight> v = find(flights, functor, f);
       if (v.size() > max){
           max = v.size();
           retFlight = f.originCode;
       }
   }
   cout << "The city with the maximum outdegree is " << retFlight << ", with " << max << " departures." << endl;
}

If (vec.size > max)
		Max = vec.size
		City = f.depart	

int main(){
    vector<Flight>flights;
    ifstream ifs("HW3Data.txt");
	if (!ifs){
		cerr << "File could not be opened!" << endl;
		exit(1);
	}
    int flightNumber;
    string originCity;
    string destCity;
    int flightDuration;
    while (ifs >> flightNumber >> originCity >> destCity >> flightDuration){
        Flight newFlight;
        newFlight.flightNumber = flightNumber;
        newFlight.originCity = originCity;
        newFlight.destCity = destCity;
        newFlight.flightDuration = flightDuration;
        flights.push_back(newFlight);
    }
    maxOutdegree(flights);
}



//Implementation (.cpp) file for a queue
 //---------------------------------------------------------------
// File: Code131_Queue.cpp
// Purpose: Implementation file for a demonstration of a queue  
//		implemented as an array.    Data type: Character
// Programming Language: C++
// Author: Dr. Rick Coleman
// Date: February 11, 2002
//---------------------------------------------------------------
#include "Code131_Queue.h"


//--------------------------------------------
// Function: Code131_Queue()
// Purpose: Class constructor
// Returns: void
//--------------------------------------------
Code131_Queue::Code131_Queue()
{
	head = tail = -1;
}

//--------------------------------------------
// Function: Code131_Queue()
// Purpose: Class destructor
// Returns: void
//--------------------------------------------
Code131_Queue::~Code131_Queue()
{
	// Nothing to do here since the memory used
	// for the queue is freed automatically.
}

//--------------------------------------------
// Function: ClearQueue()
// Purpose: Remove all items from the queue
// Returns: void
//--------------------------------------------
void Code131_Queue::ClearQueue()
{
	head = tail = -1; // Reset indices to start over
}

//--------------------------------------------
// Function: Enqueue()
// Purpose: Enqueue an item into the queue.
// Returns: true if enqueue was successful
//		or false if the enqueue failed.
// Note: We let head and tail continuing 
//		increasing and use [head % MAX_SIZE] 
//		and [tail % MAX_SIZE] to get the real
//		indices.  This automatically handles
//		wrap-around when the end of the array
//		is reached.
//--------------------------------------------
bool Code131_Queue::Enqueue(char ch)
{
	// Check to see if the Queue is full
	if(isFull()) return false;

	// Increment tail index
	tail++;
	// Add the item to the Queue
	theQueue[tail % MAX_SIZE] = ch;
	return true;
}

//--------------------------------------------
// Function: Dequeue()
// Purpose: Dequeue an item from the Queue.
// Returns: true if dequeue was successful
//		or false if the dequeue failed.
//--------------------------------------------
char Code131_Queue::Dequeue()
{
	char ch;

	// Check for empty Queue
	if(isEmpty()) return '\0';  // Return null character if queue is empty
	else
	{
		head++;
		ch = theQueue[head % MAX_SIZE];		// Get character to return
		return ch;				// Return popped character
	}
}

//--------------------------------------------
// Function: isEmpty()
// Purpose: Return true if the queue is empty
// Returns: true if empty, otherwise false
//--------------------------------------------
bool Code131_Queue::isEmpty()
{
	return (head == tail);
}

//--------------------------------------------
// Function: isFull()
// Purpose: Return true if the queue is full
// Returns: true if full, otherwise false
//--------------------------------------------
bool Code131_Queue::isFull()
{
	// Queue is full if tail has wrapped around
	//	to location of the head.  See note in
	//	Enqueue() function.
	return ((tail - MAX_SIZE) == head);
}


/*Queue - Linked List implementation*/
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
// Two glboal variables to store address of front and rear nodes. 
struct Node* front = NULL;
struct Node* rear = NULL;

// To Enqueue an integer
void Enqueue(int x) {
	struct Node* temp = 
		(struct Node*)malloc(sizeof(struct Node));
	temp->data =x; 
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

// To Dequeue an integer.
void Dequeue() {
	struct Node* temp = front;
	if(front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

int Front() {
	if(front == NULL) {
		printf("Queue is empty\n");
		return;
	}
	return front->data;
}

void Print() {
	struct Node* temp = front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue 
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();
}

// Stack - Object oriented implementation using arrays
#include <iostream>
using namespace std;
#define MAX_SIZE 101 

class Stack
{
private:
  int A[MAX_SIZE];  // array to store the stack
	int top;   // variable to mark the top index of stack. 
public:
	// constructor
	Stack()
	{
		top = -1; // for empty array, set top = -1
	}

	// Push operation to insert an element on top of stack. 
	void Push(int x) 
	{
	  if(top == MAX_SIZE -1) { // overflow case. 
			printf("Error: stack overflow\n");
			return;
		}
		A[++top] = x;
	}
 
	// Pop operation to remove an element from top of stack.
	void Pop() 
	{
		if(top == -1) { // If stack is empty, pop should throw error. 
			printf("Error: No element to pop\n");
			return;
		}
		top--;
	}
 
	// Top operation to return element at top of stack. 
	int Top() 
	{
		return A[top];
	}
 
	// This function will return 1 (true) if stack is empty, 0 (false) otherwise
	int IsEmpty()
	{
		if(top == -1) return 1;
		return 0;
	}

	// ONLY FOR TESTING - NOT A VALID OPERATION WITH STACK 
	// This function is just to test the implementation of stack. 
	// This will print all the elements in the stack at any stage. 
	void Print() {
		int i;
		printf("Stack: ");
		for(i = 0;i<=top;i++)
			printf("%d ",A[i]);
		printf("\n");
	}
};

int main()
{
    // Code to test the implementation. 
    // calling Print() after each push or pop to see the state of stack. 
	Stack S;
	S.Push(2);S.Print();
	S.Push(5);S.Print();
	S.Push(10);S.Print();
	S.Pop();S.Print();
	S.Push(12);S.Print();
}


//STACK USING ARRAYS

class IntStack
{
public:
   IntStack(int num) {  top = 0; maxelem = num; s = new int[maxelem]; }
   void  push(int t)
   {
      if (top == maxelem) return;
      s[top++] = t;
   }
   int pop()
   {
      if (top == 0) return -1;
      return s[--top];
   }
   void display()
   {
     if (top == 0) { cout << "(empty)\n";  return; }
     for (int t=0 ; t < top ; t++) cout << s[t] << " ";
     cout << "\n";
   }
   int   empty()  {  return top == 0;  }
private:
   int *s;
   int top;
   int maxelem;
};

void main()
{
   IntStack *s = new IntStack(100);
   int d;

   s->display();
   s->push(1);
   s->display();
   s->push(2);
   s->display();
   s->push(3);
   s->display();
   s->push(4);
   s->display();
   s->pop();
   s->display();
   s->pop();
   s->display();
   s->push(10);
   s->display();
   s->pop();
   s->display();
   s->pop();
   s->display();
   s->pop();
   s->display();
   s->pop();
   s->display();
   s->pop();
   s->display();
}

//STACK USING LINKED LIST

//   Creating a NODE Structure
struct node
{
    int data;
    struct node *next;
};

// Creating a class STACK
class stack
{
    struct node *top;
    public:
    stack() // constructure
    {
        top=NULL;
    }
    void push(); // to insert an element
    void pop();  // to delete an element
    void show(); // to show the stack
};
// PUSH Operation
void stack::push()
{
    int value;
    struct node *ptr;
    cout<<"nPUSH Operationn";
    cout<<"Enter a number to insert: ";
    cin>>value;
    ptr=new node;
    ptr->data=value;
    ptr->next=NULL;
    if(top!=NULL)
        ptr->next=top;
    top=ptr;
    cout<<"nNew item is inserted to the stack!!!";

}

// POP Operation
void stack::pop()
{
    struct node *temp;
    if(top==NULL)
    {
        cout<<"nThe stack is empty!!!";
    }
    temp=top;
    top=top->next;
    cout<<"nPOP Operation........nPoped value is "<<temp->data;
    delete temp;
}

// Show stack
void stack::show()
{
    struct node *ptr1=top;
    cout<<"nThe stack isn";
    while(ptr1!=NULL)
    {
        cout<<ptr1->data<<" ->";
        ptr1=ptr1->next;
    }
    cout<<"NULLn";
}

// Main function
int main()
{
    stack s;
    int choice;
    while(1)
    {
        cout<<"n-----------------------------------------------------------";
        cout<<"nttSTACK USING LINKED LISTnn";
        cout<<"1:PUSHn2:POPn3:DISPLAY STACKn4:EXIT";
        cout<<"nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.show();
                break;
            case 4:
                return 0;
                break;
            default:
                cout<<"Please enter correct choice(1-4)!!";
                break;
        }
    }
    return 0;
}

//STACK USING LINKED LIST

#include<iostream>
using namespace std;
//Define node pointer
struct node{
	int data;
	node* next;
};
//Head and tail pointers
node* head;
node*tail;
//Push element in stack
void push(node *& head, node *&tail, int data)
{
	if (head==NULL)
	{   node* n= new node;
	    n->data=data;
	    n->next=NULL;
		head=n;
		tail=n;
	}
	else if (head!=NULL)
	{
	  node* n= new node;
	  n->data=data;
	  n->next=head; 
		head=n;
	}
}
//Show elements in stack
void showdata(node *& head)
{    node* temp=new node;
     temp=head;
	if (temp==NULL)
	{
	cout<<"The stack is empty"<<endl;
	}
	else
	{
		cout<<"The elements in the stack are: "<<endl;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
}
// Pop first element in stack
void pop(node *&head, node *& tail)
{
	if (head==NULL)
	{
		cout<<"The stack is empty"<<endl;
	}
	else if (head==tail)
	{   cout<<"The value "<<head->data<<" was popped"<<endl;
	    delete head; 
		head=NULL;
		tail=NULL;
	}
	else 
	{
		node* delptr=new node;
		delptr=head;
		head=head->next;
		cout<<"The value "<<delptr->data<<" was popped"<<endl;
		delete delptr;
	}
}
//Show top-most element in stack
void top(node *& head)
{
	node* temp=new node;
	temp=head;
	if (temp==NULL)
	{
	cout<<"The stack is empty"<<endl;
    }   
	else
	{
	cout<<"The value at the top of the stack is "<<temp->data<<endl;
    }
}
//Show number of elements in stack
void sizeofstack(node *& head)
{   
    node* temp = new node;
	temp=head; 
	int count=0;
	if (temp==NULL)
	{
	cout<<"The size of the stack is "<<count<<endl;
    }
	else
	{
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
		cout<<"The size of the stack is "<<count<<endl;
	}
}
//Destroy stack
void destroystack(node *& head)
{
	node* delptr=new node;
	if (head==NULL)
	{
	cout<<"The stack is empty"<<endl;	
	}
	else
	{
	while(head!=NULL)
	{
	delptr=head;
	head=head->next;
	delete delptr;
  }
  cout<<"Stack has been destroyed!"<<endl;
  }
}
//Menu function
char menu()
{
char choice;
    cout<<"Menu: \n";
    cout<<"1. Push values in stack."<<endl;
    cout<<"2. Pop value from top of stack."<<endl;
    cout<<"3. Show the stack."<<endl;
    cout<<"4. Show the top of the stack."<<endl;
    cout<<"5. Number of elements in stack."<<endl;
    cout<<"6. Destroy stack."<<endl;
    cout<<"7. Exit."<<endl;
    cout<<"Enter your choice (1-6) from above: ";
    cin>>choice;
    return choice;
}
//Main function
int main()
{
	node* head;
	node* tail;
	head=NULL;
	tail=NULL;
    char choice;
    do{
    cout<<"-----------------------------------------------------"<<endl;
	choice=menu();
	cout<<"-----------------------------------------------------"<<endl;
	switch(choice)
    {
    	case '1':
    	int data;
		cout<<"Enter value to be stored in stack: ";
		cin>>data; 
		push(head,tail,data);
		break;
		
		case '2': 
		pop(head,tail);
		break;
		case '3':
		showdata(head);
		break;
		case '4':
		top(head);
		break;
		case '5':
		sizeofstack(head);
		break;		
		case '6':
		destroystack(head);
		break;
		default:
		cout<<"Exiting Menu";
	}
}while(choice!='7');
		return 0;
	
}

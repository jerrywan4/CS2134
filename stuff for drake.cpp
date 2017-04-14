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
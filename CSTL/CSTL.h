#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0

// Generalized Structure of node For Singly Linked List
template <class T>
struct node
{
	T Data;
	struct node *Next;
};

// Generalized Structure of node For Queue
template <class T>
struct qnode
{
	int P;
	T data;
	struct qnode *next;
};

// Generalized Structure of node For GEN_STACK
template <class T>
struct snode
{
	T data;
	struct snode *next;
};

// Generalized Structure of node For Doubly Linked List
template <class T>
struct dnode
{
	T Data;
	struct dnode *Next;
	struct dnode *Prev;
};

template <class T>
struct tnode
{
	T data;
	struct tnode<T> *lchild;
	struct tnode<T> *rchild;
};

//Abstract Class of Linked_List
template <class T>
class Linked_List
{
protected:
	virtual void InsertFirst(T) = 0;
	virtual void InsertLast(T) = 0;
	virtual void InsertAtPos(T, int) = 0;
	virtual void Display() = 0;
	virtual int Count() = 0;
	virtual void DeleteFirst() = 0;
	virtual void DeleteLast() = 0;
	virtual void DeleteAtPos(int) = 0;
};

///////////////////////////////////////////////////////////////////////
//
//	ClassName 		:GEN_SLLL
//	Description		:This is class designed for Singly linear linked list
//	Author			:Pranav Choudhary
///////////////////////////////////////////////////////////////////////

//Generic Class For Singly Linear Linked List

template <class T>
class GEN_SLLL : protected Linked_List<T>
{
private:
	struct node<T> *Head; //Start Pointer
	struct node<T> *Tail; //End  Pointer
	int size;

public:
	GEN_SLLL();
	~GEN_SLLL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);
	void Display();
	void DisplayR();
	int Count();
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	int Frequency(T);
	int FirstOccurance(T);
	int LastOccurance(T);
	T Largest();
	T Smallest();
	void ReverseList();
	void Concat(GEN_SLLL<T> &op1, GEN_SLLL<T> &op2);

	template <class X>
	friend bool operator==(GEN_SLLL<X> &op1, GEN_SLLL<X> &op2); //Compares Linked List For Equality
	template <class X>
	friend bool operator>(GEN_SLLL<X> &op1, GEN_SLLL<X> &op2); //Check For Greater than
	template <class X>
	friend bool operator<(GEN_SLLL<X> &op1, GEN_SLLL<X> &op2); //Check for Less Than
};

///////////////////////////////////////////////////////////////////////
//
//	ClassName 		:GEN_SCLL
//	Description		:This is class designed Singly Circular linked list
//	Author			:Pranav Choudhary
//
///////////////////////////////////////////////////////////////////////

template <class T>
class GEN_SCLL : protected Linked_List<T>
{
private:
	struct node<T> *Head;
	struct node<T> *Tail;
	T size;

public:
	GEN_SCLL();
	~GEN_SCLL();

	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Frequency(T);
	int FirstOccurance(T);
	int LastOccurance(T);
	T Largest();
	T Smallest();
	int Count();
	void Concat(GEN_SCLL<T> &op1, GEN_SCLL<T> &op2);

	template <class X>
	friend bool operator<(GEN_SCLL<X> &op1, GEN_SCLL<X> &op2); //Check for Less Than
	template <class X>
	friend bool operator>(GEN_SCLL<X> &op1, GEN_SCLL<X> &op2); //Check For Greater than
	template <class X>
	friend bool operator==(GEN_SCLL<X> &op1, GEN_SCLL<X> &op2); //Compares Linked List For Equality
};

///////////////////////////////////////////////////////////////////////
//
//	ClassName 		:GEN_DLLL
//	Description		:This is class designed for Doubly linear linked list
//	Author			:Pranav Choudhary
///////////////////////////////////////////////////////////////////////

//Generic Class For Singly Circular Linked List

template <class T>
class GEN_DLLL : protected Linked_List<T>
{
private:
	struct dnode<T> *Head;
	struct dnode<T> *Tail;
	int size;

public:
	GEN_DLLL();
	~GEN_DLLL();

	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	void DisplayB();
	int Count();
	int Frequency(T);
	int FirstOccurance(T);
	int LastOccurance(T);
	T Largest();
	T Smallest();
	void Concat(GEN_DLLL<T> &op1, GEN_DLLL<T> &op2);
	template <class X>
	friend bool operator==(GEN_DLLL<X> &op1, GEN_DLLL<X> &op2); //Compares Linked List For Equality
	template <class X>
	friend bool operator>(GEN_DLLL<X> &op1, GEN_DLLL<X> &op2); //Check For Greater than
	template <class X>
	friend bool operator<(GEN_DLLL<X> &op1, GEN_DLLL<X> &op2); //Check for Less Than
};

///////////////////////////////////////////////////////////////////////
//
//	ClassName 		:GEN_DCLL
//	Description		:This is class designed for Doubly Circular linked list
//	Author			:Pranav Choudhary
///////////////////////////////////////////////////////////////////////

//Generic Class For Doubly Linear Linked List

template <class T>
class GEN_DCLL : protected Linked_List<T>
{
private:
	struct dnode<T> *Head;
	struct dnode<T> *Tail;
	int size;

public:
	GEN_DCLL();
	~GEN_DCLL();

	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T, int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	void DisplayR();
	int Count();
	int Frequency(T);
	int FirstOccurance(T);
	int LastOccurance(T);
	T Largest();
	T Smallest();
	void Concat(GEN_DCLL<T> &op1, GEN_DCLL<T> &op2);
	template <class X>
	friend bool operator==(GEN_DCLL<X> &op1, GEN_DCLL<X> &op2); //Compares Linked List For Equality
	template <class X>
	friend bool operator>(GEN_DCLL<X> &op1, GEN_DCLL<X> &op2); //Check For Greater than
	template <class X>
	friend bool operator<(GEN_DCLL<X> &op1, GEN_DCLL<X> &op2); //Check for Less Than
};

///////////////////////////////////////////////////////////////////////
//
//	ClassName 		:GEN_QUEUE
//	Description		:This is class designed for Queue
//	Author			:Pranav Choudhary
///////////////////////////////////////////////////////////////////////

//Generic Class For Queue

template <class T>
struct Node
{
	T Data;
	struct Node *Next;
};

template <class T>
class GEN_QUEUE
{
private:
	struct Node<T> *Head;
	struct Node<T> *Tail;

public:
	GEN_QUEUE();
	~GEN_QUEUE();
	void Enqueue(T);
	T Dequeue();
	void Display();
	int Count();
};

//////////////////////////////////////////////////////////////
//
//	ClassName 		:GEN_PRI_QUEUE
//	Description		:This is class designed for priority queue
//	Author			:Pranav Choudhary
//
//////////////////////////////////////////////////////////////

//Generic Class For Priority Queue

template <class T>
class GEN_PRI_QUEUE
{
private:
	struct qnode<T> *Front;
	struct qnode<T> *Rear;
	int size;

public:
	GEN_PRI_QUEUE();
	~GEN_PRI_QUEUE();
	void Enqueue(T, int);
	T Dequeue();
	void Display();
	int Count();
};

///////////////////////////////////////////////////////////////////
//	
//	ClassName 		:GEN_TREE
//	Description		:This is class designed for Binary Search Tree
//	Author			:Pranav Choudhary
//
///////////////////////////////////////////////////////////////////

template <class T>
class GEN_TREE
{
private:
	struct tnode<T> *Head;
	void Insert(struct tnode<T> **, T);
	void Inorder(struct tnode<T> *);
	void Preorder(struct tnode<T> *);
	void Postorder(struct tnode<T> *);
	int Count(struct tnode<T> *);
	bool Search(struct tnode<T> *, T);
	void DeleteGEN_TREE(struct tnode<T> *);
	int CountLeaf(struct tnode<T> *);
	int CountNonLeaf(struct tnode<T> *);
	int Level(struct tnode<T> *, T);
	T Minimum(struct tnode<T> *);
	T Maximum(struct tnode<T> *);

public:
	GEN_TREE();
	void Insert(T);
	void Inorder();
	void Preorder();
	void Postorder();
	int Count();
	bool Search(T);
	void DeleteGEN_TREE();
	int CountLeaf();
	int CountNonLeaf();
	int Level(T);
	T Minimum();
	T Maximum();
};

///////////////////////////////////////////////////////////////////
//	
//	ClassName 		:GEN_TREE
//	Description		:This is class designed for stack
//	Author			:Pranav Choudhary
//
///////////////////////////////////////////////////////////////////
template<class T>
class GEN_STACK
{
    private:
        T   *Arr;
        int iTop;
        int iSize;
    
    public:
    /* Parameterized constructor with default args */
    GEN_STACK(int);
    /* Destructor */
    ~GEN_STACK();
    /* IsEmpty: check stack is empty or not */
    bool IsEmpty();
    /* IsFull: check stack is full or not */
    bool IsFull();
    /* Push: Push element in stack */
    void Push(T);
    /* Pop: Pop element from stack */
    T Pop();
    /* Display elements in stack */
    void Display();

};// end of class GEN_STACK declaration

////////////////////////////////////////////// End of CSTL.h ///////////////////////////////////////////

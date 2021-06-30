/////////////////////////////////////////////////////////////////////
//
//	This Program Contains Following Data structures
//
//	1.Singly Linear Linked List
//	2.Singly Circular Linked List
//	3.Doubly Linear Linked List
//	4.Doubly Circular Linked List
//	5.Stack(Dynamic)
//	6.Queue(Dynamic)
//	7.Priority Queue(Dynamic)
//  8.Tree
//
/////////////////////////////////////////////////////////////////////

#include "CSTL.h"

template <class T>
bool operator==(GEN_SLLL<T> &op1, GEN_SLLL<T> &op2) //Compares Linked List For Equality
{
	struct node<T> *temp1 = op1.Head;
	struct node<T> *temp2 = op2.Head;

	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if (temp1->Data != temp2->Data)
		{
			break;
		}
		temp1 = temp1->Next;
		temp2 = temp2->Next;
	}
	if ((temp1 == NULL) && (temp2 == NULL))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
bool operator>(GEN_SLLL<T> &op1, GEN_SLLL<T> &op2) //Check For Greater than
{
	struct node<T> *temp1 = op1.Head;
	struct node<T> *temp2 = op2.Head;

	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if ((temp1->Data) < (temp2->Data))
		{
			break;
		}
		temp1 = temp1->Next;
		temp2 = temp2->Next;
	}
	if ((temp1 == NULL) && (temp2 == NULL))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
bool operator<(GEN_SLLL<T> &op1, GEN_SLLL<T> &op2) //Check for Less Than
{
	struct node<T> *temp1 = op1.Head;
	struct node<T> *temp2 = op2.Head;

	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if ((temp1->Data) > (temp2->Data))
		{
			break;
		}
		temp1 = temp1->Next;
		temp2 = temp2->Next;
	}
	if ((temp1 == NULL) && (temp2 == NULL))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
GEN_SLLL<T>::GEN_SLLL() //CONSTRUCTOR
{
	Head = NULL;
	Tail = NULL;
	size = 0;
}

template <class T>
GEN_SLLL<T>::~GEN_SLLL() //DESTRUCTOR
{
	printf("Inside Destructor");
	if (Head != NULL)
	{
		struct node<T> *nTemp = NULL;
		while (Head != NULL)
		{
			nTemp = Head;
			Head = Head->Next;
			delete nTemp;
			size--;
		}
	}
}

template <class T>
void GEN_SLLL<T>::InsertFirst(T tVal) //GENERIC FUNCTION TO DISPLAY SINGLY LINEAR LINKED LIST
{
	struct node<T> *newn = NULL;
	newn = new struct node<T>;
	if (newn == NULL)
	{
		return;
	}

	newn->Next = NULL;
	newn->Data = tVal;

	if (Head == NULL)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn->Next = Head;
		Head = newn;
	}
	size++;
}

template <class T>
void GEN_SLLL<T>::DisplayR() //GENERIC FUNCTION TO DISPLAY SINGLY LINEAR LINKED LIST IN REVERSE MANNER
{
	struct node<T> *temp = Head;
	T Arr[size];
	int i = 0;
	while (temp != NULL)
	{
		Arr[i] = temp->Data;
		temp = temp->Next;
		i++;
	}
	i--;
	while (i >= 0)
	{
		cout << "| " << Arr[i] << " |"
			 << "->";
		i--;
	}
	cout << "NULL\n";
}

template <class T>
void GEN_SLLL<T>::Display() //GENERIC FUNCTION TO DISPLAY SINGLY LINEAR LINKED LIST
{
	struct node<T> *temp = Head;
	while (temp != NULL)
	{
		cout << "| " << temp->Data << " |"
			 << "->";
		temp = temp->Next;
	}
	cout << "NULL\n";
}

template <class T>
int GEN_SLLL<T>::Count() //GENERIC FUNCTION TO COUNT NODES IN SINGLY LINEAR LINKED LIST
{
	return this->size;
}

template <class T>
void GEN_SLLL<T>::InsertLast(T tVal) //GENERIC FUNCTION TO INSERT NODE AT LAST POSITION IN SINGLY LINEAR LINKED LIST
{
	struct node<T> *newn = NULL;
	newn = new struct node<T>;

	if (newn == NULL)
	{
		return;
	}

	newn->Next = NULL;
	newn->Data = tVal;

	if (Head == NULL)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->Next = newn;
		Tail = newn;
	}
	size++;
}

template <class T>
void GEN_SLLL<T>::InsertAtPos(T tVal, int iPos) //GENERIC FUNCTION TO INSERT NODE AT GIVEN POSITION IN SLLL
{
	if ((Head == NULL) || (iPos > size + 1) || (iPos <= 0))
	{
		return;
	}
	else if (iPos == 1)
	{
		InsertFirst(tVal);
	}
	else if (iPos == size + 1)
	{
		InsertLast(tVal);
	}
	else
	{
		struct node<T> *newn = NULL;
		struct node<T> *temp = Head;

		newn = new struct node<T>;
		if (newn == NULL)
		{
			return;
		}

		newn->Next = NULL;
		newn->Data = tVal;

		for (int i = 1; i < (iPos - 1); i++)
		{
			temp = temp->Next;
		}
		newn->Next = temp->Next;
		temp->Next = newn;
		size++;
	}
}
template <class T>
void GEN_SLLL<T>::DeleteFirst() //GENERIC FUNCTION TO DELETE FIRST NODE IN SLLL
{
	struct node<T> *temp = Head;
	if (Head == NULL)
	{
		return;
	}
	else
	{
		Head = Head->Next;
		delete (temp);
		size--;
	}
}

template <class T>
void GEN_SLLL<T>::DeleteLast() //GENERIC FUNCTION TO DELETE LAST NODE IN SLLL
{
	if (Head == NULL)
	{
		return;
	}
	else if (Head->Next == NULL)
	{
		delete Head;
		Head = NULL;
		size--;
	}
	else
	{
		struct node<T> *temp = Head;

		while (temp->Next != Tail)
		{
			temp = temp->Next;
		}
		delete Tail;
		Tail = temp;
		Tail->Next = NULL;
		size--;
	}
}

template <class T>
void GEN_SLLL<T>::DeleteAtPos(int iPos) //GENERIC FUNCTION TO DELETE NODE FROM GIVEN POSITION IN SLLL
{
	if ((Head == NULL) || (iPos <= 0) || (iPos > size))
	{
		return;
	}
	else if (iPos == 1)
	{
		DeleteFirst();
	}
	else if (iPos == size)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *target = NULL;
		struct node<T> *Navigate = Head;

		for (int i = 1; i < (iPos - 1); i++)
		{
			Navigate = Navigate->Next;
		}
		target = Navigate->Next;
		Navigate->Next = target->Next;
		delete target;
		size--;
	}
}

template <class T>
int GEN_SLLL<T>::Frequency(T tVal) //GENERIC FUNCTION TO COUNT FREQUENCY OF GIVEN DATA IN SLLL
{
	struct node<T> *temp = Head;
	int iCnt = 0;
	while (temp != NULL)
	{
		if (temp->Data == tVal)
		{
			iCnt++;
		}
		temp = temp->Next;
	}
	return iCnt;
}

template <class T>
int GEN_SLLL<T>::FirstOccurance(T tVal) //GENERIC FUNCTION TO SEARCH FIRST OCCURANCE  OF GIVEN DATA IN SLLL
{
	struct node<T> *temp = Head;
	int iCnt = 1, iPos = 0;
	while (temp != NULL)
	{
		if ((temp->Data) == tVal)
		{
			iPos = iCnt;
			break;
		}
		iCnt++;
		temp = temp->Next;
	}
	return iPos;
}

template <class T>
int GEN_SLLL<T>::LastOccurance(T tVal) //GENERIC FUNCTION TO SEARCH LAST OCCURANCE OF GIVEN DATA IN SLLL
{
	struct node<T> *temp = Head;
	int iCnt = 1, iPos = 0;
	while (temp != NULL)
	{
		if ((temp->Data) == tVal)
		{
			iPos = iCnt;
		}
		iCnt++;
		temp = temp->Next;
	}
	return iPos;
}

template <class T>
T GEN_SLLL<T>::Largest() //GENERIC FUNCTION TO FIND LARGEST OF GIVEN DATA IN SLLL
{
	struct node<T> *temp = Head;
	int tMax = 0;
	tMax = temp->Data;
	while (temp != NULL)
	{
		if ((temp->Data) >= tMax)
		{
			tMax = temp->Data;
		}
		temp = temp->Next;
	}
	return tMax;
}

template <class T>
T GEN_SLLL<T>::Smallest() //GENERIC FUNCTION TO FIND SMALLEST OF GIVEN DATA IN SLLL
{
	struct node<T> *temp = Head;
	int tMin = 0;
	tMin = temp->Data;
	while (temp != NULL)
	{
		if ((temp->Data) <= tMin)
		{
			tMin = temp->Data;
		}
		temp = temp->Next;
	}
	return tMin;
}

template <class T>
void GEN_SLLL<T>::ReverseList() //GENERIC FUNCTION TO REVERSE LINKED LIST IN PLACE
{
	struct node<T> *NEXT = NULL;
	struct node<T> *curr = Head;
	struct node<T> *PREV = NULL;

	if (Head == NULL)
	{
		return;
	}
	else
	{
		while (curr != NULL)
		{
			NEXT = curr->Next; //make current node's Next node as Next
			curr->Next = PREV; //store PREV value in current node's Next value
			PREV = curr;	   //make current node as PREV for further operations
			curr = NEXT;	   //move to Next node;
		}
		Head = PREV; //at last PREV will contain Last node address
	}
}

template <class T>
void GEN_SLLL<T>::Concat(GEN_SLLL<T> &op1, GEN_SLLL<T> &op2) ////GENERIC FUNCTION TO CONCAT TWO LINKED LIST
{
	struct node<T> *temp = op2.Head;

	if ((op1.Head == NULL) && (op2.Head == NULL))
	{
		return;
	}
	while (temp != NULL)
	{
		struct node<T> *newn = new struct node<T>;
		newn->Next = NULL;
		newn->Data = temp->Data;
		op1.Tail->Next = newn;
		op1.Tail = newn;
		temp = temp->Next;
		op1.size++;
	}
}


template <class T>
bool operator==(GEN_SCLL<T> &op1, GEN_SCLL<T> &op2) //Compares Linked List For Equality
{
	struct node<T> *temp1 = op1.Head;
	struct node<T> *temp2 = op2.Head;

	if ((temp1 == NULL) || (temp2 == NULL))
	{
		cout << "Can't Compare\n";
		return FALSE;
	}

	do
	{
		if (temp1->Data != temp2->Data)
		{
			break;
		}

		temp1 = temp1->Next;
		temp2 = temp2->Next;

	} while ((temp1 != op1.Tail->Next) && (temp2 != op2.Tail->Next));

	if ((temp1 == op1.Tail->Next) && (temp2 == op2.Tail->Next))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
bool operator>(GEN_SCLL<T> &op1, GEN_SCLL<T> &op2) //Check For Greater than
{
	struct node<T> *temp1 = op1.Head;
	struct node<T> *temp2 = op2.Head;

	if ((temp1 == NULL) || (temp2 == NULL))
	{
		cout << "Can't Compare\n";
		return FALSE;
	}

	do
	{
		if ((temp1->Data) < (temp2->Data))
		{
			break;
		}
		temp1 = temp1->Next;
		temp2 = temp2->Next;
	} while ((temp1 != op1.Tail->Next) && (temp2 != op2.Tail->Next));

	if ((temp1 == NULL) && (temp2 == NULL))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
bool operator<(GEN_SCLL<T> &op1, GEN_SCLL<T> &op2) //Check for Less Than
{
	struct node<T> *temp1 = op1.Head;
	struct node<T> *temp2 = op2.Head;

	if ((temp1 == NULL) || (temp2 == NULL))
	{
		cout << "Can't Compare\n";
		return FALSE;
	}

	do
	{
		if ((temp1->Data) > (temp2->Data))
		{
			break;
		}
		temp1 = temp1->Next;
		temp2 = temp2->Next;
	} while ((temp1 != op1.Tail->Next) && (temp2 != op2.Tail->Next));

	if ((temp1 == op1.Tail->Next) && (temp2 == op2.Tail->Next))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
GEN_SCLL<T>::GEN_SCLL()
{
	Head = NULL;
	Tail = NULL;
	size = 0;
}

template <class T>
GEN_SCLL<T>::~GEN_SCLL()
{
	struct node<T> *temp = NULL;
	if ((Head != NULL) && (Tail != NULL))
	{
		do
		{
			temp = Head;
			Head = Head->Next;
			Tail->Next = Head;
			delete temp;

		} while (Head != Tail->Next);
	}
}

template <class T>
void GEN_SCLL<T>::Display()
{
	struct node<T> *temp = Head;
	if ((Head == NULL) && (Tail == NULL))
	{
		return;
	}
	do
	{
		cout << "|" << temp->Data << "|->";
		temp = temp->Next;
	} while (temp != Tail->Next);
}

template <class T>
int GEN_SCLL<T>::Count()
{
	return this->size;
}

template <class T>
void GEN_SCLL<T>::InsertFirst(T tVal)
{
	struct node<T> *newn = NULL;
	newn = new struct node<T>;

	newn->Next = NULL;
	newn->Data = tVal;

	if ((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn->Next = Head;
		Head = newn;
	}
	Tail->Next = Head;
	size++;
}

template <class T>
void GEN_SCLL<T>::InsertLast(T tVal)
{
	struct node<T> *newn = NULL;

	newn = new struct node<T>;
	newn->Next = NULL;
	newn->Data = tVal;

	if ((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->Next = newn;
		Tail = Tail->Next;
	}
	Tail->Next = Head;
	size++;
}

template <class T>

void GEN_SCLL<T>::DeleteFirst()
{
	if ((Head == NULL) && (Tail == NULL))
	{
		return;
	}
	else if (Head == Tail)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Head = Head->Next;
		delete Tail->Next;
		Tail->Next = Head;
	}
	size--;
}

template <class T>
void GEN_SCLL<T>::DeleteLast()
{
	if ((Head == NULL) && (Tail == NULL))
	{
		return;
	}
	else if (Head == Tail)
	{
		delete Tail;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		struct node<T> *temp = Head;
		while (temp->Next != Tail)
		{
			temp = temp->Next;
		}
		delete Tail;
		Tail = temp;
		Tail->Next = Head;
	}
	size--;
}

template <class T>
void GEN_SCLL<T>::InsertAtPos(T tVal, int iPos)
{
	if ((Head == NULL) || (Tail == NULL) || (iPos <= 0) || (iPos > size + 1))
	{
		return;
	}
	else if (iPos == 1)
	{
		InsertFirst(tVal);
	}
	else if (iPos == size + 1)
	{
		InsertLast(tVal);
	}
	else
	{
		struct node<T> *newn = NULL;
		struct node<T> *temp = Head;

		newn = new struct node<T>;
		if (newn == NULL)
		{
			return;
		}

		newn->Next = NULL;
		newn->Data = tVal;

		for (int i = 1; i < (iPos - 1); i++)
		{
			temp = temp->Next;
		}
		newn->Next = temp->Next;
		temp->Next = newn;
		size++;
	}
}

template <class T>
void GEN_SCLL<T>::DeleteAtPos(int iPos)
{
	if ((Head == NULL) || (Tail == NULL) || (iPos <= 0) || (iPos > size))
	{
		return;
	}
	else if (iPos == 1)
	{
		DeleteFirst();
	}
	else if (iPos == size)
	{
		DeleteLast();
	}
	else
	{
		struct node<T> *temp = Head;
		struct node<T> *target = NULL;

		for (int i = 1; i < (iPos - 1); i++)
		{
			temp = temp->Next;
		}
		target = temp->Next;
		temp->Next = target->Next;
		delete target;
		size--;
	}
}

template <class T>
int GEN_SCLL<T>::Frequency(T tVal)
{
	struct node<T> *temp = Head;
	int iCnt = 0;
	do
	{
		if (temp->Data == tVal)
		{
			iCnt++;
		}
		temp = temp->Next;
	} while (temp != Tail->Next);
	return iCnt;
}

template <class T>
int GEN_SCLL<T>::FirstOccurance(T tVal)
{
	struct node<T> *temp = Head;
	int iCnt = 1, iPos = 0;
	do
	{
		if ((temp->Data) == tVal)
		{
			iPos = iCnt;
			break;
		}
		iCnt++;
		temp = temp->Next;
	} while (temp != Tail->Next);
	return iPos;
}

template <class T>
int GEN_SCLL<T>::LastOccurance(T tVal)
{
	struct node<T> *temp = Head;
	int iCnt = 1, iPos = 0;
	do
	{
		if ((temp->Data) == tVal)
		{
			iPos = iCnt;
		}
		iCnt++;
		temp = temp->Next;
	} while (temp != Tail->Next);
	return iPos;
}

template <class T>
T GEN_SCLL<T>::Largest()
{
	struct node<T> *temp = Head;
	int tMax = 0;
	tMax = temp->Data;
	do
	{
		if ((temp->Data) >= tMax)
		{
			tMax = temp->Data;
		}
		temp = temp->Next;
	} while (temp != Tail->Next);
	return tMax;
}

template <class T>
T GEN_SCLL<T>::Smallest()
{
	struct node<T> *temp = Head;
	int tMin = 0;
	tMin = temp->Data;
	do
	{
		if ((temp->Data) <= tMin)
		{
			tMin = temp->Data;
		}
		temp = temp->Next;
	} while (temp != Tail->Next);
	return tMin;
}

template <class T>
void GEN_SCLL<T>::Concat(GEN_SCLL<T> &op1, GEN_SCLL<T> &op2)
{
	struct node<T> *temp = op1.Head;

	if ((op1.Head == NULL) && (op2.Head == NULL))
	{
		return;
	}
	op1.Tail->Next = op2.Head;
	while (op1.Tail != op2.Tail)
	{
		op1.Tail = op1.Tail->Next;
	}
	op1.Tail->Next = op1.Head;

	op1.size = op1.size + op2.size;
}

template <class T>
bool operator==(GEN_DLLL<T> &op1, GEN_DLLL<T> &op2) //Compares Linked List For Equality
{
	struct dnode<T> *temp1 = op1.Head;
	struct dnode<T> *temp2 = op2.Head;

	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if (temp1->Data != temp2->Data)
		{
			break;
		}
		temp1 = temp1->Next;
		temp2 = temp2->Next;
	}
	if ((temp1 == NULL) && (temp2 == NULL))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
bool operator>(GEN_DLLL<T> &op1, GEN_DLLL<T> &op2) //Check For Greater than
{
	struct dnode<T> *temp1 = op1.Head;
	struct dnode<T> *temp2 = op2.Head;

	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if ((temp1->Data) < (temp2->Data))
		{
			break;
		}
		temp1 = temp1->Next;
		temp2 = temp2->Next;
	}
	if ((temp1 == NULL) && (temp2 == NULL))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
bool operator<(GEN_DLLL<T> &op1, GEN_DLLL<T> &op2) //Check for Less Than
{
	struct dnode<T> *temp1 = op1.Head;
	struct dnode<T> *temp2 = op2.Head;

	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if ((temp1->Data) > (temp2->Data))
		{
			break;
		}
		temp1 = temp1->Next;
		temp2 = temp2->Next;
	}
	if ((temp1 == NULL) && (temp2 == NULL))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
GEN_DLLL<T>::GEN_DLLL()
{
	Head = NULL;
	Tail = NULL;
	size = 0;
}

template <class T>
GEN_DLLL<T>::~GEN_DLLL()
{
	struct dnode<T> *temp = NULL;
	while (Head != NULL)
	{
		temp = Head;
		Head = Head->Next;
		delete temp;
	}
}

template <class T>
void GEN_DLLL<T>::Display()
{
	struct dnode<T> *temp = Head;
	cout << "\nNULL";
	while (temp != NULL)
	{
		cout << "<-"
			 << "|" << temp->Data << "|"
			 << "->";
		temp = temp->Next;
	}
	cout << "NULL\n";
}

template <class T>
void GEN_DLLL<T>::DisplayB()
{
	struct dnode<T> *temp = Tail;
	cout << "\nNULL";
	while (temp != NULL)
	{
		cout << "<-"
			 << "|" << temp->Data << "|"
			 << "->";
		temp = temp->Prev;
	}
	cout << "NULL\n";
}

template <class T>
int GEN_DLLL<T>::Count()
{
	return this->size;
}

template <class T>
void GEN_DLLL<T>::InsertFirst(T tVal)
{
	struct dnode<T> *newn = NULL;
	newn = new struct dnode<T>;
	if (newn == NULL)
	{
		return;
	}
	newn->Next = NULL;
	newn->Prev = NULL;
	newn->Data = tVal;

	if (Head == NULL)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Head->Prev = newn;
		newn->Next = Head;
		Head = newn;
	}
	size++;
}

template <class T>
void GEN_DLLL<T>::InsertLast(T tVal)
{
	struct dnode<T> *newn = NULL;
	newn = new struct dnode<T>;
	if (newn == NULL)
	{
		return;
	}
	newn->Next = NULL;
	newn->Prev = NULL;
	newn->Data = tVal;

	if (Head == NULL)
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->Next = newn;
		newn->Prev = Tail;
		Tail = newn;
	}
	size++;
}

template <class T>
void GEN_DLLL<T>::DeleteFirst()
{
	if (Head == NULL)
	{
		return;
	}
	else if (Head->Next == NULL)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
		size--;
	}
	else
	{
		Head = Head->Next;
		delete Head->Prev;
		Head->Prev = NULL;
		size--;
	}
}

template <class T>
void GEN_DLLL<T>::DeleteLast()
{
	if (Head == NULL)
	{
		return;
	}
	else if (Head->Next == NULL)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
		size--;
	}
	else
	{
		Tail = Tail->Prev;
		delete Tail->Next;
		Tail->Next = NULL;
		size--;
	}
}

template <class T>
void GEN_DLLL<T>::InsertAtPos(T tVal, int iPos)
{
	if ((Head == NULL) || (iPos < 1) || (iPos > (Count() + 1)))
	{
		return;
	}
	if (iPos == 1)
	{
		InsertFirst(tVal);
	}
	else if (iPos == (Count() + 1))
	{
		InsertLast(tVal);
	}
	else
	{
		struct dnode<T> *newn = NULL;
		struct dnode<T> *temp = Head;
		newn = new struct dnode<T>;
		if (newn == NULL)
		{
			return;
		}
		newn->Next = NULL;
		newn->Prev = NULL;
		newn->Data = tVal;

		for (T i = 1; i < (iPos - 1); i++)
		{
			temp = temp->Next;
		}
		newn->Next = temp->Next;
		temp->Next->Prev = newn;
		temp->Next = newn;
		newn->Prev = temp;
		size++;
	}
}

template <class T>
void GEN_DLLL<T>::DeleteAtPos(int iPos)
{
	if ((Head == NULL) || (iPos < 1) || (iPos > Count()))
	{
		return;
	}
	if (iPos == 1)
	{
		DeleteFirst();
	}
	else if (iPos == Count())
	{
		DeleteLast();
	}
	else
	{
		struct dnode<T> *temp = Head;

		for (int i = 1; i < (iPos - 1); i++)
		{
			temp = temp->Next;
		}
		temp->Next = temp->Next->Next;
		delete (temp->Next->Prev);
		temp->Next->Prev = temp;
		size--;
	}
}

template <class T>
int GEN_DLLL<T>::Frequency(T tVal)
{
	struct dnode<T> *temp = Head;
	int iCnt = 0;
	while (temp != NULL)
	{
		if (temp->Data == tVal)
		{
			iCnt++;
		}
		temp = temp->Next;
	}
	return iCnt;
}

template <class T>
int GEN_DLLL<T>::FirstOccurance(T tVal)
{
	struct dnode<T> *temp = Head;
	int iCnt = 1, iPos = 0;
	while (temp != NULL)
	{
		if ((temp->Data) == tVal)
		{
			iPos = iCnt;
			break;
		}
		iCnt++;
		temp = temp->Next;
	}
	return iPos;
}

template <class T>
int GEN_DLLL<T>::LastOccurance(T tVal)
{
	struct dnode<T> *temp = Head;
	int iCnt = 1, iPos = 0;
	while (temp != NULL)
	{
		if ((temp->Data) == tVal)
		{
			iPos = iCnt;
		}
		iCnt++;
		temp = temp->Next;
	}
	return iPos;
}

template <class T>
T GEN_DLLL<T>::Largest()
{
	struct dnode<T> *temp = Head;
	int tMax = 0;
	tMax = temp->Data;
	while (temp != NULL)
	{
		if ((temp->Data) >= tMax)
		{
			tMax = temp->Data;
		}
		temp = temp->Next;
	}
	return tMax;
}

template <class T>
T GEN_DLLL<T>::Smallest()
{
	struct dnode<T> *temp = Head;
	int tMin = 0;
	tMin = temp->Data;
	while (temp != NULL)
	{
		if ((temp->Data) <= tMin)
		{
			tMin = temp->Data;
		}
		temp = temp->Next;
	}
	return tMin;
}

template <class T>
void GEN_DLLL<T>::Concat(GEN_DLLL<T> &op1, GEN_DLLL<T> &op2)
{
	struct dnode<T> *temp = op1.Head;

	if ((op1.Head == NULL) && (op2.Head == NULL))
	{
		return;
	}
	op1.Tail->Next = op2.Head;
	op2.Head->Prev = op1.Tail;

	while (op1.Tail != op2.Tail)
	{
		op1.Tail = op1.Tail->Next;
	}

	op1.size = op1.size + op2.size;
}

template <class T>
bool operator==(GEN_DCLL<T> &op1, GEN_DCLL<T> &op2) //Compares Linked List For Equality
{
	struct dnode<T> *temp1 = op1.Head;
	struct dnode<T> *temp2 = op2.Head;

	if ((temp1 == NULL) || (temp2 == NULL))
	{
		cout << "Can't Compare\n";
		return FALSE;
	}

	do
	{
		if (temp1->Data != temp2->Data)
		{
			break;
		}
		temp1 = temp1->Next;
		temp2 = temp2->Next;
	} while ((temp1 != op1.Tail->Next) && (temp2 != op2.Tail->Next));

	if ((temp1 == op1.Tail->Next) && (temp2 == op2.Tail->Next))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
bool operator>(GEN_DCLL<T> &op1, GEN_DCLL<T> &op2) //Check For Greater than
{
	struct dnode<T> *temp1 = op1.Head;
	struct dnode<T> *temp2 = op2.Head;

	if ((temp1 == NULL) || (temp2 == NULL))
	{
		cout << "Can't Compare\n";
		return FALSE;
	}

	do
	{
		if ((temp1->Data) < (temp2->Data))
		{
			break;
		}

		temp1 = temp1->Next;
		temp2 = temp2->Next;
	} while ((temp1 != op1.Tail->Next) && (temp2 != op2.Tail->Next));

	cout << op1.Tail->Data;
	cout << op1.Tail->Data;

	if ((temp1 == op1.Tail->Next) && (temp2 == op2.Tail->Next))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
bool operator<(GEN_DCLL<T> &op1, GEN_DCLL<T> &op2) //Check for Less Than
{
	struct dnode<T> *temp1 = op1.Head;
	struct dnode<T> *temp2 = op2.Head;

	if ((temp1 == NULL) || (temp2 == NULL))
	{
		cout << "Can't Compare\n";
		return FALSE;
	}

	do
	{
		if ((temp1->Data) > (temp2->Data))
		{
			break;
		}
		temp1 = temp1->Next;
		temp2 = temp2->Next;
	} while ((temp1 != op1.Tail->Next) && (temp2 != op2.Tail->Next));

	if ((temp1 == op1.Tail->Next) && (temp2 == op2.Tail->Next))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
GEN_DCLL<T>::GEN_DCLL()
{
	this->Head = NULL;
	this->Tail = NULL;
	this->size = 0;
}

template <class T>
GEN_DCLL<T>::~GEN_DCLL()
{
	struct dnode<T> *temp = NULL;
	if ((Head != NULL) && (Tail != NULL))
	{
		do
		{
			temp = Head;
			Head = Head->Next;
			Tail->Next = Head;
			delete temp;

		} while (Head != Tail->Next);
	}
}

template <class T>
void GEN_DCLL<T>::InsertFirst(T tVal)
{
	struct dnode<T> *newn = new struct dnode<T>;

	newn->Next = NULL;
	newn->Prev = NULL;
	newn->Data = tVal;

	if ((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		newn->Next = Head;
		Head->Prev = newn;
		Head = newn;
	}
	Tail->Next = Head;
	Head->Prev = Tail;
	size++;
}

template <class T>
void GEN_DCLL<T>::InsertLast(T tVal)
{
	struct dnode<T> *newn = new struct dnode<T>;

	newn->Next = NULL;
	newn->Prev = NULL;
	newn->Data = tVal;

	if ((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->Next = newn;
		newn->Prev = Tail;
		Tail = newn;
	}
	Tail->Next = Head;
	Head->Prev = Tail;
	size++;
}

template <class T>
void GEN_DCLL<T>::Display()
{
	struct dnode<T> *temp = Head;
	/*for(int i=1;i<=size;i++)
	{
		cout<<"<-|"<<temp->Data<<"|->";
		temp=temp->Next;
	}*/
	temp = Head;
	if ((Head == NULL) && (NULL == Tail))
	{
		return;
	}
	cout << "\n->";
	do
	{
		cout << "<-|" << temp->Data << "|->";
		temp = temp->Next;
	} while (temp != Tail->Next);
	cout << "<-\n";
}

template <class T>
void GEN_DCLL<T>::DisplayR()
{
	struct dnode<T> *temp = Tail;
	/*for(int i=1;i<=size;i++)
	{
		cout<<"<-|"<<temp->Data<<"|->";
		temp=temp->Prev;
	}*/

	temp = Tail;
	if ((Head == NULL) && (NULL == Tail))
	{
		return;
	}
	cout << "\n->";
	do
	{
		cout << "<-|" << temp->Data << "|->";
		temp = temp->Prev;
	} while (temp != Head->Prev);
	cout << "<-\n";
}

template <class T>
void GEN_DCLL<T>::DeleteFirst()
{
	if ((Head == NULL) && (NULL == Tail))
	{
		return;
	}
	else if (Head == Tail)
	{
		delete Head;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Head = Head->Next;
		delete Head->Prev;
		Tail->Next = Head;
		Head->Prev = Tail;
		size--;
	}
}

template <class T>
void GEN_DCLL<T>::DeleteLast()
{
	if ((Head == NULL) && (NULL == Tail))
	{
		return;
	}
	else if (Head == Tail)
	{
		delete Tail;
		Head = NULL;
		Tail = NULL;
	}
	else
	{
		Tail = Tail->Prev;
		delete Tail->Next;
		Tail->Next = Head;
		Head->Prev = Tail;
		size--;
	}
}

template <class T>
void GEN_DCLL<T>::InsertAtPos(T tVal, int iPos)
{

	if ((iPos < 1) || (iPos > size + 1))
	{
		return;
	}
	if (iPos == 1)
	{
		InsertFirst(tVal);
	}
	else if (iPos == size + 1)
	{
		InsertLast(tVal);
	}
	else
	{
		struct dnode<T> *newn = NULL;
		struct dnode<T> *temp = Head;
		newn = new struct dnode<T>;

		newn->Next = NULL;
		newn->Prev = NULL;
		newn->Data = tVal;

		for (int i = 1; i < iPos; i++)
		{
			temp = temp->Next;
		}

		temp->Prev->Next = newn;
		newn->Prev = temp->Prev;
		newn->Next = temp;
		temp->Prev = newn;
		size++;
	}
}

template <class T>
void GEN_DCLL<T>::DeleteAtPos(int iPos)
{
	if ((iPos < 1) || (iPos > size))
	{
		return;
	}
	if (iPos == 1)
	{
		DeleteFirst();
	}
	else if (iPos == size)
	{
		DeleteLast();
	}
	else
	{
		struct dnode<T> *temp = Head;
		for (int i = 1; i < iPos; i++)
		{
			temp = temp->Next;
		}
		temp->Prev->Next = temp->Next;
		temp->Next->Prev = temp->Prev;
		delete temp;
		size--;
	}
}

template <class T>
int GEN_DCLL<T>::Count()
{
	return this->size;
}

template <class T>
int GEN_DCLL<T>::Frequency(T tVal)
{
	struct dnode<T> *temp = Head;
	int iCnt = 0;
	do
	{
		if (temp->Data == tVal)
		{
			iCnt++;
		}
		temp = temp->Next;
	} while (temp != Tail->Next);
	return iCnt;
}

template <class T>
int GEN_DCLL<T>::FirstOccurance(T tVal)
{
	struct dnode<T> *temp = Head;
	int iCnt = 1, iPos = 0;
	do
	{
		if ((temp->Data) == tVal)
		{
			iPos = iCnt;
			break;
		}
		iCnt++;
		temp = temp->Next;
	} while (temp != Tail->Next);
	return iPos;
}

template <class T>
int GEN_DCLL<T>::LastOccurance(T tVal)
{
	struct dnode<T> *temp = Head;
	int iCnt = 1, iPos = 0;
	do
	{
		if ((temp->Data) == tVal)
		{
			iPos = iCnt;
		}
		iCnt++;
		temp = temp->Next;
	} while (temp != Tail->Next);
	return iPos;
}

template <class T>
T GEN_DCLL<T>::Largest()
{
	struct dnode<T> *temp = Head;
	int tMax = 0;
	tMax = temp->Data;
	do
	{
		if ((temp->Data) >= tMax)
		{
			tMax = temp->Data;
		}
		temp = temp->Next;
	} while (temp != Tail->Next);
	return tMax;
}

template <class T>
T GEN_DCLL<T>::Smallest()
{
	struct dnode<T> *temp = Head;
	int tMin = 0;
	tMin = temp->Data;
	do
	{
		if ((temp->Data) <= tMin)
		{
			tMin = temp->Data;
		}
		temp = temp->Next;
	} while (temp != Tail->Next);
	return tMin;
}

template <class T>
void GEN_DCLL<T>::Concat(GEN_DCLL<T> &op1, GEN_DCLL<T> &op2) ////GENERIC FUNCTION TO CONCAT TWO LINKED LIST
{
	struct dnode<T> *temp = op1.Head;

	if ((op1.Head == NULL) && (op2.Head == NULL))
	{
		return;
	}
	op1.Tail->next = op2.Head;
	op2.Head->Prev = op1.Tail;

	while (op1.Tail != op2.Tail)
	{
		op1.Tail = op1.Tail->Next;
	}

	op1.Tail->next = op1.Head;
	op1.Head->Prev = op1.Tail;

	op1.size = op1.size + op2.size;
}

template <class T>
GEN_QUEUE<T>::GEN_QUEUE()
{
	Head = NULL;
	Tail = NULL;
}

template <class T>
GEN_QUEUE<T>::~GEN_QUEUE()
{
	struct Node<T> *temp = NULL;
	while (Head != NULL)
	{
		temp = Head;
		Head = Head->Next;
		delete temp;
	}
}

template <class T>
void GEN_QUEUE<T>::Enqueue(T tVal)
{
	struct Node<T> *newn = NULL;

	newn = (struct Node<T> *)malloc(sizeof(struct Node<T>));
	newn->Next = NULL;
	newn->Data = tVal;

	if ((Head == NULL) && (Tail == NULL))
	{
		Head = newn;
		Tail = newn;
	}
	else
	{
		Tail->Next = newn;
		Tail = newn;
	}
}

template <class T>
T GEN_QUEUE<T>::Dequeue()
{
	if ((Head == NULL) && (Tail == NULL))
	{
		cout << "\nQUEUE is Empty\n";
		return -1;
	}
	if (Head == Tail)
	{
		T temp;
		temp = Head->Data;
		free(Head);
		Head = NULL;
		Tail = NULL;
		return temp;
	}
	else
	{
		T temp;
		struct Node<T> *p = Head;
		temp = Head->Data;
		Head = Head->Next;
		free(p);
		return temp;
	}
}

template <class T>
void GEN_QUEUE<T>::Display()
{
	struct Node<T> *temp = Head;
	while (temp != NULL)
	{
		cout << temp->Data << "\t";
		temp = temp->Next;
	}
}

template <class T>
int GEN_QUEUE<T>::Count()
{
	int iCnt = 0;
	struct Node<T> *temp = Head;
	while (temp != NULL)
	{
		iCnt++;
		temp = temp->Next;
	}
	return iCnt;
}

template <class T>
GEN_PRI_QUEUE<T>::GEN_PRI_QUEUE()
{
	Front = NULL;
	Rear = NULL;
	size = 0;
}

template <class T>
GEN_PRI_QUEUE<T>::~GEN_PRI_QUEUE()
{
	struct qnode<T> *temp = NULL;
	while (Front != NULL)
	{
		temp = Front;
		Front = Front->next;
		delete temp;
	}
}

template <class T>
void GEN_PRI_QUEUE<T>::Display()
{
	struct qnode<T> *temp = Front;
	while (temp != NULL)
	{
		cout << "|" << temp->data << ":" << temp->P << "|->";
		temp = temp->next;
	}
	cout << "NULL\n";
}

template <class T>
void GEN_PRI_QUEUE<T>::Enqueue(T tVal, int iP)
{
	struct qnode<T> *newn = NULL;

	newn = new struct qnode<T>;
	newn->data = tVal;
	newn->next = NULL;
	newn->P = iP;

	if ((Front == NULL) && (Rear == NULL))
	{
		Front = newn;
		Rear = newn;
	}
	else
	{
		Rear->next = newn;
		Rear = Rear->next;
	}
	size++;
}

template <class T>
T GEN_PRI_QUEUE<T>::Dequeue()
{
	if ((Front == NULL) && (Rear == NULL))
	{
		cout << "QUEUE Underflow\n";
		return -1;
	}
	else if (Front == Rear)
	{
		T tVal = Front->data;
		delete Front;
		Front = NULL;
		Rear = NULL;
		size--;
		return tVal;
	}
	else
	{
		int iCnt = 0;
		int iPos = 0, Pri = 0;
		struct qnode<T> *temp = Front;
		struct qnode<T> *target = NULL;
		Pri = temp->P;
		while (temp != NULL)
		{
			iCnt++;
			if (Pri <= temp->P)
			{
				Pri = temp->P;
				iPos = iCnt;
			}
			temp = temp->next;
		}
		if (iPos == 1)
		{
			T tVal = Front->data;
			temp = Front;
			Front = Front->next;
			delete temp;
			size--;
			return tVal;
		}
		else if (iPos == size)
		{
			temp = Front;
			for (int i = 1; i < size - 1; i++)
			{
				temp = temp->next;
			}
			T tVal = Rear->data;
			delete Rear;
			Rear = temp;
			Rear->next = NULL;
			size--;
			return tVal;
		}
		else
		{
			temp = Front;
			for (int i = 1; i < iPos - 1; i++)
			{
				temp = temp->next;
			}
			target = temp->next;
			T tVal = target->data;
			temp->next = target->next;
			delete target;
			size--;
			return tVal;
		}
	}
}

template <class T>
int GEN_PRI_QUEUE<T>::Count()
{
	return size;
}
 ////////////////////////////////////////////////////////////
//
//  Name        :GEN_STACK
//  Input       :int
//  Returns     :   -
//  Description :constructor
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
template<class T>
GEN_STACK<T>::GEN_STACK(int iNum) 
{
    this->iSize = iNum;
    this->iTop = -1;
    this->Arr = new T[this->iSize];
}// end of constructor

////////////////////////////////////////////////////////////
//
//  Name        :~GEN_STACK
//  Input       :   -
//  Returns     :   -
//  Description :destructor
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
template<class T>
GEN_STACK<T>::~GEN_STACK()
{
   delete[] Arr;
}// end of destructor

////////////////////////////////////////////////////////////
//
//  Name        :IsEmpty
//  Input       :void
//  Returns     :bool
//  Description :Check whether stack is empty or not
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
template<class T>
bool GEN_STACK<T>::IsEmpty()
{
    if(this->iTop == -1)
    {
        return true;
    }
    else
    {
        return false;
    }    
}// end of IsEmpty

////////////////////////////////////////////////////////////
//
//  Name        :IsFull
//  Input       :void
//  Returns     :bool
//  Description :Check whether stack is full or not
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
template<class T>
bool GEN_STACK<T>::IsFull()
{
    if(this->iTop == iSize)
    {
        return true;
    }
    else
    {
        return false;
    }    
}// end of IsFull

////////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :void
//  Returns     :void
//  Description :Displays stack elements
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
template<class T>
void GEN_STACK<T>::Display()
{
    if(IsEmpty())
    {
        cout << "Cannot display stack is empty!!\n";
        return;
    }
    int i = 0;
    cout << "Top--->";
    for(i = this->iSize -1; i >= 0; i--)
    {
        cout << "\t| " << this->Arr[i] << " |" << endl;
    }
}// end of Display

////////////////////////////////////////////////////////////
//
//  Name        :Push
//  Input       :int
//  Returns     :void
//  Description :Push els in stack
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
template<class T>
void GEN_STACK<T>::Push(T tData)
{
    if(IsFull())
    {
        cout << "Stack is Full\n";
        return;
    }
    this->iTop++;
    this->Arr[iTop] = tData;
}// end of Push

////////////////////////////////////////////////////////////
//
//  Name        :Pop
//  Input       :void
//  Returns     :int
//  Description :Pop els from stack
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
template<class T>
T GEN_STACK<T>::Pop()
{
    if(IsEmpty())
    {
        cout << "Stack is Empty\n";
        return T(-1);
    }
    T tData = 0;
    tData = this->Arr[iTop--];
    return tData;
}// end of Push

template <class T>
GEN_TREE<T>::GEN_TREE()
{
	Head = NULL;
}

template <class T>
void GEN_TREE<T>::Insert(struct tnode<T> **First, T iNo)
{
	struct tnode<T> *newn = NULL;
	struct tnode<T> *temp = NULL;

	newn = (struct tnode<T> *)malloc(sizeof(struct tnode<T>));

	newn->rchild = NULL;
	newn->lchild = NULL;
	newn->data = iNo;

	if (*First == NULL)
	{
		*First = newn;
	}
	else
	{
		temp = *First;

		while (1)
		{
			if (iNo > temp->data)
			{
				if (temp->rchild == NULL)
				{
					temp->rchild = newn;
					break;
				}
				temp = temp->rchild;
			}
			else if (iNo < temp->data)
			{
				if (temp->lchild == NULL)
				{
					temp->lchild = newn;
					break;
				}
				temp = temp->lchild;
			}
			else if (iNo == temp->data)
			{
				free(newn);
				break;
			}
		}
	}
}

template <class T>
void GEN_TREE<T>::Inorder(struct tnode<T> *First)
{
	if (First != NULL)
	{
		Inorder(First->lchild);
		cout << First->data << " ";
		Inorder(First->rchild);
	}
}

template <class T>
void GEN_TREE<T>::Preorder(struct tnode<T> *First)
{
	if (First != NULL)
	{
		cout << First->data << " ";
		Preorder(First->lchild);
		Preorder(First->rchild);
	}
}

template <class T>
void GEN_TREE<T>::Postorder(struct tnode<T> *First)
{
	if (First != NULL)
	{
		Postorder(First->lchild);
		Postorder(First->rchild);
		cout << First->data << " ";
	}
}

template <class T>
bool GEN_TREE<T>::Search(struct tnode<T> *First, T iNo)
{
	while (First != NULL)
	{
		if (iNo == First->data)
		{
			break;
		}
		else if (iNo > First->data)
		{
			First = First->rchild;
		}
		else if (iNo < First->data)
		{
			First = First->lchild;
		}
	}
	if (First != NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template <class T>
int GEN_TREE<T>::Count(struct tnode<T> *First)
{
	static int iCnt = 0;
	if (First != NULL)
	{
		iCnt++;
		Count(First->lchild);
		Count(First->rchild);
	}
	return iCnt;
}

template <class T>
int GEN_TREE<T>::CountLeaf(struct tnode<T> *First)
{
	static int iCnt = 0;
	if (First != NULL)
	{
		if ((First->lchild == NULL) && (First->rchild == NULL))
		{
			iCnt++;
		}
		CountLeaf(First->lchild);
		CountLeaf(First->rchild);
	}
	return iCnt;
}

template <class T>
int GEN_TREE<T>::CountNonLeaf(struct tnode<T> *First)
{
	static int iCnt = 0;
	if (First != NULL)
	{
		if ((First->lchild != NULL) || (First->rchild != NULL))
		{
			iCnt++;
		}
		CountNonLeaf(First->lchild);
		CountNonLeaf(First->rchild);
	}
	return iCnt;
}

template <class T>
T GEN_TREE<T>::Minimum(struct tnode<T> *First)
{
	while (First->lchild != NULL)
	{
		First = First->lchild;
	}
	return First->data;
}

template <class T>
T GEN_TREE<T>::Maximum(struct tnode<T> *First)
{
	while (First->rchild != NULL)
	{
		First = First->rchild;
	}
	return First->data;
}

template <class T>
int GEN_TREE<T>::Level(struct tnode<T> *First, T iNo)
{
	int level = 0;
	while (First != NULL)
	{
		if (iNo == First->data)
		{
			break;
		}
		else if (iNo > First->data)
		{
			First = First->rchild;
			level++;
		}
		else if (iNo < First->data)
		{
			First = First->lchild;
			level++;
		}
	}
	if (First != NULL)
	{
		return level;
	}
	else
	{
		return -1;
	}
}

template <class T>
void GEN_TREE<T>::DeleteGEN_TREE(struct tnode<T> *First)
{
	if (First != NULL)
	{
		DeleteGEN_TREE(First->lchild);
		DeleteGEN_TREE(First->rchild);
		cout << "Deleted item\t" << First->data << " "
			 << "\n";
		free(First);
	}
}

template <class T>
void GEN_TREE<T>::Insert(T tVal)
{
	Insert(&Head, tVal);
}

template <class T>
int GEN_TREE<T>::Count()
{
	return Count(this->Head);
}

template <class T>
int GEN_TREE<T>::CountLeaf()
{
	return CountLeaf(this->Head);
}

template <class T>
int GEN_TREE<T>::CountNonLeaf()
{
	return CountNonLeaf(this->Head);
}

template <class T>
int GEN_TREE<T>::Level(T tVal)
{
	return Level(this->Head, tVal);
}
template <class T>
void GEN_TREE<T>::Inorder()
{
	Inorder(this->Head);
}

template <class T>
void GEN_TREE<T>::Preorder()
{
	Preorder(this->Head);
}

template <class T>
void GEN_TREE<T>::Postorder()
{
	Postorder(this->Head);
}

template <class T>
bool GEN_TREE<T>::Search(T tVal)
{
	return Search(this->Head, tVal);
}

template <class T>
T GEN_TREE<T>::Maximum()
{
	return Maximum(this->Head);
}

template <class T>
T GEN_TREE<T>::Minimum()
{
	return Minimum(this->Head);
}

template <class T>
void GEN_TREE<T>::DeleteGEN_TREE()
{
	DeleteGEN_TREE(this->Head);
}

///////////////////////////////////////////// End of CSTL.cpp ////////////////////////////////////////////

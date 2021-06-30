#include "CSTL.h"
//Entry Point Function
int main()
{

	//Objects of GEN_SLLL Class
	//You can Replace GEN_SLLL with other classes linke GEN_SCLL,GEN_DLLL,GEN_DCLL
	GEN_SLLL<int> iobj1, iobj2;
	GEN_SLLL<char> cobj1;
	GEN_SLLL<float> fobj1;
	GEN_SLLL<double> dobj1;

	//Objects of GEN_QUEUE Class
	GEN_QUEUE<int> qiobj;
	GEN_QUEUE<char> qcobj;
	GEN_QUEUE<float> qfobj;
	GEN_QUEUE<double> qdobj;

	//Objects of GEN_STACK Class
	GEN_STACK<float> siobj(10);
	GEN_STACK<char> scobj(5);

	//Objects of GEN_PRI_QUEUE Class
	GEN_PRI_QUEUE<int> pqiobj;

	//Objects of GEN_TREE class
	GEN_TREE<char> tobj;

	//Local Variables
	int ch = 0;
	int iRet = 0;
	char cRet = '\0';

	//Menu driven
	cout << "1. Linked List\n";
	cout << "2. Queue\n";
	cout << "3. Stack\n";
	cout << "4. Priority Queue\n";
	cout << "5. Binary Search Tree\n";
	cout << "Enter choice\n";
	cin >> ch;

	switch (ch)
	{
	case 1:
		cout << "InsertFirst in first linked list\n\n";
		iobj1.InsertFirst(40);
		iobj1.InsertFirst(30);
		iobj1.InsertFirst(20);
		iobj1.InsertFirst(10);
		iobj1.Display();
		cout << "Number of Nodes in first linked list:\t" << iobj1.Count() << "\n\n";

		cout << "InsertFirst in second linked list\n\n";
		iobj2.InsertFirst(400);
		iobj2.InsertFirst(300);
		iobj2.InsertFirst(200);
		iobj2.InsertFirst(100);
		iobj2.Display();
		cout << "Number of Nodes in second linked list:\t" << iobj1.Count() << "\n\n";

		cout << "Conct two linked list and store resultant linked list in first linked list\n";
		iobj1.Concat(iobj1, iobj2);
		iobj1.Display();
		cout << "Number of Nodes in first linked list:\t" << iobj1.Count() << "\n\n";

		cout << "InsertLast\n\n";
		iobj1.InsertLast(1111);
		iobj1.InsertLast(505);
		iobj1.InsertLast(105);
		iobj1.InsertLast(155);
		iobj1.Display();
		cout << "Number of Nodes in first linked list:\t" << iobj1.Count() << "\n\n";

		cout << "InsertAtPos\n\n";
		iobj1.InsertAtPos(1000, 11);
		iobj1.Display();
		cout << "Number of Nodes in first linked list:\t" << iobj1.Count() << "\n\n";

		cout << "DeleteFirst\n\n";
		iobj1.DeleteFirst();
		iobj1.Display();
		cout << "Number of Nodes in first linked list:\t" << iobj1.Count() << "\n\n";

		cout << "DeleteLast\n\n";
		iobj1.DeleteLast();
		iobj1.Display();
		cout << "Number of Nodes in first linked list:\t" << iobj1.Count() << "\n\n";

		cout << "DeleteAtPos\n\n";
		iobj1.DeleteAtPos(3);
		iobj1.Display();

		cout << "ReverseList\n\n";
		iobj1.ReverseList();
		iobj1.Display();
		cout << "Number of Nodes in first linked list:\t" << iobj1.Count() << "\n\n";

		cobj1.InsertFirst('P');
		cobj1.InsertFirst('Q');
		cobj1.InsertFirst('R');

		cobj1.Display();

		cout << iobj1.Frequency(10) << endl;
		cout << iobj1.FirstOccurance(10) << endl;
		cout << iobj1.LastOccurance(10) << endl;
		cout << iobj1.Largest() << endl;
		cout << iobj1.Smallest() << endl;

		iobj1.Display();
		cout << "\n\n";
		iobj2.Display();

		if (iobj1 == iobj2)
		{
			cout << "Both Linked Lists Are Equal\n";
		}
		else if (iobj1 > iobj2)
		{
			cout << "1st Linked list is Greater than 2nd\n";
		}
		else if (iobj1 < iobj2)
		{
			cout << "2nd Linked list is Greater than 1st\n";
		}
		else
		{
			cout << "Linked List are different\n";
		}
		break;

	case 2:
		qcobj.Enqueue('P');
		qcobj.Enqueue('R');

		qcobj.Display();
		cout << "\n"
			 << qcobj.Count() << "\n";

		cout << qcobj.Dequeue() << "\t";
		cout << qcobj.Dequeue() << "\t";
		iRet = qcobj.Dequeue();
		cout << iRet << "\n";

		qdobj.Enqueue(11.21);
		qdobj.Enqueue(21.51);

		qdobj.Display();
		cout << "\n"
			 << qdobj.Count() << "\n";

		cout << qdobj.Dequeue() << "\t";
		cout << qdobj.Dequeue() << "\t";
		cout << qdobj.Dequeue() << "\t";
		break;

	case 3:
		cout << "\nElement Pushed\n";
		siobj.Push(10.25);
		siobj.Push(20.36);
		siobj.Push(30.18);
		siobj.Push(40.69);
		siobj.Display();

		cout << "\nElement Poped\n";
		cout << siobj.Pop() << "\t";
		cout << siobj.Pop() << "\t";
		cout << siobj.Pop() << "\t";
		cout << siobj.Pop() << "\t";
		cout << siobj.Pop() << "\t";

		cout << "\nElement Pushed\n";
		scobj.Push('P');
		scobj.Push('Q');
		scobj.Push('R');
		scobj.Display();

		cout << "\nElement Poped\n";
		cout << scobj.Pop() << "\t";
		cout << scobj.Pop() << "\t";
		cout << scobj.Pop() << "\t";
		cout << scobj.Pop() << "\t";
		break;

	case 4:
		pqiobj.Enqueue(11, 25);
		pqiobj.Enqueue(16, 27);
		pqiobj.Enqueue(19, 18);
		pqiobj.Enqueue(40, 29);
		pqiobj.Enqueue(11, 1);
		pqiobj.Enqueue(17, 6);
		pqiobj.Enqueue(25, 16);
		pqiobj.Enqueue(36, 13);
		pqiobj.Enqueue(51, 35);
		pqiobj.Enqueue(71, 5);
		pqiobj.Enqueue(91, 15);
		pqiobj.Enqueue(81, 20);

		pqiobj.Display();
		cout << pqiobj.Count() << endl;

		cout << pqiobj.Dequeue() << endl;
		cout << pqiobj.Dequeue() << endl;
		cout << pqiobj.Dequeue() << endl;
		cout << pqiobj.Dequeue() << endl;
		cout << pqiobj.Dequeue() << endl;
		cout << pqiobj.Dequeue() << endl;
		cout << pqiobj.Dequeue() << endl;
		cout << pqiobj.Dequeue() << endl;
		cout << pqiobj.Dequeue() << endl;
		cout << pqiobj.Dequeue() << endl;
		cout << pqiobj.Dequeue() << endl;

	case 5:
		tobj.Insert('H');
		tobj.Insert('E');
		tobj.Insert('L');
		tobj.Insert('O');
		tobj.Insert('W');
		tobj.Insert('R');

		printf("Inorder\n");
		tobj.Inorder();

		printf("\nPreorder\n");
		tobj.Preorder();

		printf("\nPostorder\n");
		tobj.Postorder();

		iRet = tobj.Count();
		printf("\n%d Number of Nodes \n", iRet);

		iRet = tobj.CountLeaf();
		printf("%d Nummber of Leaf Nodes  \n", iRet);

		iRet = tobj.CountNonLeaf();
		printf("%d Nummber of Non Leaf Nodes  \n", iRet);

		cRet = tobj.Maximum();
		printf("%c is Maximum Node  \n", cRet);

		cRet = tobj.Minimum();
		printf("%c Minimum Node is \n", cRet);

		//cout<<"Enter the node to be Searched\n";
		iRet = tobj.Level('H');
		printf("Level of Node H Is %d  \n", iRet);
		tobj.DeleteGEN_TREE();
	}
	return 0;
}

/////////////////////////////////////////////// End of CSTLMain.cpp ///////////////////////////////////////

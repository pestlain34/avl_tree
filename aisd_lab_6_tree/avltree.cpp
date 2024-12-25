#include"avltree.h"
int GetHeight(Tree* node) {
	if (node == nullptr) {
		return 0;
	}
	return node->height;
}

void leftRotate(Tree*& root, Tree* x) {
	Tree* y = x->Right; 
	x->Right = y->Left;  
	if (y->Left != nullptr) {
		y->Left->Prev = x; 
	}
	y->Prev = x->Prev;    
	if (x->Prev == nullptr) {
		root = y;  
	}
	else if (x == x->Prev->Left) {
		x->Prev->Left = y;  
	}
	else {
		x->Prev->Right = y; 
	}
	y->Left = x;   
	x->Prev = y;    

	x->height = max(GetHeight(x->Left), GetHeight(x->Right)) + 1;
	y->height = max(GetHeight(y->Left), GetHeight(y->Right)) + 1;
}

void rightRotate(Tree*& root, Tree* y) {
	Tree* x = y->Left;       
	y->Left = x->Right;       
	if (x->Right) {
		x->Right->Prev = y;  
	}
	x->Prev = y->Prev;        
	if (!y->Prev) {
		root = x;             
	}
	else if (y == y->Prev->Left) {
		y->Prev->Left = x;    
	}
	else {
		y->Prev->Right = x;   
	}
	x->Right = y;             
	y->Prev = x;             

	
	y->height = max(GetHeight(y->Left), GetHeight(y->Right)) + 1;
	x->height = max(GetHeight(x->Left), GetHeight(x->Right)) + 1;
}

void BalanceTree(Tree*& Root, Tree* NewElem) {
	Tree* MainTree = NewElem;

	while (MainTree) {
		MainTree->height = max(GetHeight(MainTree->Left), GetHeight(MainTree->Right)) + 1;
		int balance = GetHeight(MainTree->Right) - GetHeight(MainTree->Left);

		if (balance == 2) { // Правое поддерево "тяжёлое"
			if (GetHeight(MainTree->Right->Right) >= GetHeight(MainTree->Right->Left)) {
				cout << "Выполняется простой поворот влево" << endl;
				leftRotate(Root, MainTree);
			}
			else {
				cout << "Выполняется большой поворот влево" << endl;
				BigLeftRotate(Root, MainTree);
			}
		}
		else if (balance == -2) { // Левое поддерево "тяжёлое"
			if (GetHeight(MainTree->Left->Left) >= GetHeight(MainTree->Left->Right)) {
				cout << "Выполняется простой поворот вправо" << endl;
				rightRotate(Root, MainTree);
			}
			else {
				cout << "Выполняется большой поворот вправо" << endl;
				BigRightRotate(Root, MainTree);
			}
		}

		if (MainTree->Prev) {
			MainTree = MainTree->Prev;
		}
		else {
			Root = MainTree;
			break;
		}
	}
}

void BigLeftRotate(Tree*& root, Tree* x) {
	rightRotate(root, x->Right);
	leftRotate(root, x);
}

void BigRightRotate(Tree*& root, Tree* x) {
	leftRotate(root, x->Left);
	rightRotate(root, x);
}



void AddTreeElem(Tree*& Root, Tree* NewElem)
{
	if (!Root)
	{
		Root = new Tree;
		Root->elem = NewElem->elem;
		Root->height = 1;
		Root->Prev = nullptr;
		Root->Left = nullptr;
		Root->Right = nullptr;
		return;
	}

	Tree* MainTree = Root;
	while (true)
	{
		if (NewElem->elem < MainTree->elem)
		{
			if (MainTree->Left)
				MainTree = MainTree->Left;
			else
			{
				MainTree->Left = NewElem;
				NewElem->Prev = MainTree;
				break;
			}
		}
		else
		{
			if (MainTree->Right)
				MainTree = MainTree->Right;
			else
			{
				MainTree->Right = NewElem;
				NewElem->Prev = MainTree;
				break;
			}
		}
	}
	BalanceTree(Root, MainTree);
}




void showutil(Tree* root, int space , int count) {
	if (root == nullptr) return;
	space += count;
	showutil(root->Right, space);
	cout << "\n";
	for (int i = count; i < space; i++) {
		cout << " ";
	}
	cout << root->elem<<"\n";
	showutil(root->Left, space);
}
void ShowTree(Tree* root) {
	cout << "Вывод состояния дерева" << endl;
	showutil(root, 0);
	cout << endl<<endl<<endl;
}



void DeleteTreeElem(Tree*& Root, Tree*& DeleteElem)
{
	Tree* MainTree = Root;
	Tree* TmpElem = nullptr;
	Tree* OneMoreTmp = nullptr;
	int counter = 0;
	while (true)
	{
		if (MainTree)
		{
			if (DeleteElem->elem == MainTree->elem)
			{
				if (MainTree->Prev || GetHeight(MainTree) > 1)
				{
					OneMoreTmp = MainTree;
					if (MainTree->Left || MainTree->Right)
					{
						if (MainTree->Right)
							MainTree = MainTree->Right;
						TmpElem = OneMoreTmp->Prev;
						while (MainTree->Left)
							MainTree = MainTree->Left;
						if (MainTree->Prev)
						{
							if (MainTree->Prev->Right == MainTree)
								MainTree->Prev->Right = nullptr;
							else
								MainTree->Prev->Left = nullptr;
						}
						if (TmpElem)
						{
							if (TmpElem->Right)
							{
								if (TmpElem->Right == OneMoreTmp)
									TmpElem->Right = MainTree;
								else
									TmpElem->Left = MainTree;

							}
							else
								TmpElem->Left = MainTree;
						}
						if (MainTree->Prev != OneMoreTmp)
							TmpElem = MainTree->Prev;
						else TmpElem = MainTree;
						MainTree->Prev = OneMoreTmp->Prev;
						if (OneMoreTmp->Right != MainTree)
						{
							MainTree->Right = OneMoreTmp->Right;
							if (MainTree->Right)
								MainTree->Right->Prev = MainTree;
						}
						else
							MainTree->Right = nullptr;
						if (OneMoreTmp->Left != MainTree)
						{
							MainTree->Left = OneMoreTmp->Left;
							if (MainTree->Left)
								MainTree->Left->Prev = MainTree;
						}
						else
							MainTree->Left = nullptr;
						BalanceTree(Root, TmpElem);
					}
					else
					{
						TmpElem = MainTree->Prev;
						if (TmpElem)
						{
							if (TmpElem->Right)
							{
								if (TmpElem->Right == MainTree)
									TmpElem->Right = nullptr;
								else
									TmpElem->Left = nullptr;
							}
							else

								TmpElem->Left = nullptr;
						}
						BalanceTree(Root, TmpElem);
					}
					cout << "Элемент был удален" << endl;
					ShowTree(Root);
					return;
				}
				else
				{
					Root = nullptr;
					cout << "Дерево пустое" << endl;
					return;
				}
			}
			else if (DeleteElem->elem > MainTree->elem)
				MainTree = MainTree->Right;
			else
				MainTree = MainTree->Left;
		}
		else
		{
			cout << "Такого элемента в дереве нет" << endl;
			return;
		}
	}
}
void searchtreeelement(Tree* tree, int value) {
	int steps = 0;
	Tree* curtree = tree;
	while (curtree) {
		steps++;
		if (curtree->elem == value) {
			cout << "Элемент " <<value<< " был найден за " << steps << " шагов" << endl;
			return;
		}
		else if (value < curtree->elem) curtree = curtree->Left;
		else curtree = curtree->Right;
	}
	cout << "Элемент " << value<< " не был найден за  " << steps << " шагов" << endl;
}

void zadanie(Tree*& root) {
	if (!root) {
		cout << "Дерево пустое" << endl;
		return;
	}
	queue<Tree*> q;
	q.push(root);
	Tree* prevnode = nullptr;
	while (!q.empty()) {
		Tree* cur = q.front();
		q.pop();
		if (cur->elem < 0) cur->elem = abs(cur->elem);
		if (cur->elem % 4 == 0) cur->elem = cur->elem / 2;
		if (prevnode) {
			cur->elem = abs(cur->elem - prevnode->elem);
		}
		prevnode = cur;
		if (cur->Left) {
			q.push(cur->Left);
		}
		if (cur->Right) {
			q.push(cur->Right);
		}
	}

}
void showobxod(Tree* Root) {
	queue<Tree*>q;
	q.push(Root);
	while (!q.empty()) {
		Tree* cur = q.front();
		q.pop();
		cout << cur->elem << " ";
		if (cur->Left) {
			q.push(cur->Left);
		}
		if (cur->Right) {
			q.push(cur->Right);
		}
	}
	cout << endl;
}

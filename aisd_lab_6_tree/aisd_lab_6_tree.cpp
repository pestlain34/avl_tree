#include"avltree.h"
int main()
{
    setlocale(LC_ALL, "ru");
    Tree* Root = nullptr;
    Tree* elem1 = new Tree{ 10, 1, nullptr, nullptr, nullptr };
    AddTreeElem(Root, elem1);
    ShowTree(Root);
    Tree* elem2 = new Tree{ 5, 1, nullptr, nullptr, nullptr };
    AddTreeElem(Root, elem2);
    ShowTree(Root);
    Tree* elem3 = new Tree{ 15, 1, nullptr, nullptr, nullptr };
    AddTreeElem(Root, elem3);
    ShowTree(Root);
    Tree* elem4 = new Tree{ 3, 1, nullptr, nullptr, nullptr };
    AddTreeElem(Root, elem4);
    ShowTree(Root);
    Tree* elem5 = new Tree{ 7, 1, nullptr, nullptr, nullptr };
    AddTreeElem(Root, elem5);
    ShowTree(Root);
    Tree* elem6 = new Tree{ 9, 1, nullptr, nullptr, nullptr };
    AddTreeElem(Root, elem6);
    ShowTree(Root);
    zadanie(Root);
    cout << "Дерево после выполнений условий задания" << endl << endl << endl;
    ShowTree(Root);
    cout << "Список узлов в порядке обхода дерева" << endl;
    showobxod(Root);

    searchtreeelement(Root, 8);
    searchtreeelement(Root, 20);
    return 0;
}
#ifndef AVLTREE_H
#define AVLTREE_H
#pragma once
#include<iostream>
#include<vector>
#include<string>
#include <fstream>
#include <sstream>
#include<cmath>
#include <iomanip>
#include<queue>
using namespace std;

struct Tree
{
    int elem; // содержимое узла
    int height; // высота узла
    Tree* Prev; // указатель на предка
    Tree* Left; // указатель на меньшего потомка
    Tree* Right; // указатель на большего потомка
};

// Прототипы функций
void leftRotate(Tree*& root, Tree* x);
void rightRotate(Tree*& Root, Tree* y);
void BigLeftRotate(Tree*& root, Tree* x);
void BigRightRotate(Tree*& root, Tree* x);
int GetHeight(Tree* node);
void BalanceTree(Tree*& Root, Tree* NewElem);
void AddTreeElem(Tree*& Root, Tree* NewElem);
void DeleteTreeElem(Tree*& Root, Tree*& DeleteElem);
void searchtreeelement(Tree* tree, int value);
void showutil(Tree* root, int space , int count = 10);
void ShowTree(Tree* root);
void zadanie(Tree*& root);
void showobxod(Tree* Root);

#endif //AVLTREE_H

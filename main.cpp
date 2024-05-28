#include <iostream>
#include <cstring>
#include <fstream>
#include "node.h"

//Colors
#define RESET "\033[0m"
#define RED   "\033[31m"
#define BLUE  "\033[34m" //Substitute for black

using namespace std;

struct Trunk { //Used for printing
    Trunk* previous;
    char* str;

    Trunk(Trunk* previous, char* str) {
        this->previous = previous;
        this->str = str;
    }
};

void showTrunks(Trunk* p) { //Used for printing
    if (p == NULL)
        return;

    showTrunks(p->previous);

    cout << p->str;
}

//Basic Tree Functions - Insertion
void PARSE(char* in, int* modify, int& count);
void ADD(Node*& head, Node*& current, Node*& previous, int value);
void FADD(Node*& head);
void PRINT(Node* root, Trunk* previous, bool isLeft);
//Basic Tree Functions - Deletion
bool SEARCH(Node* current, int& data);
void DELETE(Node* &head, Node* &v);

//For Insertion
void BALANCE(Node*& head, Node*& current);
void rotateLeft(Node*& head, Node*& current);
void rotateRight(Node*& head, Node*& current);

//For Deletion
Node* getSibling(Node* &x);
Node* successor(Node* &x);
Node* replaceNode(Node* &x);
bool hasRedChild(Node* &x);
void fixDoubleBlack(Node* &head, Node* &x);
void swapNodeValues(Node* &u, Node* &x);


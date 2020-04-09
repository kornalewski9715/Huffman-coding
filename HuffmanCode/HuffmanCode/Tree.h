#pragma once
#include <iostream>
#include<fstream>
#include<string>
#include"HTNode.h"
#include"Alphabet.h"
#include"Tlist.h"

using namespace std;

class Tree :public Tlist {
private:
    int i, l;
    string buf, exit, decod, com;
    HTNode* p, * r, * v1, * v2;
public:
    Tree();
    void MakeTree(HTNode*& root);
    void PREORDER(HTNode*& t, string b);
    void codH(HTNode*& t, char r, string& z);
    void HuffmanCode(HTNode*& t, Alphabet& A);
    void dictionary(HTNode* t, Alphabet& A, string& z);
    void HuffmanDecode();
};


#pragma once

#include <iostream>
#include<fstream>
#include<string>
#include"HTNode.h"
#include"Alphabet.h"
#include"Tlist.h"

using namespace std;

class Tlist {
private:
    HTNode* front, * back;
    int counter;
public:
    Tlist();
    ~Tlist();
    int size();
    HTNode* push_front(HTNode* p);
    void showKeys();
    void MakeList(HTNode*& root, Alphabet& A);
};

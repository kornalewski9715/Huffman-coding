#pragma once
#include <iostream>
#include<string>
#include"HTNode.h"

using namespace std;

class HTNode {
public:
    HTNode* next;
    HTNode* left; //lewy syn
    HTNode* right; //prawy syn
    string code;
    char ch;
    int count;
    HTNode();
};


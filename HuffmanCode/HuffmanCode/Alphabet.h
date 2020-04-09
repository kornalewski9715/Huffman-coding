#pragma once
#include <iostream>
#include<string>
#include"Alphabet.h"


using namespace std;

class Alphabet {
private:
    friend class Tlist;
    friend class Tree;
    string name, text, temphelp, alphabet, codded;
    int* afreq;
public:
    Alphabet();
    void open_f();
    void alfa();
    void wylicz();
    void sort();
    void display(bool x);
};


#include <iostream>
#include<fstream>
#include<string>
#include"HTNode.h"
#include"Alphabet.h"
#include"Tlist.h"

using namespace std;

Tlist::Tlist() {
    front = back = NULL;
    counter = 0;
}
Tlist:: ~Tlist() {
    HTNode* p;
    while (front)
    {
        p = front->next;
        delete front;
        front = p;
    }
}
int Tlist::size() {
    return counter;
}
HTNode* Tlist::push_front(HTNode* p) {
    p->next = front;
    front = p;
    if (!back) {
        back = front;
    }
    counter++;
    return front;
}
void Tlist::showKeys() {
    HTNode* p;
    if (!front) {
        cout << "Lista jest pusta" << endl;
    }
    else {
        p = front;
        while (p) {
            cout << p->ch << " " << p->count << " ";
            p = p->next;
        }
        cout << endl;
    }
}
void Tlist::MakeList(HTNode*& root, Alphabet& A) {
    HTNode* p;
    Tlist();
    for (int i = 0; i < A.alphabet.length(); i++) {
        p = new HTNode;
        p->next = root;
        p->left = NULL;
        p->right = NULL;
        p->ch = A.alphabet[i];
        p->count = A.afreq[i];
        root = p;
        push_front(p);
    }
}




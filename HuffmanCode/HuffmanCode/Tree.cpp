#include <iostream>
#include<fstream>
#include<string>
#include"HTNode.h"
#include"Alphabet.h"
#include"Tree.h"
#include"Tlist.h"

using namespace std;

Tree::Tree() {
    string decod = "";
    int i = 0;
    int l = 0;
    string buf = "", exit;
    string com = "";
    HTNode* p = NULL, * r = NULL, * v1 = NULL, * v2 = NULL;
}
void Tree::MakeTree(HTNode*& root) {
    while (true) {
        v1 = root;
        v2 = v1->next;

        if (!v2) {
            break;
        }

        l++;

        root = v2->next;

        p = new HTNode;
        p->left = v1;
        p->right = v2;
        p->count = v1->count + v2->count;

        if (!root || (p->count <= root->count)) {
            p->next = root;
            root = p;
            continue;
        }
        r = root;

        while (r->next && (p->count > r->next->count)) {
            r = r->next;
        }
        p->next = r->next;
        r->next = p;


    }

}
void Tree::PREORDER(HTNode*& t, string b) {
    if (t == nullptr)
        return;
    if (t->ch != '\0') {
        t->code = b;
    }
    if (t->left != nullptr)
        PREORDER(t->left, b + "0");
    if (t->right != nullptr)
        PREORDER(t->right, b + "1");
}
void Tree::codH(HTNode*& t, char r, string& z) {
    if (t->ch == r) {
        z += t->code;
    }
    else {
        if (t->left != nullptr)
            codH(t->left, r, z);
        if (t->right != nullptr)
            codH(t->right, r, z);
    }
}
void Tree::HuffmanCode(HTNode*& t, Alphabet& A) {
    for (int i = 0; i < A.text.length(); i++) {
        codH(t, A.text[i], A.codded);
    }
    fstream plik;
    plik.open("Compresion.txt", ios::out);
    if (plik.good() == true) {
        plik << A.codded;
    }
    else {
        cout << "Nie mozna odczytac pliku Compresion" << endl;
    }

}
void Tree::dictionary(HTNode* t, Alphabet& A, string& z) {
    fstream plik;
    plik.open("Dictionary.txt", ios::out | ios::trunc); // skasowanie poprzedniego s³wonika
    plik.close();
    for (int i = 0; i < A.alphabet.length(); i++) {
        fstream plik2;
        plik2.open("Dictionary.txt", ios::out | ios::app);
        if (plik2.good() == true) {
            if (t->ch == A.alphabet[i]) {
                z = t->code;

            }
            else {
                if (t->left != nullptr)
                    codH(t->left, A.alphabet[i], z);
                if (t->right != nullptr)
                    codH(t->right, A.alphabet[i], z);
            }
            plik2 << A.alphabet[i] << endl;
            plik2 << z << endl;
            z = "";
            plik2.close();
        }
        else {
            cout << "Nie mozna odczytac pliku Dictionary" << endl;
        }
    }
}
void Tree::HuffmanDecode() {
    ifstream plik6;
    plik6.open("Dictionary.txt", ios::in);
    if (plik6.good() != true) {
        cout << "Nie ma dostepu do pliku" << endl;
        system("pause");

    }
    else {
        while (!plik6.eof()) {
            getline(plik6, buf);
            i++;

        }
        plik6.close();
    }

    i -= 1;
    buf.clear();

    string* tabC = new string[i / 2];
    string* tabS = new string[i / 2];
    int a = 0;
    cout << "\n";


    ifstream plik7;
    plik7.open("Dictionary.txt", ios::in);
    if (plik7.good() != true) {
        cout << "Nie ma dostepu do pliku" << endl;
        system("pause");
    }
    else {
        while (true) {
            if (a < (i / 2)) {
                getline(plik7, tabS[a]);
                getline(plik7, tabC[a]);
            }
            else {
                break;
            }
            a++;
        }
        plik7.close();
    }
    fstream plik4;
    plik4.open("Compresion.txt", ios::in);
    if (plik4.good() != true) {
        cout << "Nie ma dostepu do pliku 3" << endl;
        system("pause");
    }
    else {
        getline(plik4, com);
        plik4.close();
    }
    int l = com.size();
    for (int ind = 0; ind < l; ++ind) {
        buf += com[ind];
        for (int jnd = 0; jnd < (i / 2); ++jnd) {
            if (tabC[jnd] == buf) {
                exit += tabS[jnd];
                buf.clear();
                break;
            }

        }

    }

    cout << "Podaj nazwe pliku wyjsciowego dekodowania" << endl;
    cin >> decod;
    decod += ".txt";
    ofstream plikz;
    plikz.open(decod, ios::out);
    if (plikz.good() != true) {
        cout << "Nie ma dostepu do pliku 2" << endl;
    }
    else {
        plikz << exit;
        plikz.close();
    }


    delete[] tabC;
    delete[] tabS;

    cout << "Wiadomosc zdekodowana" << endl;


}

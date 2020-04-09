#include <iostream>
#include<fstream>
#include<string>
#include"HTNode.h"
#include"Alphabet.h"

using namespace std;

Alphabet::Alphabet() {
    string nazwa = "", text = "", pom = "", alfabet = "", codded = "";
    int* wyliczenia = NULL;
}
void Alphabet::open_f() {
    cout << "Podaj plik do zakodowania" << endl;
    cin >> name;
    name += ".txt";
    fstream plik;
    plik.open(name, ios::in);
    if (plik.good() == true) {
        while (!plik.eof()) {
            getline(plik, temphelp);
            text += temphelp;
        }
        plik.close();
    }
    else {
        cout << "Nie mozna odczytac pliku" << endl;
    }
}
void Alphabet::alfa() {

    for (int i = 0; i < text.length(); i++) {
        bool rozne = true;
        if (i == 0) {
            alphabet = text[i];
        }
        if (i != 0 && alphabet[alphabet.length() - 1] != text[i]) {
            for (int x = 0; x < alphabet.length(); x++) {
                if (alphabet[x] == text[i]) {
                    rozne = false;
                }

            }
            if (rozne == true) {
                alphabet += text[i];
            }

        }

    }
    afreq = new int[alphabet.length()];
    wylicz();
    sort();
}
void Alphabet::wylicz() {
    for (int i = 0; i < alphabet.length(); i++) {
        afreq[i] = 0;
        for (int x = 0; x < text.length(); x++) {
            if (alphabet[i] == text[x]) {
                afreq[i]++;
            }
        }
    }

}
void Alphabet::sort() {
    int  tempi;
    char temp;
    for (int i = 0; i < alphabet.length() - 1; i++) {
        for (int j = 0; j < alphabet.length() - 1 - i; j++) {
            if (afreq[j] < afreq[j + 1])
            {
                tempi = afreq[j + 1];
                afreq[j + 1] = afreq[j];
                afreq[j] = tempi;

                temp = alphabet[j + 1];
                alphabet[j + 1] = alphabet[j];
                alphabet[j] = temp;
            }
        }
    }

}
void Alphabet::display(bool x) {
    if (x == true) {
        for (int i = 0; i < alphabet.length(); i++) {
            cout << alphabet[i] << " " << afreq[i] << " ";
        }
    }
    else if (x == false)
    {
        for (int i = 0; i < codded.length(); i++) {
            cout << codded[i];
        }

    }
}


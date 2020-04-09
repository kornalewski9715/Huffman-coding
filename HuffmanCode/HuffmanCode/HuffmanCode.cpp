// HuffmanCode.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include<fstream>
#include<string>
#include"HTNode.h"
#include"Alphabet.h"
#include"Tree.h"
#include"Tlist.h"
using namespace std;

int main()
{
    Alphabet Start;
    Tlist List;
    HTNode* root;
    Tree T;
    Start.open_f(); //Otwarcie pliku
    Start.alfa();   //Utworzenie alfabety
    List.MakeList(root, Start);//Stworzenie listy
    T.MakeTree(root);//Tworzenei drzewa na podstawie uporządkowanej listy
    T.PREORDER(root, "");//nadanie znakom odpowiedni kod składający się z 0 i 1
    string pom = ""; 
    T.dictionary(root, Start, pom); //Tworzenie słownika
    T.HuffmanCode(root, Start); //Kodowanie wiadomości
    List.~Tlist();
    T.HuffmanDecode();//Dekodowanie wiadomości
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

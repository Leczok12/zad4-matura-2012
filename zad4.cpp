#include <iostream>
#include <string>
#include <fstream>

char codeLetter(char l, int i, std::string key) {
    if (l > 90 || l < 65)
        return l;

    char nl = l + (key[i % key.length()] - 64);
    if (nl > 90)
        return nl -= 26;
    return nl;
}
char decodeLetter(char l, int i, std::string key) {
    if (l > 90 || l < 65)
        return l;

    char nl = l - (key[i % key.length()] - 64);
    if (nl < 65)
        return nl += 26;
    return nl;
}


int main()
{
    //===[ A ]===
    printf("podpunkt A - poczatek\n");

    std::fstream file_tj;
    std::fstream file_klucze1;
    std::fstream file_wynik4a;

    file_tj.open("tj.txt", std::ios::in);
    file_klucze1.open("klucze1.txt", std::ios::in);
    if (!file_tj || !file_klucze1) {
        printf("Brak pliku tj.txt lub klucze1.txt\n");
    };

    file_wynik4a.open("wynik4a.txt", std::ios::out | std::ios::trunc);
    if (!file_wynik4a) {
        printf("Problem ze stworzeniem lub otworzeniem pliku wynik4a.txt\n");
    }

    char a_word[50];
    char a_key[50];

    while (file_tj.getline(a_word,50) && file_klucze1.getline(a_key,50))
    {
        std::string s_word(a_word);
        std::string s_key(a_key);
        std::string resoult = "";

        for (int i = 0; i < s_word.length(); i++)
        {
            resoult += codeLetter(s_word[i], i, s_key);
        }

        file_wynik4a << resoult << "\n";
    }

    file_tj.close();
    file_klucze1.close();
    file_wynik4a.close();

    printf("podpunkt A - koniec\n");

    //===[ B ]===
    printf("podpunkt B - poczatek\n");

    std::fstream file_sz;
    std::fstream file_klucze2;
    std::fstream file_wynik4b;

    file_sz.open("sz.txt", std::ios::in);
    file_klucze2.open("klucze2.txt", std::ios::in);
    if (!file_sz || !file_klucze2) {
        printf("Brak pliku sz.txt lub klucze2.txt\n");
    };

    file_wynik4b.open("wynik4b.txt", std::ios::out | std::ios::trunc);
    if (!file_wynik4b) {
        printf("Problem ze stworzeniem lub otworzeniem pliku wynik4b.txt\n");
    }

    char b_word[50];
    char b_key[50];

    while (file_sz.getline(b_word, 50) && file_klucze2.getline(b_key, 50))
    {
        std::string s_word(b_word);
        std::string s_key(b_key);
        std::string resoult = "";

        for (int i = 0; i < s_word.length(); i++)
        {
            resoult += decodeLetter(s_word[i], i, s_key);
        }

        file_wynik4b << resoult << "\n";
    }

    file_sz.close();
    file_klucze2.close();
    file_wynik4b.close();

    printf("podpunkt B - koniec\n");
}

#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <locale>
#include <conio.h>
using namespace std;

class String {
private:
    char* str;
public:
    String() {
        const char *G = "FGHAf kjgs ihdgs";
        str = new char[strlen(G)+1];
        strcpy(str, G);

    }
    String(const char* FF) {
        int a = strlen(FF) + 1;
        str = new char[a];
        strcpy(str, FF);
    }
    ~String() {
        cout << "Удаляю строку... Прощайте друзья...";
        delete[] str;
    }
    void display() {
        cout << str << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    const char* GG = "Вкусно и точка";
    const char* GH = "С горы, с горы, с горы, я лечу";
    String MMM(GG);
    MMM.display();
    String Azino(GH);
    Azino.display();
    _getch();
    //Пытаюсь создать массив из элементов класса
    int a = 16;
    String* MN;
    MN = new String[a];
    for (int i = 0; i < a; i++) {
        MN[i].display();
    }
    delete[] MN;
    _getch();
}

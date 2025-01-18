#include <conio.h>
#include <iostream>
#include <locale>
using namespace std;

void perevod1(double& GG) {
    GG *= 2.54;
}
void perevod2(double* GG) {
    *GG *= 2.54;
}
void perevod3(double* GG, int a) {
    for (int i = 0; i < a; i++) {
        *GG++ *= 2.54;
    }
}
void obm(int*, int*);
void sorting(int* T, int raz) {
    for (int i = 0; i < raz - 1; i++) {
        for (int j = i + 1; j < raz; j++) {
            obm(T + i, T + j);
        }
    }
}
void obm(int* C1, int* C2) {
    if (*C1 > *C2) {
        int temp = *C1;
        *C1 = *C2;
        *C2 = temp;
    }
}
void kopiruem(char* str1, const char* str2) {
    while (*str2) {
        *str1++ = *str2++;
    }
    *str1 = '\x0';
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int A1 = 22;
    int A2 = 33;
    cout << &A1 << endl;
    cout << &A2 << endl << endl;
    int* B1 = &A1;
    int* B2 = &A2;
    cout << B1 << endl << B2 << endl << endl << endl;
    _getch();
    //Посмотрим операцию ссылки
    double v = 10.0;
    cout << v << endl;
    perevod1(v);
    cout << v << endl;
    //Операция указателей
    double w = 20.0;
    cout << w << endl;
    perevod2(&w);
    cout << w << endl << endl << endl;
    _getch();
    //Используем массив указателей
    double VW[] = { 12.0, 22.0, 83.15, 61.12, 10.0 };
    int a = sizeof(VW) / sizeof(*VW);
    for (int i = 0; i < sizeof(VW) / sizeof(*VW); i++) {
        cout << VW[i] << endl;
    }
    perevod3(VW, a);
    for (int i = 0; i < sizeof(VW) / sizeof(*VW); i++) {
        cout << VW[i] << endl;
    }
    cout << endl;
    _getch();
    //Херачим сортировку
    int mas[] = { 12, 32, 66, 109, 11, 14, 10, 28, 16, 104 };
    int raz = sizeof(mas) / sizeof(mas[0]);
    for (int i = 0; i < raz; i++) {
        cout << mas[i] << "  ";
    }
    cout << endl;
    sorting(mas, raz);
    for (int i = 0; i < raz; i++) {
        cout << mas[i] << "  ";
    }
    cout << endl << endl;
    _getch();
    //Копирование строк с помощью указателей
    char str1[55];
    const char* str2 = "Кручу, кручу, кручу, педали кручу";
    cout << str2 << endl;
    kopiruem(str1, str2);
    cout << str1 << endl << endl;
    _getch();
    //Создал массив строк у которых не будет оставаться свободного места
    const char* masstr[7] = { "Понедельник","Вторник","Среда","Четверг","Пятница","Суббота","Воскресенье" };
    for (int i = 0; i < 7; i++) {
        cout << masstr[i] << endl;
    }
    cout << endl;
    _getch();
}

#include <conio.h>
#include <locale>
#include <iostream>
using namespace std;
const int max = 80;
const int maxu = 40;

class stack1 {
private:
    char urav[80];
    int raz;
public:
    stack1() {
        raz = 0;
    }
    void push(char k) {
        urav[++raz] = k;
    }
    char pop() {
        return urav[raz--];
    }
    int gettop() {
        return raz;
    }
    void viv() {
        for (int i = 0; i < raz; i++) {
            cout << urav[i];
        } 
    }
};

class arifmetika {
private:
    stack1 s;            //стек данных
    int len;            //длина строки
    char* str;          //Строка для ввода
public:
    arifmetika(char* STR) {
        str = STR;      //Запомнили указатель на строку
        len = strlen(str);
    }
    void parse() {      //Добавляем данные в стек
        char ch;
        char lastN;
        char lastZ;
        for (int i = 0; i < len; i++) {
            ch = str[i];
            if (ch >= '0' && ch <= '9') {
                s.push(ch);
            }
            else {
                if (ch == '-' || ch == '+' || ch == '*' || ch == '/') {
                    if (s.gettop() == 1) {
                        s.push(ch);
                    }
                    else {
                        lastN = s.pop();
                        cout << lastN;
                        lastZ = s.pop();
                        cout << lastZ << "\n";
                        if ((ch == '*' || ch == '/') && (lastZ == '+' || lastZ == '-')) {
                            s.push(lastZ);
                            s.push(lastN);
                        }
                        else {
                            switch (lastZ) {
                            case '+':s.push(int(s.pop()) + int(lastN));
                                break;
                            case '-':s.push(int(s.pop()) - int(lastN));
                                break;
                            case '/':s.push(int(s.pop()) / int(lastN));
                                break;
                            case '*':s.push(int(s.pop()) * int(lastN));
                                break;
                            default:cout << "Ну ты братишка долбаеб конечно, из четырех знаков нормальный выбрать не смог..." << endl;
                                exit(1);
                            }
                        }
                        s.push(ch);
                    }
                }
                else {
                    cout << "Дружище, ну ты опять в штаны насрал, исправляйся в следующий раз " << ch << "tut" << endl;
                    exit(1);
                }
            }
        }
    }
    void solve() {       //Получаем результат
        char lastN;
        s.viv();
        while (s.gettop() > 1) {                //У нас последние 3 значения в стеке имеют вид по типу (а+с) исправляем.
            lastN = s.pop();
            cout << s.pop() << "TUT" << endl;
            switch (s.pop()) {
            case '+':s.push(int(s.pop()) + int(lastN));
                break;
            case '-':s.push(int(s.pop()) - int(lastN));
                break;
            case '/':s.push(int(s.pop()) / int(lastN));
                break;
            case '*':s.push(int(s.pop()) * int(lastN));
                break;
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    char prodolzhaem;
    char str[80];

    cout << "Короче, необходимо ввести выражение по типу 2+4/2*3-4+1-3" << endl;
    cout << "Проблема в том что и во время вычислений и в конце не должно появляться чисел состоящих из двух и более цифр" << endl;
    cout << "Без фигни, не используем там скобки пробелы и тп" << endl;
    cout << "Жмякните 1 раз Enter, если поняли" << endl;
    _getch();
    do {
        system("cls");
        cout << "Фигачьте ваше выражение сюда" << endl;
        cin >> str;
        arifmetika* vir = new arifmetika(str);
        vir->parse();
        vir->solve();
        cout << "Наш результат: " << endl << "Если вас неустроил наш результат,то сочувствую" << endl;
        delete vir;
        cout << "Повторим?(y(это не русская буква) или д/(все что угодно другое))" << endl;
        cin >> prodolzhaem;
    } while (prodolzhaem == 'y' || prodolzhaem == 'д');
    _getch();
}

#include <conio.h>
#include <iostream>
#include <locale>
using namespace std;

struct list {
    int data;
    list* link;
};

class linklist {
private:
    list* stak;
public:
    linklist() {
        stak = NULL;
    }
    void addition(int peak) {
        list* temp = new list;
        temp->data = peak;
        temp->link = stak;
        stak = temp;
        //delete[]temp;
    }
    void conclution() {
        list* temp1 = stak;
        while (temp1) {
            cout << temp1->data << "\n";
            temp1 = temp1->link;
        }
        delete[]temp1;
    }
    ~linklist() {
        delete[]stak;
        cout << "Произошла очистка";
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    linklist first;
    first.addition(14);
    first.addition(15);
    first.addition(94);
    first.addition(13);
    first.addition(24);
    first.conclution();
    cout << endl;
    first.conclution();
    _getch();
}


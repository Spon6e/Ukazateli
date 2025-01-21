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
    }
    void conclution() {
        list* temp = stak;
        while (temp) {
            cout << temp->data << "\n";
            temp = temp->link;
        }
    }
};


int main()
{
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


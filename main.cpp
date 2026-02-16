#include "Header.h"

int main() {
    setlocale(LC_ALL, "Rus");
    using namespace std;
    int num;

    cout << "Введите номер задачи (или 0, чтобы выйти): ";
    cin >> num;

    while (num != 0) {

        while ((num < 1 || num > 3) && num != 0) {
            cout << "Ошибка! Введите цифру 1-3:";
            cin >> num;
        }

        switch (num) {
        case 1:
            cout << endl << "(^-^) ===== Задание 1 ===== (^-^)" << endl << endl;
            task1();
            break;
        case 2:
            cout << endl << "(^-^) ===== Задание 2 ===== (^-^)" << endl << endl;
            task2();
            break;
        case 3:
            cout << endl << "(^-^) ===== Задание 3 ===== (^-^)" << endl << endl;
            task3();
            break;
        }
        cout << "Введите номер задачи (или 0, чтобы выйти): ";
        cin >> num;
    }
    
    cout << endl << "====== Конец проги ======" << endl;

    return 0;
}

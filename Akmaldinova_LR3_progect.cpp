#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

void EnterThreeDigitNumber(int& X) {
    do {
        cout << "Введите целое трехзначное число X: ";
        if (!(cin >> X)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод. Пожалуйста, введите целое число." << endl;
        } else if (X < 100 || X > 999) {
            cout << "Число должно быть трехзначным. Попробуйте снова." << endl;
        }
    } while (X < 100 || X > 999);
}

void EnterDigitN(int X, int& N) {
    do {
        cout << "Введите цифру N (меньше числа разрядов числа X, т.е. N < 3): ";
        if (!(cin >> N)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод. Пожалуйста, введите целое число." << endl;
        } else if (N < 0 || N >= 3) {
            cout << "Цифра N должна быть от 0 до 2. Попробуйте снова." << endl;
        }
    } while (N < 0 || N >= 3);
}

void FirstDigit(int X) {
    int firstDigit = X / 100; // Получаем первую цифру
    cout << "Первая цифра числа X: " << firstDigit << endl;
}

void NthDigit(int X, int N) {
    int nthDigit = (X / static_cast<int>(pow(10, N))) % 10; 
    cout << N << "-я цифра числа X (справа налево): " << nthDigit << endl;
}

int main() {
    int choice, X = 0, N = 0;

    do {
        cout << "Меню:\n";
        cout << "1. Ввести целое трехзначное число X\n";
        cout << "2. Ввести цифру N (меньше числа разрядов числа X)\n";
        cout << "3. Найти первую цифру числа X\n";
        cout << "4. Найти N-ю цифру числа X (цифры нумеруются справа налево)\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный выбор. Попробуйте снова.\n";
            continue;
        }

        switch (choice) {
        case 1:
            EnterThreeDigitNumber(X);
            break;
        case 2:
            if (X == 0) {
                cout << "Сначала введите число X (пункт 1).\n";
            } else {
                EnterDigitN(X, N);
            }
            break;
        case 3:
            if (X == 0) {
                cout << "Сначала введите число X (пункт 1).\n";
            } else {
                FirstDigit(X);
            }
            break;
        case 4:
            if (X == 0 || N < 0) {
                cout << "Сначала введите число X и цифру N (пункты 1 и 2).\n";
            } else {
                NthDigit(X, N);
            }
            break;
        case 0:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
#include <iostream>
#include <string> 
using namespace std;

// Функция для ввода целого трехзначного числа X
void EnterThreeDigitNumber(int& X) {
    do {
        cout << "Введите целое трехзначное число X: ";
        cin >> X;
    } while (X < 100 || X > 999);
}

// Функция для ввода цифры N (меньше числа разрядов числа X)
void EnterDigitN(int X, int& N) {
    do {
        cout << "Введите цифру N (меньше числа разрядов числа X, т.е. N < 3): ";
        cin >> N;
    } while (N >= to_string(X).length());
}

// Функция для нахождения первой цифры числа X
void FirstDigit(int X) {
    do {
        cout << "Введите цифру N (меньше числа разрядов числа X, т.е. N < 3): ";
        cin >> N;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод. Пожалуйста, введите целое число." << endl;
        }
    } while (N >= to_string(X).length());
}

// Функция для нахождения N-ной цифры числа X (цифры нумеруются справа налево)
void NthDigit(int X, int N) {
    void NthDigit(int X, int N) {
        string strX = to_string(X);
        int nthDigit = strX[strX.length() - 1 - N] - '0'; // Получаем N-ю цифру
        cout << N << "-я цифра числа X (справа налево): " << nthDigit << endl;
    }
    
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
        cin >> choice;

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
            if (X == 0 || N == 0) {
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
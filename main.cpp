#include <iostream>
using namespace std;

// Функции для фрагмента №13 (сумма цифр числа)
int F13_val(int n) { // Передача по значению
    int s = 0, k;    // s - сумма, k - текущая цифра
    for (; n != 0; n = n / 10) {
        k = n % 10;  // Получаем последнюю цифру
        s += k;      // Добавляем к сумме
    }
    return s;        // Возвращаем сумму цифр
}

void F13_ref(int n, int& s) { // Передача результата по ссылке
    s = 0;                    // s - сумма (выходной параметр)
    int k;                    // k - текущая цифра
    for (; n != 0; n = n / 10) {
        k = n % 10;
        s += k;
    }
}

void F13_pointer(int n, int* s) { // Передача результата по указателю
    *s = 0;                       // s - указатель на сумму
    int k;                        // k - текущая цифра
    for (; n != 0; n = n / 10) {
        k = n % 10;
        *s += k;
    }
}

// Функции для фрагмента №15 (разворот числа)
int F15_val(int n) { // Передача по значению
    int s = 0, k;    // s - результат разворота, k - текущая цифра
    for (; n != 0; n = n / 10) {
        k = n % 10;
        s = s * 10 + k; // Формируем число, добавляя цифры справа
    }
    return s;
}

void F15_ref(int n, int& s) { // Передача результата по ссылке
    s = 0;                    // s - результат разворота
    int k;                    // k - текущая цифра
    for (; n != 0; n = n / 10) {
        k = n % 10;
        s = s * 10 + k;
    }
}

void F15_pointer(int n, int* s) { // Передача результата по указателю
    *s = 0;                       // s - указатель на результат
    int k;                        // k - текущая цифра
    for (; n != 0; n = n / 10) {
        k = n % 10;
        *s = *s * 10 + k;
    }
}

// Функции для фрагмента №18 (поиск палиндромов)
void F18_val(int v, int A[], int& j) { // Передача массива по значению, j по ссылке
    j = 0;                             // j - индекс для записи в массив
    for (int a = 10; a < v; a++) {
        int n = a, s = 0, k;
        for (; n != 0; n = n / 10) {
            k = n % 10;
            s = s * 10 + k;
        }
        if (a == s) A[j++] = a; // Если число равно своему зеркалу, записываем
    }
}

void F18_ref(int v, int A[], int& j) { // Передача j по ссылке
    j = 0;
    for (int a = 10; a < v; a++) {
        int n = a, s = 0, k;
        for (; n != 0; n = n / 10) {
            k = n % 10;
            s = s * 10 + k;
        }
        if (a == s) A[j++] = a;
    }
}

void F18_pointer(int v, int* A, int* j) { // Передача массива и j по указателю
    *j = 0;
    for (int a = 10; a < v; a++) {
        int n = a, s = 0, k;
        for (; n != 0; n = n / 10) {
            k = n % 10;
            s = s * 10 + k;
        }
        if (a == s) A[(*j)++] = a;
    }
}

// Функции для фрагмента №20 (удаление максимума из массива)
void F20_val(int A[], int n) { // Передача по значению
    int k = 0;                 // k - индекс максимума
    for (int i = 1; i < n; i++)
        if (A[i] > A[k]) k = i;
    for (int j = k; j < n - 1; j++) A[j] = A[j + 1]; // Сдвиг элементов
}

void F20_ref(int A[], int& n) { // Передача n по ссылке
    int k = 0;
    for (int i = 1; i < n; i++)
        if (A[i] > A[k]) k = i;
    for (int j = k; j < n - 1; j++) A[j] = A[j + 1];
    n--; // Уменьшаем размер массива
}

void F20_pointer(int* A, int* n) { // Передача по указателю
    int k = 0;
    for (int i = 1; i < *n; i++)
        if (A[i] > A[k]) k = i;
    for (int j = k; j < *n - 1; j++) A[j] = A[j + 1];
    (*n)--; // Уменьшаем размер массива
}

// Функции для фрагмента №23 (копирование простых чисел)
void F23_val(int A[], int n, int B[], int& j) { // Передача по значению, j по ссылке
    j = 0;                                      // j - индекс для массива B
    for (int i = 0; i < n; i++) {
        int m;
        for (m = 2; m < A[i]; m++)
            if (A[i] % m == 0) break;
        if (m == A[i]) B[j++] = A[i]; // Если число простое, копируем
    }
    B[j] = 0; // Завершаем массив
}

void F23_ref(int A[], int n, int B[], int& j) { // Передача j по ссылке
    j = 0;
    for (int i = 0; i < n; i++) {
        int m;
        for (m = 2; m < A[i]; m++)
            if (A[i] % m == 0) break;
        if (m == A[i]) B[j++] = A[i];
    }
    B[j] = 0;
}

void F23_pointer(int* A, int n, int* B, int* j) { // Передача по указателю
    *j = 0;
    for (int i = 0; i < n; i++) {
        int m;
        for (m = 2; m < A[i]; m++)
            if (A[i] % m == 0) break;
        if (m == A[i]) B[(*j)++] = A[i];
    }
    B[*j] = 0;
}

int main() {
    // Тест для F13
    int s13_1, s13_2;
    cout << "F13_val_1: " << F13_val(123) << endl;
    F13_ref(456, s13_1);
    cout << "F13_ref_1: " << s13_1 << endl;
    F13_pointer(789, &s13_2);
    cout << "F13_pointer_1: " << s13_2 << endl;
    cout << "F13_val_2: " << F13_val(111) << endl;
    F13_ref(222, s13_1);
    cout << "F13_ref_2: " << s13_1 << endl;
    F13_pointer(333, &s13_2);
    cout << "F13_pointer_2: " << s13_2 << endl;

    // Тест для F15
    int s15_1, s15_2;
    cout << "F15_val_1: " << F15_val(123) << endl;
    F15_ref(456, s15_1);
    cout << "F15_ref_1: " << s15_1 << endl;
    F15_pointer(789, &s15_2);
    cout << "F15_pointer_1: " << s15_2 << endl;
    cout << "F15_val_2: " << F15_val(111) << endl;
    F15_ref(222, s15_1);
    cout << "F15_ref_2: " << s15_1 << endl;
    F15_pointer(333, &s15_2);
    cout << "F15_pointer_2: " << s15_2 << endl;

    // Тест для F18
    int A18_1[10], A18_2[10], j18_1, j18_2;
    F18_val(100, A18_1, j18_1);
    cout << "F18_val_1: ";
    for (int i = 0; i < j18_1; i++) cout << A18_1[i] << " ";
    cout << endl;
    F18_ref(50, A18_2, j18_2);
    cout << "F18_ref_1: ";
    for (int i = 0; i < j18_2; i++) cout << A18_2[i] << " ";
    cout << endl;

    // Тест для F20
    int A20_1[] = {3, 1, 4, 1, 5}, n20_1 = 5;
    int A20_2[] = {2, 8, 1, 7}, n20_2 = 4;
    F20_val(A20_1, n20_1);
    cout << "F20_val_1: ";
    for (int i = 0; i < n20_1 - 1; i++) cout << A20_1[i] << " ";
    cout << endl;
    F20_ref(A20_2, n20_2);
    cout << "F20_ref_1: ";
    for (int i = 0; i < n20_2; i++) cout << A20_2[i] << " ";
    cout << endl;

    // Тест для F23
    int A23_1[] = {4, 5, 6, 7}, n23_1 = 4, B23_1[10], j23_1;
    int A23_2[] = {2, 3, 4, 5}, n23_2 = 4, B23_2[10], j23_2;
    F23_val(A23_1, n23_1, B23_1, j23_1);
    cout << "F23_val_1: ";
    for (int i = 0; i < j23_1; i++) cout << B23_1[i] << " ";
    cout << endl;
    F23_ref(A23_2, n23_2, B23_2, j23_2);
    cout << "F23_ref_1: ";
    for (int i = 0; i < j23_2; i++) cout << B23_2[i] << " ";
    cout << endl;

    return 0;
}

#include <iostream>
using namespace std;

// Программа №15: Разворачивает число
// По значению
int F15_val(int n) {
    int s = 0, k;
    for (; n != 0; n /= 10) {
        k = n % 10;
        s = s * 10 + k;
    }
    return s;
}

// По ссылке
void F15_ref(int n, int& s) {
    s = 0;
    int k;
    for (; n != 0; n /= 10) {
        k = n % 10;
        s = s * 10 + k;
    }
}

// По указателю
void F15_pointer(int n, int* s) {
    *s = 0;
    int k;
    for (; n != 0; n /= 10) {
        k = n % 10;
        *s = *s * 10 + k;
    }
}

// Программа №21: Поиск простых чисел
// По значению
int F21_val(int v, int A[], int size) {
    int i = 0, a, n;
    for (a = 2; a < v; a++) {
        for (n = 2; n < a; n++) {
            if (a % n == 0) break;
        }
        if (n == a && i < size) A[i++] = a;
    }
    if (i < size) A[i] = 0;
    return i;
}

// По ссылке
void F21_ref(int v, int A[], int& count) {
    int i = 0, a, n;
    for (a = 2; a < v; a++) {
        for (n = 2; n < a; n++) {
            if (a % n == 0) break;
        }
        if (n == a) A[i++] = a;
    }
    A[i] = 0;
    count = i;
}

// По указателю
void F21_pointer(int v, int* A, int* count) {
    int i = 0, a, n;
    for (a = 2; a < v; a++) {
        for (n = 2; n < a; n++) {
            if (a % n == 0) break;
        }
        if (n == a) A[i++] = a;
    }
    A[i] = 0;
    *count = i;
}

// Программа №39: Сумма положительных элементов до нуля
// По значению
int F39_val(int A[], int n) {
    int s = 0, i;
    for (i = 0; i < n; i++) {
        if (A[i] < 0) continue;
        if (A[i] == 0) break;
        s += A[i];
    }
    return s;
}

// По ссылке
void F39_ref(int A[], int n, int& sum) {
    sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (A[i] < 0) continue;
        if (A[i] == 0) break;
        sum += A[i];
    }
}

// По указателю
void F39_pointer(int* A, int n, int* sum) {
    *sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (A[i] < 0) continue;
        if (A[i] == 0) break;
        *sum += A[i];
    }
}

// Программа №48: Удаление парных дубликатов
// По значению
int F48_val(int A[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        if (A[i] == A[i + 1]) {
            for (j = i; j < n - 2; j++) A[j] = A[j + 2];
            n -= 2;
            i--;
        }
    return n;
}

// По ссылке
void F48_ref(int A[], int& n) {
    int i, j;
    for (i = 0; i < n - 1; i++)
        if (A[i] == A[i + 1]) {
            for (j = i; j < n - 2; j++) A[j] = A[j + 2];
            n -= 2;
            i--;
        }
}

// По указателю
void F48_pointer(int* A, int* n) {
    int i, j;
    for (i = 0; i < *n - 1; i++)
        if (A[i] == A[i + 1]) {
            for (j = i; j < *n - 2; j++) A[j] = A[j + 2];
            *n -= 2;
            i--;
        }
}

// Программа №58: Подсчет положительных после отрицательных
// По значению
int F58_val(int A[], int n) {
    int s = 0, k = 0, i;
    for (i = 0; i < n; i++)
        if (A[i] < 0) k = 1;
        else {
            if (k == 1) s++;
            k = 0;
        }
    return s;
}

// По ссылке
void F58_ref(int A[], int n, int& count) {
    count = 0;
    int k = 0, i;
    for (i = 0; i < n; i++)
        if (A[i] < 0) k = 1;
        else {
            if (k == 1) count++;
            k = 0;
        }
}

// По указателю
void F58_pointer(int* A, int n, int* count) {
    *count = 0;
    int k = 0, i;
    for (i = 0; i < n; i++)
        if (A[i] < 0) k = 1;
        else {
            if (k == 1) *count += 1;
            k = 0;
        }
}

// Функция для вывода массива
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

int main() {
    // Тесты для программы №15
    int num1 = 123, num2 = 456, result;
    cout << "F15_val_1: " << F15_val(num1) << endl;
    F15_ref(num1, result);
    cout << "F15_ref_1: " << result << endl;
    F15_pointer(num1, &result);
    cout << "F15_pointer_1: " << result << endl;
    cout << "F15_val_2: " << F15_val(num2) << endl;
    F15_ref(num2, result);
    cout << "F15_ref_2: " << result << endl;
    F15_pointer(num2, &result);
    cout << "F15_pointer_2: " << result << endl;

    // Тесты для программы №21
    int A1[10] = {0}, A2[10] = {0};
    int n1 = 10, n2 = 10, count;
    F21_val(10, A1, n1);
    cout << "F21_val_1: "; printArray(A1, F21_val(10, A1, n1)); cout << endl;
    F21_ref(15, A1, count);
    cout << "F21_ref_1: "; printArray(A1, count); cout << endl;
    F21_pointer(10, A1, &count);
    cout << "F21_pointer_1: "; printArray(A1, count); cout << endl;
    F21_val(15, A2, n2);
    cout << "F21_val_2: "; printArray(A2, F21_val(15, A2, n2)); cout << endl;
    F21_ref(20, A2, count);
    cout << "F21_ref_2: "; printArray(A2, count); cout << endl;
    F21_pointer(15, A2, &count);
    cout << "F21_pointer_2: "; printArray(A2, count); cout << endl;

    // Тесты для программы №39
    int A3[] = {1, -2, 3, 0, 5}, A4[] = {2, -1, 4, 6, 0};
    n1 = 5, n2 = 5;
    cout << "F39_val_1: " << F39_val(A3, n1) << endl;
    F39_ref(A3, n1, result);
    cout << "F39_ref_1: " << result << endl;
    F39_pointer(A3, n1, &result);
    cout << "F39_pointer_1: " << result << endl;
    cout << "F39_val_2: " << F39_val(A4, n2) << endl;
    F39_ref(A4, n2, result);
    cout << "F39_ref_2: " << result << endl;
    F39_pointer(A4, n2, &result);
    cout << "F39_pointer_2: " << result << endl;

    // Тесты для программы №48
    int A5[] = {1, 1, 2, 3, 3}, A6[] = {2, 2, 4, 4, 6};
    n1 = 5, n2 = 5;
    n1 = F48_val(A5, n1);
    cout << "F48_val_1: "; printArray(A5, n1); cout << endl;
    F48_ref(A5, n1);
    cout << "F48_ref_1: "; printArray(A5, n1); cout << endl;
    F48_pointer(A5, &n1);
    cout << "F48_pointer_1: "; printArray(A5, n1); cout << endl;
    n2 = F48_val(A6, n2);
    cout << "F48_val_2: "; printArray(A6, n2); cout << endl;
    F48_ref(A6, n2);
    cout << "F48_ref_2: "; printArray(A6, n2); cout << endl;
    F48_pointer(A6, &n2);
    cout << "F48_pointer_2: "; printArray(A6, n2); cout << endl;

    // Тесты для программы №58
    int A7[] = {-1, 2, -3, 4, 5}, A8[] = {1, -2, 3, -4, 5};
    n1 = 5, n2 = 5;
    cout << "F58_val_1: " << F58_val(A7, n1) << endl;
    F58_ref(A7, n1, result);
    cout << "F58_ref_1: " << result << endl;
    F58_pointer(A7, n1, &result);
    cout << "F58_pointer_1: " << result << endl;
    cout << "F58_val_2: " << F58_val(A8, n2) << endl;
    F58_ref(A8, n2, result);
    cout << "F58_ref_2: " << result << endl;
    F58_pointer(A8, n2, &result);
    cout << "F58_pointer_2: " << result << endl;

    return 0;
}

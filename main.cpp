#include <iostream>
#include <string>
using namespace std;

// Программа №15: Разворачивает число
// По значению
int reverseNumber_val(int n) {
    int s = 0, k;
    while (n > 0) {
        k = n % 10;
        s = s * 10 + k;
        n /= 10;
    }
    return s;
}

// По ссылке
void reverseNumber_ref(int n, int& s) {
    s = 0;
    int k;
    while (n > 0) {
        k = n % 10;
        s = s * 10 + k;
        n /= 10;
    }
}

// По указателю
void reverseNumber_pointer(int n, int* s) {
    *s = 0;
    int k;
    while (n > 0) {
        k = n % 10;
        *s = *s * 10 + k;
        n /= 10;
    }
}

// Программа №21: Сортировка массива методом пузырька
// По значению (копия массива)
void bubbleSort_val(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// По ссылке
void bubbleSort_ref(int A[], int& n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// По указателю
void bubbleSort_pointer(int* A, int* n) {
    for (int i = 0; i < *n - 1; i++) {
        for (int j = 0; j < *n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

// Программа №39: Поиск минимального и максимального элементов
// По значению
void findMinMax_val(int A[], int n, int& min, int& max) {
    min = A[0];
    max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }
}

// По ссылке
void findMinMax_ref(int A[], int n, int& min, int& max) {
    min = A[0];
    max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < min) min = A[i];
        if (A[i] > max) max = A[i];
    }
}

// По указателю
void findMinMax_pointer(int* A, int n, int* min, int* max) {
    *min = A[0];
    *max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] < *min) *min = A[i];
        if (A[i] > *max) *max = A[i];
    }
}

// Программа №48: Подсчёт гласных букв в строке
// По значению
int countVowels_val(string s) {
    int count = 0;
    for (char c : s) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

// По ссылке
void countVowels_ref(string s, int& count) {
    count = 0;
    for (char c : s) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
}

// По указателю
void countVowels_pointer(string s, int* count) {
    *count = 0;
    for (char c : s) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            *count += 1;
        }
    }
}

// Программа №58: Сумма элементов главной диагонали
// По значению
int sumDiagonal_val(int A[][10], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i][i];
    }
    return sum;
}

// По ссылке
void sumDiagonal_ref(int A[][10], int n, int& sum) {
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i][i];
    }
}

// По указателю
void sumDiagonal_pointer(int* A, int n, int* sum) {
    *sum = 0;
    for (int i = 0; i < n; i++) {
        *sum += *(A + i * n + i); // Доступ к элементу A[i][i] через указатель
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
    int num1 = 123, num2 = 111, result;
    cout << "F15_val_1: " << reverseNumber_val(num1) << endl;
    reverseNumber_ref(num1, result);
    cout << "F15_ref_1: " << result << endl;
    reverseNumber_pointer(num1, &result);
    cout << "F15_pointer_1: " << result << endl;
    cout << "F15_val_2: " << reverseNumber_val(num2) << endl;
    reverseNumber_ref(num2, result);
    cout << "F15_ref_2: " << result << endl;
    reverseNumber_pointer(num2, &result);
    cout << "F15_pointer_2: " << result << endl;

    // Тесты для программы №21
    int A1[] = {5, 3, 1, 7, 9}, A2[] = {2, 0, 4, 6, 8};
    int n1 = 5, n2 = 5;
    bubbleSort_val(A1, n1);
    cout << "F21_val_1: "; printArray(A1, n1); cout << endl;
    bubbleSort_ref(A1, n1);
    cout << "F21_ref_1: "; printArray(A1, n1); cout << endl;
    bubbleSort_pointer(A1, &n1);
    cout << "F21_pointer_1: "; printArray(A1, n1); cout << endl;
    bubbleSort_val(A2, n2);
    cout << "F21_val_2: "; printArray(A2, n2); cout << endl;
    bubbleSort_ref(A2, n2);
    cout << "F21_ref_2: "; printArray(A2, n2); cout << endl;
    bubbleSort_pointer(A2, &n2);
    cout << "F21_pointer_2: "; printArray(A2, n2); cout << endl;

    // Тесты для программы №39
    int min, max;
    findMinMax_val(A1, n1, min, max);
    cout << "F39_val_1: min=" << min << ", max=" << max << endl;
    findMinMax_ref(A1, n1, min, max);
    cout << "F39_ref_1: min=" << min << ", max=" << max << endl;
    findMinMax_pointer(A1, n1, &min, &max);
    cout << "F39_pointer_1: min=" << min << ", max=" << max << endl;
    findMinMax_val(A2, n2, min, max);
    cout << "F39_val_2: min=" << min << ", max=" << max << endl;
    findMinMax_ref(A2, n2, min, max);
    cout << "F39_ref_2: min=" << min << ", max=" << max << endl;
    findMinMax_pointer(A2, n2, &min, &max);
    cout << "F39_pointer_2: min=" << min << ", max=" << max << endl;

    // Тесты для программы №48
    string s1 = "hello", s2 = "hi";
    int count;
    cout << "F48_val_1: " << countVowels_val(s1) << endl;
    countVowels_ref(s1, count);
    cout << "F48_ref_1: " << count << endl;
    countVowels_pointer(s1, &count);
    cout << "F48_pointer_1: " << count << endl;
    cout << "F48_val_2: " << countVowels_val(s2) << endl;
    countVowels_ref(s2, count);
    cout << "F48_ref_2: " << count << endl;
    countVowels_pointer(s2, &count);
    cout << "F48_pointer_2: " << count << endl;

    // Тесты для программы №58
    int matrix1[10][10] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[10][10] = {{1, 0, 0}, {0, 2, 0}, {0, 0, 3}};
    int sum, n = 3;
    cout << "F58_val_1: " << sumDiagonal_val(matrix1, n) << endl;
    sumDiagonal_ref(matrix1, n, sum);
    cout << "F58_ref_1: " << sum << endl;
    sumDiagonal_pointer(&matrix1[0][0], n, &sum);
    cout << "F58_pointer_1: " << sum << endl;
    cout << "F58_val_2: " << sumDiagonal_val(matrix2, n) << endl;
    sumDiagonal_ref(matrix2, n, sum);
    cout << "F58_ref_2: " << sum << endl;
    sumDiagonal_pointer(&matrix2[0][0], n, &sum);
    cout << "F58_pointer_2: " << sum << endl;

    return 0;
}

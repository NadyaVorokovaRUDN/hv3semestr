/* задание 2. А
 int *ptr = (int*)malloc(sizeof(int)) - int *ptr = new int
 int *ptrArr = (int*)malloc(sizeof(int)*N) - int *ptr = new int[n]
 free(ptr) = delete ptr
 free(ptrArr) - delete[] ptrArr
 
 Динамическую память нужно освобождать так как до того момента как мы вызываем delete она считается забронированным. Выделеную память освободить дважды можно, но не надо. Невыделенную память нельзя освободить так как указатель на этот участок равен нулю.
 */


#include <iostream>
using namespace std;


int main() {
    int x;
    std::cout << "Введите количество строк: ";
    std::cin >> x;

    int** arr = new int* [x];
    for (int i = 0; i < x; i++) {
        *(arr + i) = new int[i + 1];
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0 || j == 0 || j == i) {
                *(*(arr + i) + j) = 1;
            }
            else {
                *(*(arr + i) + j) = *(*(arr + i-1) + j-1) + *(*(arr + i-1) + j);
            }
        }
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j <= i; j++) {
            cout << *(*(arr + i) + j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < x; i++) {
        delete[] *(arr + i);
    }
    delete[] arr;

    return 0;
}

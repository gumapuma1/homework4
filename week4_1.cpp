/*
Сгенерировать массив со случайными числами в диапазоне:
[-20,10]
Составить программу, которая будет считать количество действий перестановки элементов. 
Исследовать зависимость количества перестановок от количества элементов в массиве 
(рассмотреть не менее 5-ти значений длины, например, для 100, 1000, 5000, 10000, 100000). 
В результате исследования должна получится сравнительная таблица для нескольких методов:
Сортировка выбором;
Сортировка вставками;
Сортировка пузырьком.
Каждую сортировку необходимо провести не менее 3 раз (при разных стартовых значениях ГСЧ). 
В этом задании интересны ваши рассуждения и мысли о полученных результатах (код ведь и так есть).
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

const int n = 10000;

void arrayFill(int arr[n]);
void arrayShow(int arr[n]);
void fileWrite(unsigned long c);
void selectionSort(int data[], int len, unsigned long &c);
void insertionSort(int data[], int len, unsigned long &c);
void bubbleSort(int data[], int len, unsigned long &c);

int main() {
    int arra[n];
    unsigned long count = 0;
    arrayFill(arra);

    bubbleSort(arra, n, count);
    fileWrite(count);

    return 0;
}

void arrayFill(int arr[n]) {
    srand (time(NULL));
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 31 + (-20);
    }
}

void arrayShow(int arr[n]) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fileWrite(unsigned long c) {
    ofstream fout;
    fout.open("data.txt", ofstream::out | ofstream::app);

    if(!fout.is_open()) {
        cout << "Error. File isn't open.";
    }
    else {
        fout << "Array len - " << n << endl;
        fout << "Sort type - bubbleSort." << endl;
        fout << "Number of permutations - " << c << endl << endl;
    }
}

void selectionSort(int data[], int len, unsigned long &c) {
    int j = 0;
    float tmp = 0;

    for(int i=0; i<len; i++){
        // ищем номер наименьшего элемента среди элементов от i-го до конца
        j = i;


        for(int k = i; k < len; k++){
            if(data[j] > data[k]){
                j = k;
                c++;
            }
        }
        // меняем местами наибольший элемент и текущий
        tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }
}

void insertionSort(int data[], int len, unsigned long &c) {
    float key = 0;
    int j = 0;
    // проход по массиву
    for(int i = 1; i<len; i++){
        key = data[i];  // ключевой/текущий элемент
        j = i - 1;
        // перестановка элемента на нужное место
        while(j >= 0 && data[j] > key){
            data[j+1] = data[j];
            j = j-1;
            data[j+1] = key;
            c++;
        }
    }
}

void bubbleSort(int data[], int len, unsigned long &c) {
    float tmp = 0;
    // идём по массиву
    for(int i = 0; i<len; i++){
        // делаем проверки в оставшейся части массива
        for(int j = len-1; j >= i+1; j--){
            if(data[j] < data[j-1]){  // сравниваем соседние элементы
                // делаем перестановку
                tmp = data[j];
                data[j] =data[j-1];
                data[j-1] = tmp;
                c++;
            }
        }
    }
}

/*
Вывод в файл data.txt после тестов:

Array len - 100
Sort type - selectionSort.
Number of permutations - 250

Array len - 100
Sort type - selectionSort.
Number of permutations - 281

Array len - 100
Sort type - selectionSort.
Number of permutations - 247

Array len - 1000
Sort type - selectionSort.
Number of permutations - 3009

Array len - 1000
Sort type - selectionSort.
Number of permutations - 2999

Array len - 1000
Sort type - selectionSort.
Number of permutations - 2895

Array len - 10000
Sort type - selectionSort.
Number of permutations - 30030

Array len - 10000
Sort type - selectionSort.
Number of permutations - 30047

Array len - 10000
Sort type - selectionSort.
Number of permutations - 30047

Array len - 100
Sort type - insertionSort.
Number of permutations - 2399

Array len - 100
Sort type - insertionSort.
Number of permutations - 2340

Array len - 100
Sort type - insertionSort.
Number of permutations - 2233

Array len - 1000
Sort type - insertionSort.
Number of permutations - 233612

Array len - 1000
Sort type - insertionSort.
Number of permutations - 243539

Array len - 1000
Sort type - insertionSort.
Number of permutations - 240487

Array len - 10000
Sort type - insertionSort.
Number of permutations - 23983029

Array len - 10000
Sort type - insertionSort.
Number of permutations - 24470312

Array len - 10000
Sort type - insertionSort.
Number of permutations - 24175032

Array len - 100
Sort type - bubbleSort.
Number of permutations - 2520

Array len - 100
Sort type - bubbleSort.
Number of permutations - 2296

Array len - 100
Sort type - bubbleSort.
Number of permutations - 2069

Array len - 1000
Sort type - bubbleSort.
Number of permutations - 240861

Array len - 1000
Sort type - bubbleSort.
Number of permutations - 246816

Array len - 1000
Sort type - bubbleSort.
Number of permutations - 239833

Array len - 10000
Sort type - bubbleSort.
Number of permutations - 24148711

Array len - 10000
Sort type - bubbleSort.
Number of permutations - 24148711

Array len - 10000
Sort type - bubbleSort.
Number of permutations - 24174367

    Проанализировав полученные результаты, можно сделать вывод,
что из трех предложенных вариантов сортировки сортировка выбором
показывает себя самой эффективной для массивов длиной вплоть до 10000.
    Сортировка вставками и пузырьковая сортировка, как видно по полученным
данным, работают приблезительно с одинаковой скоростью.
*/
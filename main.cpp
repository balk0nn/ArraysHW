//
// Created by balk0n on 26.12.2022.
//

#include "main.h"



using namespace std;

//Делим массив на 2 массива с элементами больше pivot'a и меньше
template <typename T>
static int partition(T arr[], int idx_start, int idx_end)
{
    int idx_pivot = 0;
    //Выбираем пивот случайным образом;
    int random = idx_start + rand() % (idx_end - idx_start);
    int pivot = arr[idx_start];
    int counter = 0, i = 0, j = 0;

    for (int k = idx_start + 1; k <= idx_end; ++k)
        if (arr[k] <= pivot)
            counter++;

    idx_pivot = counter + idx_start;

    std::swap(arr[idx_pivot], arr[idx_start]);

    i = idx_start;
    j = idx_end;

    while (i < idx_pivot && j > idx_pivot)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < idx_pivot && j > idx_pivot)
            std::swap(arr[i], arr[j]);
    }
    return idx_pivot;
}

template <typename T>
void quickSort(T arr[], int idx_start, int idx_end) {
    if (idx_start >= idx_end)
        return;

    int idx_pivot = partition(arr, idx_start, idx_end);

    quickSort(arr, idx_start, idx_pivot - 1);
    quickSort(arr, idx_pivot + 1, idx_end);
}


//Меняет местами значения 2-х переменных
template <typename T>
void swapp(T *ptr_a, T *ptr_b){
    T *ptr_c = new T;
    *ptr_c = *ptr_b;
    *ptr_b = *ptr_a;
    *ptr_a = *ptr_c;
    delete ptr_c;
}

void task5Sort(){
    cout << "Enter the length of your array" << endl;
    int length;
    cin >> length;
    int *arrayTask5 = new int[length];
    int countNegatives = 0;
    for(int i = 0; i < length; i++){
        cin >> arrayTask5[i];
        if(arrayTask5[i] < 0){
            countNegatives ++;
        }
    }
    for(int i = 0; i < length; i++){
        cout << arrayTask5[i] << " ";
    }
    cout << endl;
    int *Negatives = new int[countNegatives];
    int *everythingElse = new int[length - countNegatives];
    int negativeCounter = 0;
    //Записываем отрицательные и все остальные элементы в соответствующие массивы
    for(int i = 0; i < length; i++){
        if(arrayTask5[i] < 0){
            Negatives[negativeCounter] = arrayTask5[i];
            negativeCounter ++;
        }
        else {
            everythingElse[i - negativeCounter] = arrayTask5[i];
        }
    }
    //Перезаписываем основной массив в нужном порядке
    for(int i = 0; i < length; i++){
        if(i < countNegatives){
            arrayTask5[i] = Negatives[i];
        }
        else{
            arrayTask5[i] = everythingElse[i - countNegatives];
        }
    }
    for(int i = 0; i < length; i++){
        cout << arrayTask5[i] << " ";
    }
}


void task9Sort(){
    cout << "Enter the length of your array" << endl;
    int length;
    cin >> length;
    int *arrayTask9 = new int[length];
    int countNegatives = 0;
    for(int i = 0; i < length; i++){
        cin >> arrayTask9[i];
        if(arrayTask9[i] < 0){
            countNegatives ++;
        }
    }
    for(int i = 0; i < length; i++){
        cout << arrayTask9[i] << " ";
    }
    cout << endl;
    int *Negatives = new int[countNegatives];
    int *everythingElse = new int[length - countNegatives];
    int negativeCounter = 0;
    //Записываем отрицательные и все остальные элементы в соответствующие массивы
    for(int i = 0; i < length; i++){
        if(arrayTask9[i] < 0){
            Negatives[negativeCounter] = arrayTask9[i];
            negativeCounter ++;
        }
        else {
            everythingElse[i - negativeCounter] = arrayTask9[i];
        }
    }
    quickSort(Negatives,0,countNegatives);
    quickSort(everythingElse,0,length-countNegatives);

    for(int i = 0; i < (length - countNegatives)/2; i++){
        swapp(&everythingElse[i], &everythingElse[length - countNegatives - i]);
    }
    //Перезаписываем основной массив в нужном порядке
    for(int i = 0; i < length; i++){
        if(i < countNegatives){
            arrayTask9[i] = Negatives[i];
        }
        else{
            arrayTask9[i] = everythingElse[i - countNegatives];
        }
    }
    for(int i = 0; i < length; i++){
        cout << arrayTask9[i] << " ";
    }
}

int main(){
/*
    //Задача 1
    int a = 5;
    int b = 6;
    swapp(&a, &b);
    cout << a << " " << b << endl;
*/

/*
    //Задача 2
    cout << "Enter the number n" << endl;
    int n;
    cin >> n;
    int *a = new int [n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    swapp(&(a[0]), &(a[n-1]));
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
*/
/*
    //Задача 6
    auto *array = new double[14];
    for(int i = 0; i < 14; i++){
        cin >> array[i];
    }
    int switchCount = 0;
    for(int i = 0; i < 7; i++){
        swapp(&(array[i]), &(array[i + 7]));
        switchCount ++;
    }
    for(int i = 0; i < 14; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Total of "<< switchCount << " swaps" << endl;
*/

    //Задача 5
    //task5Sort();
    //Задача 9
    task9Sort();
    return 0;
}

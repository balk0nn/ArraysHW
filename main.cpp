//
// Created by balk0n on 26.12.2022.
//

#include "main.h"

using namespace std;


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
    task5Sort();
    return 0;
}

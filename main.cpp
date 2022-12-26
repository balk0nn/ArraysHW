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

int main(){
/*
    //Задача 1
    int a = 5;
    int b = 6;
    swapp(&a, &b);
    cout << a << " " << b << endl;
*/
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

    return 0;
}

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

void task1(){
    int a = 5;
    int b = 6;
    swapp(&a, &b);
    cout << a << " " << b << endl;
}

void task2(){
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
}
//Задача 4
void task4() {
    double arr[12];
    int t = 0;
    cout << "Input array: ";
    for (int i = 0; i < 12; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 12 - 1; i++)
    {
        for (int j = i + 1; j < 12; j++)
        {
            if (arr[i] < arr[j])
            {
                double* d = new double;
                *d = arr[i];
                arr[i] = arr[j];
                arr[j] = *d;
                delete d;
                t++;
            }
        }
    }
    cout << "Descending: ";
    for (int i = 0; i < 12; i++) {
        cout << arr[i] << " ";
    }
    cout << "Number of permutations: " << t << endl;
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


void task6(){
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
}
template <typename T>
int task71(T arr[], int i) { 
    //Сравнение числа с предыдущим и последующим в массиве
    if ((arr[i] < arr[i + 1]) && (arr[i ] < arr[i - 1])) {
        return 1;
    }
    else{
        return 0;
    }
}
template <typename T>
void task7(T arr[], int size){
    int numb = 0;
    for (int i = 1; i < size - 1; i++) {
        if ( task71( arr, i) == 1 ) {
            numb=numb+1;
        }
    }
    cout << numb << endl;
}
//Задача 8
template <typename T>
void task81(T arr, int stroka) {
    //Эта функция находит нули и считает нужную сумму чисел.
    //Искомый массив можно рассматривать как одномерный за счёт передачи номера строки
    int size = sizeof(arr[stroka]) / sizeof(arr[stroka][0]);
    int firstzero;
    int  secondzero;
    double between = 0;
    //Нахождение первого нуля
    for (int i = size - 1; i >= 0; i--) {
        if (arr[stroka][i] == 0) {
            firstzero = i;
        }
    }
    //Нахождение второго нуля в строке
    for (int i = 0; i < size; i++) {
        if (arr[stroka][i] == 0) {
            secondzero = i;
        }
    }
    for (int i = firstzero + 1; i < secondzero; i++) {
        between = between + arr[stroka][i];
    }
    cout << between<<endl;
}

void task8() {
    int arr[3][6] = {
    {1, 0, 3, 6, 2, 0},
    {3, 7, 0, 4, 0, 1} ,
    {0, 0, 2, 3, 7, 5}};
    int size = sizeof(arr) / sizeof(arr[0]);
    //Каждую строку отправляем в функцию вместе с самим массивом  
    for (int i = 0; i < size; i++) {
        task81(arr, i);
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

void task10(){
    cout << "Enter the length of the first array" << endl;
    int length1;
    cin >> length1;
    double *array1 = new double[length1];
    cout << "Enter elements of the first array" << endl;
    for(int i = 0; i < length1; i++){
        cin >> array1[i];
    }
    for(int i = 0; i < length1; i++){
        cout << array1[i] << " ";
    }
    cout << endl;
    cout << "Enter the length of the first array" << endl;
    int length2;
    cin >> length2;
    double *array2 = new double[length2];
    cout << "Enter elements of the second array" << endl;
    for(int i = 0; i < length1; i++){
        cin >> array2[i];
    }
    for(int i = 0; i < length2; i++){
        cout << array2[i] << " ";
    }
    cout << endl;
    double *max1_ptr = &array1[0], *max2_ptr = &array2[0];
    for(int i = 0; i < length1; i++){
        if(*&array1[i] > *max1_ptr){
            max1_ptr = &array1[i];
        }
    }
    for(int i = 0; i < length2; i++){
        if(*&array2[i] > *max2_ptr){
            max2_ptr = &array2[i];
        }
    }
    swapp( max1_ptr, max2_ptr);
    cout << "after swapping" << endl;
    for(int i = 0; i < length1; i++){
        cout << array1[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < length2; i++){
        cout << array2[i] << " ";
    }
}
//Задача 11
void task11() {
    double arr[3][6] = {
    {1, 0.5, 3, 6, 2, 0},
    {3, 7, 0, 4.6, 0, 1.8} ,
    {0, 0, 2, 3.1, 7.0, 5} };

    //Находим количество столбцов и строк в массиве
    int sizestolb = sizeof(arr[0]) / sizeof(arr[0][0]);
    int size = sizeof(arr) / sizeof(arr[0]);
    //Печать изначального массива
    for (int strok = 0; strok < size; strok++) {
        for (int stolb = 0; stolb < sizestolb; stolb++) {
            cout << arr[strok][stolb]<<" "; }
        cout << endl; 
    }
    cout << endl;
    //Выделяем память под вспомогательный массив
    double *mesto = new double[size];
    //Заполняем массив последним столбцом
    for (int strok = 0; strok <= size; strok++) { 
    mesto[strok] = arr[strok][sizestolb-1];    
    }
    //Смещаем все столбцы, а вотом заполняется первый из вспомогательного массива
    for (int strok = 0; strok < size; strok++) { 
        for (int stolb = sizestolb-1;stolb > 0 ; stolb--) { 
        arr[strok][stolb] =  arr[strok][stolb-1];
    }
    arr[strok][0]= mesto[strok];
}
   //Удаляем вспомогательный массив
    delete[] mesto;
    //Печать итога
    for (int strok = 0; strok < size; strok++) {
       for (int stolb = 0; stolb < sizestolb; stolb++) {
          cout << arr[strok][stolb]<<" ";
       }cout << endl;
}}

//Задача 12
void task12() {
    int arr[3][6] = {
    {1, 0, 3, 9, 2, 0},
    {3, 7, 0, 4, 0, 1} ,
    {0, 0, 2, 3, 2, 3} };
     //Находим количество строк и столбцов. Определяем номер максимальной и минимальной строки и их значения. Изначально 0-ая строка берётся за максимум и минимум
    int sizestrok = sizeof(arr) / sizeof(arr[0]);
    int sizestolb = sizeof(arr[0]) / sizeof(arr[0][0]);
    int maxstr=0;
    int minstr=0;
    int max = 0;
    int min = 0;
    for (int i = 0; i < sizestolb; i++) {
        max = max + arr[0][i];
    }
    min = max;
    //В каждой строке считаем сумму. Сравниваем с макс и мин
    for (int strok = 0; strok < sizestrok; strok++) {
        int sum = 0;
        for (int i = 0; i < sizestolb; i++) {
            sum = sum + arr[strok][i];
        }
        if (sum > max) {
            max = sum;
            maxstr = strok;
        }
        if (sum < min) {
            min = sum;
            minstr = strok;
        }
    }
    cout << "MIN " << minstr << endl << "MAX  " << maxstr << endl;
}


//Задача 13
void task13(){

    //Просим ввести длины массивов
    int m, n;
    cout << "Enter the length of the first array" << endl;
    cin >> m;
    cout << "Enter the length of the second array" << endl;
    cin >> n;

    //создаем массивы как сказано в условии
    int *nums1 = new int[m + n];
    int *nums2 = new int[n];
    cout << "Enter the elements of the first array" << endl;

    //Заполняем массивы следуя условиям
    for(int i = 0; i < m + n; i++){
        if(i < m){
            cin >> nums1[i];
        }
        else{
            nums1[i] = 0;
        }
    }
    cout << "Enter the elements of the second array" << endl;
    for (int i = 0; i < n; i++){
        cin >> nums2[i];
    }

    //Переносим второй массив в конец первого (вместо нулей)
    for(int i = m; i < m + n; i++){
        nums1[i] = nums2[i - m];
    }
    quickSort(nums1,0,m + n - 1);

    //Выводим отсортированный массив
    for(int i = 0; i < m + n; i++){
        cout << nums1[i] << " ";
    }

}

int main(){

    //Задача 1
    //task1();

    //Задача 2
    //task2();
    
    //Задача 3
    /*
    double** p = 0;
    p = new double*;
    *p = new double;
    **p = 2;
    cout << **p<<endl;
    delete* p;
    delete p;
     */

    //Задача 4
    //task4();

    //Задача 6
    //task6();

    //Задача 5
    //task5Sort();

    //Задача 7
    //double arr2[6] = { 3.5, 2, 4, 0, 1, 3 };
    //int size2 = sizeof(arr2) / sizeof(arr2[0]);
   //В функцию отправляются сам массив и размер. (Массивы могут быть разных типов)
   //task7(arr2, size2);
    
    //Задача 8
    //task8();
    
    //Задача 9
    //task9Sort();

    //Зададча 10
    //task10();
    
     //Задача 11
    //task11();

    //Задача 12
    //task12();
    
    //Задача 13
    //task13();
    return 0;
}

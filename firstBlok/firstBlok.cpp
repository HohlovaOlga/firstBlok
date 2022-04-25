using namespace std;
#include <iostream>

class DinamicArrayIntNumber {
public:
    int* arr;
    int size;
    //конструктор и длина массива
    DinamicArrayIntNumber() {
        arr = new int[10];
    }
    DinamicArrayIntNumber(int size) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    DinamicArrayIntNumber(int size, int n) {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = n;
        }
    }
    DinamicArrayIntNumber(const DinamicArrayIntNumber& dinamic) {
        int i;
        size = dinamic.size;
        arr = new int[size];
        for (int i = 0; i < dinamic.size; i++) {
            arr[i] = dinamic.arr[i];
        }
    }
    DinamicArrayIntNumber(DinamicArrayIntNumber&& dinamic)
        : arr(dinamic.arr), size(dinamic.size)
    {
        dinamic.arr = nullptr;

    }
    //деструктор
    ~DinamicArrayIntNumber()
    {
        delete[] arr;
    }
    //доступ к элементу
    int& operator[](const int index);
    int getSizeOfArray() {
        return size;
    }
    int getElementOfArray(int i) {
        return arr[i];
    }
    //resize
    void resize(int newSize) 
    {
        int* newArray = new int[newSize];
        if (size >= newSize) 
        {
            for (int i = 0; i < newSize; i++) 
            {
                newArray[i] = arr[i];
            }

            delete[] arr;
            size = newSize;
            this->arr = newArray;
        }
        if (size < newSize) 
        {
            for (int i = 0; i < size; i++) 
            {
                newArray[i] = arr[i];
            }

            for (int k = 0; k < newSize - size; k++) 
            {
                newArray[k + size] = 0;
            }

            delete[] arr;
            size = newSize;
            this->arr = newArray;
        }
    }
    //присваивание
    DinamicArrayIntNumber& operator=(const  DinamicArrayIntNumber& diname) {
        delete[] arr;
        size = diname.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = diname.arr[i];
        }

        return *this;
    }
    //перемещение
    DinamicArrayIntNumber& operator=(DinamicArrayIntNumber&& dinamic) {
        delete[] arr;
        size = dinamic.size;
        arr = dinamic.arr;
        dinamic.arr = nullptr;
        return *this;
    }
    // операторы
    friend bool operator == (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator != (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend bool operator> (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator<= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend bool operator< (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator>= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    //конкатенация массивов
    friend DinamicArrayIntNumber operator+(DinamicArrayIntNumber& d1, DinamicArrayIntNumber& d2);
    //ввод вывод с консоли
    friend ostream& operator<<(ostream& out, const DinamicArrayIntNumber& d1);
    friend istream& operator>>(istream& in, DinamicArrayIntNumber& d1);
};

//оператор равенства
bool operator== (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2) {
    if (d1.size == d2.size) {
        for (int i = 0; i < d1.size; i++) {
            if (d1.arr[i] != d2.arr[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}
//оператор на неравенство
bool operator != (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    return !(d1 == d2);
}
int& DinamicArrayIntNumber::operator[](const int index) {
    return arr[index];
}
//оператор сравнения двух массивов
bool operator> (const const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    if (d1.size > d2.size) {
        return true;
    }
    if (d2.size > d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] <= d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator>= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    if (d1.size > d2.size) {
        return true;
    }
    if (d2.size > d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] < d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator< (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    if (d1.size < d2.size) {
        return true;
    }
    if (d2.size < d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] >= d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator<= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    if (d1.size < d2.size) {
        return true;
    }
    if (d2.size < d1.size) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] > d2.arr[i]) {
            return false;
        }
    }
    return true;
}
//объединение двух массивов
DinamicArrayIntNumber operator+(DinamicArrayIntNumber& d1, DinamicArrayIntNumber& d2)
{
    int size_d1 = d1.size;
    int size = d1.size + d2.size;

    d1.resize(size);

    for (int i = size_d1; i < d1.size; i++) 
    {
        d1[i] = d2[i];
    }

    return d1;
}
//оператор вывода
ostream& operator<< (ostream& out, const DinamicArrayIntNumber& dinamic)
{
    out << "DinamicArrayIntNumber(";
    for (int i = 0; i < dinamic.size; i++) {
        out << dinamic.arr[i] << ", ";
    }
    out << ")";

    return out;
}
//оператор ввода
istream& operator>> (istream& in, DinamicArrayIntNumber& dinamic)
{

    for (int i = 0; i < dinamic.size; i++) {
        in >> dinamic.arr[i];
    }
    return in;
}

int main()
{
    int size = 10;
    //Создание массива по размеру
    DinamicArrayIntNumber dinamicArray1(size);
    //Создание массива по размеру и числу
    DinamicArrayIntNumber dinamicArray2(size);

   //Вывод первого массива
    for (int i = 0; i < size; i++) {
        cout << dinamicArray1[i] << " ";
    }
    cout << endl;

    //Вывод второго массива
    for (int i = 0; i < size; i++) {
        cout << dinamicArray2[i] << " ";
    }
    cout << endl;

    //Конструктор копирования
    DinamicArrayIntNumber dinamicArray3(dinamicArray1);

    //Вывод третьего массива
    for (int i = 0; i < size; i++) {
        cout << dinamicArray3[i] << " ";
    }
    cout << endl;

    //Вывод длины 2 массива
    cout << dinamicArray2.size << endl;

    //Доступ к нулевому элементу
    cout << dinamicArray1[0] << endl;

    //Изменение размера 1 массива
    dinamicArray1.resize(5);
    for (int i = 0; i < 5; i++) {
        cout << dinamicArray1[i] << " ";
    }
    cout << endl;

    //Изменение размера 2 массива
    dinamicArray1.resize(15);
    for (int i = 0; i < 15; i++) {
        cout << dinamicArray1[i] << " ";
    }
    cout << endl;

    //Оператор ==
    cout << (dinamicArray1 == dinamicArray2) << endl;

    //Оператор <
    cout << (dinamicArray1 < dinamicArray2) << endl;


}
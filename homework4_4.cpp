/*
Объявить сущность и описать её свойства (характеристики вроде роста, цвета, названия и прочего). 
Объявить массивы сущностей. Заполнить атрибуты числовыми и текстовыми значениями (диапазон значений определить самостоятельно).
автомобиль
одежда
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

const int n = 10;

void randString(string &str);
void randChar(char &ch);
void randYear(int &x);
void randHp(int &x);
void randPrice(int &x);

struct Car{
    int year;
    string model;
    int hp; //horsepower
    char color;
};

struct Clothes{
    string brand;
    string designer;
    int price;
    char color;
};

int main() {
    Car cars[n];
    Clothes tshirt[n];
    srand (time(NULL));
    
    cout << "Cars: \n"; 
    for(int i = 0; i < n; i++) {
        randString(cars[i].model);
        randChar(cars[i].color);
        randYear(cars[i].year);
        randHp(cars[i].hp);

        cout << cars[i].model << "  " << cars[i].color << "  "
             << cars[i].year << "  " << cars[i].hp << endl;
    }

    cout << "\nClothes: \n";
    for(int i = 0; i < n; i++) {
        randString(tshirt[i].brand);
        randString(tshirt[i].designer);
        randChar(tshirt[i].color);
        randPrice(tshirt[i].price);

        cout << tshirt[i].brand << "  " << tshirt[i].designer << "  "
             << tshirt[i].color << "  " << tshirt[i].price << endl;
    }

    return 0;
}

void randString(string &str){
    static const char alphabet[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    str = "     ";


    for(int i=0; i < str.length(); i++){
        int r = rand() % (sizeof(alphabet)-1);
        str[i] = alphabet[r];
    }
    str[str.length()] = 0;
}

void randChar(char &ch) {
    static const char alphabet[] =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    int r = rand() % (sizeof(alphabet)-1);
        ch = alphabet[r];
    }

void randYear(int &x) {
    x = rand() % 60 + 1960;
}

void randHp(int &x) {
    x = rand() % 800 + 75;
}

void randPrice(int &x) {
    x = rand() & 10000 + 10;
}

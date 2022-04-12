#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <windows.h>
using namespace std;



bool is_integer(float k)
{
    return floor(k) == k;
}
bool is_integerD(double k)
{
    return floor(k) == k;
}

bool is_integer_eps(float k, float eps)
{
    return k - floor(k) < eps;
}
void reverse_substr(char* &str,int start,int end)
{
    int i, j;
    for (i = start, j = end; i < j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

char* native_sprintf(float k)
{
    char* str = new char[100];
    int iter = 0;
    //sprintf(str, "%f", k);
    int data1 = (int)k,data2; //целая часть числа
    float data2f = k - data1; //дробная часть числа
    while(!is_integer_eps(data2f,0.001))
        data2f *= 10;
    data2 = (int)data2f;
    while(data1>0)
    {
        str[iter] = data1%10 + '0';
        data1 /= 10;
        iter++;
    }
    reverse_substr(str,0,iter-1);
    str[iter] = '.';
    iter++;
    int iter_point = iter;
    while(data2>0)
    {
        str[iter] = data2%10 + '0';
        data2 /= 10;
        iter++;
    }
    reverse_substr(str,iter_point,iter-1);
    str[iter] = '\0';
    return str;
}

void PrintStr(char* str)
{
    for(int i=0;i<sizeof(str);i++)
        cout<<str[i];
}

void first(){
    float inp;
    char* mainarr = new char[255];
    int mainctr=-1;
    while(1){
        cin>>inp;
        if(cin.fail()){
            break;
        }
        char* arr = new char[sizeof(inp)];
        sprintf(arr,"%f",inp);

        if(mainctr<255){
            if(is_integer(inp)){
                for(int i=0;i<sizeof(arr);i++){
                    mainctr++;
                    if(mainctr>254) break;
                    if(arr[i]!='.'){
                        mainarr[mainctr] = arr[i];
                    }else{
                        mainarr[mainctr] = ' ';
                        break;
                    }
                }
            }else {
                for (int i = 0; i < sizeof(arr); i++) {
                    mainctr++;
                    if(mainctr>254) break;
                    mainarr[mainctr] = arr[i];
                }
                mainctr++;
                mainarr[mainctr] = ' ';
            }
        }
    }
    for(int i=0;i<mainctr;i++){
        cout<<mainarr[i];
    }
}

void second(){
    double inp;
    string temp,mainstr;
    int mainctr=0;
    while(1){
        cin>>inp;
        if(cin.fail()){
            break;
        }
        if(is_integerD(inp)){
            temp = to_string((int)inp );
        }else{
            temp = to_string(inp);
        }
        if(mainstr.length()+temp.length()+1<255){
            mainstr+=temp;
            mainstr+=' ';
        }else{
            break;
        }
    }
    cout<<mainstr;
}
int main() {
    SetConsoleOutputCP(CP_UTF8);
    int work = -1;
    while (work != 0) {
        system("cls");
        cout << "Лабораторная работа №3 ИКБО-13-21 Смольников А.Б. Вариант 20" << endl << endl;
        cout << "Меню\n";
        cout << "Задание 1 (C-string)" << endl;
        cout
                << "Дана последовательность чисел (целых и вещественных). Преобразовать каждое число в строковое представление. Объединить полученные строки в текст разделяя их символом пробел. Объединение строки производить пока длина строки не превысит 255 символов. "
                << endl;
        cout << "Задание 2 (string)" << endl;
        cout << "Аналогично с заданием 1 " << endl;
        cout << "0) Выход\n";
        cout << "Ваш выбор: ";
        cin >> work;
        system("cls");
        cout << "Лабораторная работа №3 ИКБО-13-21 Смольников А.Б. Вариант 20" << endl << endl;


        switch (work) {
            case 1: {
                cout << "Задание 1 (C-string)" << endl;
                first();
                break;
            }
            case 2: {
                cout << "Задание 2 (динамический массив)" << endl;
                second();
                break;
            }
            default: {
                break;
            }
        }
        return 0;
    }
}

// 实现字符串逆序

#include <iostream>
using namespace std;

void Reverse(char arr[], int size)
{
    char *p = arr;
    char *q = arr + size - 1;
    while (p < q)
    {
        char ch = *p;
        *p = *q;
        *q = ch;
        p++;
        q--;
    }
}

int main()
{
    char arr[] = "Hello World";
    cout << arr << endl;
    Reverse(arr, strlen(arr));
    cout << arr << endl;
    return 0;
}
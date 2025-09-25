#include <iostream>
using namespace std;

void print_array_ptr(const int* arr, int length);

int main(void)
{

}

void print_array_ptr(const int* arr, int length)
{
    if(arr == nullptr){
        cout << "Error: Null Pointer recieved" << endl;
    }
    cout << "Array by pointer: ";
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print_array_ref(const int (&arr)[6]) // fixed size array
{
    int length = sizeof(arr) / sizeof(arr[0]);

    cout << "Array by reference: " << endl;
    for(int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

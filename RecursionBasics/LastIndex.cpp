#include <iostream>
using namespace std;

int lastIndex(int input[], int size, int x)
{
    if (size == 0)
    {
        return -1;
    }

    int num = lastIndex(input + 1, size - 1, x);

    if (num != -1)
    {
        return num + 1;
    }
    else
    {
        if (input[0] == x)
        {
            return 0;
        }else{
            return -1;
        }
    }

    
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 1};
    cout << lastIndex(arr, 6, 1);
}
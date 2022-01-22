#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int alphaRec(int *input, int size)
{
    if (size == 0)
    {
        return 1;
    }

    if (size == 1)
    {
        return 1;
    }

    int output = alphaRec(input, size - 1);
    if ((input[size - 2] * 10 + input[size - 1]) <= 26)
    {
        output += alphaRec(input, size - 2);
    }

    return output;
}

ll alphaDpRec(int *input, int size, ll *output)
{
    if (size == 0)
    {
        return 1;
    }

    if (size == 1)
    {
        return 1;
    }

    if (output[size] > 0)
    {
        return output[size];
    }

    ll m = pow(10, 9) + 7;

    ll out = alphaDpRec(input, size - 1, output);
    if ((input[size - 2] * 10 + input[size - 1]) <= 26)
    {
        out += alphaDpRec(input, size - 2, output);
    }

    output[size] = out % m;
    return out;
}

ll alphaDpItr(int *input, int size)
{
    ll *output = new ll[size + 1];

    ll m = pow(10, 9) + 7;

    output[0] = 1;
    output[1] = 1;

    for (int i = 2; i <= size; i++)
    {
        ll out = output[i - 1];
        if ((input[i - 2] * 10 + input[i - 1]) <= 26)
        {
            out += output[i - 2];
        }
        output[i] = (out % m);
    }

    ll fout=output[size];
    delete [] output;
    return fout;
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        size_t found = str.find('0');
        if (found != string::npos)
        {
            cout << 0 << endl;
            continue;
        }

        int *input = new int[str.length()];
        for (int i = 0; i < str.length(); i++)
        {
            input[i] = str[i] - '0';
        }
        ll *arr = new ll[str.length()];
        for (int i = 0; i < str.length() + 1; i++)
        {
            arr[i] = 0;
        }
        cout << alphaDpItr(input, str.length()) << endl;
    }
    return 0;
}
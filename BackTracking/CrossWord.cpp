#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValidVert(int r, int c, vector<string> word, int index, char arr[10][10])
{
    int count = 0;
    for (int i = 0; i < word[index].length(); i++)
    {
        if (arr[i + r][c] == '+')
        {
            break;
        }

        if (arr[i + r][c] != '+' && arr[i + r][c] != '-')
        {
            if (arr[i + r][c] != word[index][count])
            {
                break;
            }
        }

        count++;
    }
    if (count == word[index].length())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void setVertical(int r, int c, vector<string> word, int index, char arr[10][10], bool *helper)
{
    for (int i = 0; i < word[index].length(); i++)
    {
        if (arr[i + r][c] == '-')
        {
            arr[i + r][c] = word[index][i];
            helper[i] = true;
        }
        else
        {
            helper[i] = false;
        }
    }
}

void resetVertical(int r, int c, vector<string> word, int index, char arr[10][10], bool *helper)
{
    for (int i = 0; i < word[index].length(); i++)
    {
        if (helper[i] == true)
        {
            arr[i + r][c] = '-';
        }
    }
}

bool isValidHorz(int r, int c, vector<string> word, int index, char arr[10][10])
{
    int count = 0;
    for (int i = 0; i < word[index].length(); i++)
    {
        if (arr[r][c + i] == '+')
        {
            break;
        }

        if (arr[r][c + i] != '+' && arr[r][c + i] != '-')
        {
            if (arr[r][c + i] != word[index][count])
            {
                break;
            }
        }

        count++;
    }

    if (count == word[index].length())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void setHorizontal(int r, int c, vector<string> word, int index, char arr[10][10], bool *helper)
{
    for (int i = 0; i < word[index].length(); i++)
    {
        if (arr[r][c + i] == '-')
        {
            arr[r][c + i] = word[index][i];
            helper[i] = true;
        }
        else
        {
            helper[i] = false;
        }
    }
}

void resetHorizontal(int r, int c, vector<string> word, int index, char arr[10][10], bool *helper)
{
    for (int i = 0; i < word[index].length(); i++)
    {
        if (helper[i] == true)
        {
            arr[r][c + i] = '-';
        }
    }
}

bool crossword(char arr[10][10], vector<string> word, int index)
{
    if (index == word.size())
    {
        return true;
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == '-' || arr[i][j] == word[index][0])
            {
                // cout<<isValidVert(i, j, word, index, arr)<<endl;
                if (isValidVert(i, j, word, index, arr))
                {
                    // bool *helper = new bool[word[index].length()];
                    bool helper[10];
                    setVertical(i, j, word, index, arr, helper);
                    bool post = crossword(arr, word, index + 1);
                    if (post)
                    {
                        return true;
                    }
                    else
                    {
                        resetVertical(i, j, word, index, arr, helper);
                    }
                }

                if (isValidHorz(i, j, word, index, arr))
                {
                    // bool *helper = new bool[word[index].length()];
                    bool helper[10];
                    setHorizontal(i, j, word, index, arr, helper);
                    bool post = crossword(arr, word, index + 1);
                    if (post)
                    {
                        return true;
                    }
                    else
                    {
                        resetHorizontal(i, j, word, index, arr, helper);
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    // char **arr = new char *[10];
    char arr[10][10];
    for (int i = 0; i < 10; i++)
    {
        // char *rw = new char[10];
        string str;
        cin >> str;
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = str[j];
        }
        // arr[i] = rw;
    }

    string str;

    int i = 0;
    int j = 0;
    vector<string> word;
    cin >> str;
    int k = 0;
    for (; j < str.length();)
    {
        if (str[j] == ';')
        {
            string stk = str.substr(i, j - i);
            word.push_back(stk);
            i = j + 1;
        }
        j++;
    }
    word.push_back(str.substr(i, j - i));

    crossword(arr, word, 0);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}
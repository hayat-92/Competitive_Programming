#include <iostream>
using namespace std;

bool checker(char **matrix, int curr_row, int curr_col, int row, int col, string str, int str_index, bool **visited)
{
    if ((curr_row < 0 || curr_col < 0) || curr_col >= col || curr_row >= row)
    {
        if (str.size() == str_index)
        {
            return true;
        }
        return false;
    }
    for (int r = curr_row; r < row; r++)
    {

        for (int i = curr_col; i < col; i++)
        {
            if (str[str_index] == matrix[r][i] && !visited[r][i])
            {
                visited[r][i] = true;
                bool fnl;
                fnl = checker(matrix, r + 1, i, row, col, str, str_index + 1, visited);
                if (fnl)
                {
                    return fnl;
                }
                fnl = checker(matrix, r, i + 1, row, col, str, str_index + 1, visited);
                if (fnl)
                {
                    return fnl;
                }
                fnl = checker(matrix, r - 1, i, row, col, str, str_index + 1, visited);
                if (fnl)
                {
                    return fnl;
                }
                fnl = checker(matrix, r, i - 1, row, col, str, str_index + 1, visited);
                if (fnl)
                {
                    return fnl;
                }
                fnl = checker(matrix, r + 1, i + 1, row, col, str, str_index + 1, visited);
                if (fnl)
                {
                    return fnl;
                }
                fnl = checker(matrix, r - 1, i - 1, row, col, str, str_index + 1, visited);
                if (fnl)
                {
                    return fnl;
                }
                fnl = checker(matrix, r + 1, i - 1, row, col, str, str_index + 1, visited);
                if (fnl)
                {
                    return fnl;
                }
                fnl = checker(matrix, r - 1, i + 1, row, col, str, str_index + 1, visited);
                if (fnl)
                {
                    return fnl;
                }
                visited[r][curr_col] = false;
            }
        }
    }
    return false;
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        char **matrix = new char *[N];
        for (int i = 0; i < N; i++)
        {
            matrix[i] = new char[M];
            cin >> matrix[i];
        }

        string str = "CODINGNINJA";

        bool **visited = new bool *[N];
        for (int i = 0; i < N; i++)
        {
            visited[i] = new bool[M];
            for (int j = 0; j < M; j++)
            {
                visited[i][j] = false;
            }
        }

        bool value = checker(matrix, 0, 0, N, M, str, 0, visited);
        cout << value << endl;
    }

    return 0;
}
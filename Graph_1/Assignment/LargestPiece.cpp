#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


//MY SOLUTION

// int checker(char **matrix, int i, int j, int N, bool **visited)
// {

//     if (i < 0 || j < 0 || i >= N || j >= N)
//     {
//         return 0;
//     }

//     // visited[i][j] = true;
//     int left, right, top, bottom;
//     left = 0;
//     right = 0;
//     top = 0;
//     bottom = 0;
//     if (j - 1 >= 0 && matrix[i][j - 1] == '1' && !visited[i][j - 1])
//     {
//         visited[i][j-1] = true;
//         left = checker(matrix, i, j - 1, N, visited);
//     }
//     if (j + 1 < N && matrix[i][j + 1] == '1' && !visited[i][j + 1])
//     {
//         visited[i][j+1] = true;
//         right = checker(matrix, i, j + 1, N, visited);
//     }
//     if (i - 1 >= 0 && matrix[i - 1][j] == '1' && !visited[i - 1][j])
//     {
//         visited[i-1][j] = true;
//         top = checker(matrix, i - 1, j, N, visited);
//     }
//     if (i + 1 < N && matrix[i + 1][j] == '1' && !visited[i + 1][j])
//     {
//         visited[i+1][j] = true;
//         bottom = checker(matrix, i + 1, j, N, visited);
//     }

//     int sum = left + right + top + bottom;
//     return sum + 1;
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int N;
//         cin >> N;

//         char **matrix = new char *[N];
//         for (int i = 0; i < N; i++)
//         {
//             matrix[i] = new char[N];
//             cin >> matrix[i];
//         }

//         bool **visited = new bool *[N];
//         for (int i = 0; i < N; i++)
//         {
//             visited[i] = new bool[N];
//             for (int j = 0; j < N; j++)
//             {
//                 visited[i][j] = false;
//             }
//         }

//         int value = 0;

//         for (int i = 0; i < N; i++)
//         {
//             for (int j = 0; j < N; j++)
//             {
//                 if (matrix[i][j] == '1' && !visited[i][j])
//                 {
//                     visited[i][j]=true;
//                     int x = checker(matrix, i, j, N, visited);
//                     value = max(x, value);
//                 }
//             }
//         }

//         cout << value << endl;

//         for(int i=0; i<N; i++){
//             delete [] matrix[i];
//         }

//         delete [] matrix;
//         for(int i=0; i<N; i++){
//             delete [] visited[i];
//         }

//         delete [] visited;
//     }

//     return 0;
// }


//TA SOLUTION

void cake(int **edges, bool **visited, int row, int col, int N, int &count)
{
    // Boundary conditions

    if (row < 0 || col < 0 || row >= N || col >= N || edges[row][col] == 0 || visited[row][col] == true)
    {
        return;
    }

    visited[row][col] = true;
    count++;
    if (row == N - 1 && col == N - 1)
    {
        if (edges[row][col] == 1)
        {
            visited[row][col] = true;
        }
    }

    visited[row][col] = true;
    cake(edges, visited, row + 1, col, N, count);
    cake(edges, visited, row, col + 1, N, count);
    cake(edges, visited, row - 1, col, N, count);
    cake(edges, visited, row, col - 1, N, count);
}
int main()
{

    // write your code here
    int t;
    cin >> t;
    int count = 0;
    while (t--)
    {

        int N;
        cin >> N;
        // cout<<N;
        int **edges = new int *[N];
        for (int i = 0; i < N; i++)
        {
            edges[i] = new int[N];
            for (int j = 0; j < N; j++)
            {
                edges[i][j] = 0;
            }
        }

        for (int i = 0; i < N; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < N; j++)
            {
                if (str[j] == '0')
                {
                    edges[i][j] = 0;
                }
                else
                {
                    edges[i][j] = 1;
                }
                // cout<<edges[i][j]<<" ";
            }
            // cout<<endl;
        }
        int count = 0;
        int result = -999999;
        bool **visited = new bool *[N];
        for (int i = 0; i < N; i++)
        {
            visited[i] = new bool[N];
            for (int j = 0; j < N; j++)
            {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (edges[i][j] != 1)
                {
                    continue;
                }
                int count = 0;
                cake(edges, visited, i, j, N, count);
                // cout<<count;
                result = max(result, count);
            }
        }
        cout << result << endl;
        result = 0;
    }
    return 0;
}
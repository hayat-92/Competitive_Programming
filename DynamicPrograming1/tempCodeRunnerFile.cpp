int health_countDP(int **input, int r, int c)
{
    int **dp = new int *[r];
    for (int i = 0; i < r; i++)
    {
        dp[i] = new int[c];
    }

    dp[r - 1][c - 1] = 1;
    dp[r - 2][c - 1] = 1;
    dp[r - 1][c - 2] = 1;

    for (int i = r - 3; i >= 0; i--)
    {
        if (input[i + 1][c - 1] > 0)
        {
            if (input[i + 1][c - 1] >= dp[i + 1][c - 1])
            {
                dp[i][c - 1] = 1;
            }
            else
            {
                dp[i][c-1]=dp[i+1][c-1]-input[i+1][c-1];
            }
        }else{
            dp[i][c-1]=dp[i+1][c-1]-input[i+1][c-1];
        }
    }

    for (int i = c - 3; i >= 0; i--)
    {
        if (input[r- 1][i + 1] > 0)
        {
            if (input[r - 1][i+ 1] >= dp[r- 1][i + 1])
            {
                dp[r-1][i] = 1;
            }
            else
            {
                dp[r-1][i]=dp[r-1][i+1]-input[r-1][i+1];
            }
        }else{
            dp[r-1][i]=dp[r-1][i+1]-input[r-1][i+1];
        }
    }

    for(int i=r-2; i>=0; i--){
        for(int j=c-2; j>=0; j--){
            if(dp[i+1][j]<dp[i][j+1]){
                if(input[i+1][j]>=dp[i+1][j]){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=dp[i+1][j]-input[i+1][j];
                }
            }else{
                if(input[i][j+1]>=dp[i][j+1]){
                    dp[i][j]=1;
                }else{
                    dp[i][j]=dp[i][j+1]-input[i][j+1];
                }
            }
        }
    }

    int fnl=dp[0][0];

    for(int i=0; i<r; i++){
        delete [] dp[i];
    }

    delete [] dp;

    return fnl;
}

int health_count(int **input, int rs, int cs, int re, int ce)
{
    if (rs == re && cs == ce)
    {
        return 1;
    }

    if (rs > re || cs > ce)
    {
        return INT_MAX;
    }

    int op1 = health_count(input, rs + 1, cs, re, ce);
    int op2 = health_count(input, rs, cs + 1, re, ce);
    int mvl = min(op1, op2);
    if (input[rs][cs] > 0)
    {
        if (input[rs][cs] >= mvl)
        {
            return 1;
        }
        else
        {
            return mvl - input[rs][cs];
        }
    }
    else
    {
        return mvl - input[rs][cs];
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c, r;
        cin >> r >> c;
        int **input = new int *[r];
        for (int i = 0; i < r; i++)
        {
            int *rw = new int[c];
            for (int j = 0; j < c; j++)
            {
                cin >> rw[j];
            }
            input[i] = rw;
        }

        // cout << health_count(input, 0, 0, r - 1, c - 1) << endl;
        cout<<health_countDP(input, r,c)<<endl;
        for(int i=0; i<r; i++){
            delete [] input[i];
        }

        delete[] input;
    }
    return 0;
}
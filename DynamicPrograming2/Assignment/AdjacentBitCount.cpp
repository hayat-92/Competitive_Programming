#include <iostream>
// #include <bits/stdc++.h>
#include <cstring>
using namespace std;
 
#define MAX 1000
 
// Function to find the number of Bit Strings
// of length N with K adjacent set bits
int waysToKAdjacentSetBits(int dp[][MAX][2], int n, int k,
                           int currentIndex, int adjacentSetBits, int lastBit)
{
    /* Base Case when we form bit
       string of length n */
    if (currentIndex == n) {
 
        // if f(bit string) = k, count this way
        if (adjacentSetBits == k)
            return 1;
        return 0;
    }
 
    if (dp[currentIndex][adjacentSetBits][lastBit] != -1) {
 
        return dp[currentIndex][adjacentSetBits][lastBit];
    }
 
    int noOfWays = 0;
 
    /* Check if the last bit was set,
    if it was set then call for
    next index by incrementing the
    adjacent bit count else just call
    the next index with same value of
    adjacent bit count and either set the
    bit at current index or let it remain
    unset */
 
    if (lastBit == 1) {
        // set the bit at currentIndex
        noOfWays += waysToKAdjacentSetBits(dp, n, k, currentIndex + 1,
                                                 adjacentSetBits + 1, 1);
 
        // unset the bit at currentIndex
        noOfWays += waysToKAdjacentSetBits(dp, n, k, currentIndex + 1,
                                                    adjacentSetBits, 0);
    }
 
    else if (!lastBit) {
        noOfWays += waysToKAdjacentSetBits(dp, n, k,  currentIndex + 1,
                                                     adjacentSetBits, 1);
 
        noOfWays += waysToKAdjacentSetBits(dp, n, k, currentIndex + 1,
                                                   adjacentSetBits, 0);
    }
 
    dp[currentIndex][adjacentSetBits][lastBit] = noOfWays;
 
    return noOfWays;
}
 
// Driver Code
int main()
{
    int n = 5, k = 2;
 
    /* dp[i][j][k] represents bit strings of length i
    with f(bit string) = j and last bit as k */
    int dp[MAX][MAX][2];
    memset(dp, -1, sizeof(dp));
 
    /* total ways = (ways by placing 1st bit as 1 +
                    ways by placing 1st bit as 0) */
    int totalWays = waysToKAdjacentSetBits(dp, n, k, 1, 0, 1)
                    + waysToKAdjacentSetBits(dp, n, k, 1, 0, 0);
 
    cout << "Number of ways = " << totalWays << "\n";
 
    return 0;
}
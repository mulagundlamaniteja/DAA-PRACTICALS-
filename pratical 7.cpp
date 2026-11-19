#include <iostream>  // Used for input and output (cin, cout)
#include <vector>    // Used to create dynamic arrays (vectors)
using namespace std;

int main()
{
    int n, amount;  // n = number of coin denominations, amount = target amount

    cout << "Enter number of coins: ";
    cin >> n;  // Read the number of different coin denominations

    vector<int> coins(n);  // Create a vector to store coin denominations

    cout << "Enter coins denomination: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];  // Read each coin denomination

    cout << "Enter amount: ";
    cin >> amount;  // Read the target amount

    // Create DP array and initialize all values with amount + 1 (infinity)
    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;  // 0 coins are needed to form amount 0

    // Calculate minimum coins required for every amount from 1 to target amount
    for (int i = 1; i <= amount; i++)
    {
        // Check every available coin denomination
        for (int j = 0; j < n; j++)
        {
            // Check if the current coin can be used to form amount i
            if (coins[j] <= i)
            {
                // Find the minimum coins by comparing the current answer
                // with the answer obtained using the current coin
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // Check whether the target amount can be formed or not
    if (dp[amount] == amount + 1)
        cout << "Amount cannot be formed";
    else
        // Display the minimum number of coins required
        cout << "Minimum number of coins = " << dp[amount];

    return 0;  // End the program successfully
}

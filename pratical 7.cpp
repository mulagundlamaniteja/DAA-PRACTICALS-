#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coins denomination: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter amount: ";
    cin >> amount;

    vector<int> dp(amount + 1, amount + 1);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[amount] == amount + 1)
        cout << "Amount cannot be formed";
    else
        cout << "Minimum number of coins = " << dp[amount];

    return 0;
}
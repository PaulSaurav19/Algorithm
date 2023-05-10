// A Dynamic Programming based C++ program to find minimum
// of coins to make a given change V
#include<stdio.h>
#include<limits.h>

// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
	// table[i] will be storing the minimum number of coins
	// required for i value. So table[V] will have result
	int table[V + 1];

	// Base case (If given value V is 0)
	table[0] = 0;

	// Initialize all table values as Infinite
	for (int i = 1; i <= V; i++)
		table[i] = INT_MAX;

	// Compute minimum coins required for all
	// values from 1 to V
	for (int i = 1; i <= V; i++) {
		// Go through all coins smaller than i
		for (int j = 0; j < m; j++)
			if (coins[j] <= i) {
				int sub_res = table[i - coins[j]];
				if (sub_res != INT_MAX
					&& sub_res + 1 < table[i])
					table[i] = sub_res + 1;
			}
	}

	if (table[V] == INT_MAX)
		return -1;

	return table[V];
}


int main()
{
	int coins[] = { 9, 6, 5, 1 };
	int m = sizeof(coins) / sizeof(coins[0]);
	int V = 11;
	printf("Minimum coins required is %d\n" ,minCoins(coins, m, V));
	return 0;
}




#include <stdio.h>

void findMinCoins(int coins[], int n, int value)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        while (value >= coins[i])
        {
            value -= coins[i];
            count++;
        }
        if (value == 0)
            break;
    }
    printf("Minimum number of coins required: %d", count);
}

int main()
{
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = sizeof(coins) / sizeof(coins[0]);
    int value;
    printf("Enter the value for which you want to find the minimum number of coins: ");
    scanf("%d", &value);
    findMinCoins(coins, n, value);
    return 0;
}


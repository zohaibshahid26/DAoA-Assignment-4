#include <iostream>
#include<string>
#include<fstream>
#include <vector>
#include <algorithm>
using namespace std;

int CCGreedy(vector<int>& coins, int amount)
{
	int count = 0;
	for (int i = 0; i < coins.size(); ++i)
	{
		while (amount >= coins[i])
		{
			amount -= coins[i];
			count++;
		}
	}

	if (amount != 0)
		return -1;

	return count;
}


int CCDP(vector<int>& coins, int amount)
{
		int n = coins.size();
		sort(coins.begin(), coins.end());
		vector<vector<int>> dp(n, vector<int>(amount + 1, INT_MAX));

		for (int i = 0; i < n; i++)
		{
			dp[i][0] = 0;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < amount + 1; j++)
			{
				if (coins[i] > j)
				{
					if (i == 0)
						dp[i][j] = j;
					else
						dp[i][j] = dp[i - 1][j];
				}
				else
				{
					if (i == 0)
						dp[i][j] = min(dp[i][j - coins[i]] + 1, j);

					else
						dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i]]);
				}
			}
		}

		if (dp[n - 1][amount] == INT_MAX)
			return -1; 
		return dp[n - 1][amount];
	
}

int main()
{
	ifstream file;
	file.open("cc.txt");
	string currency;
	file >> currency;
	cout << currency << endl;
	int denominations;
	file >> denominations;
	string denomstring;
	int find;
	vector<int> coins(denominations);
	for (int i = 0; i < denominations; i++)
	{
		file >> denomstring;
		find = denomstring.find(',');
		coins[i] = stoi(denomstring.substr(find + 1));
	}

	sort(coins.rbegin(), coins.rend());  //sorting the coins in descending order.

	bool isGreedySol = true;
	for (int i = 1; i < denominations; i++)
	{
		if (coins[0] % coins[i] == 0)
			isGreedySol = true;
		else
		{
			isGreedySol = false;
			break;
		}
	}
	
	cout << "Enter the amount to make from these denominations :  " << endl;
	for (int i = 0; i < denominations; i++)
		cout << coins[i] << " ";
	cout << endl;
	int amount;
	cin >> amount;
	if (isGreedySol)
	{
		int result = CCGreedy(coins, amount);
		if (result == -1)
			cout << "Can't make the given amount from these denominations:" << endl;
		else
			cout << "Greedy Solution:  Min number of coins to make the amount : " <<amount<<" is " << result << endl;

	}
	else
	{
		cout << "Greedy Solution : Might Fail We will go for the DP solution" << endl;
		int result = CCDP(coins, amount);
		if(result == -1)
			cout << "Can't make the given amount from these denominations:" << endl;
		else
			cout << "DP Solution  Min number of coins to make the amount : " << amount << " is " << result << endl;
	}

	return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;


string LCSusingRecursion(const string& string1, const string& string2, int n1, int n2)
{
	if (n1 == 0 || n2 == 0)
		return "";

	if (string1[n1 - 1] == string2[n2 - 1])
		return LCSusingRecursion(string1, string2, n1 - 1, n2 - 1) + string1[n1 - 1];
	else
	{
		string str1 = LCSusingRecursion(string1, string2, n1, n2 - 1);
		string str2 = LCSusingRecursion(string1, string2, n1 - 1, n2);
		int l1 = str1.length();
		int l2 = str2.length();
		if (l1 > l2)
			return str1;
		else
			return str2;
	}
}

string LCSUsingDP(const string& string1, const string& string2)
{

	int l1 = string1.length();
	int l2 = string2.length();

	vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
	for (int i = 1; i <= l1; i++)
	{
		for (int j = 1; j <= l2; j++)
		{
			if (string1[i - 1] == string2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	int i = l1;
	int j = l2;
	string longestsubsq;

	while (i > 0 && j > 0) {
		if (string1[i - 1] == string2[j - 1])
		{
			longestsubsq = string1[i - 1] + longestsubsq;
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) 
			i--;
		else 
			j--;
	}
	return longestsubsq;
}


int main() 
{
	int noOfSubsequences;
	cout << "Enter the number of subsequences you want to enter: ";
	cin >> noOfSubsequences;

	while (noOfSubsequences <= 0)
	{
		cout << "Enter no of subsequences greater than zero: ";
		cin >> noOfSubsequences;
	}

	cin.ignore();
	vector<string> subsq(noOfSubsequences);
	for (int i = 0; i < noOfSubsequences; i++)
	{
		cout << "Enter Seq No " << i + 1 << " : ";
		getline(cin, subsq[i]);
	}

	int choice;
	cout << "Select Method to Find Longest Common Subsequence:" << endl;
	cout << "1. Recursion" << endl;
	cout << "2. Dynamic Programming" << endl;
	cout << "Enter your choice (1 or 2): ";
	cin >> choice;

	if (choice == 1) 
	{
		if (noOfSubsequences == 1)
			cout << subsq[0];
		else if (noOfSubsequences > 1) 
		{
			string result = LCSusingRecursion(subsq[0], subsq[1], subsq[0].length(), subsq[1].length());
			for (int i = 2; i < noOfSubsequences; i++)
				result = LCSusingRecursion(result, subsq[i], result.length(), subsq[i].length());
			cout << "Longest Common Subsequence using Recursion is: " << result;
		}
	}
	else if (choice == 2)
	{
		if (noOfSubsequences == 1)
			cout << subsq[0];
		else if (noOfSubsequences > 1)
		{
			string result = LCSUsingDP(subsq[0], subsq[1]);
			for (int i = 2; i < noOfSubsequences; i++)
				result = LCSUsingDP(result, subsq[i]);
			cout << "Longest Common Subsequence using Dynamic Programming: " << result;
		}
	}
	else
		cout << "Invalid choice!";

	return 0;
}
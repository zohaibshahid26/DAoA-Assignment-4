# DAoA-Assignment-4
## 1-Coin Change Problem
Problem:
Given a set of coin denominations (coins) and a target amount (amount), find the minimum number of coins needed to make exact change for that amount. If such a combination of coins doesn't exist, return -1.

Solutions:

### Greedy Algorithm (CCGreedy):
#### Approach:
This algorithm prioritizes maximizing the value per coin at each step.
#### Steps:

* Sort denominations: 
* Order coins in descending order (highest value to lowest).
* Iterate through denominations:
* For each denomination:
  While the remaining amount is greater than or equal to the current denomination's value, subtract that denomination from the remaining amount and add one to the coin count.
* Check completion: If the remaining amount is zero after iterating through all denominations, return the coin count; otherwise, return -1.

Example:

Denominations: [25, 10, 5, 1]
Amount: 37
Sorted denominations: [25, 10, 5, 1]
Iteration:
25: 37 - 25 = 12, count = 1
10: 12 - 10 = 2, count = 2
2: 2 - 2 = 0, count = 3

#### Asymptotic Upper Bound:
Time complexity: O(n log n) due to sorting, which dominates the loop iterations.
Space complexity: O(1) as it only uses temporary variables.

***

### Dynamic Programming (CCDP):

#### Approach:
This method builds upon optimal sub-solutions to solve the entire problem.
DP table: Creates a 2D table (dp), where dp[i][j] stores the minimum number of coins needed to make change for amount j using only the first i denominations.

#### Steps:
* dp[0][0] = 0 (no coins needed for amount 0).
* dp[i][0] = 0 for all i (no coins needed for amount 0, regardless of denominations).

* Fills the table iteratively using the following formula:  dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1)
* This compares two possibilities:
1) utilizing the previous solution without the current denomination;
2) adding a coin of the current denomination and using the solution for the remaining amount.
* Solution: The final answer is stored in dp[n - 1][amount] which will be the fewest no of coins required to make the required amount.
If there is still INT_MAX on that index so it means that we cannot make that amount.

#### Asymptotic Upper Bound:
Time complexity: O(n * amount) due to nested loops.
Space complexity: O(n * amount) for the DP table.



## 2- Longest Common Subsequence (LCS) with Recursion and Dynamic Programming
Problem:
Given multiple sequences (usually strings), the LCS problem asks for the longest subsequence that is common to all of them. This subsequence does not have to be continuous within any of the original sequences.
Solving the Problem:

### 1. Recursive Approach (LCSusingRecursion):

This approach utilizes divide-and-conquer by splitting the problem into smaller subproblems based on comparing characters at the ends of the involved sequences.

#### Base cases:
If either sequence is empty, the LCS is an empty string (no common characters).
#### Recursive cases:
* If the last characters of both sequences match:
* The current character is included in the LCS, and the problem recurses on the remaining substrings (excluding the last character).
* If the last characters don't match:
      * Two recursive calls are made:
            Omit the last character from the first sequence and recurse with the remaining sequences.
            Omit the last character from the second sequence and recurse with the remaining sequences.
* Finding the longest subsequence:  The result of the recursion is the longest of the two subsequences obtained from the recursive calls.
  
### 2. Dynamic Programming Approach (LCSUsingDP):

This approach utilizes memorization to avoid redundant calculations, significantly improving efficiency.

#### Steps:
* DP table:
    A 2D table dp is created, where dp[i][j] stores the length of the LCS for the first i characters of the first sequence and the first j characters of the second sequence.

* Initialize all entries in the first row and first column of dp to 0 (empty subsequences).
* Filling the table:
Iterate through the table, filling each cell dp[i][j] using the following formula:
if strings[i - 1] == strings[j - 1]:
dp[i][j] = dp[i - 1][j - 1] + 1   characters match, increment LCS length
else:
dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])   choose the longer LCS from excluding characters

* Finding the longest subsequence:
  * The final entry dp[n][m] (where n and m are the lengths of the respective sequences) holds the length of the LCS for all sequences.
* Backtrack through the table from dp[n][m] to identify the characters included in the LCS based on the chosen values in each cell.
  
#### Aysmptotic Upperbounds:
#### Recursion: Time complexity: O(2^n) due to exponential possibilities in the recursion tree and overlapping subproblems. Space complexity: O(n) for the recursion stack.
#### Dynamic Programming: Time complexity: O(n * m) due to iterating through the DP table only once. Space complexity: O(n * m) for the DP table.

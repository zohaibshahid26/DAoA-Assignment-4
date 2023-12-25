# DAoA-Assignment-4
## 1-Coin Change Problem
Problem:
Given a set of coin denominations (coins) and a target amount (amount), find the minimum number of coins needed to make exact change for that amount. If such a combination of coins doesn't exist, return -1.

Solutions:

### Greedy Algorithm (CCGreedy):
#### Approach:
This algorithm prioritizes maximizing the value per coin at each step.
##### Steps:
*Sort denominations: 
*Order coins in descending order (highest value to lowest).
*Iterate through denominations:
*For each denomination:
  While the remaining amount is greater than or equal to the current denomination's value, subtract that denomination from the remaining amount and add one to the coin count.
*Check completion: If the remaining amount is zero after iterating through all denominations, return the coin count; otherwise, return -1.

Example:

Denominations: [25, 10, 5, 1]
Amount: 37
Sorted denominations: [25, 10, 5, 1]
Iteration:
25: 37 - 25 = 12, count = 1
10: 12 - 10 = 2, count = 2
2: 2 - 2 = 0, count = 3

# Asymptotic Upper Bound:
Time complexity: O(n log n) due to sorting, which dominates the loop iterations.
Space complexity: O(1) as it only uses temporary variables.


# Dynamic Programming (CCDP):

# Approach:
This method builds upon optimal sub-solutions to solve the entire problem.
DP table: Creates a 2D table (dp), where dp[i][j] stores the minimum number of coins needed to make change for amount j using only the first i denominations.

Base cases:
dp[0][0] = 0 (no coins needed for amount 0).
dp[i][0] = 0 for all i (no coins needed for amount 0, regardless of denominations).

 Fills the table iteratively using the following formula:
dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1)
This compares two possibilities:
1) utilizing the previous solution without the current denomination;
2) adding a coin of the current denomination and using the solution for the remaining amount.
Solution: The final answer is stored in dp[n - 1][amount] which will be the fewest no of coins required to make the required amount.
If there is still INT_MAX on that index so it means that we cannot make that amount.

# Asymptotic Upper Bound:
Time complexity: O(n * amount) due to nested loops.
Space complexity: O(n * amount) for the DP table.

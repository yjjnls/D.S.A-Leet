/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0
≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of
0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])

Credits:
Special thanks to @memoryless for adding this problem and creating all test
cases.
*/

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }

        int end = n > 10 ? 10 : n;
        int res = 10;//f(1)
        int fn = 9;
        for (int i = 2; i <= end; ++i)
        {
            //f(2)=9*9
            //f(i)=f(i-1)*(11-i) i>2
            fn = fn * (11 - i);
            res += fn;
        }
        return res;
    }
};

//time:O(n)
//space:O(1)

/* dynamic programing
f(1) = 10. (0, 1, 2, 3, ...., 9)

f(2) = 9 * 9. Because for each number i from 1, ..., 9, we can pick j to form a 2-digit number ij and there are 9 numbers that are different from i for j to choose from.

f(3) = f(2) * 8 = 9 * 9 * 8. Because for each number with unique digits of length 2, say ij, we can pick k to form a 3 digit number ijk and there are 8 numbers that are different from i and j for k to choose from.

Similarly f(4) = f(3) * 7 = 9 * 9 * 8 * 7....

...

f(10) = 9 * 9 * 8 * 7 * 6 * ... * 1

f(11) = 0 = f(12) = f(13)....

any number with length > 10 couldn't be unique digits number.

The problem is asking for numbers from 0 to 10^n. Hence return f(1) + f(2) + .. + f(n)
*/

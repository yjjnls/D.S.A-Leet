/*
Implement pow(x, n).

*/

class Solution
{
public:
    double myPow(double x, int n)
    {
    }
};

/*
solution 1
连乘n个x
time:O(n)

solution 2 优化
x^n = x^(n/2)^2 n is even
x^n = x^(n/2)^2 *x n is odd

n要大于0
time:O(log n)

solution 3 iteration
★递归的话适合于从上往下递归
而要从下网上，则迭代更适合

将n(n>=0) 转为2进制数
*/

//solution 2
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n >= 0)
            return PowPositive(x, n);
        else
            return 1.0 / PowPositive(x, -n);
    }
    double PowPositive(double x, int n)
    {
        //recursion terminator
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n == 2)
            return x * x;

        double res = PowPositive(x, n / 2);
        if (n % 2 == 0)
            return res * res;
        else
            return res * res * x;
    }
};
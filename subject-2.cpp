class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long _n) {
        // write your code here, try to do it without arithmetic operators.
        long long powR   = 5;
        long long result = 0;
        while(_n >= powR)
        {
            result += (_n / powR);
            powR *= 5;
        }
        return result;
    }
};


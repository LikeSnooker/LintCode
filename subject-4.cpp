// ugly number
// 只有 2 ,3 5 因子的数,  14就不是 14 分解为 2 和7 ,有了一个7 就不是 ugly number
class Solution {
public:
    /**
     * @param n, An integer
     * @return: the nth prime number as description.
     */
    bool ugly(int num)
    {
        if (num == 1)
            return true;
        if(num == 2)
            return true;
        if(num == 3)
            return true;
        if(num == 5)
            return true;
        if( (num & 1) == 0)
            return ugly(num >> 1);
        if(num % 3 == 0)
            return ugly(num /3);
        if(num % 5 == 0)
            return ugly(num /5);
        return false;
    }
    int nthUglyNumber(int n) {
        int num = 1;
        int i   = 0;
        while (i < n) {
            if(ugly(num))
            {
                i++;
                num++;
            }
            else
                num ++;
        }
        // write your code here
        return num-1;
    }
};
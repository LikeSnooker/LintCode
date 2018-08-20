/*
 * 题目，统计 0-n之间 ，数字k出现的次数,例子： 当n = 10 k= 0 ,输出2 
 */

/*
 * 解题思路就是 依次统计出 出现在个位 十位 百位上的数字的个数
 */
class Solution {
public:
    /**
     * @param k: An integer
     * @param n: An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        // write your code here
        int count   = 0;
        int target = 1;
        if(n == 0)
            return k==0?1:0;
        while(target <= n)
        {
            int digit = n % (target * 10);
            digit     = digit / target;
            if(target == 1 || k!= 0)
            {
                if(digit > k)
                    count += target;
                else if(digit == k)
                {
                    count += n % target;
                    count ++;
                }
            }
            if(n >= target * 10)
                count += ((n / (target * 10)) * target);
        
            target = target * 10;
        }
        return count;
    }
};
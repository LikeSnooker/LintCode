// ugly number
// 只有 2 ,3 5 因子的数,  14就不是 14 分解为 2 和7 ,有了一个7 就不是 ugly number
class Solution {
public:
    /**
     * param n, An integer
     * return: the nth prime number as description.
     */
    // 用动态规划的思路求解
    // 考虑到一个ugly number可以通过对另一个ugly number乘上2、3、5获得,我们可以维系一个保存了
    // ugly  number 的队列,将队列中的某个数乘上2、3、5 并添加到队列中
    int nthUglyNumber(int n) {
        vector<int> ugly_nums;
        ugly_nums.push_back(1);
        
        int num2_ix = 0;
        int num3_ix = 0;
        int num5_ix = 0;
        
        int nth = 1;
        while(nth < n)
        {
            int num2 = ugly_nums[num2_ix] * 2;
            int num3 = ugly_nums[num3_ix] * 3;
            int num5 = ugly_nums[num5_ix] * 5;
            int temp  = num2 < num3 ? num2 : num3;
            int min   = temp < num5 ? temp : num5;
            ugly_nums.push_back(min);
            
            if(ugly_nums[num2_ix] * 2 <= ugly_nums.back())
                num2_ix ++;
            if(ugly_nums[num3_ix] * 3 <= ugly_nums.back())
                num3_ix ++;
            if(ugly_nums[num5_ix] * 5 <= ugly_nums.back())
                num5_ix ++;
            
            nth ++;
        }
        return ugly_nums.back();
    }
};

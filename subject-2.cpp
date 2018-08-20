class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    /* 这里用到了基本算数定理:任何一个大于1的自然数 N,如果N不为质数，那么N可以唯一分解成有限个质数的乘积N=P1a1P2a2P3a3......Pnan，这里P1<P2<P3......<Pn均为质数，其中指数ai是正整数
     * 我们假象这个数被分解层2的i次方，5的j次方，以及其他质数,很容易得到 末尾零的个数，就是 i j中的较小值，（因为
     * 每有一对2和5就会乘积为10，在末尾产生一个零），另外可以肯定的是5的次方数j一定是小的，因此我们只要统计出J就可以了
     * 统计J...._...._...._...._....=，一横是5个一次方的倍数，；两横是5的2次方的倍数。n/5 就是5的一次方倍数
     * 数的个数，n/25就是二次方的数的个数，只要累加就好了，因为5的二次方同样是5的一次方的倍数，已经被统计了一次
     * 
     * 
     * 
     * 
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


#include <iostream>
class Solution {
public:
    /**
     * @param b  : An integer
     * @param a  : An integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here
        int carry = 0;
        int mask  = 1;
        int result= 0;
        int bit   = 0;
        for(int c = 0; c < (sizeof(int) << 3);c++)
        {
            int a_bit = a & mask;
            int b_bit = b & mask;
            bit = a_bit ^ b_bit;
            int temp = bit ^ carry;
            if(temp)
            {
                result = result | temp;
            }
            if(a_bit || b_bit)
            {
                if(carry)
                {
                    carry = mask << 1;
                }
                else
                {
                    if( a_bit && b_bit)
                    {
                        carry = mask << 1;
                    }
                }
            }
            else
            {
                carry = 0;
            }
            mask = mask << 1;
        }
        return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s = Solution();
    for(int i = 0;i < 100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i+j == s.aplusb(i, j))
            {
                printf("%d + %d = %d,this result is correct\n",i,j,s.aplusb(i, j));
            }
            else
            {
                printf("%d + %d = %d,this result is wrong\n",i,j,s.aplusb(i, j));
            }
            
        }
    }
    std::cout << "Hello, World!\n";
    return 0;
}

// You have a long flowerbed in which some of the plots are planted, and some are not .However, flowers cannot be planted in adjacent plots.

//                                                                                                  Given an integer array flowerbed containing 0's and
//                                                                                                  1's,
//     where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no - adjacent - flowers rule.

//  

//                                                                                                                                                                Example 1 :

//     Input : flowerbed = [ 1, 0, 0, 0, 1 ],
//             n = 1 Output : true Example 2 :

//     Input : flowerbed = [ 1, 0, 0, 0, 1 ],
//             n = 2 Output : false
//  

//                            Constraints :

//                            1 <= flowerbed.length <= 2 * 104 flowerbed[i] is 0 or
//                 1. There are no two adjacent flowers in flowerbed.0 <= n <= flowerbed.length

//                                                                                 来源：力扣（LeetCode）
//                                                                                     链接：https : //leetcode-cn.com/problems/can-place-flowers
//                                                                                                   著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int nplanted = 0;
        if (n == 0)
            return true;
        if (flowerbed.size() == 1)
        {
            if (flowerbed[0] == 0 && n <= 1)
            {
                return true;
            }
            else
                return false;
        }
        for (int i = 0; i < flowerbed.size();)
        {
            if (flowerbed[i] == 0)
            {
                //check
                if (i == 0) //special condition
                {
                    if (flowerbed[i + 1] == 0)
                    {
                        flowerbed[i] = 1;
                        nplanted++;
                        i += 2;
                        continue;
                    }
                }
                else if (i == flowerbed.size() - 1)
                {
                    if (flowerbed[i - 1] == 0)
                    {
                        flowerbed[i] = 1;
                        nplanted++;
                        i++;
                        continue;
                    }
                }
                else
                {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                    {
                        flowerbed[i] = 1;
                        nplanted++;
                        i += 2;
                        continue;
                    }
                }
            }
            ++i;
        }
        if (nplanted < n)
        {
            return false;
        }
        else
            return true;
    }
};
/*面试题 01.06. 字符串压缩
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:
 输入："aabcccccaaa"
 输出："a2b1c5a3"

 示例2:
 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：
字符串长度在[0, 50000]范围内。
*/

//一次遍历 碰到_就将他后面的字符改成大写
class Solution 
{
public:
    string compressString(string S) 
    {
        size_t size = S.size();
        if(size == 0)
        {
            return S;
        }

        string ret;
        int temp = 1;
        for(size_t i = 0; i+1 <= size; ++i)
        {
            if(S[i] == S[i+1])
            {
                ++temp;
            }
            else
            {
                ret += S[i];
                ret += to_string(temp);
                temp = 1;
            }
        }

        return ret.size() >= size ? S : ret; 
    }
};
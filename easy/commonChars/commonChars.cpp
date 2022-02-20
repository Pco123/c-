/*1002. 查找共用字符
给你一个字符串数组 words ，请你找出所有在 words 的每个字符串中都出现的共用字符（ 包括重复字符），并以数组形式返回。你可以按 任意顺序 返回答案。
示例 1：
输入：words = ["bella","label","roller"]
输出：["e","l","l"]

示例 2：
输入：words = ["cool","lock","cook"]
输出：["c","o"]
提示：
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] 由小写英文字母组成
*/


/*计数*/
class Solution 
{
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<int> mintimes(26, INT_MAX);
        int temp[26]= {0};
        for(string& word : words)
        {
            memset(temp, 0, sizeof(temp));
            for(char& ch : word)
            {
                temp[ch - 'a']++;
            }

            for(size_t i = 0; i < 26; ++i)
            {
                mintimes[i] = mintimes[i] > temp[i] ? temp[i] : mintimes[i];  
            }
        }

        vector<string> ret;
        for(size_t i = 0 ; i < 26; ++i)
        {
            while(mintimes[i]-- != 0)
            {
                ret.push_back(string(1, i+'a'));
            }
        }
        return ret;
    }
};

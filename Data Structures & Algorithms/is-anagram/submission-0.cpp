class Solution {
public:
    bool isAnagram(string s, string t) {

    unordered_map<char, int> sLetterCount;
    unordered_map<char, int> tLetterCount;

    if(s.length() == t.length())
    {
        for(int index = 0; index < s.length(); index++)
            {
                sLetterCount[s[index]]++;
            }

        for(int index = 0; index < t.length(); index++)
            {
                tLetterCount[t[index]]++;
            }
    
        if(sLetterCount == tLetterCount)
        {
            return true;
        }
    }
    return false;
    }
};

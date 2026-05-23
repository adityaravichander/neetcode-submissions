class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // sliding window solution

        unordered_set<char> window;
        int l = 0;
        int maxLength = 0;
        for(int r = 0; r < s.length(); r++)
        {
            while(window.find(s[r]) != window.end())
            {
                window.erase(s[l]);
                l++;
            }
            window.insert(s[r]);
            maxLength = max(maxLength, r-l+1);
        
        }
        return maxLength;
        /* one pointer solution 
        string temp = "";
        int lengthLongSubString = 0;
        for(char c: s)
        {
            int pos = temp.find(c);
            if(pos != string::npos)  // not nonexistent == existing
            {
                temp = temp.substr(pos+1);
            }
            temp += c;
            lengthLongSubString = max(lengthLongSubString, (int)temp.length());
        }
        return lengthLongSubString;
        */
    }
};

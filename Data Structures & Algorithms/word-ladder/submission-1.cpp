class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end())
        {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);

        int length = 1;
        
        while(!q.empty())
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
                string word = q.front();
                q.pop();

                if(word  == endWord)
                {
                    return length;
                }

                for(int pos = 0; pos < word.size(); pos++)
                {
                    char originalChar = word[pos];

                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        if(c==originalChar) continue;

                        word[pos] = c;

                        if(wordSet.find(word) != wordSet.end())
                        {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }

                    word[pos] = originalChar;
                }
            }
            length++;
        }
    return 0;
    }
};

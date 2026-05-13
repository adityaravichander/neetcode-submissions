class Solution {
public:
    bool isPalindrome(string s) {

    string alphanumericString = "";
     for (char letter : s) {
        if (alphaNum(letter)) { // Check if the character is alphanumeric
            alphanumericString += tolower(letter); // Append to the new string
        }
    }

    int currentIndex = 0, nextIndex = alphanumericString.length() - 1;

    while(currentIndex < nextIndex)
    {
        if(alphanumericString[currentIndex] == alphanumericString[nextIndex])
        {
            currentIndex++;
            nextIndex--;
        }
        else
        {
            return false;
        }
    }
    return true;        
    }

    bool alphaNum(char c) {
        return ( c >= 'A' && c <= 'Z' ||
                 c >= 'a' && c <= 'z' ||
                 c >= '0' && c <= '9');
    }

    }

;

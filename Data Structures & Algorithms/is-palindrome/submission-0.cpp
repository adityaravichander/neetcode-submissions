class Solution {
public:
    bool isPalindrome(string s) {

    string alphanumericString = "";
     for (char letter : s) {
        if (isalnum(letter)) { // Check if the character is alphanumeric
            alphanumericString += letter; // Append to the new string
        }
    }

    int currentIndex = 0, nextIndex = alphanumericString.length() - 1;

    while(currentIndex < nextIndex)
    {
        if(tolower(alphanumericString[currentIndex]) == tolower(alphanumericString[nextIndex]))
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
};

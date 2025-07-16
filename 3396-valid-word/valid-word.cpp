class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    bool isAlp(char c){
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
    }
    bool isNum(char c){
        return (c >= '0' && c <= '9');
    }
    bool isValid(string word) {
        if (word.size() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char ch : word){
            if (!isAlp(ch) && !isNum(ch)) return false;

            if (isAlp(ch)){
                if (isVowel(ch)) hasVowel = true;
                else hasConsonant = true;
            }
        }
        return hasVowel && hasConsonant;
    }
};
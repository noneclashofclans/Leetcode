class Solution {
public:
    bool isPalindrome(string s){
        int left = 0;
        int right = s.length()-1;
        while (left < right){
            if(s[left] != s[right]) return false; //not palindrome
            left++;
            right--;
        }
        return true;
    }
    int countPalindromicSubsequence(string s) {
       unordered_map<char, vector<int>> char_indexes;
       unordered_set<string> uniquePalindromes;

       //storing the indexes of each charecter
       for(int i = 0; i < s.size(); i++){
        char_indexes[s[i]].push_back(i);
       }

       //now traversing through the map
       for(const auto & [ch , indexes] : char_indexes){
        //at least the size should be 2
        if (indexes.size() > 1){
            int first = indexes.front();
            int last = indexes.back();

            if (last - first > 1){
                unordered_set<char> middleChars;
                for (int middle = first + 1; middle < last; middle ++){
                    middleChars.insert(s[middle]);
                }
                //now verify the functionality of the middle charecters
                for (char middle : middleChars){
                    string palindrome = string(1, ch) + middle + string(1, ch);
                    uniquePalindromes.insert(palindrome);
                }
            }
        }
       }
       return uniquePalindromes.size();
    }
};
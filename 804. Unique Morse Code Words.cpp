class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        string s = "";
        set<string> morse_set;
        for(int i = 0 ; i < words.size(); i++)
        {
            for(int j = 0 ; j < words[i].size() ; j++)
            {
                s = s + morse[words[i][j] - 'a'];
            }
            
            morse_set.insert(s);
            s = "";
        }
        int n = morse_set.size();
        return n;
    }
};

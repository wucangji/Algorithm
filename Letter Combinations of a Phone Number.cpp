class Solution {
public:
    vector<string> keyboard = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        dfs(digits, 0, "", result);
        return result;
    }
    
    void dfs(string digits, int num, string path, vector<string> &result){
        if(num == digits.size()){
            result.push_back(path);
            return; // do not forget to return
        }
        for(auto c:keyboard[digits[num]-'0']){   // digits[num] not [num-1] since pass num+1 in the next round
            dfs(digits, num+1, path+c , result);
        }
    }
    
};


// can add another way

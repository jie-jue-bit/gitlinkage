class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> result;
            backtrack(result, "", 0, 0, n);
            return result;
        }
    
    private:
        void backtrack(vector<string>& result, string current, int left, int right, int n) {
            // 终止条件：当前字符串长度达到 2 * n
            if (current.length() == 2 * n) {
                result.push_back(current);
                return;
            }
    
            // 添加左括号
            if (left < n) {
                backtrack(result, current + "(", left + 1, right, n);
            }
            // 添加右括号（必须保证 `right < left` 才能加右括号）
            if (right < left) {//第二个if保证了这两个if可以同时出现，才能有所有组合！
                backtrack(result, current + ")", left, right + 1, n);
            }
        }
    };




    class Solution {
        public:
        vector<string> generateParenthesis(int n){
            vector<string> result;
            backtrack(result,"",0,0,n);
            return result;
        }
        private:
        void backtrack(vector<string>& result,string cur,int left,int right,int n){
        if(cur.length()==2*n){
        result.push_back(cur);
        return;
        }
        if(left<n){
            backtrack(result,cur+"(",left+1,right,n);
        }
        if(right<left){
            backtrack(result,cur+")",left,right+1,n);
        }
        }
            };
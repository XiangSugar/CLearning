/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (35.99%)
 * Total Accepted:    532K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
bool isValid(char* s) {
    int len = strlen(s);
    if(len % 2)
        return false;
    int limit = len / 2;
    char cur;
    int p = 0;
    char * stack = malloc(limit);

    for(int i=0; i<len; i++){
        cur = s[i];
        if(cur=='{' || cur=='[' || cur=='('){
            if(p == limit)
                return false;
            stack[p++] = cur; 
        }
        else{
            if(p == 0)
                return false;
            if(cur=='}'&&stack[p-1]=='{' || cur==']'&&stack[p-1]=='[' || cur==')'&&stack[p-1]=='(')
                p--;
            else
                return false;
        }
    }
    free(stack);
    return 0 == p;
}


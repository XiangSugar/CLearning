/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.07%)
 * Total Accepted:    420.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0)
        return "";
        
    char * s = NULL;
    int len = 0;
    int i = 1, j = 0, num;

    int minsize = strlen(strs[0]);
    for(i; i<strsSize; i++){ //求所有字符串的最短长度
        if(minsize > (num = strlen(strs[i])))
            minsize = num;
    }
    for(i=0; i<minsize; i++){
        for(j=1; j<strsSize; j++)
            if(*(strs[0]+i) != *(strs[j]+i))
                break;
        if(j == strsSize)
            len++;
        else
            break;
    }
    s = (char *)malloc(sizeof(char) * (len + 1));
    for(i=0; i<len; i++)
        s[i] = *(strs[0] + i);
    *(s+len) = '\0';

    return s;
}


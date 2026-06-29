/*
给定两个字符串 s 和 t，长度分别是 m 和 n，返回 s 中的 最短窗口 子串，使得该子串包含 t 中的每一个字符（包括重复字符）。如果没有这样的子串，返回空字符串 ""。

测试用例保证答案唯一。

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
示例 2：

输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
*/
//leetcode 76
#include <iostream>
#include <unordered_map>
using namespace std;
string minWindow(string s, string t){
    int m = s.size(),n = t.size();
    if(m<n)
        return "";
    unordered_map<char, int> tmap;
    for(auto c: t){
        tmap[c]++;
    }
    int l = 0,r = 0;
    unordered_map<char,int> smap;
    int valid = 0;
    int tmp_len = INT32_MAX;
    int start = 0;
    while(r<m){
        smap[s[r]]++;
        if(tmap.find(s[r])!=tmap.end() && smap[s[r]]==tmap[s[r]]){
            valid++;
        }
        while(valid==tmap.size()){
            if(tmp_len>(r-l+1)){
                start = l;
                tmp_len = r-l+1;
            }
            if(tmap.find(s[l])!=tmap.end()){
                if(smap[s[l]]==tmap[s[l]])
                    valid--;
                // 只更新窗口的中含有的目标字符
                smap[s[l]]--;
            }
            l++;
        }
        r++;
    }
    return tmp_len == INT32_MAX?"" : s.substr(start, tmp_len);
}
int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string res = minWindow(s,t);
    cout<<res<<endl;
}
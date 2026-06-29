#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//leetcode 567
bool mycode(string s1, string s2){
    unordered_map<char, int> map1;
    for(auto i:s1){
        map1[i]++;
    }
    int n1 = s1.size();
    int n2 = s2.size();
    for(int i = 0; i<n2-n1+1; i++){
        unordered_map<char, int> map2;
        for (int j = i;j<i+n1;j++){
            map2[s2[j]]++;
        }
        int valid = 0;
        for(auto it = map1.begin();it!=map1.end();it++){
            // cout<<it->first<<endl;
            // cout<<it->second<<endl;
            if(map2.find(it->first)==map2.end()||map1[it->first]!=map2[it->first]){
                break;
            }
            valid++;
        }
        if(valid==map1.size())
            return true;
    }
    return false;
}
bool mycode2(string s1, string s2){
    int l = 0, r= 0;
    int n1 = s1.size();
    int n2 = s2.size();
    unordered_map<char,int> map1;
    for(auto c:s1){
        map1[c]++;
    }
    unordered_map<char,int> map2;
    int valid = 0;
    while(r<n2){
        map2[s2[r]]++;
        if(map1.find(s2[r])!=map1.end() && map2[s2[r]]==map1[s2[r]]){
            valid++;
        }
        while(r-l>=n1){
            if(map1.find(s2[l])!=map1.end() && map2[s2[l]]==map1[s2[l]])
                valid--;
            map2[s2[l]]--;
            l++;
        }
        if(valid==map1.size())
            return true;
        r++;
    }
    return false;
}
vector<int> findAnagrams(string s, string p) {
    if(s.size()<p.size())
        return {};
    vector<int> res;
    unordered_map<char,int> map2;
    for(auto c:p)
        map2[c]++;
    int n1 = s.size();
    int n2 = p.size();
    unordered_map<char,int> map1;
    for(int i = 0;i<n1-n2+1;i++){
        if(i==0){
            for(int j = 0;j<n2;j++){
                map1[s[j]]++;
            }
        }else{
            map1[s[i+n2]]++;
            map1[s[i-n2]]--;
        }
        int valid = 0;
        for(int k = 0;k<p.size();k++){
            if(map1.find(p[k])!=map1.end() && map1[p[k]]==map2[p[k]]){
                valid++;
            }
        }
        if(valid==p.size())
            res.push_back(i);
    }
    return res;
}
vector<int> findAnagrams2(string s, string p) {
    if(s.size()<p.size())
        return {};
    vector<int> res;
    unordered_map<char,int> map2;
    for(auto c:p)
        map2[c]++;
    int n1 = s.size();
    int n2 = p.size();
    unordered_map<char,int> map1;
    int valid = 0;
    int target = map2.size();
    for(int i = 0;i<n1;i++){
        map1[s[i]]++;
        if(map1.find(s[i])!=map1.end() && map1[s[i]]==map2[s[i]]){
            valid++;
        }
        if(i-n2>=0){
            if(map1.find(s[i-n2])!=map1.end() && map1[s[i-n2]]==map2[s[i-n2]]){
                valid--;
            }
            map1[s[i-n2]]--;
        }
        if(valid==target)
            res.push_back(i+1-n2);
    }
    return res;
}
int main(){
    string s = "ab";
    string p = "eidbjaooo";
    bool res = mycode2(s, p);
    cout<<res<<endl;
    // for(int i = 0;i<res.size();i++){
    //     cout<<res[i]<<endl;
    // }
}
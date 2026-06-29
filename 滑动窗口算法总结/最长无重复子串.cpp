#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
// bool isfuhe(unordered_map<char,int> mymap){
//     for(auto it = mymap.begin();it!=mymap.end();it++){
//         if(it->second != 1)
//             return false;
//     }
//     return true;
// }
int LongestSubstringWithoutRepeating(string s){
    unordered_map<char, int> smap;
    int l = 0, r = 0;
    int max_len = 0;
    while(r<s.size()){
        smap[s[r]]++;
        while(smap[s[r]]>1){
            smap[s[l]]--;
            if(smap[s[l]]==0)
                smap.erase(s[l]);
            l++;
        }
        if(max_len<smap.size()){
            max_len = smap.size();
        }
        
        r++;
    }
    return max_len;
}
int main(){
    string s = "abcabcbb";
    int res = LongestSubstringWithoutRepeating(s);
    cout<<res<<endl;    
}
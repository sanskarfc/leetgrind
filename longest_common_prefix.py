class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = len(strs)
        ans = ""
        for ind in range(200):
            ch = ""
            for s in strs:
                if(ind >= len(s)):
                    return ans
                    
                if(ch == ""):
                    ch = s[ind]
                else:
                    if(s[ind] != ch):
                        return ans
            ans += ch
        return strs[0]
        
                    

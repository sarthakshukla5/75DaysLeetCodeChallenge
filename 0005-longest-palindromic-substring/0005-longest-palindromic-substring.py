class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
            
        res = ""
        for i in range(len(s)):
            # Odd length palindromes (e.g., "aba")
            tmp1 = self.helper(s, i, i)
            if len(tmp1) > len(res):
                res = tmp1
                
            # Even length palindromes (e.g., "abba")
            tmp2 = self.helper(s, i, i + 1)
            if len(tmp2) > len(res):
                res = tmp2
                
        return res

    def helper(self, s: str, l: int, r: int) -> str:
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l + 1:r]
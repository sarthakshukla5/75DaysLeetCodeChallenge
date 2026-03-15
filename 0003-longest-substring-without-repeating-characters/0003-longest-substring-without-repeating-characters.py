class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        seen_chars = set()  
        left = 0             
        max_length = 0       
        
        for right in range(len(s)):
            
            # if duplicate found, shrink window from the left
            while s[right] in seen_chars:
                seen_chars.remove(s[left])
                left += 1
            
            # add current character to the set
            seen_chars.add(s[right])
            
            # update maximum length
            current_length = right - left + 1
            max_length = max(max_length, current_length)
        
        return max_length       
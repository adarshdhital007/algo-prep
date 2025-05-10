class Solution:
    def __init__(self):
        self.res = ""
    
    def expand(self, s:str, left:int, right:int):
        while left >= 0 and right < len(s) and  s[left] == s[right]:
            if right - left + 1 > len(self.res):
                self.res = s[left:right+1]
            left -= 1
            right += 1
    
    def longestPalindrome(self, s: str) -> str:
        for i in range(len(s)):
            self.expand(s, i ,i)
            self.expand(s, i , i+1)
        return self.res
        
#   Runtime : 102ms

#   Don't try to use low-level mind to program python
#   Usually it'll be slower

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if(x<0):
            return False
        numDigit = len(str(x))
        for i in range(numDigit//2):
            left = x//(10**(numDigit-1))
            right = x%10
            if(right != left):
                return False
            x -= left*(10**(numDigit-1))
            x//=10
            numDigit-=2
        return True
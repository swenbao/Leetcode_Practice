# runTime : 61ms

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if(x<0):
            return False
        num_str = str(x)
        j = -1
        for i in range(len(num_str)//2):
            if(num_str[i] != num_str[j]):
                return False
            j-=1
        return True
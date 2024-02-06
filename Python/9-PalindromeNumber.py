class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)

        if len(s) == 0:
            return False

        left = 0
        right = len(s) - 1

        for _ in range(0, int(len(s) / 2)):
            if s[left] != s[right]:
                return False
            
            left += 1
            right -= 1

        return True
    
    def isPalindrome_1(self, x: int) -> bool:
        s1 = str(x)
        s2 = s1[::-1]
        return s1 == s2
        

if __name__ == "__main__":
    # num = -121
    # num = 121
    num = 10
    print(Solution().isPalindrome_1(num))

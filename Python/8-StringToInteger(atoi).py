class Solution:
    def myAtoi(self, s: str) -> int:
        result = ""
        intResult = 0
        sign = 1

        s = s.strip()
        if len(s) <= 0:
            return 0
        
        if s[0] == '-':
            sign = -1
            s = s[1:]
        elif s[0] == '+':
            sign = 1
            s = s[1:]

        if len(s) <= 0:
            return 0
        
        for c in s:
            if c < "0" or c > "9":
                break
            result = result + c

        if len(result) > 0:
            intResult = sign * int(result)
        else:
            intResult = 0

        if intResult > (pow(2, 31) - 1):
            intResult = (pow(2, 31) - 1)

        if intResult < (-1) * pow(2, 31):
            intResult = (-1) * pow(2, 31)

        return intResult
    

if __name__ == "__main__":
    # inputStr = "42"
    # inputStr = "   -42"
    # inputStr = "4193 with words"
    # inputStr = "2147483648" # max + 1
    # inputStr = "2147483647" # max
    # inputStr = "-2147483648" # min
    # inputStr = "-2147483649" # min -1
    # inputStr = "-+42"
    inputStr = "+1"
    # inputStr = "    words1555"
    print(Solution().myAtoi(inputStr))
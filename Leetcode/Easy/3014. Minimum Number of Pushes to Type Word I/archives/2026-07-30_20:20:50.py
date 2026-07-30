class Solution:
    def minimumPushes(self, word: str) -> int:
        sum = 0
        for i in range(len(word)):
            sum += i // 8 + 1
        return sum 
            
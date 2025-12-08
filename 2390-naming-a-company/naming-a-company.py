class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        groups = [set() for _ in range(26)]

        for word in ideas:
            first = ord(word[0]) - ord('a')
            groups[first].add(word[1:])

        ans = 0

        for i in range(26):
            for j in range(i + 1, 26):
                a = groups[i]
                b = groups[j]
                common = len(a & b)
                ans += (len(a) - common) * (len(b) - common) * 2

        return ans
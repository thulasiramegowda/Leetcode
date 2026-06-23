class Solution(object):
    def zigZagArrays(self, n, l, r):
        MOD = 10**9 + 7
        k = r - l + 1
        if n < 2: return 0
        up = [i for i in range(k)]   
        down = [k - 1 - i for i in range(k)]  
        
        for _ in range(3, n + 1):
            new_up = [0] * k
            new_down = [0] * k
            
            s_down = 0
            for v in range(k):
                new_up[v] = s_down
                s_down = (s_down + down[v]) % MOD
        
            s_up = 0
            for v in range(k - 1, -1, -1):
                new_down[v] = s_up
                s_up = (s_up + up[v]) % MOD
                
            up, down = new_up, new_down
            
        return (sum(up) + sum(down)) % MOD
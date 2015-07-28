class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isIsomorphic(self, s, t):
        
       return self.func(s,t) and self.func(t,s)
    
    def func(self,s,t):
        
        dic = {}
        for u,v in zip(s,t):           
            if dic.get(u) is None :
                        
                dic[u]=v
            else:
                if dic[u] != v:
                
                 return False
  
        return True
s = Solution()
print s.isIsomorphic('paper','title')

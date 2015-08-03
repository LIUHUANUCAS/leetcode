#Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
# determine if the input string is valid.
# The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution:
    # @return a boolean
    def isValid(self, s):
                ls = []
                for i in s:
                    if i in ['(','[','{']:
                        ls.append(i)
                    else:
                        if len(ls) == 0:
                            return False
                        if  ls[-1] + i in ['()','[]','{}']:
                            ls.pop()
                        else:
                            return False
                return len(ls) == 0

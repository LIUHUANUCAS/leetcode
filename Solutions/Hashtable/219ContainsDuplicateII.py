class Solution:
    #Given an array of integers and an integer k, find out whether there there are 
    #two distinct indices i and j in the array such that nums[i] = nums[j] 
    #and the difference between i and j is at most k.

    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        dic = {}
        for i,v in enumerate(nums):
            if dic.get(v) is None:
                dic[v] = [i]
            else:
                dic[v].append(i)
         
        
        for item in dic.values():
            if len(item) <=1 :
                continue
            else:
                if (item[1] - item[0]) <= k:
                    return True
        return False
if __name__ == "__main__":
    s = Solution()
    nums = [1,2,3,1,1,1,1,2,3,4,6,5,7,4,3,2,4,5]
    k = 1;
    print s.containsNearbyDuplicate(nums,k)
    

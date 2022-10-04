
class Solution:    
    #Function to reverse every sub-array group of size k.
    def reverseInGroups(self, arr, N, K):
        # code here
        list1 = []
        for i in range(0, N, K):
            #print(arr[i:i+K])
            temp = arr[i:i+K]
            temp.reverse()
            list1.extend(temp)
        arr.clear()
        arr.extend(list1)
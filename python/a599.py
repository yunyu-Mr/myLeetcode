class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        dict2 = {list2[i]: i for i in xrange(len(list2))}
        
        # Find the minimum index sum.
        indexSum = len(list1) + len(list2)
        for i in xrange(len(list1)):
            if list1[i] in dict2:
                if i + dict2[list1[i]] < indexSum:
                    indexSum = i + dict2[list1[i]]
        # Find the common restaurant with minimum index sum.
        restaurant = []
        for i in xrange(min(indexSum+1, len(list1))):
            if list1[i] in dict2:
                if i + dict2[list1[i]] == indexSum:
                    restaurant.append(list1[i])
        return restaurant
class Solution(object):
    def leastBricks(self, wall):
        """
        :type wall: List[List[int]]
        :rtype: int
        """
        height = len(wall)   # 墙的高度
        counter = collections.defaultdict(lambda:height)  # 默认要穿过所有砖
        
        for i in range(height):        # 遍历每行
            length = 0
            for brick in wall[i][:-1]: # 遍历每块砖（除了最后一块）
                length += brick
                counter[length] -= 1   # 有缝的地方减 1
        if not counter:                # 若counter为空
            return height
        return min(counter.values())   # 返回最小穿砖数
    
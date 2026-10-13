#eu
class SnapshotArray:
    pass

#salles
class SnapshotArray:

    def __init__(self, length: int):
        self.snaps = [ [(0,0)] for _ in range(length) ]
        self.current_snap = 0

    [
        0 [ (0,5) ],
        1 [ (0,0), (3, 10), (8, 20), (11, 30) ],
        2 [ (0,0) ]
    ]

    def set(self, index: int, val: int) -> None:
        if self.snaps[index][-1][1]==val:
            return
        if self.snaps[index][-1][0]==self.current_snap:
            self.snaps[index].pop()
        self.snaps[index].append( (self.current_snap, val) )

    def snap(self) -> int:
        self.current_snap+=1
        return self.current_snap-1

    def get(self, index: int, snap_id: int) -> int:
        values = self.snaps[index]

        #print("GET", values) [ (0,0), (3, 10), (8, 20), (11, 30) ]

        left, right = 0, len(values)-1
        result = 0
        while left<=right:
            mid = (left+right)//2
            if values[mid][0]<=snap_id:
                left = mid+1
                result = values[mid][1]
            else:
                right = mid-1
        return result

# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
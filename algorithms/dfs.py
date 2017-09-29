WHITE = 0
GRAY = 1
BLACK = 2

class Graph(object):
    def __init__(self, n):
        self.V = []
        self.Adj = [[] for i in xrange(n)]

class Vertex(object):
    def __init__(self, label):
        self.label = label
        self.parent = None
        self.d = 0
        self.f = 0
        self.color = WHITE

time = 0

def dfs(graph):
    for u in graph.V:
        if u.color == WHITE:
            dfs_visit(graph, u)
        
    for u in graph.V:
        print("d:%d, f:%d" %(u.d, u.f))
    
def dfs_visit(graph, u):
    global time
    time += 1
    u.d = time
    # print("discover V%d at %d." %(u.label, u.d))
    u.color = GRAY
    for v in graph.Adj[u.label]:
        if v.color == WHITE:
            v.parent = u
            dfs_visit(graph, v)
    u.color = BLACK
    time += 1
    u.f = time
    # print("finish V%d at %d." %(u.label, u.f))

if __name__ == '__main__':
    n = 4
    
    graph = Graph(n)
    graph.V = [Vertex(i) for i in xrange(n)]
    v = graph.V
    graph.Adj[0] = [v[1], v[3]]
    graph.Adj[1] = [v[2]]
    graph.Adj[2] = [v[3]]
    graph.Adj[3] = []
    
    dfs(graph)
    
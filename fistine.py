def parse():
    [D, N, M, nbCars, bonusPoint] = map(int,input().split())
    streets = []
    for i in range(M):
        [B,E,name,L] = input().split()
        streets.append((int(B),int(E),name,int(L)))
    paths = []
    taken_streets = set()
    for _ in range(nbCars):
        prse = input().split()
        P = int(prse[0])
        path = []
        for i in range(P):
            path.append(prse[1+i])
            taken_streets.add(prse[i+1])
        paths.append(path)
    real_streets = []
    for x in streets :
        if x[2] in taken_streets:
            real_streets.append(x)
    return D, N, M, nbCars, bonusPoint, real_streets, paths
    # D = duration
    # N = nb vertices
    # M = nb arcs
    # nbcars = nb cars
    # bonus point
    # real_streets = streets same order
    # paths

def to_graph(N,M,real_streets):
    tab 

def simple_solve(D,N,M,nbCars,bonusPoint,real_streets,paths):
    

print(parse())

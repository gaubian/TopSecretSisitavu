def parse():
    [D, N, M, nbCars, bonusPoint] = map(int,input().split())
    streets = []
    for i in range(M):
        [B,E,name,L] = input().split()
        streets.append((int(B),int(E),name,int(L)))
    paths = []
    for _ in range(nbCars):
        prse = input().split()
        P = int(prse[0])
        path = []
        for i in range(P):
            path.append(prse[1+i])
        paths.append(path)
    return D, N, M, nbCars, bonusPoint, streets, paths

print(parse())

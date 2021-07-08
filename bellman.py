from copy import deepcopy

n = 6
dist = [[float("inf")]*n for i in range(n)]

def print_matrix(matrix):
    copy = deepcopy(matrix)
    copy.insert(0,[i+1 for i in range(n)])
    for i in range(n+1):
        copy[i].insert(0,i)

    s = [[str(e) for e in row] for row in copy]
    lens = [max(map(len, col)) for col in zip(*s)]
    fmt = '\t'.join('{{:{}}}'.format(x) for x in lens)
    table = [fmt.format(*row) for row in s]

    print('\n'.join(table))




# substituir pela sua matriz os indices são o valor do nó - 1
# dist[0][1] = 2 # aresta (1,2)
# dist[0][4] = 1 # aresta (1,5)
# dist[1][2] = 3 # aresta (2,3)
# dist[3][0] = 3 # aresta(4,1)
# dist[4][5] = 2 # aresta(5,6)

dist[0][1] = 2
dist[1][2] = 4
dist[0][4] = 5
dist[3][0] = 1
dist[4][5] = -3


# Bellman-Ford(v):   # v = vértice inicial


D = [float("inf")] * n
D[0] = 0

for i in range(n):
    dist[i][i] = 0

for k in range(n-1):
    print(f"\nk: {k} ===============================================")
    print_matrix(dist)
    for i in range(n):
        for j in range(n):
            if dist[i][j] != 0 and  D[j] > D[i] + dist[i][j]:
                D[j] = D[i] + dist[i][j]


print(f"\nk: {n} ===============================================")
# print_matrix(dist)

print(D)

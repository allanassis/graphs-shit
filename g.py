# adj_list = [[2,3],[4,5],[],[],[6],[7],[]]
# visited = [False] * 7

# class Queue:
#     def __init__(self):
#         self._arr = []

#     def enqueue(self, data):
#         self._arr.append(data)
    
#     def dequeue(self):
#         first_item = self._arr[0]
#         del self._arr[0]
#         return first_item

#     def is_empty(self):
#         return not bool(len(self._arr))

# def dfs(node_index):
#     if visited[node_index]:
#         return
#     print(node_index+1)
#     visited[node_index] = True
#     for key, val in enumerate(adj_list[node_index]):
#         dfs(val - 1)

# def bfs(node_index):
#     adj_list = [[2,3],[4,5],[],[],[6],[7],[]]

#     visited = [False] * 7
#     visited[node_index] = True

#     queue = Queue()
#     queue.enqueue(node_index)

#     while not queue.is_empty():
#         q_item = queue.dequeue()
#         # if visited[q_item]: continue
#         print(q_item+1)
#         for key, val in enumerate(adj_list[q_item]):
#             if visited[val - 1]:
#                 continue
#             queue.enqueue(val - 1)
#             visited[val - 1] = True

# # dfs(0)
# bfs(0)

# Reescreva o algoritmo de Busca em Profundidade em um digrafo representado por matriz de adjacências, 
# de tal forma a preencher, durante a busca,  os vetores GE e GS, que indicam, respectivamente, 
# os graus de entrada e de saída de cada vértice.

# adj_list = [[2,3],[4,5],[],[],[6],[7],[]]
visited = [False] * 4

matriz_adj = [
    [0,1,0,0],
    [0,0,0,0],
    [1,1,0,0],
    [0,0,1,0]
]
# visited = [
#     [0,0,0,0],
#     [0,0,0,0],
#     [0,0,0,0],
#     [0,0,0,0]
# ]
GE = [0] * 4
GS = [0] * 4

def dfs(node_index):
    if visited[node_index]:
        return
    print("no", node_index+1)
    visited[node_index] = True
    for val in range(len(matriz_adj[node_index])):
        if matriz_adj[node_index][val] == 1:
            GE[val] = GE[val] + 1
            GS[node_index] = GS[node_index] + 1
            dfs(val)

componentes = 0
for i in range(len(matriz_adj)):
    print("componente", componentes)
    dfs(i)
    componentes=componentes+1

print("GE", GE)
print("GS", GS)


# QUESTÃO - 3


# matriz_adj <- /*PREENCHE A MATRIZ*/
# GE <- [0] * TAMANHO_DO_GRAFO            // Cria o vetor GE preenchendo todos os valores com 0 do tamanho do grafo
# GS <- [0] * TAMANHO_DO_GRAFO            // Cria o vetor GS preenchendo todos os valores com 0 do tamanho do grafo
# visitados <- [false] * TAMANHO_DO_GRAFO // Cria o vetor visitados com todos os valores com false do tamanho do grafo

# busca_profunda(no_index):
#     se visitados[no_index]:                  // Verifica se o nó já foi visitado, se sim não faz nada
#         retorna
#     visitado[no_index] <- true               // Se não foi visitado adiciona como visitado no vetor visitados
#     para i <- 0 ... TAMANHO_DO_GRAFO:       // Percorre todos os valores do vetor da matriz de adjencias no no_index
#         se matriz_adj[no_index][i] == 1:    // Verifica se nesse no e esse valor da matriz de fato é uma aresta
#             GE[i] <- GE[i] + 1               // Incrementa o vetor de entradas
#             GS[no_index] <- GS[no_index] + 1 // Incrementa o vetor de saídas
#             busca_profunda(i)               // Chama a busca profunda para o próximo nó

# para i <-0 ...TAMANHO_DO_GRAFO:
#     busca_profunda(i)


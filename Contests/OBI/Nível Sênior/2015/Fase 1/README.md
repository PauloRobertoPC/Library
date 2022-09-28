Divisores - [Teoria Dos Números]. Basta contar os divisores.

Lápis de Cor - [BFS Multisource]. 

Metrô - [DFS + Observação]. Note que nesse tipo de grafo todos os nós do ciclo que tem ligação com a central tem grau 3 ou 4, sendo assim, basta rodar uma dfs a partir das extremidades(que tem grau 1) e a partir do nó central(que tem grau >= 5) e sair visitando os vértices que tem grau <= 2. Depois disso todos os vértices não visitados estarão no ciclo.

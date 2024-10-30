Estrutura de Dados

Filas 
- São estrutras que permitem a inserção e remoção de dados na ordem FIFO (First in-First Out)
   - Os elementos são inseridos em ordem de chegada, o primiero inserido fica na primeira posição, o segundo inserido na segunda posição e assim por diante
      - A extremidade de inserção é a 'rear', é o último local disponível da fila
   - Para a ordem de retirada, a ordem de retirada é a mesma de insersão, o primeiro a ser removido é o elemento na primeira posição e assim por diante
      - A extremidade de remoção é 'front', é sempre o primeiro elemento da lista
- A implementação de filas é feita por um vetor[0 até N-1], sendo que parte desse vetor é a nossa fila, delimitada pelo segmento fila[p até u-1]
   - O primeiro elemento da fila é representado por 'p' e o útlumo 'u-1'
   - A fila é considerada vazia se 'p == u' e cheia se 'u == N'

  
  EXEMPLOS

  int tirafila (void){
    return fila[p++];
  }

  void colocafila (int y){
    fila[u++] = y;
  }


Para a função de hash utilizamos o método de tirar o módulo do id do jogador pelo tamanho da tabela, garantindo um processamento simples e rápido, além de distribuir em uma taxa aceitável os valores na tabela.

Para o método de resolução de conflitos nós utilizamos o endereçamento fechado com encadeamento, pois é um método simples e fácil de implementar, além de não desperdiçar memória.
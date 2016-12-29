README:


Para compilar:

	Basta realizar o comando make dentro da pasta, logo após, executar colocando como argumento alfabetos.txt e palavras.txt(nesta ordem). As entradas deverão ser digitadas na tela para encontrar as palavras.

Visão geral:

	No trabalho foi implementada uma árvore TRIE com certas modificações para se adequar as nossas buscas e inserções das palavras. Uma dessas modificações foi a escolha de colocar nos nós uma chave que irá conter a informação necessária para percorrer os nós na busca. 

	Após encontrar o caminho correto para inserir a palavra, é criado um novo nó que irá apontar para o nó que representa o fim da palavra, e nesse nó criado será inserida a palavra, além de inserir o número 1 ao nó anterior confirmando que esse nó possui palavras.

Exemplo:  T2

                         Raiz
                       /      \
                     2          3
                   /   \      /   \
                  2 *   3    2     3           (*)->existe palavra
               /  |  \
        Palavra   2   3

	Para verificar se a palavra existe, apenas é conferido se existe o inteiro 1 no nó, se sim, ele irá buscar por todas as palavras presentes nos nós filhos desse nó.

	Para procurar uma palavra a partir da entrada que foi fornecida, do nodo raiz eu vou escolhendo os nodos comparando a entrada com as chaves dos nodos filhos, assim, quando for igual, eu vou para este nodo e comparo as próximas chaves dos nodos filhos com o restante da entrada.


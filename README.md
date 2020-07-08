Problema:

Pedro está fazendo uma pesquisa sobre o problema do movimento do cavalo em um tabuleiro de xadrez e incumbiu você da tarefa de encontrar o menor conjunto de movimentos possíveis, podendo sair de qualquer quadrado a e podendo chegar em qualquer quadrado b dentro do tabuleiro, sendo que a e b são quadrados diferentes. Ele pensa que a parte mais difícil do problema é determinar o menor número de movimentos do cavalo entre 2 quadrados fornecidos e que uma vez que você está comprometido com esta tarefa, encontrar a sequência de movimentos entre estes 2 quadrados será uma tarefa muito fácil.
É claro que você sabe que o movimento é vice versa. Portanto você deve fornecer a Pedro um programa que resolva esta questão.
Seu trabalho então será escrever um programa que, pegando dois quadrados a e b como entrada, determine o número de movimentos para encontrar a rota mais curta de a até b.

Entrada:

A entrada contém um ou mais casos de teste. Cada caso de teste consiste de uma linha contendo dois quadrados separados por um espaço. Um quadrado será uma string consistindo de uma letra (a-h) representando a coluna e um dígito (1-8) representando a linha do tabuleiro de xadrez.

Saída:
para cada caso de teste imprima uma linha dizendo "To get from xx to yy takes n knight moves.". No caso xx é a origem, yy é o destino e n é a quantidade de movimentos necessários para ir de xx até yy.

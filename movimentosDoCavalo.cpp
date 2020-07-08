#include <cstdlib>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class grafo{
    
public:
    
    int **adjacencia, visitado;
    
    grafo(){
        visitado = 0;
        /*
         *Alocação da matriz de adjacencia
         */
        adjacencia = (int **) malloc(8 * sizeof(int *));
        for(int i = 0; i < 8; i++){
            adjacencia[i] = (int *)malloc(8 * sizeof(int));
            for(int j = 0; j < 8; j++){
                adjacencia[i][j] = 0;
            }
        }
    }
    
};


int menorValor(int x, int y){
    if(x < y){
        return x;
    }
    else{
        return y;
    }
    
}


/*
 *Método que percorre vértices e seus adjacentes ainda não visitados
 */
int visitaVertice(int x1, int x2, int y1, int y2, grafo vertices[], int saltos, int menor){
    //visitado = 1 (este vértice foi visitado, mas pode conter adjacentes ainda não visitados)
    vertices[(8*x1)+y1].visitado = 1;
    //Caso o vértice final seja alcançado
    if(x1 == x2 && y1 == y2){
        return saltos;
    }
    /*
     *Visita cada vértice adjacente ainda não visitado
     */
    for(int i=0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(vertices[(8 * x1) + y1].adjacencia[i][j] == 1){
                /*
                 *Ao identificar uma adjacencia, é adicionado um passo a mais percorrido pelo cavalo,
                  pois é possível realizar esse movimento
                 */
                saltos++;
                /*
                 *Caso ele chegue na posição final desejada, verificamos se o menor é menor que
                  a quantidade de saltos usados para chegar até lá. Ou seja, se não houve outro caminho
                  que necessitou de menos passos.
                 */
                if(i == x2 && j == y2){
                    if(menor > saltos){
                        menor = saltos;
                    }
                }
                /*
                 *Caso ele não chegue na posição final desejada, verificamos os outros vértices
                  adjacentes. Ou seja, outros possíveis caminhos
                 */
                else if(vertices[(8 * i)+j].visitado == 0 && saltos <= menor){
                    menor = menorValor(visitaVertice(i, x2, j, y2, vertices, saltos, menor), menor);
                    vertices[(8 * i)+j].visitado == 0;
                }
                /*
                 *Caso já tenha um caminho que chegou no ponto final utilizando menos passos que o atual,
                  é desnecessário proceguir com a execução do atual.
                 */
                else if(saltos > menor){
                    i =8;
                    j = 8;
                }
                saltos--;
            }
        }
    }
    //visitado = 2 (todos seus adjacentes já foram visitados)
    vertices[(8*x1)+y1].visitado = 2;
    return menor;
}

/*
 *Atribuímos adjacência entre os vértices considerando cada possibilidade que o cavalo poderia
  selecionar para onde ir.
 */
void atribuiAdjacencia(grafo vertices[]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            vertices[(8*i)+j].adjacencia[i][j] = 1;
            if((i-1)>=0){
                if((j+2)<8){
                    vertices[(8*i)+j].adjacencia[i-1][j+2] = 1;
                }
                if((j-2)>=0){
                    vertices[(8*i)+j].adjacencia[i-1][j-2] = 1;
                }
            }
            if((i-2)>=0){
                if((j+1)<8){
                    vertices[(8*i)+j].adjacencia[i-2][j+1] = 1;
                }
                if((j-1)>=0){
                    vertices[(8*i)+j].adjacencia[i-2][j-1] = 1;
                }
            }
            if((i+1)<8){
                if((j+2)<8){
                    vertices[(8*i)+j].adjacencia[i+1][j+2] = 1;
                }
                if((j-2)>=0){
                    vertices[(8*i)+j].adjacencia[i+1][j-2] = 1;
                }
            }
            if((i+2)<8){
                if((j+1)<8){
                    vertices[(8*i)+j].adjacencia[i+2][j+1] = 1;
                }
                if((j-1)>=0){
                    vertices[(8*i)+j].adjacencia[i+2][j-1] = 1;
                }
            }
        }
    }
}

void reset(grafo vertices[]){
    for(int i=0;i<64;i++){
        vertices[i].visitado = 0;
    }
}

int main() {
    int movimentos;
    char letra='a', posicao1[] = "0000", posicao2[] = "0000";
    grafo vertices[64];
    atribuiAdjacencia(vertices);
    int execucoes = 8;
    while(execucoes > 0){
        cin >> posicao1;
        cin >> posicao2;
        movimentos = visitaVertice(posicao1[1]-49, posicao2[1]-49, posicao1[0]-97, posicao2[0]-97, vertices, 0, 6);
        cout << "To get from ";
        cout << posicao1;
        cout << " to ";
        cout << posicao2;
        cout << " takes ";
        cout << movimentos;
        cout << " knight moves." << endl;
        reset(vertices);
        execucoes--;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int> > matrizAdjacencia(0, vector<int>(0));
vector<bool> visitado;

void DFS(int verticeInicial) {
    stack<int> stack;
    stack.push(verticeInicial-1);

    cout << endl << "Ordem de busca do algoritmo DFS: " << endl;

    while(!stack.empty()) {
        int v = stack.top();
        stack.pop();

        if(!visitado[v]) {
            cout << v+1 << " ";
            visitado[v] = true;
        }

        for(int i=matrizAdjacencia[v].size()-1;i>=0;i--) {
            if(matrizAdjacencia[v][i] == 1 && !visitado[i]) {
                stack.push(i);
            }
        }
    }
    cout << endl;
    visitado.assign(matrizAdjacencia.size(), false);
}

void BFS(int verticeInicial) {
    queue<int> fila;

    fila.push(verticeInicial-1);
    visitado[verticeInicial-1] = true;

    cout << endl << "Ordem de busca do algoritmo BFS: " << endl;

    while(!fila.empty()) {
        int v = fila.front();
        fila.pop();

        cout << v+1 << " ";

        for(int i = 0; i < matrizAdjacencia[v].size(); i++) {
            if(matrizAdjacencia[v][i] == 1 && !visitado[i]) {
                fila.push(i);
                visitado[i] = true;
            }
        }
    }
    cout << endl;
    visitado.assign(matrizAdjacencia.size(), false);
}



int main()
{

    int opcaoMenu;
    int numeroVertices=0;
    bool dirigido = false;

    do {
    cout << endl << "Representacao e percusos em grafos." << endl;
    cout << "1- Inserir Vertices" << endl;
    cout << "2- Inserir Aresta" << endl;
    cout << "3- Aplicar algoritmo de busca" << endl;
    cout << "4- Imprimir matriz de adjacencia" << endl;
    cout << "5- Resetar grafo" << endl;
    cout << "0- Sair" << endl << endl;
    cin >> opcaoMenu;

    switch(opcaoMenu){
    case 1: {
        int grafoOpcao=1;
        cout << "Quantos vertices gostaria de ter no seu grafo? " << endl;
        cin >> numeroVertices;
        matrizAdjacencia.resize(numeroVertices, vector<int>(numeroVertices));
        visitado.assign(numeroVertices, false);
        cout << "Seu grafo será nao-dirigido (1) ou dirigido(2)? " << endl;
        cin >> grafoOpcao;
        if(grafoOpcao==2){
            dirigido=true;
        }
        break;
    }
    case 2: {
        int verticeSaida, verticeDestino;
        do{
        cout << endl << "Para parar de adicionar arestas digite 0 0" << endl;
        cout << "Voce tem " << numeroVertices << " vertices" << endl;
        cout << "Digite o caminho da aresta (Exemplo: 1 2): " << endl;
        cin >> verticeSaida >> verticeDestino;

        if((verticeSaida < 1 || verticeDestino < 1) || (verticeSaida > numeroVertices || verticeDestino > numeroVertices)){
            cout << "Numero invalido, preencha de 1 ate " << numeroVertices << endl;
        } else {
            if(!dirigido){
                matrizAdjacencia[verticeSaida-1][verticeDestino-1] = 1;
                matrizAdjacencia[verticeDestino-1][verticeSaida-1] = 1;
            } else {
                matrizAdjacencia[verticeSaida-1][verticeDestino-1] = 1;
            }
            cout << "Aresta adicionada com sucesso!" << endl << endl;
        }

        } while(verticeSaida!=0 && verticeDestino!=0);


        break;
    }
    case 3: {
        int opcaoBusca, verticeInicial;
        cout << "Qual o vertice inicial? " << endl;
        cin >> verticeInicial;
        cout << "Qual algoritmo de busca voce quer utilizar? BFS(1) ou DFS(2)" << endl;
        cin >> opcaoBusca;
        if(opcaoBusca==1){
            BFS(verticeInicial);
        } else if(opcaoBusca==2) {
            DFS(verticeInicial);
        } else {
            cout << "Insira um numero valido" << endl;
        }
        break;
    }
    case 4: {
        cout << endl;
        cout << "Matriz de Adjacencia:" << endl;
        for(int i=0;i<numeroVertices;i++){
            for(int j=0;j<numeroVertices;j++){
                cout << matrizAdjacencia[i][j] << " ";
            }

            cout << endl;
        }
        cout << endl;
        break;
    }
    case 5: {
        cout << "Resetando o grafo..." << endl;
        matrizAdjacencia.clear();
        visitado.clear();
        numeroVertices = 0;
        cout << "Grafo resetado com sucesso!" << endl;
        break;
    }
    default:
        cout << "Insira um numero valido" << endl;
    }
    } while (opcaoMenu!=0);



    return 0;
}

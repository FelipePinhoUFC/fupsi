#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct TipoJogo{
    string *vet;
    int tam;
    int dist;
};


//
TipoJogo carregaJogo(int nivel){
    TipoJogo jogo;
    if(nivel == 1){
        jogo.tam = 3;
        jogo.dist = 1;
        jogo.vet = new string[3];
        jogo.vet[0] = "pedra";
        jogo.vet[1] = "tesoura";
        jogo.vet[2] = "papel";
    }
    if(nivel == 2){
        jogo.tam = 5;
        jogo.dist = 2;
        jogo.vet = new string[5];
        jogo.vet[0] = "pedra";
        jogo.vet[1] = "tesoura";
        jogo.vet[2] = "lagarto";
        jogo.vet[3] = "papel";
        jogo.vet[4] = "spock";
    }
    return jogo;
}

int escolha_computador(int tam){
    return rand() % tam;
}

//retorna indice no vetor de jogo
int perguntar_usuario(TipoJogo jogo){
    cout << "Escolha um numero abaixo, que corresponda";
    cout << "a sua opcao: " << endl;

    for( int i = 0; i < jogo.tam; i++){
        cout << i << " " << jogo.vet[i] << endl;
    }
    int opcao = -1;
    while(opcao < 0 || opcao >= jogo.tam){
        cin >> opcao;
    }
    return opcao;
}

enum Resultado{GANHOU, PERDEU, EMPATOU};

Resultado resultado_de_A(int A, int B, TipoJogo jogo){
    if(A == B)
        return EMPATOU;
    if(B < A)
        B += jogo.tam; //colocando B na frente de A
    if ((A + jogo.dist) >= B)
        return GANHOU;
    return PERDEU;
}

int opcao_inicial(){
    int opcao = 0;
    cout << "Escolha 1 para modo frouxo, ou 2 para modo Cangaceiro" << endl;
    while(opcao != 1 && opcao != 2)
        cin >> opcao;
    return opcao;
}

int main(){
    srand(time(NULL));
    int opcao = opcao_inicial();
    TipoJogo jogo = carregaJogo(opcao);
    int opUsuario = perguntar_usuario(jogo);
    int opPc =  escolha_computador(jogo.tam);

    cout << "Voce escolheu " << jogo.vet[opUsuario] << endl;
    cout << "Pc escolheu " << jogo.vet[opPc] << endl;
    Resultado res = resultado_de_A(opUsuario, opPc, jogo);
    if(res == GANHOU)
        cout << "voce ganhou" << endl;
    if(res == PERDEU)
        cout << "voce perdeu seu fraco" << endl;
    if(res == EMPATOU)
        cout << "empatou seu fraco" << endl;

    return 0;
}

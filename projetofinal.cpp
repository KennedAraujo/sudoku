//projeto final (fazer um jogo de sudoku)
#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
int main () {
    SetConsoleOutputCP(CP_UTF8);
    while(true){
        cout << "=========================================" << endl;
        cout << "              SUDOKU- MENU               " << endl;
        cout << "=========================================" << endl;
        cout << " Selecione uma opcao para prosseguir:    " << endl;
        cout << "----------------------------------------" << endl;
        cout << "  [1] -> Ler as regras do jogo          " << endl;
        cout << "  [2] -> Ver pontuacao geral            " << endl;
        cout << "  [3] -> Jogar: Dificuldade Iniciante   " << endl;
        cout << "  [4] -> Jogar: Dificuldade Intermediaria" << endl;
        cout << "  [5] -> Jogar: Dificuldade Dificil     " << endl;
        cout << "  [6] -> Sair do jogo                   " << endl;
        cout << "----------------------------------------" << endl;
        cout << " Digite sua opcao: ";
    int opicao=0;
    cin >> opicao;
    switch(opicao){
        case 1:{
            cout << "=========================================================\n";
            cout << "                    REGRAS DO SUDOKU                     \n";
            cout << "=========================================================\n\n";

            cout << "1. OBJETIVO:\n";
            cout << "   Preencha TODOS os espacos vazios do tabuleiro de modo\n";
            cout << "   que os numeros nao se repitam na mesma LINHA, COLUNA\n";
            cout << "   ou BLOCO.\n\n";

            cout << "2. NIVEIS DE DIFICULDADE (Escolha no menu):\n";
            cout << "   * Nivel 1 (Matriz 3x3): Preencha com numeros de 1 a 3.\n";
            cout << "     Sem blocos internos.\n\n";
            cout << "   * Nivel 2 (Matriz 6x6): Preencha com numeros de 1 a 9.\n";
            cout << "     Dividido em blocos de 3x3. Sem repeticao\n";
            cout << "     na linha, coluna ou bloco.\n\n";
            cout << "   * Nivel 3 (Matriz 9x9): Preencha com numeros de 1 a 9.\n";
            cout << "     Dividido em blocos de 3x3. Sem repeticao\n";
            cout << "     na linha, coluna ou bloco.\n\n";

            cout << "3. PONTUACAO:\n";
            cout << "   * Jogada correta:          +10 pontos\n";
            cout << "   * Jogada incorreta:         -5 pontos\n";
            cout << "   * Completar sem erros:    +100 pontos de bonus\n";
            cout << "   * Pontuacao nunca fica abaixo de 0.\n\n";

            cout << "4. VERIFICACAO EM TEMPO REAL:\n";
            cout << "   * O sistema avisa se o numero se repete na LINHA.\n";
            cout << "   * O sistema avisa se o numero se repete na COLUNA.\n";
            cout << "   * O sistema avisa se o numero se repete no BLOCO.\n\n";

            cout << "5. COMO JOGAR:\n";
            cout << "   * Digite a linha, coluna e numero desejado.\n";
            cout << "   * Digite 0 em qualquer campo para voltar ao menu.\n\n";

            cout << "=========================================================\n";
            break;
        }
        case 2: {
            int recorde = 0;
            ifstream arqLer("ranking.txt");
        if (arqLer.is_open()) {
            arqLer >> recorde;
            arqLer.close();
            cout << "Sua melhor pontuacao: " << recorde << " pontos." << endl;
        } 
        else {
        cout << "Nenhuma pontuacao registrada ainda." << endl;
    }
    system("pause");
    break;
}
        case 3: {
        cout << "Iniciando jogo no nivel Iniciante (Matriz 3x3)..." << endl;
    
        int matriz[3][3];
    
        // zeragem ISOLADA, fora do while
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                matriz[i][j] = 0;

        // score, erros e while ficam AQUI, fora dos for
        int score = 0;
        int erros = 0;
        bool jogando = true;
             while(jogando){
                system("cls");
                 cout <<"   |C1 |C2 |C3 |" << endl;
                 cout <<"---+---+---+---+" << endl;

                for(int i=0; i<3; i++){
                    cout <<"L" << i+1 << " |";
                    for(int j=0; j<3; j++){
                        if(matriz[i][j] == 0)
                            cout <<"   |";
                        else
                            cout <<" " << matriz[i][j] << " |";
                    }
                        cout << endl;
                        cout <<"---+---+---+---+" << endl;
                }
                cout<< "\n Pontuação: " << score << " pontos. Erros: " << erros << endl;
                cout << "Digite a linha (1-3), coluna (1-3), ou digite 0 para sair:\n";
                int linha, coluna =0;
                cin >> linha >> coluna;
                if(linha == 0 || coluna == 0)
                    break;
                cout<<" numero (1-3) para jogar (ex: 1 2 3), ou digite 0 para sair: \n";
                int numero;
                cin >> numero;
                if (numero==0)
                    break;
                if(numero < 1 || numero > 3){
                    cout << "Numero invalido! Digite um numero entre 1 e 3." << endl;
                    break;
                }
                if(matriz[linha-1][coluna-1] != 0){
                    cout << "Posicao ja preenchida! Tente novamente." << endl;
                    system("pause");
                    continue;
                }
                bool linhaOK=true;
                for(int c=0; c<3; c++){
                    if(matriz[linha-1][c] == numero){
                        linhaOK = false;
                        break;
                    }
                }
                bool colunaOK=true;
                for(int r=0; r<3; r++){
                    if(matriz[r][coluna-1] == numero){
                        colunaOK = false;
                            break;
                    }
                }
                if(linhaOK && colunaOK){
                    matriz[linha-1][coluna-1] = numero;
                    score += 10;
                    cout << "Numero colocado corretamente!" << endl;
                } 
                else {
                    erros++;
                    score -= 5;
                    cout << "Numero colocado incorretamente!" << endl;
                }
                bool completo = true;
                for(int i=0; i<3 && completo; i++){
                    for(int j=0; j<3 && completo; j++){
                        if(matriz[i][j] == 0)
                            completo = false;
                    }
                }
                if (completo) {
                    if (erros == 0) {
                        score += 100;
                    }
                        cout << "Parabens! Voce completou o tabuleiro!" << endl;
                        cout << "Pontuacao final: " << score << " pontos." << endl;

                int recorde = 0;
                    ifstream arqLer("ranking.txt");
                if (arqLer.is_open()) { 
                    arqLer >> recorde; arqLer.close(); 
                }

                if (score > recorde) {
                    ofstream arqGravar("ranking.txt");
                if (arqGravar.is_open()) { 
                    arqGravar << score << endl; arqGravar.close(); 
                }
                cout << "Novo recorde salvo!" << endl;
                } 
                else {
                    cout << "Recorde atual: " << recorde << " pontos." << endl;
                }
            system("pause");
            jogando = false;
            }
        } 
        break;
    }
        case 4: {
            cout << "Iniciando jogo no nivel Intermediario (Matriz 6x6)..." << endl;
            int matriz[6][6];
            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                    matriz[i][j] = 0;

            int score = 0;
            int erros = 0;
            bool jogando = true;
            while (jogando) {
                system("cls");
                cout << "   |C1 |C2 |C3 |C4 |C5 |C6 |" << endl;
                cout << "---+---+---+---+---+---+---+" << endl;

                for (int i = 0; i < 6; i++) {
                    cout << "L" << i+1 << " |";
                    for (int j = 0; j < 6; j++) {
                        if (matriz[i][j] == 0)
                            cout << "   |";
                        else
                            cout << " " << matriz[i][j] << " |";
                    }
                    cout << endl;

                    // separador de bloco a cada 3 linhas
                    if ((i + 1) % 3 == 0)
                        cout << "===+===+===+===+===+===+===+" << endl;
                    else
                        cout << "---+---+---+---+---+---+---+" << endl;
                }

                    cout << "\n Pontuacao: " << score << " pontos. Erros: " << erros << endl;

                    cout << "Digite a linha (1-6), ou 0 para sair: ";
                    int linha;
                    cin >> linha;
                    if (linha == 0) break;
                    if (linha < 1 || linha > 6) {
                        cout << "Linha invalida!" << endl;
                        system("pause"); 
                        continue;
                    }

                    cout << "Digite a coluna (1-6), ou 0 para sair: ";
                    int coluna;
                    cin >> coluna;
                    if (coluna == 0) break;
                    if (coluna < 1 || coluna > 6) {
                        cout << "Coluna invalida!" << endl;
                        system("pause"); 
                        continue;
                    }

                    if (matriz[linha-1][coluna-1] != 0) {
                        cout << "Posicao ja preenchida!" << endl;
                        system("pause"); 
                        continue;
                    }

                    cout << "Digite o numero (1-9), ou 0 para sair: ";
                    int numero;
                    cin >> numero;
                    if (numero == 0) break;
                    if (numero < 1 || numero > 9) {
                        cout << "Numero invalido! Digite entre 1 e 9." << endl;
                        system("pause"); 
                        continue;
                    }
                    // validar linha
                    bool linhaOK = true;
                    for (int c = 0; c < 6; c++)
                        if (matriz[linha-1][c] == numero){ 
                            linhaOK = false; break; 
                        }

                    // validar coluna
                    bool colunaOK = true;
                    for (int r = 0; r < 6; r++)
                        if (matriz[r][coluna-1] == numero){
                             colunaOK = false; break;
                        }

                    // validar bloco 3x3
                    bool blocoOK = true;
                    int inicioLinha  = ((linha-1)  / 3) * 3;
                    int inicioColuna = ((coluna-1) / 3) * 3;
                    for (int i = inicioLinha; i < inicioLinha + 3 && blocoOK; i++)
                        for (int j = inicioColuna; j < inicioColuna + 3 && blocoOK; j++)
                        if (matriz[i][j] == numero)
                        blocoOK = false;

                    if (linhaOK && colunaOK && blocoOK) {
                        matriz[linha-1][coluna-1] = numero;
                        score += 10;
                        cout << "Numero colocado corretamente! +10 pontos" << endl;
                    }   
                    else {
                    erros++;
                    score -= 5;

                    if (score < 0) 
                        score = 0;
                    if (!linhaOK)  
                        cout << "[X] Numero repetido na LINHA!" << endl;
                    if (!colunaOK) 
                        cout << "[X] Numero repetido na COLUNA!" << endl;
                    if (!blocoOK)  
                        cout << "[X] Numero repetido no BLOCO!" << endl;
                        cout << "Numero colocado incorretamente! -5 pontos" << endl;
                    }

                    // verificar vitoria
                    bool completo = true;
                    for (int i = 0; i < 6 && completo; i++)
                        for (int j = 0; j < 6 && completo; j++)
                            if (matriz[i][j] == 0) completo = false;

                    if (completo) {
                    if (erros == 0) score += 100;
                        cout << "Parabens! Voce completou o 6x6!" << endl;
                        cout << "Pontuacao final: " << score << " pontos." << endl;

                    int recorde = 0;
                    ifstream arqLer("ranking.txt");
                    if (arqLer.is_open()) { arqLer >> recorde; arqLer.close(); }

                    if (score > recorde) {
                        ofstream arqGravar("ranking.txt");
                    if (arqGravar.is_open()) { arqGravar << score << endl; arqGravar.close(); }
                        cout << "Novo recorde salvo!" << endl;
                    }       
                    else {
                        cout << "Recorde atual: " << recorde << " pontos." << endl;
                    }

                system("pause");
                jogando = false;
            }
        } 
        break;
    } 
        case 5: {
            cout << "Iniciando jogo no nivel Dificil (Matriz 9x9)..." << endl;
            int matriz[9][9];
            for (int i = 0; i < 9; i++)
                for (int j = 0; j < 9; j++)
                    matriz[i][j] = 0;

            int score = 0;
            int erros = 0;
            bool jogando = true;

            while (jogando) {
                system("cls");
                cout << "   |C1 |C2 |C3 |C4 |C5 |C6 |C7 |C8 |C9 |" << endl;
                cout << "---+---+---+---+---+---+---+---+---+---+" << endl;

                for (int i = 0; i < 9; i++) {
                    cout << "L" << i+1 << " |";
                for (int j = 0; j < 9; j++) {
                    if (matriz[i][j] == 0)
                        cout << "   |";
                    else
                        cout << " " << matriz[i][j] << " |";
                }
                cout << endl;
                if ((i + 1) % 3 == 0)
                    cout << "===+===+===+===+===+===+===+===+===+===+" << endl;
                else
                    cout << "---+---+---+---+---+---+---+---+---+---+" << endl;
                }

                cout << "\n Pontuacao: " << score << " pontos. Erros: " << erros << endl;
                cout << "Digite a linha (1-9), ou 0 para sair: ";
                int linha;
                cin >> linha;
                if (linha == 0) break;
                if (linha < 1 || linha > 9) {
                    cout << "Linha invalida!" << endl;
                    system("pause"); 
                    continue;
                }

                cout << "Digite a coluna (1-9), ou 0 para sair: ";
                int coluna;
                cin >> coluna;
                if (coluna == 0) break;
                if (coluna < 1 || coluna > 9) {
                    cout << "Coluna invalida!" << endl;
                    system("pause"); 
                    continue;
                }

                if (matriz[linha-1][coluna-1] != 0) {
                    cout << "Posicao ja preenchida!" << endl;
                    system("pause"); 
                    continue;
                }

                cout << "Digite o numero (1-9), ou 0 para sair: ";
                int numero;
                cin >> numero;
                if (numero == 0) break;
                if (numero < 1 || numero > 9) {
                    cout << "Numero invalido! Digite entre 1 e 9." << endl;
                    system("pause"); 
                    continue;
                }

                bool linhaOK = true;
                for (int c = 0; c < 9; c++)
                    if (matriz[linha-1][c] == numero) { 
                    linhaOK = false; break; 
                    }

                bool colunaOK = true;
                for (int r = 0; r < 9; r++)
                    if (matriz[r][coluna-1] == numero) { 
                    colunaOK = false; break; 
                }

                bool blocoOK = true;
                int inicioLinha  = ((linha-1)  / 3) * 3;
                int inicioColuna = ((coluna-1) / 3) * 3;
                for (int i = inicioLinha; i < inicioLinha + 3 && blocoOK; i++)
                    for (int j = inicioColuna; j < inicioColuna + 3 && blocoOK; j++)
                        if (matriz[i][j] == numero) {
                        blocoOK = false;
                        }

                if (linhaOK && colunaOK && blocoOK) {
                    matriz[linha-1][coluna-1] = numero;
                    score += 10;
                    cout << "Numero colocado corretamente! +10 pontos" << endl;
                } 
                else {
                erros++;
                score -= 5;
                if (score < 0) score = 0;
                if (!linhaOK)  
                    cout << "[X] Numero repetido na LINHA!" << endl;
                if (!colunaOK) 
                    cout << "[X] Numero repetido na COLUNA!" << endl;
                if (!blocoOK)  
                    cout << "[X] Numero repetido no BLOCO!" << endl;
                }

                bool completo = true;
                for (int i = 0; i < 9 && completo; i++)
                    for (int j = 0; j < 9 && completo; j++)
                        if (matriz[i][j] == 0) 
                        completo = false;

                if (completo) {
                    if (erros == 0) score += 100;
                        cout << "Parabens! Voce completou o 9x9!" << endl;
                        cout << "Pontuacao final: " << score << " pontos." << endl;

                    int recorde = 0;
                    ifstream arqLer("ranking.txt");
                    if (arqLer.is_open()) { 
                        arqLer >> recorde; 
                        arqLer.close(); 
                    }

                    if (score > recorde) {
                        ofstream arqGravar("ranking.txt");
                        if (arqGravar.is_open()) { 
                            arqGravar << score << endl; 
                            arqGravar.close(); 
                        }
                    cout << "Novo recorde salvo!" << endl;
                    }
                    else {
                        cout << "Recorde atual: " << recorde << " pontos." << endl;
                    }

            system("pause");
            jogando = false;
            }
        } 
        break;
    }
    case 6: {
        cout << "Saindo do jogo. Obrigado por jogar!" << endl;
        return 0;
    }
    }
}
}
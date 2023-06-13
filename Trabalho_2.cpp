//André Luis Modesto de Paula
//2077447

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct dados{

    char title[100];
    char rating[10];
    char ratingLevel[130];
    char ratingDescription[4];
    char releaseYear[5];
    char userRatingScore[3];
    char userRatingSize[3];

};

struct generico{

    char gen[100];

};

void numero_2(struct dados filme[], int QntFilmes){

    int Val=0; //Variável usada para o while permanecer funcionando
    while(Val != QntFilmes){
        int x=0; //Variável usada em if
        Val+=1;
        for(int i=(Val-1); i>0; i--){
            if(strcmp(filme[i].releaseYear, filme[Val].releaseYear)==0){
                x+=1;
                break;
            }
        }
        if(x==0){
            int PG13=0, R=0, TV14=0, TVPG=0, TVMA=0, TVY=0, NR=0, FV7=0, UR=0, PG=0, G=0, TVY7FV=0,
            TVG=0, TVY7=0; //Variáveis para cada tipo de faixa etária
            cout << "Ano: " << filme[Val].releaseYear << endl;

            for(int i=1; i<=QntFilmes; i++){
                if(strcmp(filme[i].releaseYear, filme[Val].releaseYear)==0){
                    if(strcmp("PG-13", filme[i].rating)==0){
                        PG13+=1;
                    }
                    if(strcmp("R", filme[i].rating)==0){
                        R+=1;
                    }
                    if(strcmp("TV-14", filme[i].rating)==0){
                        TV14+=1;
                    }
                    if(strcmp("TV-PG", filme[i].rating)==0){
                        TVPG+=1;
                    }
                    if(strcmp("TV-MA", filme[i].rating)==0){
                        TVMA+=1;
                    }
                    if(strcmp("TV-Y", filme[i].rating)==0){
                        TVY+=1;
                    }
                    if(strcmp("NR", filme[i].rating)==0){
                        NR+=1;
                    }
                    if(strcmp("7-FV", filme[i].rating)==0){
                        FV7+=1;
                    }
                    if(strcmp("UR", filme[i].rating)==0){
                        UR+=1;
                    }
                    if(strcmp("PG", filme[i].rating)==0){
                        PG+=1;
                    }
                    if(strcmp("G", filme[i].rating)==0){
                        G+=1;
                    }
                    if(strcmp("TV-Y7-FV", filme[i].rating)==0){
                        TVY7FV+=1;
                    }
                    if(strcmp("TV-G", filme[i].rating)==0){
                        TVG+=1;
                    }
                    if(strcmp("TV-Y7", filme[i].rating)==0){
                        TVY7+=1;
                    }


                }
            
            }
            if(PG13>0){
                cout << "PG-13:" << PG13 << endl;
            }
            if(R>0){
                cout << "R: " << R << endl;
            }
            if(TV14>0){
                cout << "TV-14: " << TV14 << endl;
            }
            if(TVPG>0){
                cout << "TV-PG: " << TVPG << endl;
            }
            if(TVMA>0){
                cout << "TV-MA: " << TVMA << endl;
            }
            if(TVY>0){
                cout << "TV-Y: " << TVY << endl;
            }
            if(NR>0){
                cout << "NR: " << NR << endl;
            }
            if(FV7>0){
                cout << "7-FV: " << FV7 << endl;
            }
            if(UR>0){
                cout << "UR: " << UR << endl;
            }
            if(PG>0){
                cout << "PG: " << PG << endl;
            }
            if(G>0){
                cout << "G: " << G << endl;
            }
            if(TVY7FV>0){
                cout << "TV-Y7-FV: " << TVY7FV << endl;
            }
            if(TVG>0){
                cout << "TV-G: " << TVG << endl;
            }
            if(TVY7>0){
                cout << "TV-Y7: " << TVY7 << endl;
            }

            cout << endl;
        }
    
    }

}

void numero_3(struct dados filme[], int QntFilmes){

    int FilmeAno_1[QntFilmes], FilmeAno_2[QntFilmes]; //Vetores para os anos

    for(int i=0; i<QntFilmes; i++){
        FilmeAno_1[i] = strtol(filme[i+1].releaseYear, NULL, 10);
        FilmeAno_2[i] = strtol(filme[i+1].releaseYear, NULL, 10);
    }
    

    cout << "Quantidade de filmes por ano: " << endl;
    for(int i=0; i<QntFilmes; i++){
        int QntVetor=0; //Variavel para contar a quantidade de filmes em cada ano

        if(FilmeAno_2[i]!=0){
            cout << "-" << FilmeAno_1[i] << ": ";
            for(int j=0; j<QntFilmes; j++){
                if(FilmeAno_1[i] == FilmeAno_2[j]){
                    QntVetor+=1;
                    FilmeAno_2[j] = 0;
                }

            }
            cout << QntVetor << endl;
        }
    }

}

void numero_4(struct dados filme[], int QntFilmes){

    int Vetor_1[QntFilmes], Vetor_2[QntFilmes];//Vetores as notas dos usuários
    int FilmeAno_1[QntFilmes], FilmeAno_2[QntFilmes], FilmeAno_3[QntFilmes];//Vetores para os anos

    for(int i=0; i<QntFilmes; i++){
        FilmeAno_1[i] = strtol(filme[i+1].releaseYear, NULL, 10);
        FilmeAno_3[i] = strtol(filme[i+1].releaseYear, NULL, 10);
        FilmeAno_2[i] = strtol(filme[i+1].releaseYear, NULL, 10);
        if(strcmp(filme[i+1].userRatingScore, "NA")!=0){
            Vetor_1[i] = strtol(filme[i+1].userRatingScore, NULL, 10);
            Vetor_2[i] = strtol(filme[i+1].userRatingScore, NULL, 10);
        }
        else if(strcmp(filme[i+1].userRatingScore, "NA")==0){
            Vetor_1[i] = 0;
            Vetor_2[i] = 0;
        }

    }
    cout << endl;

    ofstream out10_Filmes("10_filmes.dat", ios::out);

    for(int i=0; i<QntFilmes; i++){
        int Aux; //Variável para auxiliar em um for
        int QntVetor=0;//Variável para pegar a quantidade de anos repetidos
        int Num = 0;
        int Vet[Num]; //Vetor que pega os 10 videos mais apreciados
        if(FilmeAno_2[i]!=0){
            out10_Filmes << FilmeAno_1[i] << " - ";
            for(int j=0; j<QntFilmes; j++){

                if(FilmeAno_1[i] == FilmeAno_2[j]){
                    QntVetor+=1;
                    FilmeAno_2[j] = 0;
                }
            
            }
            if(QntVetor<10){
                for(int j=0; j<QntFilmes; j++){
                    if(FilmeAno_1[i] == FilmeAno_3[j]){
                        out10_Filmes << filme[j+1].title << "; ";
                    }
                }
                out10_Filmes << endl;
            }

            else if(QntVetor>=10){
                
                for(int j=0; j<QntFilmes; j++){
                    if(FilmeAno_1[i] == FilmeAno_3[j]){
                        Num+=1;
                        Vet[Num-1] = Vetor_1[j];
                        FilmeAno_3[j] = 0;
                        
                    }
                     
                    
                }

                for(int j=0; j<Num; j++){
                    for(int k=j+1; k<Num; k++){
                        if(Vet[j] < Vet[k]){
                            Aux=Vet[k];
                            Vet[k]=Vet[j];
                            Vet[j]=Aux;
                        }
                    }
                    
                }

                for(int j=0; j<10; j++){
                    for(int k=0; k<QntFilmes; k++){
                        if(FilmeAno_1[i] == FilmeAno_1[k]){
                            if(Vet[j] == Vetor_2[k]){
                                out10_Filmes << filme[k+1].title << "; ";
                                Vetor_2[k] = 200;
                                break;
                            }
                        
                        }
                        
                    }
                }
                out10_Filmes << endl;

            }
            
            
        
        }
    }
    out10_Filmes.close();

}

void numero_5(struct dados filme[], int QntFilmes){

    int QntViolento=0; //Variável para a quantidade de filmes violentos
    float QntSexual=0; //Variável para a quantidade de filmes com conteudo sexual
    float Porcentagem=0; //Porcentagem das duas variáveis

    char *Aux; //Variável auxiliar
    for(int i=1; i<QntFilmes; i++){
        char rLevel_temp[130]; //Variavel temporária para o ratingLevel
        strcpy(rLevel_temp, filme[i].ratingLevel);
        Aux = strtok(rLevel_temp, " ""."",""/""-");
        while(Aux != NULL){
            if(strcmp(Aux, "violence")==0 || strcmp(Aux, "violent")==0){
                QntViolento ++;
            }
            if(strcmp(Aux, "sexuality")==0 || strcmp(Aux, "nudity")==0 || 
            strcmp(Aux, "sexual")==0 || strcmp(Aux, "sex")==0){
                QntSexual ++;
            }
            Aux = strtok(NULL, "."" "",""/""-");
        }
    }
    cout << "Quantidade de filmes reconhecidos como violentos: " << QntViolento << endl;
    cout << "Quantidade de filmes reconhecidos com conteudo sexual: " << QntSexual << endl;

    Porcentagem = (QntViolento+QntSexual)*100/(QntFilmes-1);

    cout << "A porcentagem dos vídeos nessa categoria é: " << Porcentagem << "%" << endl << endl;


}

void numero_6(struct dados filme[],int QntFilmes){

    //*******OBSERVAÇÂO*******
    //Nessa parte para pegar a palavra-chave, o código não reconhece acentos e deve ser escrito
    //apenas 1 palavra sem hífens.

    char Exit[100]; //Variável para sair do While
    int Res = 0; //Variável para loop em While
    int Op=0; //Variável para sair do switch
    while(Res==0){
        switch(Op){

            case 0: 
                char PalavraChave[100];
                int Num;
                cout << "Digite uma palavra chave: ";
                setbuf(stdin, NULL);
                gets(PalavraChave);
                for(int i=0; i<strlen(PalavraChave); i++){
                    PalavraChave[i] = tolower(PalavraChave[i]);
                }
                cout << endl;
                char *Aux;

                for(int i=1; i<QntFilmes; i++){
                    char Title_temp[100];
                    int Aux_2=0;
                    int j=0;

                    strcpy(Title_temp, filme[i].title);
                    Aux = strtok(Title_temp, " "".""/"",""-");

                    while(Aux != NULL){
                        for(int k=0; k<strlen(Aux); k++){
                            Aux[k] = tolower(Aux[k]);
                        }
                        for(j=0; j<strlen(PalavraChave); j++){
                            if(Aux[j] == PalavraChave[j]){
                                continue;
                            }
                            else
                                break;
                        }
                        if(j==strlen(PalavraChave)){
                            cout << "Titulo: " << filme[i].title << endl;
                            cout << "Faixa etária: " << filme[i].rating << endl;
                            cout << "Descrição da faixa etária: " << filme[i].ratingLevel << endl;
                            cout << endl;
                            Aux_2+=1;
                            Num=1;
                        }
                        if(Aux_2>0)
                            break;
                        Aux = strtok(NULL, "."" ""/"",""-");
                    }

                }
                if(Num!=1){
                    cout << "Nenhum filme encontrado." << endl << endl;
                }

                cout << "Deseja continuar?" << endl << "sim/nao" << endl;
                setbuf(stdin, NULL);
                gets(Exit);
                for(int i=0; i<strlen(Exit); i++){
                    Exit[i] = tolower(Exit[i]);
                }

                if(strcmp(Exit, "nao")==0){
                    Res = 1;
                }
                else if(strcmp(Exit, "sim")==0){
                    Op = 0;
                    Res = 0;
                }
                else{
                    Op = 1;
                    Res = 0;
                }
                break;
            
            case 1:
                cout << "Erro: Digite uma opção válida." << endl << endl;
                cout << "Sim para continuar." << endl;
                cout << "Nao para sair." << endl;
                setbuf(stdin, NULL);
                gets(Exit);

                if(strcmp(Exit, "nao")==0){
                    Res = 1;
                }
                else if(strcmp(Exit, "sim")==0){
                    Op = 0;
                    Res = 0;
                }
                else{
                    Op = 1;
                    Res = 0;
                }
                break;

                

        }
    
    }

}

int main(){
    //Número 1
    int Aux = -1; //Variável auxiliar para utilizar no vetor dentro do while
    int QntFilmes=-1; //Variável para contar a quantidade de filmes sem repeti-los
    
    dados filme[1001];
    generico g[1001]; //struct genérico para salvar temporariamente os filmes

    ifstream inFilmes("netflix_all.csv", ios::in);

    string temp; //String temporária para o programa ler os filmes
    
    while(getline(inFilmes, temp)){
        int i=0, j=0; //Variáveis usadas em for
        int x=0; //Variável usada em if
        Aux+=1;

        for(j=0; temp[j] != ';'; j++){
            g[Aux].gen[j] = temp[j];
        }
        g[Aux].gen[j] = '\0';

        for(i=(Aux-1); i>0; i--){
            if(strcmp(g[i].gen, g[Aux].gen)==0){
                x+=1;
                break;
            }
        
        }
        
        if(x==0){

            QntFilmes+=1;
            int k_1=0, k_2=0, k_3=0, k_4=0, k_5=0, k_6=0; //Variáveis usadas em for para cada informação do filme

            strcpy(filme[QntFilmes].title, g[Aux].gen);
            
            for(k_1=(j+1); temp[k_1] != ';'; k_1++){
                filme[QntFilmes].rating[x] = temp[k_1];
                x+=1;
            }
            filme[QntFilmes].rating[k_1] = '\0';
            x=0;

            for(k_2=(k_1+1); temp[k_2] != ';'; k_2++){
                filme[QntFilmes].ratingLevel[x] = temp[k_2];
                x+=1;
            }
            filme[QntFilmes].ratingLevel[k_2] = '\0';
            x=0;

            for(k_3=(k_2+1); temp[k_3] != ';'; k_3++){
                filme[QntFilmes].ratingDescription[x] = temp[k_3];
                x+=1;
            }
            filme[QntFilmes].ratingDescription[k_3] = '\0';
            x=0;

            for(k_4=(k_3+1); temp[k_4] != ';'; k_4++){
                filme[QntFilmes].releaseYear[x] = temp[k_4];
                x+=1;
            }
            filme[QntFilmes].releaseYear[k_4] = '\0';
            x=0;

            for(k_5=(k_4+1); temp[k_5] != ';'; k_5++){
                filme[QntFilmes].userRatingScore[x] = temp[k_5];
                x+=1;
            }
            filme[QntFilmes].userRatingScore[k_5] = '\0';
            x=0;

            for(k_6=(k_5+1); temp[k_6] != ';'; k_6++){
                filme[QntFilmes].userRatingSize[x] = temp[k_6];
                x+=1;
            }
            filme[QntFilmes].userRatingSize[k_6] = '\0';
            x=0;

        }
        
        
    }

    inFilmes.close();

    numero_2(filme, QntFilmes);

    numero_3(filme, QntFilmes);

    numero_4(filme, QntFilmes);

    numero_5(filme, QntFilmes);

    numero_6(filme, QntFilmes);

}
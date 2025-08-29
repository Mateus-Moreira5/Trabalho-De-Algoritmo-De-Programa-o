#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int opTipoInfracao,opMenuPrincipal,opGravidade,opConsultar;
int CountV=0,CountS=0,CountC=0,CountE=0,i;
struct DadosInfrator{
    char Nome[100];
    char CPF[20];
    char PlacaVeiculo[50];
    char Local[100];
    char Data[20];
    float ValorDaMulta;
    int QuantidadeDePontos;
    char Gravidade[30];
}Ivelocidade[100],Isinal[100],Icinto[100],Iestacionar[100];
/*Cria��o de um arquivo que salvar� os dados*/
FILE *ArquivoInfratorSinal;
FILE *ArquivoInfratoVelocidade;
FILE *ArquivoInfratorCinto;
FILE *ArquivoInfratorEstacionar;
/*------------------------------------------*/
void AbrirArquivos(){
    ArquivoInfratorSinal = fopen("C:\\Windows\\Temp\\ArquivoInfratorSinal.txt", "a+");
    ArquivoInfratoVelocidade = fopen("C:\\Windows\\Temp\\ArquivoInfratorVelocidade.txt", "a+");
    ArquivoInfratorCinto = fopen("C:\\Windows\\Temp\\ArquivoInfratorCinto.txt", "a+");
    ArquivoInfratorEstacionar = fopen("C:\\Windows\\Temp\\ArquivoInfratorEstacionar.txt", "a+");
    if ( ArquivoInfratorSinal == NULL || ArquivoInfratoVelocidade == NULL || ArquivoInfratorCinto == NULL || ArquivoInfratorEstacionar == NULL){
        printf("ERRO NA CRIA��O DOS ARQUIVOS");
        exit(1);
    }
}
void FecharArquivos(){
    if (ArquivoInfratorSinal) fclose(ArquivoInfratorSinal);
    if (ArquivoInfratoVelocidade) fclose(ArquivoInfratoVelocidade);
    if (ArquivoInfratorCinto) fclose(ArquivoInfratorCinto);
    if (ArquivoInfratorEstacionar) fclose(ArquivoInfratorEstacionar);
}
void LimparBufffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF); 
}
void TipoInfracao(){
    do{
    system("cls");
    printf("|============ TIPO DE INFRA��O ============|\n");
    printf("|1. Excesso de velocidade.                 |\n");
    printf("|2. Avan�o no sinal vermelho.              |\n");
    printf("|3. N�o utiliza��o de cinto de seguran�a.  |\n");
    printf("|4. Estacionar em local indevido.          |\n");
    printf("|5. Voltar.                                |\n");
    printf("|==========================================|\n");
    printf("Digite aqui qual foi a infra��o: ");
    scanf("%i",&opTipoInfracao);
    LimparBufffer();
    switch(opTipoInfracao){
    case 1:
        system("cls");
        DadosInfratorVelocidade();
        break;
    case 2: 
        system("cls");
        DadosInfratorSinal();
        break;
    case 3:
        system("cls");
        DadosInfratorCinto();
        break;
    case 4:
        system("cls");
        DadosInfratorEstacionar();
        break;
    case 5:
        system("cls");
        break; 
    default:
        break;
    }
}while(opTipoInfracao != 5);
}
void DadosInfratorVelocidade(){
    system("cls");
    printf("Digite o nome do Infratos: ");
    fgets(Ivelocidade[CountV].Nome, sizeof(Ivelocidade[CountV].Nome), stdin);
    printf("Digite o CPF do Infrato: ");
    fgets(Ivelocidade[CountV].CPF,sizeof(Ivelocidade[CountV].CPF),stdin);
    printf("Digite a placa do ve�culo: ");
    fgets(Ivelocidade[CountV].PlacaVeiculo, sizeof(Ivelocidade[CountV].PlacaVeiculo), stdin);
    printf("Digite local que ocorreu a infra��o: ");
    fgets(Ivelocidade[CountV].Local, sizeof(Ivelocidade[CountV].Local), stdin);
    printf("Digite a data que ocorre a infra��o: ");
    fgets(Ivelocidade[CountV].Data, sizeof(Ivelocidade[CountV].Data), stdin);
    system("cls");
    printf("|============= Gravidade da infra��o =============|\n");
    printf("|1. M�dia.                                        |\n");
    printf("|2. Grave.                                        |\n");
    printf("|3. Grav�ssima.                                   |\n");
    printf("|=================================================|\n\n");
    printf("Digite a gravidade da multa: ");
    scanf("%i",&opGravidade);
    LimparBufffer();
    if(opGravidade == 1){
        strcpy(Ivelocidade[CountV].Gravidade,"M�dia");
        Ivelocidade[CountV].QuantidadeDePontos = 4;
        Ivelocidade[CountV].ValorDaMulta = 130.16;
    }
    if(opGravidade == 2){
        strcpy(Ivelocidade[CountV].Gravidade,"Grave");
        Ivelocidade[CountV].QuantidadeDePontos = 5;
        Ivelocidade[CountV].ValorDaMulta = 195.23;
    }
    if(opGravidade == 3){
        strcpy(Ivelocidade[CountV].Gravidade,"Grav�ssima");
        Ivelocidade[CountV].QuantidadeDePontos = 7;
        Ivelocidade[CountV].ValorDaMulta = 880.41;
    }
    fprintf(ArquivoInfratoVelocidade,"|--------------------------------------------------|\n");
    fprintf(ArquivoInfratoVelocidade,"|Nome do infrator: %s", Ivelocidade[CountV].Nome);
    fprintf(ArquivoInfratoVelocidade,"|CPF do infrator: %s", Ivelocidade[CountV].CPF);
    fprintf(ArquivoInfratoVelocidade,"|Placa do Veiculo: %s", Ivelocidade[CountV].PlacaVeiculo);
    fprintf(ArquivoInfratoVelocidade,"|Local em que ocorreu: %s", Ivelocidade[CountV].Local);
    fprintf(ArquivoInfratoVelocidade,"|Data em que ocorreu a infra��o: %s", Ivelocidade[CountV].Data);
    fprintf(ArquivoInfratoVelocidade,"|Gravidade da infra��o: %s\n", Ivelocidade[CountV].Gravidade);
    fprintf(ArquivoInfratoVelocidade,"|Quantidade de ponto: %i\n",Ivelocidade[CountV].QuantidadeDePontos);
    fprintf(ArquivoInfratoVelocidade,"|Valor da Multa: %f\n",Ivelocidade[CountV].ValorDaMulta);
    fprintf(ArquivoInfratoVelocidade,"|--------------------------------------------------|\n");
    system("cls");
    printf("|=========================================|\n");
    printf("|     Infra��o cadastrada com sucesso!    |\n");
    printf("|=========================================|\n");
    system("pause");
    CountV++;
}
void DadosInfratorSinal(){
    system("cls");
    printf("Digite o nome do Infratos: ");
    fgets(Isinal[CountS].Nome, sizeof(Isinal[CountS].Nome), stdin);
    printf("Digite o CPF do Infrato: ");
    fgets(Isinal[CountS].CPF,sizeof(Isinal[CountS].CPF),stdin);
    printf("Digite a placa do ve�culo: ");
    fgets(Isinal[CountS].PlacaVeiculo, sizeof(Isinal[CountS].PlacaVeiculo), stdin);
    printf("Digite local que ocorreu a infra��o: ");
    fgets(Isinal[CountS].Local, sizeof(Isinal[CountS].Local), stdin);
    printf("Digite a data que ocorre a infra��o: ");
    fgets(Isinal[CountS].Data, sizeof(Isinal[CountS].Data), stdin);
    system("cls");
    printf("|============= Gravidade da infra��o =============|\n");
    printf("|1. M�dia.                                        |\n");
    printf("|2. Grave.                                        |\n");
    printf("|3. Grav�ssima.                                   |\n");
    printf("|=================================================|\n\n");
    printf("Digite a gravidade da multa: ");
    scanf("%i",&opGravidade);
    LimparBufffer();
    switch(opGravidade){
    case 1:
        strcpy(Isinal[CountS].Gravidade,"M�dia");
        Isinal[CountS].QuantidadeDePontos = 4;
        Isinal[CountS].ValorDaMulta = 130.16;
        break;
    case 2:
        strcpy(Isinal[CountS].Gravidade,"Grave");
        Isinal[CountS].QuantidadeDePontos = 5;
        Isinal[CountS].ValorDaMulta = 195.23;
        break;
    case 3:
        strcpy(Isinal[CountS].Gravidade,"Grav�ssima");
        Isinal[CountS].QuantidadeDePontos = 7;
        Isinal[CountS].ValorDaMulta = 880.41;
        break;
    }
    fprintf(ArquivoInfratorSinal,"|--------------------------------------------------|\n");
    fprintf(ArquivoInfratorSinal,"|Nome do infrator: %s", Isinal[CountS].Nome);
    fprintf(ArquivoInfratorSinal,"|CPF do infrator: %s", Isinal[CountS].CPF);
    fprintf(ArquivoInfratorSinal,"|Placa do Veiculo: %s", Isinal[CountS].PlacaVeiculo);
    fprintf(ArquivoInfratorSinal,"|Local em que ocorreu: %s", Isinal[CountS].Local);
    fprintf(ArquivoInfratorSinal,"|Data em que ocorreu a infra��o: %s", Isinal[CountS].Data);
    fprintf(ArquivoInfratorSinal,"|Gravidade da infra��o: %s\n", Isinal[CountS].Gravidade);
    fprintf(ArquivoInfratorSinal,"|Quantidade de ponto: %i\n",Isinal[CountS].QuantidadeDePontos);
    fprintf(ArquivoInfratorSinal,"|Valor da Multa: %f\n",Isinal[CountS].ValorDaMulta);
    fprintf(ArquivoInfratorSinal,"|--------------------------------------------------|\n");
    system("cls");
    printf("|=========================================|\n");
    printf("|     Infra��o cadastrada com sucesso!    |\n");
    printf("|=========================================|\n");
    system("pause");
    CountS++;
}
void DadosInfratorCinto(){
    system("cls");
    printf("Digite o nome do Infratos: ");
    fgets(Icinto[CountC].Nome, sizeof(Icinto[CountC].Nome), stdin);
    printf("Digite o CPF do Infrato: ");
    fgets(Icinto[CountC].CPF, sizeof(Icinto[CountC].CPF), stdin);
    printf("Digite a placa do ve�culo: ");
    fgets(Icinto[CountC].PlacaVeiculo, sizeof(Icinto[CountC].PlacaVeiculo), stdin);
    printf("Digite local que ocorreu a infra��o: ");
    fgets(Icinto[CountC].Local, sizeof(Icinto[CountC].Local), stdin);
    printf("Digite a data que ocorre a infra��o: ");
    fgets(Icinto[CountC].Data, sizeof(Icinto[CountC].Data), stdin);
    system("cls");
    printf("|============= Gravidade da infra��o =============|\n");
    printf("|1. M�dia.                                        |\n");
    printf("|2. Grave.                                        |\n");
    printf("|3. Grav�ssima.                                   |\n");
    printf("|=================================================|\n\n");
    printf("Digite a gravidade da multa: ");
    scanf("%i",&opGravidade);
    LimparBufffer();
    switch(opGravidade){
    case 1:
        strcpy(Icinto[CountC].Gravidade, "M�dio");
        Icinto[CountC].QuantidadeDePontos = 4;
        Icinto[CountC].ValorDaMulta = 130.16;
        break;
    case 2:
        strcpy(Icinto[CountC].Gravidade,"Grave");
        Icinto[CountC].QuantidadeDePontos = 5;
        Icinto[CountC].ValorDaMulta = 195.23;
        break;
    case 3:
        strcpy(Icinto[CountC].Gravidade,"Grav�ssima");
        Icinto[CountC].QuantidadeDePontos = 7;
        Icinto[CountC].ValorDaMulta = 880.41;
        break;
    }
    fprintf(ArquivoInfratorCinto,"|--------------------------------------------------|\n");
    fprintf(ArquivoInfratorCinto,"|Nome do infrator: %s", Icinto[CountC].Nome);
    fprintf(ArquivoInfratorCinto,"|CPF do infrator: %s", Icinto[CountC].CPF);
    fprintf(ArquivoInfratorCinto,"|Placa do Veiculo: %s", Icinto[CountC].PlacaVeiculo);
    fprintf(ArquivoInfratorCinto,"|Local em que ocorreu: %s", Icinto[CountC].Local);
    fprintf(ArquivoInfratorCinto,"|Data em que ocorreu a infra��o: %s", Icinto[CountC].Data);
    fprintf(ArquivoInfratorCinto,"|Gravidade da infra��o: %s\n", Icinto[CountC].Gravidade);
    fprintf(ArquivoInfratorCinto,"|Quantidade de ponto: %i\n",Icinto[CountC].QuantidadeDePontos);
    fprintf(ArquivoInfratorCinto,"|Valor da Multa: %f\n",Icinto[CountC].ValorDaMulta);
    fprintf(ArquivoInfratorCinto,"|--------------------------------------------------|\n");
    system("cls");
    printf("|=========================================|\n");
    printf("|     Infra��o cadastrada com sucesso!    |\n");
    printf("|=========================================|\n");
    system("pause");
    CountC++;
}
void DadosInfratorEstacionar(){
    system("cls");
    printf("Digite o nome do Infratos: ");
    fgets(Iestacionar[CountE].Nome, sizeof(Iestacionar[CountE].Nome), stdin);
    printf("Digite o CPF do Infrato: ");
    fgets(Iestacionar[CountE].CPF, sizeof(Iestacionar[CountE].CPF), stdin);
    printf("Digite a placa do ve�culo: ");
    fgets(Iestacionar[CountE].PlacaVeiculo, sizeof(Iestacionar[CountE].PlacaVeiculo), stdin);
    printf("Digite local que ocorreu a infra��o: ");
    fgets(Iestacionar[CountE].Local, sizeof(Iestacionar[CountE].Local), stdin);
    printf("Digite a data que ocorre a infra��o: ");
    fgets(Iestacionar[CountE].Data, sizeof(Iestacionar[CountE].Data), stdin);
    system("cls");
    printf("|============= Gravidade da infra��o =============|\n");
    printf("|1. M�dia.                                        |\n");
    printf("|2. Grave.                                        |\n");
    printf("|3. Grav�ssima.                                   |\n");
    printf("|=================================================|\n\n");
    printf("Digite a gravidade da multa: ");
    scanf("%i",&opGravidade);
    LimparBufffer();
    switch(opGravidade){
    case 1:
        strcpy(Iestacionar[CountE].Gravidade,"M�dia");
        Iestacionar[CountE].QuantidadeDePontos = 4;
        Iestacionar[CountE].ValorDaMulta = 130.16;
        break;
    case 2:
        strcpy(Iestacionar[CountE].Gravidade,"Grave");
        Iestacionar[CountE].QuantidadeDePontos = 5;
        Iestacionar[CountE].ValorDaMulta = 195.23;
        break;
    case 3:
        strcpy(Iestacionar[CountE].Gravidade,"Grav�ssima");
        Iestacionar[CountE].QuantidadeDePontos = 7;
        Iestacionar[CountE].ValorDaMulta = 880.41;
        break;
    }
    fprintf(ArquivoInfratorEstacionar,"|--------------------------------------------------|\n");
    fprintf(ArquivoInfratorEstacionar,"|Nome do infrator: %s", Iestacionar[CountE].Nome);
    fprintf(ArquivoInfratorEstacionar,"|CPF do infrator: %s", Iestacionar[CountE].CPF);
    fprintf(ArquivoInfratorEstacionar,"|Placa do Veiculo: %s", Iestacionar[CountE].PlacaVeiculo);
    fprintf(ArquivoInfratorEstacionar,"|Local em que ocorreu: %s", Iestacionar[CountE].Local);
    fprintf(ArquivoInfratorEstacionar,"|Data em que ocorreu a infra��o: %s", Iestacionar[CountE].Data);
    fprintf(ArquivoInfratorEstacionar,"|Gravidade da infra��o: %s\n", Iestacionar[CountE].Gravidade);
    fprintf(ArquivoInfratorEstacionar,"|Quantidade de ponto: %i\n",Iestacionar[CountE].QuantidadeDePontos);
    fprintf(ArquivoInfratorEstacionar,"|Valor da Multa: %f\n",Iestacionar[CountE].ValorDaMulta);
    fprintf(ArquivoInfratorEstacionar,"|--------------------------------------------------|\n");
    system("cls");
    printf("|=========================================|\n");
    printf("|     Infra��o cadastrada com sucesso!    |\n");
    printf("|=========================================|\n");
    system("pause");
    CountE++;
}
void ConsultarInfracaoVelocidade(){
    system("cls");
    printf("=================== Excesso de velocidade ===================\n");
    for(i = 0; i < CountV; i++){
        printf("Nome do infrator: %s",Ivelocidade[i].Nome);
        printf("CPF do infrator: %s",Ivelocidade[i].CPF);
        printf("Placa do Ve�culo: %s",Ivelocidade[i].PlacaVeiculo);
        printf("Local da ocorr�ncia: %s",Ivelocidade[i].Local);
        printf("Data da ocorr�ncia: %s",Ivelocidade[i].Data);
        printf("Pre�o da multa: R$ %.2f\n",Ivelocidade[i].ValorDaMulta);
        printf("Quantidade de pontos: %i\n", Ivelocidade[i].QuantidadeDePontos);
        printf("Gravidade da infra��o: %s\n",Ivelocidade[i].Gravidade);
        printf("=============================================================\n");
        }
        system("pause");
}
void ConsultarInfracaoSinal(){
    system("cls");
    printf("=================== Avan�ar em sinal vermelho===================\n");
    for (i = 0; i < CountS; i++){
        printf("Nome do infrator: %s",Isinal[i].Nome);
        printf("CPF do infrator: %s",Isinal[i].CPF);
        printf("Placa do Ve�culo: %s",Isinal[i].PlacaVeiculo);
        printf("Local da ocorr�ncia: %s",Isinal[i].Local);
        printf("Data da ocorr�ncia: %s",Isinal[i].Data);
        printf("Pre�o da multa: R$ %.2f\n",Isinal[i].ValorDaMulta);
        printf("Quantidade de pontos: %i\n", Isinal[i].QuantidadeDePontos);
        printf("Gravidade da infra��o: %s\n",Isinal[i].Gravidade);
        printf("================================================================\n");
    }
    system("pause");
}
void ConsultarInfracaoCinto(){
    system("cls");
    printf("=============== Estacionamento em lugar indevido ===============\n");
    for (i = 0; i < CountE; i++){
        printf("Nome do infrator: %s",Iestacionar[i].Nome);
        printf("CPF do infrator: %s",Iestacionar[i].CPF);
        printf("Placa do Ve�culo: %s",Iestacionar[i].PlacaVeiculo);
        printf("Local da ocorr�ncia: %s",Iestacionar[i].Local);
        printf("Data da ocorr�ncia: %s",Iestacionar[i].Data);
        printf("Pre�o da multa: R$ %.2f\n",Iestacionar[i].ValorDaMulta);
        printf("Quantidade de pontos: %i\n", Iestacionar[i].QuantidadeDePontos);
        printf("Gravidade da infra��o: %s\n",Iestacionar[i].Gravidade);
        printf("================================================================\n");
        }
        system("pause");
}
void ConsultarInfracaoEstacionar(){
    system("cls");
    printf("=================== N�o uso do cinto de seguran�a ===================\n");
    for (i = 0; i < CountC; i++){
        printf("Nome do infrator: %s",Icinto[i].Nome);
        printf("CPF do infrator: %s",Icinto[i].CPF);
        printf("Placa do Ve�culo: %s",Icinto[i].PlacaVeiculo);
        printf("Local da ocorr�ncia: %s",Icinto[i].Local);
        printf("Data da ocorr�ncia: %s",Icinto[i].Data);
        printf("Pre�o da multa: R$ %.2f\n",Icinto[i].ValorDaMulta);
        printf("Quantidade de pontos: %i\n", Icinto[i].QuantidadeDePontos);
        printf("Gravidade da infra��o: %s\n",Icinto[i].Gravidade);
        printf("=====================================================================\n");
        }
        system("pause");
}
void ConsultarInfracoes(){
    do{
    system("cls");
    printf("================== Tipo da infra��o ==================\n");
    printf("|1. Excesso de velocidade.                           |\n");
    printf("|2. Avan�o no sinal vermelho.                        |\n");
    printf("|3. N�o utiliza��o de cinto de seguran�a.            |\n");
    printf("|4. Estacionar em local indevido.                    |\n");
    printf("|5. Voltar.                                          |\n");
    printf("|====================================================|\n");
    printf("Qual tipo de infra��o deseja consultar: ");
    scanf("%i",&opConsultar);
    switch(opConsultar){
        case 1: 
            ConsultarInfracaoVelocidade();
            break;
        case 2:
            ConsultarInfracaoSinal();
            break;
        case 3:
            ConsultarInfracaoCinto();
            break;
        case 4:
            ConsultarInfracaoEstacionar();
            break;
    }
    }while(opConsultar != 5);
}
void MenuPrincipal(){
    do{
        system("cls");
        AbrirArquivos();
        system("cls");
        printf("|============= Menu Principal =============|\n");
        printf("|1. Cadastrar infra��o.                    |\n");
        printf("|2. Consultar infra��es.                   |\n");
        printf("|3. Finalizar o programa.                  |\n");
        printf("|==========================================|\n\n");
        printf("Digite oque deseja: ");
        scanf("%i", &opMenuPrincipal);
        LimparBufffer();
        switch (opMenuPrincipal){
        case 1:
            TipoInfracao();
            break;
        case 2:
            ConsultarInfracoes();
            break;
        case 3:
            break;
        default:
            break;
        }
    }while(opMenuPrincipal != 3);
    FecharArquivos();
}

int main(int argc, char const *argv[]){
    setlocale(LC_ALL,"Portuguese");
    MenuPrincipal();
    system("cls");
    printf("Muito obrigado por utilizar o algoritmo!\n\nIntegrantes do grupo:\n-Mateus Moreira Fernandes.\n-Caio Vitor Campelo Alc�ntara.\n-Ian Brito Ribeiro de Castro.\n");
    return 0;
}

#include <stdio.h>

#define DINHEIRO 1
#define PIX 2
#define CARTAO 3

int main(){
    int forma_Pagamento, parcela_Cartao, tipo_Abastecimento, contador_atendimentos, contador_cartao, contador_dinheiro, contador_pix, contador_parcelas_2, contador_parcelas_3;
    float litros, valor, valor_total_litros, valor_total_valor, valor_cartao, valor_dinheiro, valor_pix;
    char gerar_Relatorio;

    contador_atendimentos = 0;
    contador_cartao = 0;
    contador_dinheiro = 0;
    contador_pix = 0;
    contador_parcelas_2 = 0;
    contador_parcelas_3 = 0;
    valor_total_litros = 0;
    valor_total_valor = 0;
    valor_cartao = 0;
    valor_dinheiro = 0;
    valor_pix = 0;

    while (gerar_Relatorio != 'S') {
        printf("Bem vindo ao Posto de combustiveis Cleiton! \n");
        printf("Qual a forma de pagamento do abastecimento? \n");
        printf("Digite:\n %d- Dinheiro\n %d- Pix\n %d- Cartao \n", DINHEIRO, PIX, CARTAO);
        scanf("%d", &forma_Pagamento);

        if (forma_Pagamento == CARTAO) {
            printf("Voce quer parcelar em quantas vezes? \n");
            printf("Digite:\n 1- A vista \n 2- 2 Parcelas \n 3- 3 parcelas \n");
            scanf("%d", &parcela_Cartao);

            if (parcela_Cartao == 2) {
                contador_parcelas_2++;
            } else if (parcela_Cartao == 3) {
                contador_parcelas_3++;
            }
        }

        printf("Voce quer abastecer em litros ou por valor? \n");
        printf("Digite:\n 1- Por litro\n 2- Por valor \n");
        scanf("%d", &tipo_Abastecimento);

        if (tipo_Abastecimento == 1) {
            printf("Quantos litros voce quer abastecer? \n");
            scanf("%f", &litros);
            valor_total_litros += litros;
        } else {
            printf("Quantos reais voce quer abastecer? \n");
            scanf("%f", &valor);
            valor_total_valor += valor;
        }
        contador_atendimentos++;

        switch (forma_Pagamento) {
            case DINHEIRO:
                valor_dinheiro += valor;
                contador_dinheiro++;
                break;
            case PIX:
                valor_pix += valor;
                contador_pix++;
                break;
            case CARTAO:
                valor_cartao += valor;
                contador_cartao++;
                break;
        }

        printf("-----------------------------------------------------\n");
        if (forma_Pagamento >= 1 || forma_Pagamento <= 3 && parcela_Cartao == 0 || parcela_Cartao == 2 || parcela_Cartao == 3) {
            printf("Abastecimento concluido! \n");
            printf("Resumo do antendimento:\n");
            switch (forma_Pagamento) {
                case 1:
                    printf("Pagamento em dinheiro");
                    break;
                case 2:
                    printf("Pagamento em pix");
                    break;
                case 3:
                    printf("Pagamento em cartão");
                    switch (parcela_Cartao) {
                        case 2:
                            printf(" em 2 vezes");
                            break;
                        case 3:
                            printf(" em 3 vezes");
                            break;
                        default:
                            printf(" a vista");
                            break;
                    }
            }
            switch (tipo_Abastecimento) {
                case 1:
                    printf("\nVoce abasteceu %.2f litros",litros);
                    break;
                case 2:
                    printf("\nVoce abasteceu %.2f reais", valor);
                    break;
            }
            printf("\n-----------------------------------------------------\n");
        }
        else{
            printf("\nVoce digitou uma opcao invalida");
            printf(" comece um novo atendimento\n");
            printf("-----------------------------------------------------\n");
            continue;
        }

        printf("Voce quer gerar o relatorio final? \n");
        printf("Digite:\n S- Para sim\n N- Para gerar outro atendimento\n");
        scanf(" %c", &gerar_Relatorio);
    }

    printf("-----------------------------------------------------\n");
    printf("Relatorio Final\n");
    printf("-----------------------------------------------------\n");
    printf("Numero total de atendimentos realizados: %d\n", contador_atendimentos);
    printf("Quantidade de vendas realizadas por Dinheiro: %d\n", contador_dinheiro);
    printf("Quantidade de vendas realizadas por Pix: %d\n", contador_pix);
    printf("Quantidade de vendas realizadas por Cartao: %d\n", contador_cartao);
    printf("Quantidade de parcelas em que os valores foram divididos:\n");
    printf("2 Parcelas: %d\n", contador_parcelas_2);
    printf("3 Parcelas: %d\n", contador_parcelas_3);
    printf("Numero de atendimentos pagos a vista (Dinheiro e Pix): %d\n", contador_dinheiro + contador_pix);
    printf("Valor total abastecido em litros: %.2f litros\n", valor_total_litros);
    printf("Valor total abastecido em reais: %.2f reais\n", valor_total_valor);
    printf("-----------------------------------------------------\n");

    return 0;
}
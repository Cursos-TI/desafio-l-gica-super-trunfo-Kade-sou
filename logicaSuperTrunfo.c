
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

typedef struct	minhas_cartas
{
	int 	populacao;
	float 	area;
	float 	pib;
	int 	pontos_turis;
	float 	pib_per_capita;
	float 	densi_pop;
	char 	estado;
	int 	cidade;
	float 	super_poder;

} Carta;

void print_scan(char *frase, char set, void *dado){
	printf("%s",frase);
	switch(set){
		case 'd':
			scanf("%d", (int*)dado);
			break ;
		case 'f':
			scanf("%f", (float *)dado);
			break ;
		case 'c':
			scanf("%c", (char *)dado);
			break ;
		default:
			printf ("erro no codigo");
	}
}

void info(Carta *carta){
	printf("Código: %c0%d\n", carta->estado, carta->cidade); 
	printf("População: %d\n", carta->populacao);
	printf("Area: %f\n", carta->area);
	printf("PIB: %f\n", carta->pib);
	printf("Pontos Turisticos: %d\n", carta->pontos_turis);
	printf("Densidade Populacional: %f\n", carta->densi_pop);
	printf("PIB per Capita: %f\n", carta->pib_per_capita);
	printf("Super Poder: %f\n", carta->super_poder);
}

Carta * lendo_dados(int nc){
	Carta *carta = malloc(sizeof(Carta) * 1);
	if (carta != NULL)
		memset(carta, 0, sizeof(Carta));

	printf("\nVoce esta inserindo a carta de numero %d\n", nc);

	do{
		print_scan("\nInforme o Estado (A-H): ", 'c', &carta->estado);
	}while (!(carta->estado >= 'A' && carta->estado <= 'H'));
	
	do{
		print_scan("\nInforme a cidade (1-4): ",'d', &carta->cidade);
	}while (!(carta->cidade >= 1 && carta->cidade <= 4));
	
	print_scan("\nInforme a População em numeros: ",'d', &carta->populacao);
	
	print_scan("\nInforme a Área em numeros: ",'f', &carta->area);
	
	print_scan("\nInforme o PIB em numeros: ",'f', &carta->pib);

	print_scan("\nInforme o numero de Pontos turisticos: ",'d', &carta->pontos_turis);

	carta->densi_pop = (float)carta->populacao / carta->area;
	carta->pib_per_capita = carta->pib / (float)carta->populacao;

	carta->super_poder = carta->area + carta->densi_pop + carta->pib + carta->pib_per_capita + (float)carta->populacao + (float)carta->pontos_turis;
	return carta;
}

int start_menu(){
	int num = 0;
	printf("Olá, bem vindo ao super trunfo du kaioba\nInforme abaixo quantas cartas voce deseja inserir :D\nCada país será dividido em oito estados, identificados pelas letras de A a H. Cada estado terá quatro cidades, numeradas de 1 a 4. A combinação da letra do estado e o número da cidade define o código da carta (por exemplo, A01, A02, B01, B02).\n\tIai menó quantas cartas ? -> ");
	scanf("%d", &num);

	printf("Uhhhhhh %d cartas bora pro jogo cria\n", num);
	return num;
}

int comparar_populacao(Carta *carta1, Carta *carta2) {
    if (carta1->populacao > carta2->populacao) {
        return carta1->populacao;
    } else {
        return carta2->populacao;
    }
}

float comparar_area(Carta *carta1, Carta *carta2) {
    if (carta1->area > carta2->area) {
        return carta1->area;
    } else {
        return carta2->area;
    }
}

float comparar_pib(Carta *carta1, Carta *carta2) {
    if (carta1->pib > carta2->pib) {
        return carta1->pib;
    } else {
        return carta2->pib;
    }
}

int comparar_pontos_turisticos(Carta *carta1, Carta *carta2) {
    if (carta1->pontos_turis > carta2->pontos_turis) {
        return carta1->pontos_turis;
    } else {
        return carta2->pontos_turis;
    }
}

float comparar_densidade(Carta *carta1, Carta *carta2) {
    if (carta1->densi_pop < carta2->densi_pop) {
        return carta1->densi_pop;
    } else {
        return carta2->densi_pop;
    }
}

float comparar_pib_per_capita(Carta *carta1, Carta *carta2) {
    if (carta1->pib_per_capita > carta2->pib_per_capita) {
        return carta1->pib_per_capita;
    } else {
        return carta2->pib_per_capita;
    }
}

float comparar_super_poder(Carta *carta1, Carta *carta2) {
    if (carta1->super_poder > carta2->super_poder) {
        return carta1->super_poder;
    } else {
        return carta2->super_poder;
    }
}

Carta* comparacao(Carta *carta1, Carta *carta2) {
    printf("\n\n\t\tCarta %c0%d \t vs \t Carta %c0%d\n", carta1->estado, carta1->cidade, carta2->estado, carta2->cidade);

    printf("População:\t\t%d \t x \t%d \t-> Vencedor %d\n", carta1->populacao, carta2->populacao, comparar_populacao(carta1, carta2));
    printf("Area: \t\t%f \t x \t%f \t-> Vencedor %f\n", carta1->area, carta2->area, comparar_area(carta1, carta2));
    printf("PIB: \t\t%f \t x \t%f \t-> Vencedor %f\n", carta1->pib, carta2->pib, comparar_pib(carta1, carta2));
    printf("Pontos Turisticos:\t%d \t x \t%d \t-> Vencedor %d\n", carta1->pontos_turis, carta2->pontos_turis, comparar_pontos_turisticos(carta1, carta2));
    printf("Densidade Pop.:\t%f \t x \t%f \t-> Vencedor %f\n", carta1->densi_pop, carta2->densi_pop, comparar_densidade(carta1, carta2));
    printf("PIB per Capita:\t%f \t x \t%f \t-> Vencedor %f\n", carta1->pib_per_capita, carta2->pib_per_capita, comparar_pib_per_capita(carta1, carta2));
    printf("Super Poder:\t%f \t x \t%f \t-> Vencedor %f\n", carta1->super_poder, carta2->super_poder, comparar_super_poder(carta1, carta2));

    return (carta1->super_poder > carta2->super_poder) ? carta1 : carta2;
}

void listar_cartas(Carta **cartas, int nc){
    for(int i = 0; i < nc; i++){
        printf("%d -> Carta %c0%d\n", i, cartas[i]->estado, cartas[i]->cidade);
    }
}

enum Atributos {
    POPULACAO = 0,
    AREA,
    PIB,
    PONTOS_TURISTICOS,
    DENSIDADE,
    PIB_PER_CAPITA,
    SUPER_PODER
};

void menu2(Carta *carta1, Carta *carta2){
    int input;

    do{
     printf(
            "Selecione um atributo:\n"
            "0 - POPULACAO\n"
            "1 - AREA\n"
            "2 - PIB\n"
            "3 - PONTOS_TURISTICOS\n"
            "4 - DENSIDADE\n"
            "5 - PIB_PER_CAPITA\n"
            "6 - SUPER_PODER\n"
            "-1 - para sair\n"
        );
    scanf("%d", &input);
    switch (input) {
        case POPULACAO:
            printf("\n\n\t\tCarta %c0%d \t vs \t Carta %c0%d\n", carta1->estado, carta1->cidade, carta2->estado, carta2->cidade);
            printf("População:\t\t%d \t x \t%d \t-> Vencedor %d\n", carta1->populacao, carta2->populacao, comparar_populacao(carta1, carta2));
            break;
        case AREA:
            printf("\n\n\t\tCarta %c0%d \t vs \t Carta %c0%d\n", carta1->estado, carta1->cidade, carta2->estado, carta2->cidade);
            printf("Área: \t\t%f \t x \t%f \t-> Vencedor %f\n", 
                carta1->area, carta2->area, comparar_area(carta1, carta2));
            break;
        case PIB:
            printf("\n\n\t\tCarta %c0%d \t vs \t Carta %c0%d\n", carta1->estado, carta1->cidade, carta2->estado, carta2->cidade);
            printf("PIB: \t\t%f \t x \t%f \t-> Vencedor %f\n", 
                carta1->pib, carta2->pib, comparar_pib(carta1, carta2));
            break;
        case PONTOS_TURISTICOS:
            printf("\n\n\t\tCarta %c0%d \t vs \t Carta %c0%d\n", carta1->estado, carta1->cidade, carta2->estado, carta2->cidade);
            printf("Pontos Turísticos:\t%d \t x \t%d \t-> Vencedor %d\n", 
                carta1->pontos_turis, carta2->pontos_turis, comparar_pontos_turisticos(carta1, carta2));
            break;
        case DENSIDADE:
        printf("\n\n\t\tCarta %c0%d \t vs \t Carta %c0%d\n", carta1->estado, carta1->cidade, carta2->estado, carta2->cidade);
            printf("Densidade Pop.:\t%f \t x \t%f \t-> Vencedor %f\n", 
                carta1->densi_pop, carta2->densi_pop, comparar_densidade(carta1, carta2));
            break;
        case PIB_PER_CAPITA:
        printf("\n\n\t\tCarta %c0%d \t vs \t Carta %c0%d\n", carta1->estado, carta1->cidade, carta2->estado, carta2->cidade);
            printf("PIB per Capita:\t%f \t x \t%f \t-> Vencedor %f\n", 
                carta1->pib_per_capita, carta2->pib_per_capita, comparar_pib_per_capita(carta1, carta2));
            break;
        case SUPER_PODER:
        printf("\n\n\t\tCarta %c0%d \t vs \t Carta %c0%d\n", carta1->estado, carta1->cidade, carta2->estado, carta2->cidade);
            printf("Super Poder:\t%f \t x \t%f \t-> Vencedor %f\n", 
                carta1->super_poder, carta2->super_poder, comparar_super_poder(carta1, carta2));
            break;
        case -1:
            printf("\nSaindo...\n");
            break ;
        default:
            printf("\nAtributo inválido\n");
            break;
    }
    }while(input != -1);

}
void menu_interativo(Carta **cartas, int nc){

	int input1, input2, c1, c2;
    printf("\n Agora que as cartas ja foram cadastradas vamos Brincar.\n");
	do{
        listar_cartas(cartas, nc);
		printf("\n Digite o numero das cartas que quiser comparar!\nCarta 1: ");
        scanf("%d", &c1);
        printf("\nCarta Selecionada -> %d -> Codigo %c0%d\nCarta 2: ", c1, cartas[c1]->estado, cartas[c1]->cidade);
        scanf("%d", &c2);
        printf("\nCarta Selecionada -> %d -> Codigo %c0%d\n", c2, cartas[c2]->estado, cartas[c2]->cidade);

        if(c1 >= nc || c2 >= nc)
            return ;
        do{
            printf("\nBoas escolhas agora vamos jogar.\nPara ver a vencedora digite 1\nPara comparar atributos digite 2\nPara mudar as cartas selecionadas digite 3\n");
            scanf("%d", &input2);
            switch(input2){
                case 1:
                        comparacao(cartas[c1], cartas[c2]);
                        break ;
                case 2:
                        menu2(cartas[c1], cartas[c2]);
                        break ;
                case 3:
                        printf ("\nRetornando...\n");
                        break ;
                default:
                        printf ("\nValor invalido!\n");
            }
        }while(input2 != 3);
        
        printf("Se quiser sair do jogo digite 42\n");
        scanf("%d", &input1);
	}while(input1 != 42);
}

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    int nc = start_menu();
    Carta **cartas = (Carta **)malloc(sizeof(Carta) * nc);
    memset(cartas, 0, sizeof(Carta) * nc);
    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

	
    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)
 	for(int i = 0; i < nc; i++){
	    cartas[i] = lendo_dados(i + 1);
  	    info(cartas[i]);
    }
    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }
    menu_interativo(cartas, nc);

    // carta vencedora.... 

    Carta *winner = cartas[0];
    Carta *empate;
    int empate_flag = 0;
    if(nc > 2){
    for(int i = 1; i < nc; i++){
	    winner = comparacao(cartas[i], winner);
    }
    }
    else if (nc > 1) 
	    winner = comparacao(winner, cartas[1]);

    for(int i = 0; i < nc; i++){
        if (winner->super_poder == cartas[i]->super_poder && !(winner->estado == cartas[i]->estado && winner->cidade == cartas[i]->cidade)){
            empate = cartas[i];
            empate_flag = 1;
        }
    }

    if(empate_flag == 0){
    printf("\n\nCarta Vencedora -> ");
    info(winner);
    }
    else{
        printf("\n Deu empate \n");
        comparacao(winner, empate);
    }

    for(int i = 0; i < nc; i++)
	    free(cartas[i]);
    free(cartas);

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}

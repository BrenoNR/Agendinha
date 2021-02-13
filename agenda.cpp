//Breno Augusto - RA 2840482011030
//Agenda para """"guardar"""" contatos (pelo menos a lógica, falta a parte de guardar mesmo)

#include <iostream>
#include <string.h> //strcmp

//Esquema de cores
#define RED "\033[31;40m"
#define GREEN "\033[1;92m"
#define WHITE "\033[37;40m"
#define YELLOW "\033[33;40m"
#define BLUE "\033[1;36m"
#define CYAN "\033[1;96m"

//acentos
#include <locale.h>

using namespace std;

struct agenda {
       char nome[30];
       int dia;
       int mes;
       int ano;
       string email;
       int vazio; //VAZIO = 0 e DISPONIVEL = 1.
} registros[1000];


//função para obter uma posição vazia na struct
int posicao(){
	
	for(int i = 0; i < 1000; i++){
			
		if (registros[i].vazio == 0){
			
			return i;
			
		}		
		
	}
	
	return -1;
	
}

//Função de cadastro da agenda
void cadastro(){
	
	//recebe a posição vazia
	int pos = posicao();
	
	cout << "		     -----------------------|" << GREEN << "CADASTRO" << WHITE << "|---------------------------\n\n";
	
	cout << "                                |Digite o nome da pessoa................: ";
	getchar(); //pra evitar pegar o enter e nao passar direto
	gets(registros[pos].nome);
	
	cout << endl;
	
	cout << "                                |Digite apenas o dia em que ela nasceu..: ";
	cin >> registros[pos].dia;
	
	cout << endl;
	
	cout << "                                |Digite o mês...........................: ";
	cin >> registros[pos].mes;
	
	cout << endl;
	
	cout << "                                |Ano de nascimento......................: ";
	cin >> registros[pos].ano;
	
	cout << endl;
	
	cout << "                                |Email para contato.....................: ";
	cin >> registros[pos].email;
	
	registros[pos].vazio = 1;
	
	cout << endl;
	
	cout << GREEN << "                                |Contato adicionado com sucesso!" << WHITE;
	
	cout << endl;
	
	cout << endl;
	
	cout << endl;
	
	system("pause");
	
}

//Função de alterar a data de aniversário atraves do nome
void alteraraniversario(){
	
	char nome[30];
	
	cout << "\n                                         Digite o nome: ";
	getchar();
	gets(nome);
	
	for(int i = 0; i < 1000; i++){
			
			if(strcmp(registros[i].nome, nome) == 0){
				
				cout << endl;
				
				cout << YELLOW << "                                        Data atual: " << registros[i].dia << "/" << registros[i].mes << "/" << registros[i].ano << WHITE << endl;
				
				cout << "\n                                           |Novo dia: ";
				cin >> registros[i].dia;
				
				cout << "\n                                           |Novo mês: ";
				cin >> registros[i].mes;
				
				cout << "\n                                           |Novo ano: ";
				cin >> registros[i].ano;
				
				cout << "\n\n                                         Alteração concluída!\n";
				
				cout << GREEN << "                                         Nova data: " << registros[i].dia << "/" << registros[i].mes << "/" << registros[i].ano << WHITE << endl << endl;
				
				system("pause");
				
				return;
			}
		
	}
	
	cout << RED << "                                       Nome nao encontrado!\n\n" << WHITE;
	
	system("pause");
}

//Função para consultar todos os aniversariantes de um determinado dia
void consultardia(){
	int dia;
	
	cout << "\n                                             Dia: ";
	cin >> dia;
	
	system("cls");
	
	cout << "		     --------------------------|" << GREEN << "ANIVERSARIANTES DO DIA " << dia << WHITE << "|---------------------------\n\n";
	
	for(int i = 0; i < 1000; i++){
		
		if(registros[i].dia == dia){
			
			cout << "                                    _______________________________________________\n";
			cout << "                                   |                                               |\n";
			cout << "                                   |  Nome.......: " << registros[i].nome << endl;
			cout << "                                   |  Email......: " << registros[i].email << endl;
			cout << "                                   |  Aniversario: " << registros[i].dia << "/" << registros[i].mes << "/" << registros[i].ano << endl;
			cout << "                                   |_______________________________________________|\n\n";
		}
		
	}
	
	cout << RED << "                                            Não há mais aniversariantes no dia " << dia << WHITE << endl;
	
	cout << endl << endl;	
	system("pause");
	
}

//Função para consultar todos aniversariantes de um mês
void consultarmes(){
	int mes;
	
	cout << "\n                                             Mês: ";
	cin >> mes;
	
	system("cls");
	
	cout << "		     --------------------------|" << GREEN << "ANIVERSARIANTES DO MÊS " << mes << WHITE << "|---------------------------\n\n";
	
	for(int i = 0; i < 1000; i++){
		
		if(registros[i].mes == mes){
			
			cout << "                                    _______________________________________________\n";
			cout << "                                   |                                               |\n";
			cout << "                                   |  Nome.......: " << registros[i].nome << endl;
			cout << "                                   |  Email......: " << registros[i].email << endl;
			cout << "                                   |  Aniversario: " << registros[i].dia << "/" << registros[i].mes << "/" << registros[i].ano << endl;
			cout << "                                   |_______________________________________________|\n\n";
			
		}
		
	}
	
	cout << RED << "                                            Não há mais aniversariantes no mês " << mes << WHITE << endl;
	
	cout << endl << endl;	
	system("pause");
	
}	

//Função para mostrar todos contatos salvos
void mostrar(){
	
	system("cls");
		
	cout << "			--------------------|" << GREEN << "AGENDA" << WHITE << "|-----------------------\n";
	
		for (int i = 0; i < 1000; i++){
					
			if(registros[i].vazio == 1){
				
					cout << "                         _________________________________________________\n";
					cout << "                         |                                               |\n";
					cout << "                         |  Nome.......: " << registros[i].nome << endl;
					cout << "                         |  Email......: " << registros[i].email << endl;
					cout << "                         |  Aniversario: " << registros[i].dia << "/" << registros[i].mes << "/" << registros[i].ano << endl;
					cout << "                         |_______________________________________________|\n\n";    
			}
					
		}
				
	system("pause");
	
	
}

//Função de excuir contato atraves do nome da pessoa
void excluir(){
	
	char nome[30];
	
	cout << "\n                                     Digite o nome do excluído: ";
	getchar();
	gets(nome);
	
	for(int i = 0; i < 1000; i++){
			
			//ele compara todos os nomes com a entrada
			//strcmp == comparação de string
			if(strcmp(registros[i].nome, nome) == 0){
				
				registros[i].vazio = 0;
				
				cout << GREEN << "\n                                         Pessoa excluída\n\n" << WHITE;
		
				system("pause");
				
				return;
			}
		
	}
	
	cout << RED << "\n                                        Nome nao encontrado!\n\n" << WHITE;
	
	system("pause");
}


int main(){
	
	//variavel de escolha do menu
	int esc;
	
	setlocale(LC_ALL, "Portuguese");
	
	do{
		
		system("cls");
		
		cout << "			--------------------|" << GREEN << "AGENDA" << WHITE << "|-----------------------\n";
		
		cout << "			__________________________________________________\n";
		
		cout << "			|                                                 |\n";
		
		cout << "			|  " << GREEN << "[1]" << WHITE << " - Registrar contato                        |\n";
		
		cout << "			|  " << GREEN << "[2]" << WHITE << " - Alterar aniversário                      |\n";
		
		cout << "			|  " << CYAN << "[3]" << WHITE << " - Consultar aniversariantes do mesmo dia   |\n";
		
		cout << "			|  " << CYAN << "[4]" << WHITE << " - Consultar aniversariantes do mesmo mes   |\n";
		
		cout << "			|  " << YELLOW<< "[7]" << WHITE << " - Mostrar agenda                           |\n";
		
		cout << "			|  " <<  RED  << "[8]" << WHITE << " - Excluir pessoa   "  << RED << "            [9]" << WHITE <<  " - Sair  |\n";
		
		cout << "			|_________________________________________________|\n\n";
		
		cout << "                                           Escolha: ";
		cin >> esc;
		
		switch (esc){
		
			case 1: {
				
				if (posicao() != -1){
					
					system("cls");
					cadastro();
					
				}
					else 
					
						cout << "Não há mais espaço na agenda!";
						
				break;
			}
			
			case 2: {
				
				alteraraniversario();
				
				break;
			}
			
			case 3: {
				
				consultardia();
				
				break;
			}
			
			case 4: {
				
				consultarmes();
					
				break;
			}
				
			case 7:{
				
				mostrar();	
			
				break;
			}
			
			case 8:	{
				
				excluir();
				
				break;
			}
			
			case 9: {
				
				return 0;
				
				break;
			}
			
			//caso nao coloque nada com nada
			default:
			
				cout << RED << "                               Coloque algo decente por favor\n\n" << WHITE;
			
				system("pause");
			
		}
		
		
		
	}while(esc != 9);
	
	
	
	return 0;
}

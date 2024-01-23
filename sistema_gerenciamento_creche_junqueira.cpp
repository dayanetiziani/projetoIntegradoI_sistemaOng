/*
******* Integrantes *******
Andressa de Farias - 10442313065
André de Osti Garcia Badan - 10442313851
Dayane Tiziani Boa Ventura - 10442313510
Deivid Lucas Muller Maia - 10442313486
Gabriel José Alves de Brito - 10442313314
Leonardo da Silveira Domingos - 10442313074
Nátaly Lara Moraes da Silva - 10442312658 
Rafael Haddad de Lima - 10442313190
*/

#include<stdio.h>
#include<locale.h>
#include<string.h>
#define TF 10
main()
{
	setlocale(LC_ALL,"Portuguese");
	
	//menu
	int opcaoMenu, opcaoCadastro;
	//1- Cadastro
	int TLE=0, codigoVoluntario, vCodigoVoluntario[TF], posicao; 
	int TLV=0, vCodigoEmpresa[TF], codigoEmpresa, vCodigoProjeto[TF], codigoProjeto;
	int TLP=0, TLH=0;
	char vNomeVoluntario[TF][60], vNomeEmpresa[TF][60], vDescricaoProjeto[TF][60];
	//2 - Exclusão
	int contVoluntarioExcluido=0, contEmpresaExcluida=0, contProjetoExcluido=0;
	int TVX=0, TEX=0, TPX=0, opcaoExclusao, posicaoHoras, posicaoVoluntario;
	int vVoluntarioExcluido[TF], vProjetoExcluido[TF], vEmpresaExcluida[TF];
	char vNomeVoluntarioExcluido[TF][60], vNomeEmpresaExcluida[TF][60], vDescricaoProjetoExcluido[TF][60];
	//3- Lançamento de horas
	int lancamentoHoras=0, vLancamentoHoras[TF], vProjetoHoras[TF],vVoluntarioHoras[TF],vEmpresaHoras[TF], i=0;
	int verifica_projeto, posicao_projeto, verifica_voluntario,posicao_voluntario, verifica_empresa, posicao_empresa;
	int posicao_horas;
	char vNomeVoluntarioHoras[TF][60], vDescricaoProjetoHoras[TF][60], vNomeEmpresaHoras[TF][60];
	//4-Relatório
	int OpcaoRelatorio, OpcaoRelatorioVoluntario, OpcaoRelatorioProjeto, OpcaoRelatorioEmpresa, contVoluntarioHoras, contProjetoHoras, contEmpresaHoras;
	//fim
	char opcaoFim[3];
	
	do
	{
		printf("\n\n ________________ INÍCIO _________________\n");
		
		printf("\n __________________________________________");
		printf("\n|                                          |");
		printf("\n|            CRECHE JUNQUEIRA              |");
		printf("\n|__________________________________________|");
		
		printf("\n\n          ******* MENU *******              \n");
		
		printf("            _______________");
		printf("\n           | 1- Cadastro   |");
		printf("\n           |_______________|");
		
		printf("\n           | 2- Exclusão   |");
		printf("\n           |_______________|");
		
		printf("\n           | 3- Lançamento |");
		printf("\n           |_______________|");
		
		printf("\n           | 4- Relatório  |");
		printf("\n           |_______________|");
		
		printf("\n           | 5- Finalizar  |");
		printf("\n           |_______________|");
		
		printf("\n\nOpcão desejada: ");
		scanf("%d",&opcaoMenu);
	
		if(opcaoMenu == 1)
		{
			printf("   _______________");
			printf("\n  |    Cadastro   |");
			printf("\n  |_______________|");
			
			printf("\n   1- Voluntário     ");
			printf("\n   2- Empresa        ");
			printf("\n   3- Projeto        ");
			printf("\n   4- Retornar      ");
			printf("\n\nOpção desejada: ");
			scanf("%d",&opcaoCadastro);
			
			while(opcaoCadastro != 4)
			{
				if(opcaoCadastro == 1)
				{
				  //processo do cadastro de voluntário 
					if(TLV<TF)//coloca esse TlV<TF pq quando der a quantidade do (TF) ele para de aceitar cadastro
					{
						printf("\n ********** Cadastro de Voluntário **********\n");
						printf("\nInforme o código do voluntário: ");
						scanf("%d",&codigoVoluntario);
						
						while(codigoVoluntario!=0)
						{
							posicao=0;
							while(codigoVoluntario != vCodigoVoluntario[posicao] && posicao<TLV)
								posicao++;
									
							if(posicao<TLV)//ACHOU
							{
								printf("\n*** ATENÇÃO ***");
								printf("\nCÓDIGO DO VOLUNTÁRIO JÁ SE ENCONTRA EM NOSSO BANCO DE DADOS\n");
							}
							else//NÃO ACHOU E VAI CADASTRAR
							{
								vCodigoVoluntario[TLV] = codigoVoluntario;	
								
								printf("Informe o nome completo do voluntário: ");
								fflush(stdin);
								gets(vNomeVoluntario[TLV]);//lê o nome completo
								strupr(vNomeVoluntario[TLV]);//transforma em maiúscula
							
								printf(" _________________________________________");
								printf("\n|                                         |");
								printf("\n|   VOLUNTÁRIO CADASTRADO COM SUCESSO!    |");
								printf("\n|_________________________________________|");
								
								TLV++;//aqui vai contar os voluntários até dar a quantidade do TF		
							}
						
							if(TLV <TF)
							{
								printf("\n\nInforme o código do voluntário ou 0 para Sair: ");
								scanf("%d",&codigoVoluntario);
							}
							else
							{
								printf("\n       *** ATENÇÃO ***");
								printf("\n\nTodas as vagas foram preenchidas");
								codigoVoluntario = 0; //forçar o codigo 0 para sair do while pois aqui o TLV se tornou = ao TF
							}
						}
					}
					else
			 			printf("Sem vagas para voluntários no momento");
		 			
				}//fim do if opcaoCadastro 1 - Voluntario
				
				if(opcaoCadastro == 2)
				{
					//processo do cadastro de Empresa 
					if(TLE <TF)//coloca esse TlE<TF pq quando der a quantidade do(TF) ele para de aceitar cadastro
					{
						printf("\n ********** Cadastro de Empresa **********\n");
						printf("\nInforme o código da Empresa: ");
						scanf("%d",&codigoEmpresa);
						
						while(codigoEmpresa!=0)
						{							
							posicao=0;
							while(codigoEmpresa != vCodigoEmpresa[posicao] && posicao<TLE)//ver se o modo de validaÃ§Ã£o Ã© somente com o nome da empresa
								posicao++;
									
							if(posicao<TLE)//ACHOU
							{
								printf("\n*** ATENÇÃO ***");
								printf("\n\nCÓDIGO DE EMPRESA JÁ SE ENCONTRA EM NOSSO BANCO DE DADOS");
							}	
							else//NÃO ACHOU E VAI CADASTRAR
							{
								vCodigoEmpresa[TLE] = codigoEmpresa;
								
								//aqui é o cadastro do nome, que só vai acontecer se o código ainda não existir
								printf("Informe o nome da Empresa: ");
								fflush(stdin);
								gets(vNomeEmpresa[TLE]);
								strupr(vNomeEmpresa[TLE]);
								
								printf(" _________________________________________");
								printf("\n|                                         |");
								printf("\n|     EMPRESA CADASTRADA COM SUCESSO!     |");
								printf("\n|_________________________________________|");
								
								TLE++;//aqui vai contar os produtos até dar a quantidade do tf				
							}	
							if(TLE <TF)
							{
								printf("\n\nInforme o código da Empresa ou 0 para Sair: ");
								scanf("%d",&codigoEmpresa);
							}
							else
							{
								printf("\n         *** ATENÇÃO ***");
								printf("\n\nTodas as vagas foram preenchidas");
								codigoEmpresa = 0; //forçar o codigo 0 para sair do while pois aqui o TLV se tornou = ao TF
							}
						}
					}
					else
				 		printf("Sem vagas para Empresas no momento");		
				}//fim do if opcaoCadastro 2 - Empresa
				
				if(opcaoCadastro == 3)
				{
					//processo do cadastro de Projeto
					if(TLP <TF)//coloca esse TLP<TF pq quando der a quantidade do(TF) ele para de aceitar cadastro
					{
						printf("\n ********** Cadastro de Projeto **********\n");
						printf("\nInforme o código do Projeto: ");
						scanf("%d",&codigoProjeto);
						
						while(codigoProjeto!=0)
						{
							posicao=0;
							while(codigoProjeto != vCodigoProjeto[posicao] && posicao<TLP)
								posicao++;
									
							if(posicao<TLP)//ACHOU
							{
								printf("\n*** ATENÇÃO ***\n");
								printf("\n\nCÓDIGO DO PROJETO JÁ SE ENCONTRA EM NOSSO BANCO DE DADOS");
							}	
							else//NÃO ACHOU E VAI CADASTRAR
							{
								vCodigoProjeto[TLP] = codigoProjeto;
								
								//aqui é o cadastro do nome, que só vai acontecer se o código ainda não existir
								printf("Informe a Descrição do projeto : ");
								fflush(stdin);
								gets(vDescricaoProjeto[TLP]);
								strupr(vDescricaoProjeto[TLP]);
									
								printf(" _________________________________________");
								printf("\n|                                         |");
								printf("\n|     PROJETO CADASTRADO COM SUCESSO!     |");
								printf("\n|_________________________________________|");
							
								TLP++;//aqui vai contar os produtos até dar a quantidade do tf			
							}
						
							if(TLP <TF)
							{
								printf("\n\nInforme o código do Projeto ou 0 para Sair: ");
								scanf("%d",&codigoProjeto);
							}
							else
							{
								printf("\n        *** ATENÇÃO ***");
								printf("\n\nTodas as vagas foram preenchidas");
								codigoProjeto = 0; //forçar o codigo 0 para sair do while pois aqui o TLV se tornou = ao TF
							}							
						}
					}
					else
				 		printf("Projeto indisponível para cadastro no momento");		
				}//fim do if do opcaoCadastro 3 - Projeto
				
				if(opcaoCadastro == 4)
				{
					printf("\n ********** Retornar **********");
				}
				if(opcaoCadastro <0 || opcaoCadastro >4)
				{
					printf("\n Opcão inválida! Escolha outra opção. ");
				}
				
				printf("\n   _______________");
				printf("\n  |    Cadastro   |");
				printf("\n  |_______________|");
				
				printf("\n   1- Voluntário     ");
				printf("\n   2- Empresa        ");
				printf("\n   3- Projeto        ");
				printf("\n   4- Retornar      ");
				printf("\n\nOpção desejada: ");
				scanf("%d",&opcaoCadastro);
				
			}//fim do while opcaoCadastro
			
		}		
		if(opcaoMenu == 2)//Exclusão
		{
			printf("   _______________");
			printf("\n  |    Exclusão   |");
			printf("\n  |_______________|");
			
			printf("\n   1- Voluntário    ");
			printf("\n   2- Empresa       ");
			printf("\n   3- Projeto       ");
			printf("\n   4- Sair      ");
			printf("\n\nOpção desejada: ");
			scanf("%d",&opcaoExclusao);
			
			while(opcaoExclusao != 4)
			{
				if(opcaoExclusao == 1)
				{
					printf("\n ********** Excluir Voluntário **********\n");
					
					printf("\nInforme o código do Voluntário: ");
					scanf("%d",&codigoVoluntario);
					
					while(codigoVoluntario != 0)//esse while serve para ficar repetindo a esclusão 
					{
						//agora vai verificar pra ver se JÁ tem o codigoVoluntario cadastrado
						posicaoVoluntario=0;
						while(codigoVoluntario != vCodigoVoluntario[posicaoVoluntario] && posicaoVoluntario<TLV)
							posicaoVoluntario++;
						
						if(posicaoVoluntario<TLV)//ACHOU. Agora vai buscar se ele já tem horas cadastradas.
						{
							posicaoHoras= -1;
							for(i=0;i<TLH;i++)
							{
								if(vVoluntarioHoras[i]==codigoVoluntario )
								{
									posicaoHoras=i;
								}
	
							}
							if(posicaoHoras >=0)//achou horas cadastradas para esse usuario e vai informar que não pode ser	excluído
							{
								printf("\n                    *** ATENÇÃO ***\n");
								printf("ESTE VOULNTÁRIO NÃO PODE SER EXCLUÍDO. ELE POSSUI LANÇAMENTO DE HORAS.");
							}
							else//exclusão aqui
							{
								vVoluntarioExcluido[TVX]= vCodigoVoluntario[posicaoVoluntario];
								strcpy(vNomeVoluntarioExcluido[TVX],vNomeVoluntario[posicaoVoluntario]);	
								
								for(i=posicaoVoluntario;i<TLV-1;i++)
								{
									vCodigoVoluntario[i]=vCodigoVoluntario[i+1];
									strcpy(vNomeVoluntario[i],vNomeVoluntario[i+1]);	
								}
								
								contVoluntarioExcluido++;
								TVX++;
								TLV--;
								
								printf("\n ___________________________________________");
								printf("\n|                                           |");
								printf("\n|     VOLUNTÁRIO EXCLUÍDO COM SUCESSO!      |");
								printf("\n|___________________________________________|");
								
							}
										
						}
						else
						{
							printf("\n              *** ATENÇÃO ***\n");
							printf("VOULNTÁRIO NÃO ENCONTRADO EM NOSSO BANCO DE DADOS");
						}
						if(TLV<TF)
						{
							printf("\n\nInforme o código do Voluntário ou 0(zero) para sair: ");
							scanf("%d",&codigoVoluntario);
						
						}
					}//fim do while repetindo a esclusão voluntários 
				}
				if(opcaoExclusao == 2)
				{
					printf("\n ********** Excluir Empresa **********\n");
					
					printf("\nInforme o código do Empresa: ");
					scanf("%d",&codigoEmpresa);
					
					while(codigoEmpresa != 0)//esse while serve para ficar repetindo a esclusão 
					{
						//agora vai verificar pra ver se JÁ tem o codigoEmpresa cadastrada
						posicao=0;
						while(codigoEmpresa != vCodigoEmpresa[posicao] && posicao<TLE)
							posicao++;
						
						if(posicao<TLE)//ACHOU. agora vai buscar se ela já tem horas cadastradas.
						{
							posicaoHoras= -1;
							for(i=0;i<TLH;i++)
							{
								if(vEmpresaHoras[i]==codigoEmpresa)
								{
									posicaoHoras=i;
								}
	
							}
							if(posicaoHoras >=0)//achou horas cadastradas para esse usuario e vai informar que não pode ser	excluído
							{
								printf("\n                                 *** ATENÇÃO ***\n");
								printf("ESTA EMPRESA NÃO PODE SER EXCLUÍDA. ELA POSSUI VÍNCULO COM PROJETO E VOLUNTÁRIO COM LANÇAMENTO DE HORAS.");
							}
							else//exclusão aqui
							{
								vEmpresaExcluida[TEX]= vCodigoEmpresa[posicao];
								strcpy(vNomeEmpresaExcluida[TEX],vNomeEmpresa[posicao]);
								
								for(i=posicao;i<TLE-1;i++)
								{
									vCodigoEmpresa[i]=vCodigoEmpresa[i+1];
									strcpy(vNomeEmpresa[i],vNomeEmpresa[i+1]);
								}
								contEmpresaExcluida++;
								TEX++;	
								TLE--;
								
								printf("\n ___________________________________________");
								printf("\n|                                           |");
								printf("\n|     EMPRESA EXCLUÍDA COM SUCESSO!         |");
								printf("\n|___________________________________________|");
							}
											
						}
						else
						{
							printf("\n              *** ATENÇÃO ***\n");
							printf("EMPRESA NÃO ENCONTRADA EM NOSSO BANCO DE DADOS");
						}
						
						if(TLV<TF)
						{
							printf("\n\nInforme o código da Empresa ou 0(zero) para sair: ");
							scanf("%d",&codigoEmpresa);
						
						}
					}//fim do while repetindo a esclusão EMPRESA 
				}
				if(opcaoExclusao == 3)
				{
					printf("\n ********** Excluir Projeto **********\n");
					
					printf("\nInforme o código do Projeto: ");
					scanf("%d",&codigoProjeto);
					
					while(codigoProjeto != 0)//esse while serve para ficar repetindo a esclusão 
					{
						//agora vai verificar pra ver se JÁ tem o codigoProjeto cadastrado
						posicao=0;
						while(codigoProjeto != vCodigoProjeto[posicao] && posicao<TLP)
							posicao++;
						
						if(posicao<TLP)//ACHOU. Agora vai buscar se ele já tem horas cadastradas.
						{
							posicaoHoras= -1;
							for(i=0;i<TLH;i++)
							{
								if(vProjetoHoras[i]==codigoProjeto )
								{
									posicaoHoras=i;
								}
	
							}
							if(posicaoHoras >=0)//achou horas cadastradas para esse projeto e vai informar que não pode ser	excluído
							{
								printf("\n                                     *** ATENÇÃO ***\n");
								printf("ESTE PROJETO NÃO PODE SER EXCLUÍDO. ELE POSSUI VÍNCULO COM EMPRESA E VOLUNTÁRIO COM LANÇAMENTO DE HORAS.");
							}
							else//exclusão aqui
							{
								vProjetoExcluido[TPX]= vCodigoProjeto[posicao];
								strcpy(vDescricaoProjetoExcluido[TPX],vDescricaoProjeto[posicao]);
								
								for(i=posicao;i<TLP-1;i++)
								{
									vCodigoProjeto[i]=vCodigoProjeto[i+1];
									strcpy(vDescricaoProjeto[i],vDescricaoProjeto[i+1]);
								}
								contProjetoExcluido++;
								TPX++;	
								TLP--;
								
								printf("\n ___________________________________________");
								printf("\n|                                           |");
								printf("\n|     PROJETO EXCLUÍDO COM SUCESSO!         |");
								printf("\n|___________________________________________|");
							}
											
						}
						else
						{
							printf("\n              *** ATENÇÃO ***\n");
							printf("PROJETO NÃO ENCONTRADO EM NOSSO BANCO DE DADOS");
						}
						
						if(TLV<TF)
						{
							printf("\n\nInforme o código do Projeto ou 0(zero) para sair: ");
							scanf("%d",&codigoProjeto);
						
						}
					}//fim do while repetindo a esclusão Projeto 
				}
				if(opcaoExclusao <0 || opcaoExclusao >4)
				{
					printf("\n Opcão inválida! Escolha outra opção. ");
				}
				
				printf("\n   _______________");
				printf("\n  |    Exclusão   |");
				printf("\n  |_______________|");
				
				printf("\n   1- Voluntário    ");
				printf("\n   2- Empresa       ");
				printf("\n   3- Projeto       ");
				printf("\n   4- Retornar          ");
				printf("\n\nOpção desejada: ");
				scanf("%d",&opcaoExclusao);
			
			}//FIM DO WHILE MENU EXCLUSÃO
		
		}//fim da opcao de Exclusão
		if(opcaoMenu == 3)//Lancamento de Horas
		{
			printf("   __________________");
			printf("\n  |    Lançamento    |");
			printf("\n  |__________________|\n");
		
			
			printf("\n ********** Lançamento de horas **********\n");
			printf("\nInforme o código do Projeto: ");
			scanf("%d",&verifica_projeto);
			
			while(verifica_projeto != 0)
			{
			//agora vai verificar pra ver se JÁ tem o codigoProjeto cadastrado
				posicao_projeto = 0;
				while(verifica_projeto != vCodigoProjeto[posicao_projeto] && posicao_projeto <TLP)
					posicao_projeto++;
					
				if(posicao_projeto < TLP)//ACHOU
				{
					printf("Informe o código do Voluntário: ");
					scanf("%d",&verifica_voluntario);
				
				//agora vai verificar pra ver se JÁ tem o codigoVoluntario cadastrado
					posicao_voluntario=0;
					while(verifica_voluntario != vCodigoVoluntario[posicao_voluntario] && posicao_voluntario <TLV)
						posicao_voluntario++;
							
					if(posicao_voluntario <TLV)//ACHOU
					{
						printf("Informe o código da Empresa: ");
						scanf("%d",&verifica_empresa);
					
					//agora vai verificar pra ver se JÁ tem o codigoEmpresa cadastrado
						posicao_empresa=0;
						while(verifica_empresa != vCodigoEmpresa[posicao_empresa] && posicao_empresa <TLE)
							posicao_empresa++;
								
						if(posicao_empresa <TLE)//ACHOU
						{
							printf("Informe quantidade de horas: ");
							scanf("%d", &lancamentoHoras);
							
							posicao_horas= -1;
							for (i = 0; i < TLH; i++)
							{
								if( vProjetoHoras[i] == verifica_projeto && vEmpresaHoras[i] == verifica_empresa && vVoluntarioHoras[i] == verifica_voluntario )
								{
									posicao_horas = i;
								}
							}
							if ( posicao_horas == -1)//não achou
							{
								vProjetoHoras[TLH] = verifica_projeto;
								vEmpresaHoras[TLH] = verifica_empresa;
								vVoluntarioHoras[TLH] = verifica_voluntario;
								vLancamentoHoras[TLH] = lancamentoHoras;
								
								strcpy(vNomeVoluntarioHoras[TLH], vNomeVoluntario[posicao_voluntario]);
								strcpy(vDescricaoProjetoHoras[TLH], vDescricaoProjeto[posicao_projeto]);
								strcpy(vNomeEmpresaHoras[TLH], vNomeEmpresa[posicao_empresa]);
								
								printf("\n _________________________________________");
								printf("\n|                                         |");
								printf("\n|     HORAS ADICIONADAS COM SUCESSO!      |");
								printf("\n|_________________________________________|");
								
								printf("\n _________________________________________");
								printf("\n| Projeto | Voluntário | Empresa | Horas  |");
								printf("\n| [%d] %d  | [%d] %d    | [%d] %d  | [%d]%d  |",TLH,vProjetoHoras[TLH],TLH,vVoluntarioHoras[TLH],TLH,vEmpresaHoras[TLH],TLH,vLancamentoHoras[TLH]);
								printf("\n|_________________________________________|\n");
								
								TLH++;
							}
							else
							{		
								printf("\n _________________________________________");
								printf("\n|                                         |");
								printf("\n|     HORAS ATUALIZADAS COM SUCESSO!      |");
								printf("\n|_________________________________________|");
								
								vLancamentoHoras[posicao_horas]+= lancamentoHoras;
								
								printf("\n _________________________________________");
								printf("\n| Projeto | Voluntário | Empresa | Horas  |");
								printf("\n| [%d] %d  | [%d] %d    | [%d] %d  | [%d]%d  |",posicao_horas,vProjetoHoras[posicao_horas],posicao_horas,vVoluntarioHoras[posicao_horas],posicao_horas,vEmpresaHoras[posicao_horas],posicao_horas,vLancamentoHoras[posicao_horas]);
								printf("\n|_________________________________________|\n");
							}
						}
						else//NÃO ACHOU E VAI INFORMAR
						{	
							printf("\n                 *** ATENÇÃO ***\n");
							printf("\nEMPRESA NÃO ENCONTRADA EM NOSSO BANCO DE DADOS.\nVOLTE E INFORME O CÓDIGO DE UMA EMPRESA VÁLIDA ");				
						}	
					}
					else//NÃO ACHOU E VAI INFORMAR
					{
						printf("\n                *** ATENÇÃO ***\n");
						printf("\nVOLUNTÁRIO NÃO ENCONTRADO EM NOSSO BANCO DE DADOS.\nVOLTE E INFORME UM CÓDIGO DE VOLUNTÁRIO VÁLIDO. ");				
					}	
				}
				else//NÃO ACHOU E VAI INFORMAR
				{
					printf("\n              *** ATENÇÃO ***\n");
					printf("\nPROJETO NÃO ENCONTRADO EM NOSSO BANCO DE DADOS.\nVOLTE E INFORME UM CÓDIGO DE PROJETO VÁLIDO. \n");
				}
				printf("\n ********** Lançamento de horas **********\n");
				printf("\nInforme o código do Projeto ou 0 para sair: ");
				scanf("%d",&verifica_projeto);
				
			}
		
		}//fim da opcao de Lancamento de Horas
		
		if(opcaoMenu == 4)//Relatorio
		{
			printf("   __________________");
			printf("\n  |    Relatório     |");
			printf("\n  |__________________|");
		
			//MENU RELATÁRIO
			printf("\n\n ******* MENU  *******\n");
			
			printf("\n1- Relatório Voluntário");
			printf("\n2- Relatório Projeto");
			printf("\n3- Relatório Empresa");
			printf("\n4- Relatório Excluídos");
			printf("\n5- Relatório Geral");
			printf("\n6- Retornar\n");
			printf("Opção: ");
			scanf("%d", &OpcaoRelatorio);
			
			//inicio do while OpcaoRelatorio
			while(OpcaoRelatorio != 6)
			{
				if(OpcaoRelatorio == 1 )
				{
					printf("\n\n **** FILTRO ****\n");
					printf("\n1-Todos os voluntários");
					printf("\n2-Por voluntário");
					printf("\n3-Retornar\n");
					printf("\nOpção: ");
					scanf("%d", &OpcaoRelatorioVoluntario);
					
					//inicio do while Relatorio Voluntario
					while(OpcaoRelatorioVoluntario != 3)     
					{
						if(OpcaoRelatorioVoluntario == 1)
						{
							printf("\nTodos os voluntários\n");
							printf(" __________________________________");
							printf("\n|Código|Nome                       |");
							printf("\n|__________________________________|\n");
							
							for(i=0;i<TLV;i++)
								printf("  [%d]  %s\n", vCodigoVoluntario[i] ,vNomeVoluntario[i]);
							
						}
						if(OpcaoRelatorioVoluntario == 2)
						{
							printf("\nPor voluntário\n");
							printf("\nInforme o código do voluntário: ");
							scanf("%d",&codigoVoluntario);
							
							posicao=0;
							while(codigoVoluntario != vCodigoVoluntario[posicao] && posicao<TLV)
								posicao++;
									
							if(posicao<TLV)//ACHOU
							{
								printf("VOLUNTÁRIO: %s", vNomeVoluntario[posicao]);
								
								printf("\n ____________________________________________");
								printf("\n|Posição | Cod.Projeto | Cod.Empresa | Horas |");
								printf("\n|____________________________________________|\n");
											
								
								contVoluntarioHoras=0;
								for(i=0;i<TLH;i++)
								{
									if(codigoVoluntario == vVoluntarioHoras[i])
									{
										contVoluntarioHoras++;
										printf("\n|   %d    |      %d     |      %d     |   %d  |",i, vProjetoHoras[i] ,vEmpresaHoras[i], vLancamentoHoras[i]);
										
									}
									
								}
								if(contVoluntarioHoras == 0)
								{
									printf("\n            *** ATENÇÃO ***\n");
									printf("\nESTE VOLUNTÁRIO NÃO POSSUI LANÇAMENTO DE HORAS. ");
								}
							}
							else//NÃO ACHOU E VAI CADASTRAR
							{
								printf("\n                             *** ATENÇÃO ***\n");
								printf("\nVOLUNTÁRIO NÃO ENCONTRADO EM NOSSO BANCO DE DADOS.\nVOLTE E INFORME UM CÓDIGO VÁLIDO. ");
							}
							
						}
						if(OpcaoRelatorioVoluntario <0 || OpcaoRelatorioVoluntario >3)
						{
							printf("\n Opcão inválida! Escolha outra opção. ");
						}
						
						printf("\n\n **** FILTRO ****\n");
						printf("\n1-Todos os voluntários");
						printf("\n2-Por voluntário");
						printf("\n3-Retornar\n");
						printf("Opção: ");
						scanf("%d", &OpcaoRelatorioVoluntario);
						
					}//fim do while Relatorio Voluntario
			
				}
				if(OpcaoRelatorio == 2 )
				{
					printf("\n\n **** FILTRO ****\n");
					printf("\n1-Todos os projetos");
					printf("\n2-Por projeto");
					printf("\n3-Retornar\n");
					printf("Opcão: ");                          
					scanf("%d", &OpcaoRelatorioProjeto);
					
					//inicio do while Relatorio Projeto
					while(OpcaoRelatorioProjeto != 3)
					{
						if(OpcaoRelatorioProjeto == 1)
						{
							printf("\nTodos os projetos\n");
							printf(" _______________________________________");
							printf("\n|Código |Descrição                      |");
							printf("\n|_______________________________________|\n");
							
							for(i=0;i<TLP;i++)
								printf("  [%d]   %s\n", vCodigoProjeto[i] ,vDescricaoProjeto[i]);
						}
						if(OpcaoRelatorioProjeto == 2)
						{
							printf("\nPor projeto\n");
							printf("\nInforme o código do projeto: ");
							scanf("%d",&codigoProjeto);
							
							posicao=0;
							while(codigoProjeto != vCodigoProjeto[posicao] && posicao<TLP)
								posicao++;
									
							if(posicao<TLP)//ACHOU
							{
								printf("\nPROJETO: %s", vDescricaoProjeto[posicao]);
								
								printf("\n _________________________________________________");
								printf("\n|Posição | Cod.Empresa  | Cod.Voluntário | Horas  |");
								printf("\n|_________________________________________________|\n");
								
								contProjetoHoras=0;
								for(i=0;i<TLH;i++)
								{
									if(codigoProjeto == vProjetoHoras[i])
									{
										contProjetoHoras++;	
										printf("\n|   %d    |      %d      |      %d       |    %d  |",i,vEmpresaHoras[i], vVoluntarioHoras[i], vLancamentoHoras[i]);	
									}
									
								}
								if(contProjetoHoras == 0)
								{
									printf("\n            *** ATENÇÃO ***\n");
									printf("\nESTE PROJETO NÃO ESTÁ VÍNCULADO COM NENHUM VOLUNTÁRIO. ");
								}
							}
							else//NÃO ACHOU E VAI CADASTRAR
							{
								printf("\n              *** ATENÇÃO ***\n");
								printf("\nPROJETO NÃO ENCONTRADO EM NOSSO BANCO DE DADOS.\nVOLTE E INFORME UM CÓDIGO VÁLIDO. ");
							}
						}
						if(OpcaoRelatorioProjeto <0 || OpcaoRelatorioProjeto >3)
						{
							printf("\n Opcão inválida! Escolha outra opção. ");
						}
						
						printf("\n\n **** FILTRO ****\n");
						printf("\n1-Todos os projetos");
						printf("\n2-Por projeto");
						printf("\n3-Retornar\n");
						printf("Opcão: ");
						scanf("%d", &OpcaoRelatorioProjeto);
						
					}//fim do while Relatorio Empresa
				}	
				if(OpcaoRelatorio == 3 )
				{
					printf("\n\n **** FILTRO ****\n");
						
					printf("\n1-Todas as Empresas");
					printf("\n2-Por Empresa");
					printf("\n3-Retornar\n");
					printf("Opcão: ");
					scanf("%d", &OpcaoRelatorioEmpresa);
					
					//inicio do while Relatorio Empresa
					while(OpcaoRelatorioEmpresa != 3)
					{
						if(OpcaoRelatorioEmpresa == 1)
						{
							printf("\nTodos as Empresas\n");
							printf(" _______________________________________");
							printf("\n|Código |Nome                           |");
							printf("\n|_______________________________________|\n");
							
							for(i=0;i<TLE;i++)
								printf("  [%d]   %s\n", vCodigoEmpresa[i] ,vNomeEmpresa[i]);
						}
						if(OpcaoRelatorioEmpresa == 2)
						{
							printf("\nPor empresa\n");
							printf("\nInforme o código da empresa: ");
							scanf("%d",&codigoEmpresa);
							
							posicao=0;
							while(codigoEmpresa != vCodigoEmpresa[posicao] && posicao<TLE)
								posicao++;
									
							if(posicao<TLE)//ACHOU
							{
								printf("\nEMPRESA: %s", vNomeEmpresa[posicao]);
								
								printf("\n _________________________________________________");
								printf("\n|Posição | Cod.Projeto  | Cod.Voluntário | Horas  |");
								printf("\n|_________________________________________________|\n");
								
								contEmpresaHoras=0;
								for(i=0;i<TLH;i++)
								{
									if(codigoEmpresa == vEmpresaHoras[i])
									{
										contEmpresaHoras++;	
										printf("\n|   %d    |      %d      |      %d       |    %d  |",i,vProjetoHoras[i], vVoluntarioHoras[i], vLancamentoHoras[i]);	
									}
									
								}
								if(contEmpresaHoras == 0)
								{
									printf("\n            *** ATENÇÃO ***\n");
									printf("\nESTA EMPRESA NÃO ESTÁ VÍNCULADA COM NENHUM VOLUNTÁRIO. ");
								}
							}
							else//NÃO ACHOU E VAI CADASTRAR
							{
								printf("\n              *** ATENÇÃO ***\n");
								printf("\nEMPRESA NÃO ENCONTRADA EM NOSSO BANCO DE DADOS.\nVOLTE E INFORME UM CÓDIGO VÁLIDO. ");
							}
						}
						if(OpcaoRelatorioEmpresa <0 || OpcaoRelatorioEmpresa >3)
						{
							printf("\n Opcão inválida! Escolha outra opção. ");
						}
						
						printf("\n\n **** FILTRO ****\n");
						printf("\n1-Todas as Empresa");
						printf("\n2-Por Empresa");
						printf("\n3-Retornar\n");
						printf("Opcão: ");
						scanf("%d", &OpcaoRelatorioEmpresa);
						
					}//fim do while Relatorio Empresa
				
			
				}
				if(OpcaoRelatorio == 4 )
				{
					printf("\n **** Excluídos ****\n");
					
					printf("\n%d VOLUNTÁRIOS EXCLUÍDOS\n", contVoluntarioExcluido);
					for(i=0;i<TVX;i++)
						printf("Código: [%d] Nome Voluntário: %s\n",vVoluntarioExcluido[i] ,vNomeVoluntarioExcluido[i]);
						
					printf("\n%d EMPRESAS EXCLUÍDAS\n", contEmpresaExcluida);
					for(i=0;i<TEX;i++)
						printf("Código: [%d] Nome Empresa: %s\n",vEmpresaExcluida[i] ,vNomeEmpresaExcluida[i]);
						
					printf("\n%d PROJETOS EXCLUÍDOS\n", contProjetoExcluido);
					for(i=0;i<TPX;i++)
						printf("Código: [%d] Descrição Projeto: %s\n",vProjetoExcluido[i] ,vDescricaoProjetoExcluido[i]);
					
						
				}
				
				if(OpcaoRelatorio == 5 )
				{
					printf("\n **** Relatório Geral ****\n");
					printf("   ____________________________________");
					printf("\n  |    Relatório: Creche Junqueira     |");
					printf("\n  |____________________________________|");
					
					printf("\n\nVOLUNTÁRIOS\n");
					for(i=0;i<TLV;i++)
						printf("Código: [%d] Nome Voluntário: %s\n",vCodigoVoluntario[i] ,vNomeVoluntario[i]);
					
					printf("\nEMPRESAS\n");
					for(i=0;i<TLE;i++)
						printf("Código: [%d] Nome Empresa: %s\n",vCodigoEmpresa[i] ,vNomeEmpresa[i]);
					
					printf("\nPROJETOS\n");
					for(i=0;i<TLP;i++)
						printf("Código: [%d] Descrição Projeto: %s\n",vCodigoProjeto[i] ,vDescricaoProjeto[i]);	
						
					printf("\n%d VOLUNTÁRIOS EXCLUÍDOS\n", contVoluntarioExcluido);
					for(i=0;i<TVX;i++)
						printf("Código: [%d] Nome Voluntário: %s\n",vVoluntarioExcluido[i] ,vNomeVoluntarioExcluido[i]);
						
					printf("\n%d EMPRESAS EXCLUÍDAS\n", contEmpresaExcluida);
					for(i=0;i<TEX;i++)
						printf("Código: [%d] Nome Empresa: %s\n",vEmpresaExcluida[i] ,vNomeEmpresaExcluida[i]);
						
					printf("\n%d PROJETOS EXCLUÍDOS\n", contProjetoExcluido);
					for(i=0;i<TPX;i++)
						printf("Código: [%d] Descrição Projeto: %s\n",vProjetoExcluido[i] ,vDescricaoProjetoExcluido[i]);
					
					printf("\n\n                  VÍNCULADOS COM HORAS\n");
					printf(" _____________________________________________________________________________________________________________");
					printf("\n| Cod.Voluntário  | Nome Voluntário  | Cod. Empresa |   Nome Empresa   | Cod.Projeto | Nome Projeto  | Horas  |");
					printf("\n|_____________________________________________________________________________________________________________|\n");
								
					for(i=0;i<TLH;i++)
						printf("\n|     %d         |  %s  |      %d      | %s  |     %d      |    %s    |   %d   |" , vVoluntarioHoras[i],vNomeVoluntarioHoras[i],vEmpresaHoras[i],vNomeEmpresaHoras[i], vProjetoHoras[i], vDescricaoProjetoHoras[i], vLancamentoHoras[i] );	
					
					
				}//MENU RELATÓRIO
				if(OpcaoRelatorio <0 || OpcaoRelatorio >6)
				{
					printf("\n Opcão inválida! Escolha outra opção. ");
				}
				
				printf("\n\n ******* MENU *******              \n");
				
				printf("\n1- Relatório Voluntátio");
				printf("\n2- Relatório Projeto");
				printf("\n3- Relatório Empresa");
				printf("\n4- Relatório Excluídos");
				printf("\n5- Relatório Geral");
				printf("\n6- Retornar\n");
				printf("Opcão: ");
				scanf("%d", &OpcaoRelatorio);
				
			}//fim do while 4- Relatorio
		
			
		}//fim da opcao Relatorio
		if(opcaoMenu == 5)//Fim
		{	
			printf("\nDeseja mesmo sair do programa?");
			printf("\nDigite SIM para sair ou NAO para continuar no sistema.\n");
			fflush(stdin); 
			gets(opcaoFim);

			
			if(stricmp(opcaoFim,"sim")==0)
			{  
				printf("\n******************   Fim   ******************     ");	
			}
			if(stricmp(opcaoFim,"nao")==0)
			{
				printf("\n\n ________________ INÍCIO _________________\n");
		
				printf("\n __________________________________________");
				printf("\n|                                          |");
				printf("\n|            CRECHE JUNQUEIRA              |");
				printf("\n|__________________________________________|");
				
				printf("\n\n          ******* MENU *******              \n");
				
				printf("            _______________");
				printf("\n           | 1- Cadastro   |");
				printf("\n           |_______________|");
				
				printf("\n           | 2- Exclusão   |");
				printf("\n           |_______________|");
				
				printf("\n           | 3- Lançamento |");
				printf("\n           |_______________|");
				
				printf("\n           | 4- Relatório  |");
				printf("\n           |_______________|");
				
				printf("\n\nOpcão desejada: ");
				scanf("%d",&opcaoMenu);
	
			}
			
		}
		if(opcaoMenu <0 || opcaoMenu >5)
		{
			printf("\n Opcão inválida! Escolha outra opção. ");
		}
		
									
	}while(opcaoMenu != 5);//fim while inicial	
			
}

			
				
				
			
			
	
	
		

	
		
	

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <locale.h>


//programa principal
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("------------------------------\n");
     printf("1. Insere na lista\n");       
     printf("2. BUSCA da lista\n");
     printf("3. Mostra a lista\n");
     //printf("4. Busca item na lista\n");
     //vamos fazer mais funções, contar, somar, etc
     printf("4. Busca nota\n"); //int conta(Lista *Ls)

     
     //AQUI NÃO PRECISA TIRAR E COLOCAR COMO NA PILHA E NA FILA, TENHO ACESSO TOTAL À FILA PARA MODIFICÁ-LA
     printf("9. Fim\n");
     printf("==> ");
 }   
 
         
main(){
  setlocale(LC_ALL,"Portuguese");
  int opmenu, item, matricula;
  float nota;
  Lista *li=lista_cria();
  Lista *aux;//apenas um ponteiro auxiliar do tipo lista
  do{
     menu();   
     scanf("%d",&opmenu);
     switch(opmenu){
        case 1: //insere
               printf("Informe matricula que deseja adicionar: ");
               scanf("%d",&matricula);
               fflush(stdin);
               printf("Informe nota que deseja adicionar: ");
               scanf("%d",&nota);
              // li=lista_ordenada(li,item);
               li=lista_insere(li,matricula,nota);//insere o novo elemento no início da lista
               break;
        case 2:  //retira
             printf("Informe nota que deseja buscar: ");
             scanf("%d",&nota);
             buscaNota(li,nota);
             break;
        case 3://mostra
		    if(lista_vazia(li))
			   printf("Lista vazia\n");
			else {
		  		  printf("Lista: ");
		          lista_mostra(li);
		      }
            break;
        /*case 4:  
             printf("Informe o item que deseja procurar: ");
             scanf("%d",&item);
             //ponteiro auxiliar para não perder a referencia
             //da lista
             aux=lista_busca(li,item); 
             if(aux==NULL)
                printf("Item %d nao localizado na lista\n",item);
             else
                 printf("Item %d localizado\n",aux->info);
                
             break;*/
        case 4: //conta
        	lista_mostra(li);
        break;
        }//fim switch
   		printf("\n");
   		system("pause");
   }while(opmenu!=9);
   lista_libera(li);
}

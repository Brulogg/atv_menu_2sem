typedef struct lista {
       int matricula;
       float nota;
       struct lista* next;
}Lista;

void buscaNota(Lista *lst, float n){
	Lista *a;   //cria uma Lista auxiliar
	a = lst;     // Atribui o valor de lst para a
	bool notaEncontrada = false;  //cria uma variavel booleana notaEncontrada
	while(a!=NULL){          //enquanto a Lista a for diferente de NULL
		if(a->nota == n){   // se a nota  do aluno for igual a nota n
			printf("A matricula %d possui a nota informada\n",a->matricula); //informa a matricula que possui a nota igual n
			notaEncontrada = true;	//atribui o valor true para a variavel, pois a nota n foi encontrada em pelo menos um aluno
		}
		a=a->next;   //A variável a indica para o próximo elemento da lista
	}
	if(!notaEncontrada){
		printf("Nenhuma matricula possui a nota informada");  //informa se nenhum aluno tiver a nota informada
	}
}

Lista* lista_cria() {
        return NULL;
}
int lista_vazia(Lista* l){
    return(l==NULL);
}

/*Lista* lista_busca(Lista* l, int dado) {     
    Lista *a; //variável usada para percorrer a lista
    for(a=l;a!=NULL;a=a->prox) { 
         if(a->numero == dado) return a;
    }
    return NULL;
}
*/

Lista* lista_insere( Lista* l, int matricula_, float nota_) {//insere no inicio
      Lista *novo= (Lista*) malloc (sizeof(Lista));
      novo->matricula=matricula_;
      novo->nota=nota_;
      novo->next=l;
      return novo;
}

void lista_mostra(Lista* l) {
     Lista *aux;//variável usada para percorrer a lista
     for(aux=l;aux!=NULL;aux=aux->next)
         printf("%d\t", aux->matricula);
     printf("\n");
}         
/*  
Lista* lista_retira(Lista* l, int dado){
      Lista* ant=NULL; //ponteiro para o anterior
      Lista *aux=l;// ponteiro para percorrer a lista  
      //procura o elemento na lista guardando seu anterior
      while(aux!=NULL && aux->numero!=dado) {
            ant=aux;
            aux=aux->prox;
      }
      //verifica se achou o elemento
      if(aux==NULL) {
           printf("\nNAO localizado\n");         
           return l; //não achou - retorna a lista
      }
      //retira o elemento
      if (ant==NULL) //primeiro da lista
         l=aux->next;
      else
        //retira do meio da lista
        ant->prox=aux->next;
      free(aux);
      return l;
}
*/

 
void lista_libera(Lista *l){
     Lista *p,*t;
     p=l;
     while(p!=NULL){
       t=p->next;
       free(p);
       p=t;
     }                           
} 



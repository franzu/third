#include<stdio.h>
#include <stdlib.h>

void quicksort(int v[],int inicio, int fim){
	int pivo, tmp, a, b, r;
	a=inicio;
	b=fim;
	r=rand()%fim;//DETERMINA O PIVO ATRIBUINDO UMA POSI��O ALEATORIA
	pivo=v[r];
	do{
		while(v[a]<pivo)a++;//VETORES ANTES DO PIVO TEM Q SER MENORES QUE O PIVO
		while(v[b]>pivo)b--;//VETORES APOS O PIVO DEVEM SER MAIORES QUE O PIVO
		if(a<=b){//TROCA OS ELEMENTOS 
			tmp=v[a];
			v[a]=v[b];//MENOR NO COME�O E MAIOR NO FIM
			v[b]=tmp;
			a++;
			b--;
		}
	}
	while(b>a);
	
	if(inicio<b) quicksort(v,inicio,b);//RECURS�O PARA ORDENAR A PRIMEIRA PARTE DO
	//VETOR
	if(a<fim) quicksort(v,a,fim);//RECURS�O PARA ORDENAR A SEGUNDA PARTE DO VETOR
}

void freq(int v[],int n){
	int a=0,p,f=0,i,j;
	for(i=0;i<n;i++){
		f=0;
		for(j=0;j<n;j++){
			if(v[i]-v[j]==0){
			f++;
			}
			if(f>=a){a=f;
			p=i;
			}
		}
	}
	if(a!=0){
		printf("o elemento mais frequente eh %d, que se repete %d vezes.",v[p],a);
	}
	if(a==0)printf("nao ha elementos mais frequentes que outros");
}

void main(){
	int n,i,j=0,k;
	int v[101];
	int *pv;
	pv = (int *) calloc(100, sizeof (int));
	v[0]=*pv;
	printf("numero de elementos inteiros do vetor(entre 0 e 100):");
	scanf("%d",&n);//LE O NUMERO DE ELEMENTOS DO VETOR
	if(n==0||n==1)return;
	else{
	printf("digite os inteiros:");
	for(i=0;i<n;i++){
		scanf("%d",&v[i]);//LE TODOS OS N ELEMENTOS
	}
	quicksort(v,0,n-1);	//ORDENA O VETOR EM ORDEM CRESCENTE A PARTIR DA FUN��O CRIADA
	while(j<n){
	printf("%d\n",v[j]);//MOSTRA O VETOR ORDENADO
	j++;
	} 
	freq(v,n);
	free(pv);
}
}

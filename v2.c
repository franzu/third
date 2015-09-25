#include<stdio.h>
#include <stdlib.h>

int v[101], n;

void f(int v[], int n){
	int i, p, s, t;
	i=p=s=t=0;
	
}

void quicksort(int v[],int inicio, int fim){
	int pivo, tmp, a, b, r;
	a=inicio;
	b=fim;
	r=rand()%fim;//DETERMINA O PIVO ATRIBUINDO UMA POSIÇÃO ALEATORIA
	pivo=v[r];
	do{
		while(v[a]<pivo)a++;//VETORES ANTES DO PIVO TEM Q SER MENORES QUE O PIVO
		while(v[b]>pivo)b--;//VETORES APOS O PIVO DEVEM SER MAIORES QUE O PIVO
		if(a<=b){//TROCA OS ELEMENTOS 
			tmp=v[a];
			v[a]=v[b];//MENOR NO COMEÇO E MAIOR NO FIM
			v[b]=tmp;
			a++;
			b--;
		}
	}
	while(b>a);
	
	if(inicio<b) quicksort(v,inicio,b);//RECURSÃO PARA ORDENAR A PRIMEIRA PARTE DO
	//VETOR
	if(a<fim) quicksort(v,a,fim);//RECURSÃO PARA ORDENAR A SEGUNDA PARTE DO VETOR
}
void teste(int v[], int n){
	int i=0,j,k,z;
	while(v[i]==v[i+1]&&k<n){
	i++;
	k++;}
	j=i+1;
	while(v[j]==v[j+1]&&k<n){
	j++;
	k++;	
	}
	z=j+1;
	while(v[z]==v[z+1]&&k<n){
	z++;
	k++;
	}
	if(k==n-1){
	printf("o elemento soh tem 3 elementos distintos que sao os mais frequentes");
		if(k-j<i&&j-i<i)printf("o mais frequente eh %d",v[i]);
			else{if(k-j<j-i&&i<j-i)printf("o mais frequente eh %d",v[j]);
				else{if(k-j>j-i&&i<k-j)printf("o mais frequente eh %d",v[k]);
					else{if(k-j==j-i&&j-i==i)printf("todos tem a mesma frequencia e sao:%d;%d;%d",v[i],v[j],v[k]);
					}
				}
			}
	}	
	f(v,n);
}


void main(){
	int i,j=0,k;
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
	quicksort(v,0,n-1);	//ORDENA O VETOR EM ORDEM CRESCENTE A PARTIR DA FUNÇÃO CRIADA
	while(j<n){
	printf("%d\n",v[j]);//MOSTRA O VETOR ORDENADO
	j++;
	} 
	teste(v,n);
	free(pv);
	getch();
}
}

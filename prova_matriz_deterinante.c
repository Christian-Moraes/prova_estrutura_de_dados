#include<stdio.h>
#define A 3
void Atribui(int[A][A],int*[A]);
void Carregar(int**);
void Determinante(int**,int*);
void Imprimir(int**,int);

int main()
{
    int a[A][A],*ap[A],**app=NULL;
    int deter=0;
    int resultado = 0;
    Atribui(a,ap);
    app=ap;
    Carregar(app);
    Determinante(app,&deter);
    Imprimir(app,deter);
}
void Atribui(int a[A][A], int *ap[A])
{
    int i;
    for(i=0;i<A;++i)
    {
        *(ap+i)=*(a+i);
    }
}

void Carregar(int **app)
{
    int i,j;
       printf("\n\nInsira os números da matriz.\n\n");
       for(i=0;i<A;++i)
       {
           for(j=0;j<A;++j)
           {
               scanf("%d",*(app+i)+j);
           }
       }
}

void Determinante(int **app, int *deter)
{
    *deter=((*(*(app+0)+0)) * (*(*(app+1)+1)) * (*(*(app+2)+2)) + (*(*(app+1)+0)) * (*(*(app+2)+1)) * (*(*(app+0)+2)) + (*(*(app+0)+1)) * (*(*(app+1)+2)) * (*(*(app+2)+0))) - ( *(*(app+0)+2) * *(*(app+1)+1) * *(*(app+2)+0) + *(*(app+0)+1) * *(*(app+1)+0) * *(*(app+2)+2) + *(*(app+1)+2) * *(*(app+2)+1) * *(*(app+0)+0));
}


void Imprimir(int **app,int deter)
{
    int i,j;
    int resultado = 0;
    printf("\n\nMatriz 3x3.\n\n");
    for(i=0;i<A;++i)
    {
        for(j=0;j<A;++j)
        {
            printf("\t%d",*(*(app+i)+j));
        }
        printf("\n");
    }
    
    printf("\n\nO determinante da matiz é igual a: %d\n\n",deter);
    
    for (i = 2; i <= deter / 2; i++) {
        if (deter % i == 0) {
            resultado++;
            break;
        }
    }
    
    if (resultado == 0)
    printf("%d é um número primo\n", deter);
    else
    printf("%d não é um número primo\n", deter);

}

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <locale.h>


int num_digitos, dois_p_digito, ultimodigito, mult_digitos, somafinal, soma, ultimodigito1;
long long int num_cartao, num_cartao1, num_cartao3, num_cartao4;


void ndigitos(void);
void ultimod(void);
void multi(void);
void valido(void);
void dpg(void);


int main(void)
{
    setlocale(LC_ALL, "portuguese");

    do{
        num_cartao = get_long_long("Insira o numero do cartao: ");

    }
    while(num_cartao<1);

    num_cartao1 = num_cartao;

    num_cartao3 = num_cartao;

    num_cartao4 = num_cartao;

    ndigitos();

    dpg();

    valido();

    printf("mult digitos= %d  somafinal = %d dois primeiros digitos = %d  e numero de digitos = %d", mult_digitos, somafinal, dois_p_digito, num_digitos);

}



//NUMERO DE DIGITOS
void ndigitos(void)
{
    while(num_cartao>0)
    {
        num_cartao = num_cartao / 10;

        num_digitos = num_digitos + 1;
    }
}


//DOIS PRIMEIROS DIGITOS
void dpg(void)
{
    dois_p_digito = num_cartao4 / pow(10, num_digitos - 2);
}


//ULTIMO DIGITO
void ultimod(void)
{
    ultimodigito = num_cartao1 % 10;

    ultimodigito1 = num_cartao3 % 10;
}

//MULTIPLICAÇÃO

void multi(void)
{

    while(num_cartao1>0)
    {
        num_cartao1 = num_cartao1 / 10;

        ultimod();

        ultimodigito = ultimodigito * 2;

        if(ultimodigito>9)
        {
            ultimodigito = (ultimodigito % 10) + (ultimodigito/10);
        }

        mult_digitos = mult_digitos + ultimodigito;


        num_cartao1 = num_cartao1/10;

    }

    while(num_cartao3>0)
    {
        ultimod();

        soma = soma + ultimodigito1;

        num_cartao3 = num_cartao3/100;

    }

    somafinal = mult_digitos + soma;
}


//VALIDO OU NAO
void valido(void)
{
    multi();

    if(dois_p_digito == 34 || dois_p_digito == 37 && num_digitos == 15)
    {
        if(somafinal % 10 == 0)
        {
            printf("Cart�o v�lido, este cart�o � da American Express.\n");
        }
        
    }
    else if(dois_p_digito == 51 || dois_p_digito == 52 || dois_p_digito == 53 || dois_p_digito == 54 || dois_p_digito == 55 && num_digitos == 16)
    {
        if(somafinal % 10 == 0)
        {
            printf("Cart�o v�lido, este cart�o � do Master Card.\n");
        }
        
    }
    else if(num_digitos == 13 || num_digitos == 14 || num_digitos == 15 || num_digitos == 16 && dois_p_digito / 10 == 4)
    {
        if(somafinal % 10 == 0)
        {
            printf("Cart�o v�lido, este cart�o � da Visa.\n");
        }
        
    }
    else
    {
        printf("Cart�o inv�lido.\n");
    }
}



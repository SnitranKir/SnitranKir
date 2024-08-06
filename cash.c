#include <stdio.h>
#include <cs50.h>

float divida;
int quant_moedas, vinte_cents, dez_cents, cinco_cents, um_cents;

void calculo_divida(void);
void resultado(void);

int main(void)
{

    do
    {
        divida = get_float("Qual é a quantia devida em reais? \n");
    }
    while(divida<=0);

    calculo_divida();

    do
    {
        resultado();
    }
    while(divida>0);

    printf("quantidade mínima de moedas = %i\n", quant_moedas);
    printf("Sendo: %i", vinte_cents);
    printf(" de 25 centavos, %i", dez_cents);
    printf(" de 10 centavos, %i", cinco_cents);
    printf(" de 5 centavos, %i", um_cents);
    printf(" de 1 centavo.\n");

}


void calculo_divida(void)
{
        divida = divida * 100;
}

void resultado(void)
{
    if(divida>=25)
    {
        quant_moedas = quant_moedas + 1;

        divida = divida - 25;

        vinte_cents = vinte_cents + 1;
    }
    else if(divida<25 && divida>=10)
    {
        quant_moedas = quant_moedas + 1;

        divida = divida - 10;

        dez_cents = dez_cents + 1;
    }
    else if(divida<10 && divida>=5)
    {
        quant_moedas = quant_moedas + 1;

        divida = divida - 5;

        cinco_cents = cinco_cents + 1;
    }
    else
    {
        quant_moedas = quant_moedas + 1;

        divida = divida - 1;

        um_cents = um_cents + 1;
    }
}

//Autor: Luiz G Klitzke

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm> 

using namespace std;

unsigned int uiTotalUnidades = 0;
unsigned int uiProcessos     = 0;
unsigned int uiSaldo         = 0;
vector<pair<unsigned int, unsigned int>> aDados;

void Mostra()
{
    cout << endl << endl;
    cout << "Saldo: " << uiSaldo << endl;
    cout << "Pr\tT\tM\t" << endl;

    for (int i = 0; i < uiProcessos; i++)
    {
        pair<unsigned int, unsigned int>& pDados = aDados[i];
        cout << i + 1 << "\t" << pDados.first << "\t" << pDados.second << endl;
    }
}

int main()
{

    cout << "Informe o total de unidades: ";
    cin >> uiTotalUnidades;
    cout << endl;

    cout << "Informe a quantidade de processos: ";
    cin >> uiProcessos;
    cout << endl;

    uiSaldo = uiTotalUnidades;

    for (int i = 0; i < uiProcessos; i++)
    {
        cout << endl << "Processo Num " << i + 1 << endl;;

        unsigned int uiTem = 0;
        cout << "Informe a quantidade que o processo tem: ";
        cin >> uiTem;

        uiSaldo -= uiTem;

        cout << endl;

        unsigned int uiMaximo = 0;
        cout << "Informe o maximo: ";
        cin >> uiMaximo;

        aDados.push_back(make_pair(uiTem, uiMaximo));
    }

    cout << "Processamento: " << endl;;

    Mostra();

    bool bProcessou = false ;
    bool bSafe      = false;

    while (true)
    {
        bProcessou = false;

        for (int i = 0; i < uiProcessos; i++)
        {
            pair<unsigned int, unsigned int>& pDados = aDados[i];

            if (pDados.first == 0 && pDados.second == 0) //Ja feito
                continue;

            if (uiSaldo + pDados.first >= pDados.second)
            {
                uiSaldo -= (pDados.second - pDados.first);
                pDados.first  = pDados.second;

                Mostra();

                uiSaldo += pDados.first;
                pDados.second = 0;
                pDados.first = pDados.second;

                Mostra();

                bProcessou = true;
            }
        }

        if (bProcessou == false)
        {
            bSafe = uiSaldo == uiTotalUnidades;
            break;
        }
    }

    cout << "Processamento finalizado, sendo: "  << (bSafe ? "safe" : "not safe") << endl;

    bool bSegura;
    cin >> bSegura;
}

//Autor: Liz G Klitzke

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm> 

using namespace std;

 int iTotalUnidades = 0;
 int iProcessos     = 0;
 int iSaldo         = 0;
vector<pair< int,  int>> aDados;

void Mostra()
{
    cout << endl << endl;
    cout << "Saldo: " << iSaldo << endl;
    cout << "Pr\tT\tM\t" << endl;

    for (int i = 0; i < iProcessos; i++)
    {
        pair< int,  int>& pDados = aDados[i];
        cout << i + 1 << "\t" << pDados.first << "\t" << pDados.second << endl;
    }
}

int main()
{

    cout << "Informe o total de unidades: ";
    cin >> iTotalUnidades;
    cout << endl;

    cout << "Informe a quantidade de processos: ";
    cin >> iProcessos;
    cout << endl;

    iSaldo = iTotalUnidades;

    for (int i = 0; i < iProcessos; i++)
    {
        cout << endl << "Processo Num " << i + 1 << endl;;

         int iTem = 0;
        cout << "Informe a quantidade que o processo tem: ";
        cin >> iTem;

        iSaldo -= iTem;

        cout << endl;

         int iMaximo = 0;
        cout << "Informe o maximo: ";
        cin >> iMaximo;

        aDados.push_back(make_pair(iTem, iMaximo));
    }

    cout << "Processamento: " << endl;;

    Mostra();

    bool bProcessou = false ;
    bool bSafe      = false;

    if (iSaldo < 0)
    {
        bSafe = false;
    }
    else
    {
        while (true)
        {
            bProcessou = false;

            for (int i = 0; i < iProcessos; i++)
            {
                pair< int, int>& pDados = aDados[i];

                if (pDados.first == 0 && pDados.second == 0) //Ja feito
                    continue;

                if (iSaldo + pDados.first >= pDados.second)
                {
                    iSaldo -= (pDados.second - pDados.first);
                    pDados.first = pDados.second;

                    Mostra();

                    iSaldo += pDados.first;
                    pDados.second = 0;
                    pDados.first = pDados.second;

                    Mostra();

                    bProcessou = true;
                }
            }

            if (bProcessou == false)
            {
                bSafe = iSaldo == iTotalUnidades;
                break;
            }
        }
    }

    cout << "Processamento finalizado, sendo: "  << (bSafe ? "safe" : "not safe") << endl;

    bool bSegura;
    cin >> bSegura;
}

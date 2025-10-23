#include <iostream>
#include <ctime>
#include <vector>

using namespace std;



int main() 
{
    srand(time(0));   
    int N, i, j, t, u;
    bool scambio;

    cout << "Quanti numeri generare?" << endl;
    cin >> N;
    i = 0;
    vector<int> Vp(N);
    vector<int> Vd(N);
    int p, d;

    p = 0;
    d = 0;
    int x;

    while (i < N)
    {
        x = rand() % (N * 10) + 1;
        if (x % 2 == 0) {
            Vp[p] = x;
            p = p + 1;
        } else {
            Vd[d] = x;
            d = d + 1;
        }
        i = i + 1;
    }
    i = 0;
    scambio = true;
    while (i <= p - 1 && scambio)
    {
        scambio = false;
        j = 0;
        while (j <= p - 2 - i) 
        {
            if (Vp[j] > Vp[j + 1]) 
            {
                t = Vp[j];
                Vp[j] = Vp[j + 1];
                Vp[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    cout << "Ordinamento numeri pari:" << endl;
    while (i < p) 
    {
        cout << Vp[i] << endl;
        i = i + 1;
    }
    j = 0;
    i = 0;
    scambio = true;
    while (i <= d - 1 && scambio) 
    {
        scambio = false;
        j = 0;
        while (j <= d - 2 - i) 
        {
            if (Vd[j] > Vd[j + 1])
            {
                t = Vd[j];
                Vd[j] = Vd[j + 1];
                Vd[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    cout << "Ordinamento numeri dispari:" << endl;
    while (i < d) 
    {
        cout << Vd[i] << endl;
        i = i + 1;
    }

    // merge
    vector<int> Vu(p+d);

    u = 0;
    i = 0;
    j = 0;
    while (i <= p - 1 && j <= d - 1)
    {
        if (Vp[i] > Vd[j])
        {
            Vu[u] = Vp[i];
            i = i + 1;
        } else {
            Vu[u] = Vd[j];
            j = j + 1;
        }
        u = u + 1;
    }
    while (i <= p - 1)
    {
        Vu[u] = Vp[i];
        u = u + 1;
        i = i + 1;
    }
    while (j <= d - 1) {
        Vu[u] = Vd[j];
        u = u + 1;
        j = j + 1;
    }

    // riordinamento dopo merge
    t = 0;
    i = 0;
    j = 0;
    scambio = true;
    while (i <= u - 1 && scambio)
    {
        scambio = false;
        j = 0;
        while (j <= u - 2 - i)
        {
            if (Vu[j] > Vu[j + 1])
            {
                t = Vu[j];
                Vu[j] = Vu[j + 1];
                Vu[j + 1] = t;
                scambio = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    i = 0;
    cout << "Riordinamento del vettore unito:" << endl;
    while (i < u)
    {
        cout << Vu[i] << endl;
        i = i + 1;
    }
    int valore;

    cout << "Inserisci il valore da cercare" << endl;
    cin >> valore;

    // ricerca binaria
    int numControlli, inizio, fine, medio, indice;

    numControlli = 0;
    indice = -1;
    inizio = 0;
    fine = N - 1;
    while (inizio <= fine && indice == -1) 
    {
        medio = (inizio * (fine - inizio) / 2);
        numControlli = numControlli + 1;
        if (valore == Vu[medio]) 
        {
            indice = medio;
        } else
        {
            numControlli = numControlli + 1;
            if (valore > Vu[medio]) 
            {
                inizio = medio + 1;
            } else 
            {
                fine = medio - 1;
            }
        }
    }
    cout << "Controlli eseguiti: " << numControlli << endl;
    if (indice != -1) 
    {
        cout << "Il valore " << Vu[indice] << " è stato trovato nella cella " << indice << endl;
    } else 
    {
        cout << "Il valore " << valore << " non è presente nel vettore." << endl;
    }
    
}

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

struct Event // Struct que representa os eventos
{
    int yL, yR; // Armazena o intervalo da coordenada y desse evento
    int x, type;

    Event(int x, int yL, int yR, int type):
        x(x), yL(yL), yR(yR), type(type) {}

    bool operator < (Event& a) const
    {
        if (x != a.x)
            return x < a.x; // Ordena por coordenada x

        return type < a.type; // Ordena pelo tipo
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Event> sweep; // Armazena todos os eventos

    // Lê todos os retângulos
    for (int i = 0; i < n; i++)
    {
        int xD, yD, xU, yU;
        cin >> xD >> yD >> xU >> yU;

        sweep.push_back(Event(xD, yD, yU, 0)); // Cria o evento "Entrada de um retângulo" desse retângulo
        sweep.push_back(Event(xU, yD, yU, 2)); // Cria o evento "Saída de um retângulo" desse retângulo
    }

    // Lê todos os pontos
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        sweep.push_back(Event(x, y, y, 1)); // Cria o evento "Pontos" desse ponto
    }

    sort(sweep.begin(), sweep.end()); // Ordena os nossos eventos

    int ans = 0;
    set<pair<int,int>> intervals; // Armazena todos os intervalos ativos

    // Itera por todos os nossos eventos (line sweep)
    for (int i = 0; i < (int)sweep.size(); i++)
    {
        int type = sweep[i].type;
        int L = sweep[i].yL, R = sweep[i].yR;

        if (type == 0) intervals.insert({L, R}); // Processando "Entrada de um retângulo"
        if (type == 1) // Processando "Pontos"
        {
            // Procura pelo primeiro intervalo com começo maior que L
            set<pair<int,int>>::iterator it = intervals.upper_bound({L+1, 0});

            // Olha para o intervalo anterior ao procurado
            if (it != intervals.begin())
            {
                it--;

                if (it->first <= L && L <= it->second)
                    ans++;
            }
        }
        if (type == 2) intervals.erase({L, R}); // Processando "Saída de um retângulo"
    }

    cout << "Número de pontos cobertos: " << ans << endl;
}

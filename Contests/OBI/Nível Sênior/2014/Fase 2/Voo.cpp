#include <bits/stdc++.h>

using namespace std;

//Quantidade de Minutos no Dia = 24*60 = 1440 minutos
#define mod 1440

int ler_horario_minutos(){
    int h, m; char ch;
    cin >> h >> ch >> m;
    return (h*60+m);
}

int ajustando_fuso(int a, int fuso){
    return ((a+fuso)+mod)%mod;
}

int qtd_horas(int a, int b){
    if(b < a) b += mod;
    return b-a;
}

int main(){
    int pa = ler_horario_minutos();
    int cb = ler_horario_minutos();
    int pb = ler_horario_minutos();
    int ca = ler_horario_minutos();
    int tot = mod*10, fuso;
    for(int i = -11; i <= 12; i++){
        int tot_min = i*60;
        if(qtd_horas(pa, ajustando_fuso(cb, -tot_min)) == qtd_horas(ajustando_fuso(pb, -tot_min), ca)){
            if(qtd_horas(pa, ajustando_fuso(cb, -tot_min)) < tot){
                tot = qtd_horas(pa, ajustando_fuso(cb, -tot_min));
                fuso = i;
            }
        }
    }
    cout << tot << " " << fuso << "\n";
    return 0;
}

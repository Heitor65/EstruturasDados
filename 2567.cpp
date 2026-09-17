#include <iostream>
#incldue <vector>
using namespace std;

int whichMaior(vector<int> vetor){
    int maior = -1;
    for(int i : vetor){
        if(i > maior){
            maior = i;
        }
    }
    return maior;
}

int whichMenor(vector<int> vetor){
    int menor = -1;
    for(int i : vetor){
        if(i < menor){
            menor = i;
        }
    }
    return menor;
}

int main() {

    int n;

    while(cin >> n){
        int a;
        cin >> a;
        vector<int> idades;
        for(int i = 0; i < a;i++){
            int b;
            cin >> b;
            idades.push_back(b);
        }
        while(idades.size() > 1){
            int maior = whichMaior(idades);
            int menor = whickMenor(idades);
            idades.pop()
        }
    }
}

#include <vector>
#include <iostream>

using namespace std;

void bubble(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        bool isOrdenado = true;
        for(int j = 0; j < v.size() - i -1 ; j++){
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
                isOrdenado = false;
            }
        }
        if(isOrdenado){
            break;
        }
        
    }
}

void selection(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        int menor = i;
        for(int j = i+1; j < v.size(); j++){
            if(v[menor] > v[j]){
                menor = j;
            }
        }
        swap(v[menor], v[i]);
    }
}

void insertion(vector<int>& v){
    for(int i = 1; i < v.size(); i++){
        int key = v[i];
        int j = i-1;
        while(j >= 0 && key < v[j]){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}


int main() {
    vector<int> arr = {7, 3, 4, 5, 3, 4};

    insertion(arr);
    for(int i : arr){
        cout << i << " ";
    }
    
    return 0;
}
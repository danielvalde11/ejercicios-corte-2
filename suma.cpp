#include <iostream>
#include<cmath>
#include<vector>
using namespace std;
int main() {
    int n;
    cout<<"Ingresa el numero de elementos: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Ingresa los elementos: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int target, j;
    cout<<"Ingresa el numero a buscar: ";
    cin>>target;
    for(int i=0; i<n; i++){
        for(j=i+1; j<n;j++){
            if(arr[i]+arr[j]==target){
                cout<<"Indices encontrados: "<<i<<" y "<<j<<endl;
                return 0;
            }
        }
    }
    cout<<"No se encontraron indices que sumen el numero objetivo."<<endl;
    return 0;
}
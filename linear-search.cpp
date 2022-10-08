#include<iostream>
using namespace std;

bool search(int arr[], int size, int key){

    for(int i=0; i<size ; i++){
        if (arr[i]==key){
            
            return 1;
        }
        
    }
    return 0;
}

int main(){
    int arr[10] = {3,5,6,7,8,-3,-8,-1,53,4};

    int key;
    cout<<"Enter the Key you want to search ";
    cin>>key;

    bool found = search(arr,15,key);

    if (found){
        cout<< "Key is Present ";
    }
    else{
        cout<<"Key is absent";
        }
}

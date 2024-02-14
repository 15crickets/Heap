#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void add(int (&nums)[100], int numNums);
void remove(int (&nums)[101]);
void sort(int (&nums)[101]);


int main(){
  cout << "Are you entering data by console or by file? Type c for console and f for file" << endl;
  char method;
  cin >> method;
  cin.get();
  if(method == 'c'){
    cout << "How many numbers will you be inputting? " << endl;
    int numNums;
    cin >> numNums;
    int nums [100];
    for(int i = 0; i < numNums; i++){
      cin >> nums[i];
    }
    cout << nums[4] << endl;    
  }
  if(method == 'f'){
    cout << "F" << endl;
  }
  bool stillRunning = true;
  while(stillRunning == true){
    cout << "What would you like to do: ADD, REMOVE, REMOVE ALL, PRINT" << endl;
    char choice [15];
    cin.get(choice, 15);
    cin.get();
    if(strcmp(choice, "ADD") == 0){
      cout << "WEVIBE" << endl;

    }
    if(strcmp(choice, "REMOVE") == 0){
      cout << "REMOVE" << endl;
    }
  }

}

void sort(int (&nums)[101]){


}
void add (int (&nums)[101], int numNums){



}

void remove(int (&nums)[101]){




}


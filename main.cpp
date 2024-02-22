#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;

void add(int (&nums)[101], int &numTracker, int value);
void remove(int (&nums)[101], int &numTracker);
void sort(int (&nums)[101], int index);
void display(int nums [101], int numTracker);
void deleteSort(int (&nums)[101], int numTracker, int index);

int main(){
  cout << "Are you entering data by console or by file? Type c for console and f for file" << endl;
  char method;
  cin >> method;
  cin.get();
  int numTracker = 0;
  int nums[101];
  if(method == 'c'){
    cout << "How many numbers will you be inputting? " << endl;
    int numNums;
    cin >> numNums;
    cin.get();
    nums[0] = 599;
    for(int i = 0; i < numNums; i++){
      int x = 0;
      cin >> x;
      cin.get();
      nums[numTracker] = x;
      cout << "X: " << x          << endl;
      add(nums, numTracker, nums[numTracker]);
      
    }
    cout << nums[1] << nums[2] << nums [3] << endl;
    display(nums, numTracker);    
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
      remove(nums, numTracker);
    }
    if(strcmp(choice, "PRINT") == 0){
      display(nums, numTracker);
    }
  }

}

void sort(int (&nums)[101], int index){
  int reducedIndex = floor(index/2);
  cout << "REDUCEDINDEX: " << reducedIndex << endl;
  if(reducedIndex == 0){
    return;
  }
  if(nums[index] > nums[reducedIndex]){
    int temp = nums[index];
    nums[index] = nums[reducedIndex];
    nums[reducedIndex] = temp;
    sort(nums, reducedIndex);
  }
  return;
  
}
void deleteSort(int (&nums)[101], int numTracker, int index){
  int leftTotal = 0;
  int rightTotal = 0;
  if(2*index <= numTracker){
    if(nums[index] < nums[2*index]){
      leftTotal = nums[2*index] - nums[index];
    
    }
  }
  if(2*index + 1 <= numTracker){
    if(nums[index] < nums[2*index + 1]){
      rightTotal = nums[2*index + 1] - nums[index];

    }
  }
  if(2*index <= numTracker){
    if(leftTotal >= rightTotal){
      int temp = nums[index];
      nums[index] = nums[2*index];
      nums[2*index] = temp;
      deleteSort(nums, numTracker, 2*index);
    }
  }
  if(2*index + 1 <= numTracker){
    if(rightTotal > leftTotal){
      int temp = nums[index];
      nums[index] = nums[2*index + 1];
      nums[2*index + 1] = temp;
      deleteSort(nums, numTracker, 2*index + 1);
    }
  }
  return;
}
void add (int (&nums)[101], int &numTracker, int value){
  nums[numTracker + 1] = value;
  cout << "NUMTRACKER: " << numTracker << "VALUE: " << value << endl;
  sort(nums, numTracker);
  numTracker++;
  return;
}

void remove(int (&nums)[101], int &numTracker){
  cout << "NUMTRACKER " << numTracker << endl;
  cout << "NUMTRACKER VALUE: " << nums[numTracker] << endl;
  int value = nums[numTracker];
  nums[1] = value;
  nums[numTracker] = -1;
  numTracker = numTracker - 1;
  deleteSort(nums, numTracker, 1);
  



}

void display(int nums [101], int numTracker){
  for(int i = 1; i < numTracker; i++){
    cout << nums[i];

  }
  
}


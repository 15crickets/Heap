/*
Author: Vikram Vasudevan
Date: 2/26/2024
Description: This program takes in integer inputs and arranges them in a max heap data structure.

 */

#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#include "fstream"
using namespace std;

//function prototypes
void add (int (&nums)[101], int &numTracker);
void addMethod (int (&nums)[101], int &numTracker, int value);
void remove(int (&nums)[101], int &numTracker);
void sort(int (&nums)[101], int index);
void display(int nums [101], int numTracker, int count, int index);
void deleteSort(int (&nums)[101], int numTracker, int index);
void removeAll(int (&nums)[101], int &numTracker);

//main
int main(){
  //initializing variables + arrays.
  int numTracker = 0;
  int nums[101];
  bool stillRunning = true;
  //while loop where program runs until quit.
  while(stillRunning == true){
    //inputting user choice
    cout << "What would you like to do: ADD, REMOVE, REMOVE ALL, PRINT, or QUIT" << endl;
    char choice [15];
    cin.get(choice, 15);
    cin.get();
    if(strcmp(choice, "ADD") == 0){
      numTracker = numTracker + 1;
      add(nums, numTracker);
 
    }
    if(strcmp(choice, "REMOVE") == 0){
      remove(nums, numTracker);
    }
    if(strcmp(choice, "PRINT") == 0){
      display(nums, numTracker, 0, 1);
    }
    if(strcmp(choice, "REMOVE ALL") == 0){
      removeAll(nums, numTracker);
    }
    if(strcmp(choice, "QUIT") == 0){
      stillRunning = false;
    }
  }

}
//function that removes everything from the table
void removeAll(int (&nums)[101], int &numTracker){
  while(numTracker > 0){
    remove(nums, numTracker);
  }


}

//add function
void add (int (&nums)[101], int &numTracker){
  //determining add method
  cout << "Are you entering data by console or by file? Type c for console and f for file" << endl;
  char method;
  cin >> method;
  cin.get();
  if(method == 'c'){
    //determininig the number of numbers to add.
    cout << "How many numbers will you be inputting? " << endl;
    int numNums;
    cin >> numNums;
    cin.get();
    //adding the numbers into the nums array.
    for(int i = 0; i < numNums; i++){
      int x = 0;
      cin >> x;
      cin.get();
      nums[numTracker] = x;
      addMethod(nums, numTracker, nums[numTracker]);
      
    }
    numTracker = numTracker - 1;
    display(nums, numTracker, 0, 1);    
  }
  //handling inputting by file
  else if(method == 'f'){
    ifstream fin("numbers.txt");
    
    while(fin >> nums[numTracker]){
      sort(nums, numTracker);
      numTracker++;
    }
    numTracker = numTracker - 1;
  }
  
}

//this function sorts the table after a new number has been added.
void sort(int (&nums)[101], int index){
  int reducedIndex = floor(index/2);
  
  if(reducedIndex == 0){
    return;
  }
  
  //swapping values and recalling the function.
  if(nums[index] > nums[reducedIndex]){
    int temp = nums[index];
    nums[index] = nums[reducedIndex];
    nums[reducedIndex] = temp;
    sort(nums, reducedIndex);
  }
  return;
  
}

//this function sorts the table after the remove function is called.
void deleteSort(int (&nums)[101], int numTracker, int index){
  int leftTotal = 0;
  int rightTotal = 0;
  //calculating whether a sort needs to occur.
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
  //sorting and recalling the function.
  if(2*index <= numTracker){
    if(leftTotal > rightTotal){
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
//this method adds a number to the end of the array and increments numTracker.
void addMethod (int (&nums)[101], int &numTracker, int value){
  nums[numTracker + 1] = value;
  sort(nums, numTracker);
  numTracker++;
  return;
}

//this method swaps the first and last numbers and then removes the new last number, before calling the function that sorts the table.
void remove(int (&nums)[101], int &numTracker){
  cout << "Number removed: " << nums[1] << endl;
  int value = nums[numTracker];
  nums[1] = value;
  nums[numTracker] = -1;
  numTracker = numTracker - 1;
  deleteSort(nums, numTracker, 1);
}

//this function prints the table.
void display(int nums [101], int numTracker, int count, int index){
  if((index*2) + 1 <= numTracker){
    display(nums, numTracker, count + 1, (index*2) + 1);
  }
  //tabbing over the appropriate number based on the number of times recursion has occurred.
  for(int i = 0; i < count; i++){
    cout << '\t';
  }
  if(numTracker != 0){
    cout << nums[index] << endl;
  }
  if((index * 2) <= numTracker){
    display(nums, numTracker, count + 1, (index * 2));
  }
  
    
}


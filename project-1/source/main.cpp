#include <iostream>
#include "linked_list.h"
using namespace std;

// when compiling cd into source then type in the command line(make all) then ./a.out

int main(int argc, char** argv) {
  // makes the linked list and the variables for the switch case
  LinkedList<int> list;
  int num = 0;
  char letter = 'z';

  // menu
  do{
    // Tells you what the different options are 
    cout << "Enter which letter option you would like to choose:" << endl;
    cout << "a.) Add an element to list" << endl;
    cout << "p.) Show the whole list" << endl;
    cout << "r.) Reverse the list" << endl;
    cout << "d.) Delete the first element of list" << endl;
    cout << "q.) Exit" << endl;
    // stores what the user has entered
    cin >> letter;
    // makes it so that if the user enters a capital letter it still works
    letter = tolower(letter);

    // the switch case activates the different functions 
    switch(letter){
      case 'a':
        // has you list what number you want added to the list
        cout << "Enter the number you want to add: ";
        // stores the users number and puts it into the function to add to the front
        cin >> num;
        list.push_front(num);
          break;

      case 'p':
        // lists all the elements in the linked list
        list.print();
          break;          

      case 'r':
        // reverses the linked list 
        list.reverse();
          break;

      case 'd':
        // deletes the first front element of the linked list
        list.pop_front();
          break;          
    }
    
    // adds a empty line for clarity when you go through the menu again 
    cout << endl;
    // resets the number that is enter if there is one
    num = 0;
  }while (letter != 'q');


  return 0;
  
}



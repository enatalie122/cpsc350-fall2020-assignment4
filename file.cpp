/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//file.cpp is the implementation of the File class.

#include "file.h"

File::File(){
  string file_name_ = "";
  file_contents_ = new DoublyLinkedList<int>();
}

File::~File(){
  delete file_contents_;
}

DoublyLinkedList<int>* File::get_file_contents(){
  return file_contents_;
}

void File::set_file_name(string file_name){
  file_name_ = file_name;
}

void File::ProcessFile(string name){
  set_file_name(name);
  ReadFile();
}

void File::ReadFile(){
  string line;
  ifstream file;
  while (file.is_open() == false){
    file.open(file_name_);
    if (file.is_open()){                      //proceed if we can open the file
      while (getline(file, line)){
        file_contents_->Append(stoi(line));   //adds each line to a DoublyLinkedList
      }
      file.close();
      break;
    } else {                                  //prints an error message if the file cannot be opened
      cout << "Unable to open file." << endl; //and allows the user to enter a different file name..
      cout << "Enter a file name: ";
      cin >> file_name_;
      cout << endl;
    }
  }
}

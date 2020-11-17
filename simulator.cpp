/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//simulator.cpp is the implementation of the Simulator class.

#include "simulator.h"

Simulator::Simulator(){
  clock_ = 0;
  number_of_windows_ = 0;
  student_queue_ = new GenQueue<Student>();
  file_ = new DoublyLinkedList<int>();
  windows_ = new DoublyLinkedList<Window>();
  helped_students_ = new DoublyLinkedList<Student>();
}

Simulator::Simulator(DoublyLinkedList<int> *file){
  clock_ = 0;
  file_ = file;
  number_of_windows_ = file_->GetDataFromPosition(0);
  student_queue_ = new GenQueue<Student>();
  windows_ = new DoublyLinkedList<Window>();
  helped_students_ = new DoublyLinkedList<Student>();
  SetData();
  SetWindows();
}

Simulator::~Simulator(){
  delete student_queue_;
  delete file_;
  delete windows_;
  delete helped_students_;
}

DoublyLinkedList<Student>* Simulator::get_helped_students(){
  return helped_students_;
}

DoublyLinkedList<Window>* Simulator::get_windows(){
  return windows_;
}


void Simulator::Simulate(){
  while(!student_queue_->IsEmpty() || !AllWindowsIdle()){       //Loops until there are no more students in the queue and all of the windows are idle

    for(int i = 0; i < windows_->GetLength(); ++i){             //iterates through each window for every clock tick

      bool received_student = false;                            //used later to determine if a tick should be added to the window's idle time
      Window temp = windows_->GetDataFromPosition(i);
      Window *w = AccessWindow(temp);

      if (!w->IsIdle()) {                                        //if the window is occupied
        w->set_occupied_time(w->get_occupied_time() - 1);        //decrement it's occupied time
        windows_->RemovePosition(i);                             //remove the old window from windows_
        if(i == 0){                                              //and add the updated window to the proper location
          windows_->Prepend(*w);
        } else {
          Window temp = windows_->GetDataFromPosition(i - 1);
          windows_->InsertAfter(*w, temp);
        }
        continue;                                                //exit the current iteration
      }
      if(!student_queue_->IsEmpty()){
        Student s = student_queue_->Peek();
        if(w->IsIdle() && s.get_arrival_time() <= clock_){       //there is a free window and a student currently in line
          received_student = true;                               //marked true so that idle time won't update
          Student *student = AccessStudent(s);
          student->set_help_time(clock_);                        //record the clock tick when the student received help
          helped_students_->Append(*student);
          student_queue_->Dequeue();
          w->set_occupied_time(student->get_time_needed() - 1);  //let the window know how long it will be occupied for
          w->set_key(i);                                         //tell the new window what position it will occupy in windows_
        }
      }
      if (received_student == false){                            //if the window isn't helping anyone during this clock tick
        w->set_idle_time(w->get_idle_time() + 1);                //increment the idle time
      }
      windows_->RemovePosition(i);                               //remove the old window from windows_
      if(i == 0){                                                //and add the updated window to the proper location
        windows_->Prepend(*w);
      } else {
        Window temp = windows_->GetDataFromPosition(i - 1);
        windows_->InsertAfter(*w, temp);
      }
    }
    clock_++;
  }
}

bool Simulator::AllWindowsIdle(){
  for(int i = 0; i < windows_->GetLength(); ++i){
    Window w = windows_->GetDataFromPosition(i);
    if(!w.IsIdle())
      return false;
  }
  return true;
}

Student* Simulator::AccessStudent(Student stu){
  Student *new_student = new Student();
  new_student->set_arrival_time(stu.get_arrival_time());
  new_student->set_time_needed(stu.get_time_needed());
  new_student->set_key(stu.get_key());
  return new_student;
}

Window* Simulator::AccessWindow(Window window){
  Window *new_window = new Window();
  new_window->set_idle_time(window.get_idle_time());
  new_window->set_key(window.get_key());
  new_window->set_occupied_time(window.get_occupied_time());
  return new_window;
}

void Simulator::SetWindows(){
  for(int i = 0; i < number_of_windows_; ++i){
    Window *w = new Window(i);
    windows_->Append(*w);
  }
}

void Simulator::SetData(){
  int number_of_students;
  int clock_tick;
  bool is_clock_tick = true;                              //tracking if the line of the file is a clock tick
  bool is_number_of_students;                             //or an indicator of how many students will arrive
  int student_count = 0;

  for(int i = 1; i < file_->GetLength(); ++i){
    if(is_clock_tick){
      clock_tick = file_->GetDataFromPosition(i);
      is_clock_tick = false;                               //switching bools so that we know the next number indicates how many students will arrive
      is_number_of_students = true;
    } else if (is_number_of_students){
      number_of_students = file_->GetDataFromPosition(i);
      is_number_of_students = false;
    } else {
      student_count++;                                     //tracking how many student objects to crreate based on number of students indicated in file
      Student *s = new Student(i);
      s->set_time_needed(file_->GetDataFromPosition(i));   //update it's variable appropriately
      s->set_arrival_time(clock_tick);
      s->set_key(i);
      student_queue_->Enqueue(*s);                         //add the student to the queue
      if(student_count == number_of_students){             //if we've finished creating students we reset is_clock_tick to indicate the next variable
        is_clock_tick = true;                              //will be a clock tick
        student_count = 0;                                 //reset the student count so we track the next batch of students 
      }
    }
  }
}

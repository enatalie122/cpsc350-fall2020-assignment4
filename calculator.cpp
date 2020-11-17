/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//calculator.cpp is the implementation of the Calculator class.

#include "calculator.h"

Calculator::Calculator(){
  simulator = new Simulator();
  student_wait_times_ = new DoublyLinkedList<int>();
  window_idle_times_ = new DoublyLinkedList<int>();
  mean_student_wait_time_ = 0.0;
  median_student_wait_time_ = 0;
  longest_student_wait_time_ = 0;
  wait_times_over_ten_ = 0;
  mean_window_idle_time_ = 0.0;
  longest_window_idle_time_ = 0;
  idle_times_over_5_ = 0;
}

Calculator::Calculator(Simulator *s){
  simulator = s;
  student_wait_times_ = new DoublyLinkedList<int>();
  window_idle_times_ = new DoublyLinkedList<int>();
  mean_student_wait_time_ = 0.0;
  median_student_wait_time_ = 0;
  longest_student_wait_time_ = 0;
  wait_times_over_ten_ = 0;
  mean_window_idle_time_ = 0.0;
  longest_window_idle_time_ = 0;
  idle_times_over_5_ = 0;
}

Calculator::~Calculator(){
  delete student_wait_times_;
  delete window_idle_times_;
}

void Calculator::Calculate(){
  CalculateWaitTimes();
  CalculateIdleTimes();
  CalculateMedian();
  CalculateStudentMean();
  CalculateWindowMean();
  longest_student_wait_time_ = FindLongestTime(student_wait_times_);
  longest_window_idle_time_ = FindLongestTime(window_idle_times_);
  wait_times_over_ten_ = FindWaitTimes(student_wait_times_, 10);
  idle_times_over_5_ = FindWaitTimes(window_idle_times_, 5);
  PrintCalculations();
}


void Calculator::CalculateWaitTimes(){
  int curr_wait_time;
  Student curr_student;
  DoublyLinkedList<Student> *students = simulator->get_helped_students();
  for(int i = 0; i < students->GetLength(); ++i){
    curr_student = students->GetDataFromPosition(i);
    curr_wait_time = curr_student.get_help_time() - curr_student.get_arrival_time();
    student_wait_times_->Append(curr_wait_time);
  }
}

void Calculator::CalculateIdleTimes(){
  DoublyLinkedList<Window> *temp = simulator->get_windows();
  Window curr_window;
  int curr_time;
  for(int i = 0; i < temp->GetLength(); ++i){
    curr_window = temp->GetDataFromPosition(i);
    curr_time = curr_window.get_idle_time() ;
    window_idle_times_->Append(curr_time);
  }
}

void Calculator::CalculateStudentMean(){
  int number_of_students = 0;
  for(int i = 0; i < student_wait_times_->GetLength(); ++i){
    if(student_wait_times_->GetDataFromPosition(i) != 0){                       //wait times of 0 do not count towards the average
        mean_student_wait_time_ += student_wait_times_->GetDataFromPosition(i);
        number_of_students++;
    }
  }
  if(number_of_students != 0)                                                   //if all students had a wait time of 0 we want to avoid dividing by 0
    mean_student_wait_time_ /= number_of_students;
}

void Calculator::CalculateWindowMean(){
  for(int i = 0; i < window_idle_times_->GetLength(); ++i){
    mean_window_idle_time_ += window_idle_times_->GetDataFromPosition(i);
  }
  mean_window_idle_time_ /= window_idle_times_->GetLength();
}

void Calculator::CalculateMedian(){
  student_wait_times_->Sort();
  if(student_wait_times_->GetLength() % 2 == 0){            //if there are an even number of students average the two middle values to calculate the median
    int temp1 = student_wait_times_->GetDataFromPosition(student_wait_times_->GetLength()/2 - 1);
    int temp2 = student_wait_times_->GetDataFromPosition(student_wait_times_->GetLength()/2);
    median_student_wait_time_ = (temp1 + temp2) / 2;
  } else {
    median_student_wait_time_ = student_wait_times_->GetDataFromPosition(student_wait_times_->GetLength()/2);
  }
}

int Calculator::FindLongestTime(DoublyLinkedList<int> *times){
  int max = times->GetDataFromPosition(0);
  for(int i = 0; i < times->GetLength(); ++i){
    int curr_val = times->GetDataFromPosition(i);
    if(curr_val > max)
      max = curr_val;
  }
  return max;
}

int Calculator::FindWaitTimes(DoublyLinkedList<int> *times, int wait_length){
  int sum = 0;
  for(int i = 0; i < times->GetLength(); ++i){
    int curr_val = times->GetDataFromPosition(i);
    if(curr_val > wait_length)
      sum += 1;
  }
  return sum;
}

void Calculator::PrintCalculations(){
  cout << "1. Mean student wait time: " << mean_student_wait_time_ << endl;
  cout << "2. Median student wait time: " << median_student_wait_time_ << endl;
  cout << "3. Longest student wait time: " << longest_student_wait_time_ << endl;
  cout << "4. Number of students waiting over 10 minutes: " << wait_times_over_ten_ << endl;
  cout << "5. Mean window idle time: " << mean_window_idle_time_ << endl;
  cout << "6. Longest window idle time: " << longest_window_idle_time_ << endl;
  cout << "7. Number of windows idle over 5 minutes: " << idle_times_over_5_ << endl;
}

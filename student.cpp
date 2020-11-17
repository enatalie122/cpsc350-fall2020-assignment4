/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//student.cpp is the implementation of the Student class. 

#include "student.h"

Student::Student(){
  arrival_time_ = 0;
  help_time_ = 0;
  time_needed_ = 0;
  key_ = 0;
}

Student::Student(int key){
  arrival_time_ = 0;
  help_time_ = 0;
  time_needed_ = 0;
  key_ = key;
}

Student::~Student(){}

void Student::set_arrival_time(unsigned int arrival_time){
  arrival_time_ = arrival_time;
}

void Student::set_help_time(unsigned int help_time){
  help_time_ = help_time;
}

void Student::set_time_needed(unsigned int time_needed){
  time_needed_ = time_needed;
}

void Student::set_key(int key){
  key_ = key;
}

unsigned int Student::get_arrival_time(){
  return arrival_time_;
}

unsigned int Student::get_help_time(){
  return help_time_;
}

unsigned int Student::get_time_needed(){
  return time_needed_;
}

int Student::get_key(){
  return key_;
}

bool Student::operator==(Student a){
  return(a.get_key() == key_);
}

bool Student::operator<(Student a){
  return(key_ < a.get_key());
}

bool Student::operator>(Student a){
  return(key_ > a.get_key());
}

ostream& operator<<(ostream& os, const Student& s)
{
    os << s.key_;
    return os;
}

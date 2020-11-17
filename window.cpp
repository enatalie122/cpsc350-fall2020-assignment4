/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//window.cpp is the implementation of the Window class. 

#include "window.h"

Window::Window(){
  occupied_time_ = 0;
  idle_time_ = 0;
  key_ = 0;
}

Window::Window(unsigned int key){
  occupied_time_ = 0;
  idle_time_ = 0;
  key_ = key;
}

Window::~Window(){}

bool Window::IsIdle(){
  if(occupied_time_ > 0)   //if the window is currently helping a student it is not considered idle
    return false;
  return true;
}

void Window::set_idle_time(int idle_time){
  idle_time_ = idle_time;
}

void Window::set_key(unsigned int key){
  key_ = key;
}

void Window::set_occupied_time(unsigned int occupied_time){
  occupied_time_ = occupied_time;
}

int Window::get_idle_time(){
  return idle_time_;
}

unsigned int Window::get_key(){
  return key_;
}

unsigned int Window::get_occupied_time(){
  return occupied_time_;
}

bool Window::operator==(Window w){
  return(w.get_key() == key_);
}

bool Window::operator<(Window w){
  return(key_ < w.get_key());
}

bool Window::operator>(Window w){
  return(key_ > w.get_key());
}

ostream& operator<<(ostream& os, const Window& w)
{
    os << w.key_;
    return os;
}

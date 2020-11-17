/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//student.h is the header file for the Student class.

#ifndef STUDENT
#define STUDENT

#include <iostream>
using namespace std;

/*The Student class simulates a student receiving help at the registrar's office. The student
*object stores data about the student and allows for comparison to other Student objects.
*/
class Student{
public:

  /* Default constructor: Student
  * Sets all unsigned int and int values to 0.
  */
  Student();

  /* Overloaded constructor: Student
  * Sets the key to a specified value and all unsigned int values to 0.
  */
  Student(int key);

  /* Destructor: ~Student
  * Does not delete anything because no pointers are used in the student class.
  */
  ~Student();

  /* Mutator function: set_arrival_time
  * Sets the member variable arrival_time_ to a specified value.
  * Parameters:
  * arrival_time: an unsigned int representing the new value of arrival_time_.
  */
  void set_arrival_time(unsigned int arrival_time);

  /* Mutator function: set_help_time
  * Sets the member variable help_time_ to a specified value.
  * Parameters:
  * help_time: an unsigned int representing the new value of help_time_.
  */
  void set_help_time(unsigned int help_time);

  /* Mutator function: set_time_needed
  * Sets the member variable time_needed_ to a specified value.
  * Parameters:
  * time_needed: an unsigned int representing the new value of time_needed_.
  */
  void set_time_needed(unsigned int time_needed);

  /* Mutator function: set_key
  * Sets the member variable key_ to a specified value.
  * Parameters:
  * key: an int representing the new value of key_.
  */
  void set_key(int key);

  /* Accessor function: get_arrival_time
  * Returns the member variable, arrival_time_.
  * Returns:
  * An unsigned int representing the member variable, arrival_time_.
  */
  unsigned int get_arrival_time();

  /* Accessor function: get_help_time
  * Returns the member variable, help_time_.
  * Returns:
  * An unsigned int representing the member variable, help_time_.
  */
  unsigned int get_help_time();

  /* Accessor function: get_time_needed
  * Returns the member variable, time_needed_.
  * Returns:
  * An unsigned int representing the member variable, time_needed_.
  */
  unsigned int get_time_needed();

  /* Accessor function: get_key
  * Returns the member variable, key_.
  * Returns:
  * An int representing the member variable, key_.
  */
  int get_key();

  /* Operator Overloader: operator==
  * Overloads the == operator to allow for the comparison of two student objects based on their keys
  * Parameters:
  * a: a Student representing the object to be compared to.
  * Returns:
  * A bool representing whether or not the two Students are equal.
  */
  bool operator==(Student a);

  /* Operator Overloader: operator<
  * Overloads the < operator to allow for the comparison of two student objects based on their keys
  * Parameters:
  * a: a Student representing the object to be compared to.
  * Returns:
  * A bool representing whether or not the current object is less than a different student object.
  */
  bool operator<(Student a);

  /* Operator Overloader: operator>
  * Overloads the > operator to allow for the comparison of two student objects based on their keys
  * Parameters:
  * a: a Student representing the object to be compared to.
  * Returns:
  * A bool representing whether or not the current object is greater than a different student object.
  */
  bool operator>(Student a);

  /* Operator Overloader: operator<<
  * Overloads the << operator so the student object can be printed with the cout object.
  * Parameters:
  * os: a reference to an ostream object
  * s: a reference to a student object
  * Returns:
  * A reference to the os ostream object.
  */
  friend ostream& operator<<(ostream& os, const Student& s);

private:

  /* Member variable: arrival_time_
  * An unsigned int representing the clock tick when the student arrives.
  */
  unsigned int arrival_time_;

  /* Member variable: help_time_
  * An unsigned int representing the clock tick when the student gets help from a window.
  */
  unsigned int help_time_;

  /* Member variable: time_needed_
  * An unsigned int representing the amount of time the student will spend at a window.
  */
  unsigned int time_needed_;

  /* Member variable: key_
  * An int representing a unique number given to each student. This number is used to distinguish one
  * student from another since multiple students could theoretically have the same arrival time, help
  * time, and and time needed. 
  */
  int key_;

};
#endif

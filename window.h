/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//window.h is the header file of the Window class.

#ifndef WINDOW
#define WINDOW

#include "student.h"
using namespace std;

/*The Window class simulates a window in the registrar's office. The Window
*object stores data about the window and allows for comparison to other Window objects.
*/
class Window{
public:

  /*Default constructor: Window
  * Sets all unsigned int and int values to 0.
  */
  Window();

  /*Overloaded constructor: Window
  * Sets the key to a specified value and all other unsigned int and int values to 0.
  */
  Window(unsigned int key);

  /* Destructor: ~Window
  * Does not delete anything because no pointers are used in the Window class.
  */
  ~Window();


  /* Member function: IsIdle
  * Indicates whether or not the window is occupied with a student.
  * Returns:
  * A bool representing whether or not the window is helping a student.
  */
  bool IsIdle();

  /* Mutator function: set_idle_time
  * Sets the member variable idle_time to a specified value.
  * Parameters:
  * idle_time: an int representing the new value of idle_time.
  */
  void set_idle_time(int idle_time);

  /* Mutator function: set_key
  * Sets the member variable key_ to a specified value.
  * Parameters:
  * key: an unsigned int representing the new value of key_.
  */
  void set_key(unsigned int key);

  /* Mutator function: set_occupied_time
  * Sets the member variable occupied_time_ to a specified value.
  * Parameters:
  * occupied_time: an unsigned int representing the new value of occupied_time_.
  */
  void set_occupied_time(unsigned int occupied_time);

  /* Accessor function: get_idle_time
  * Returns the member variable, idle_time_.
  * Returns:
  * An int representing the member variable, idle_time_.
  */
  int get_idle_time();

  /* Accessor function: get_key
  * Returns the member variable, key_.
  * Returns:
  * An unsigned int representing the member variable, key_.
  */
  unsigned int get_key();

  /* Accessor function: get_occupied_time
  * Returns the member variable, occupied_time_.
  * Returns:
  * An unsigned int representing the member variable, occupied_time_.
  */
  unsigned int get_occupied_time();

  /* Operator Overloader: operator==
  * Overloads the == operator to allow for the comparison of two window objects based on their keys
  * Parameters:
  * a: a Window representing the object to be compared to.
  * Returns:
  * A bool representing whether or not the two Windows are equal.
  */
  bool operator==(Window w);

  /* Operator Overloader: operator<
  * Overloads the < operator to allow for the comparison of two window objects based on their keys
  * Parameters:
  * a: a Window representing the object to be compared to.
  * Returns:
  * A bool representing whether or not the current object is less than a different window object.
  */
  bool operator<(Window w);

  /* Operator Overloader: operator>
  * Overloads the > operator to allow for the comparison of two window objects based on their keys
  * Parameters:
  * a: a Window representing the object to be compared to.
  * Returns:
  * A bool representing whether or not the current object is greater than a different window object.
  */
  bool operator>(Window w);

  /* Operator Overloader: operator<<
  * Overloads the << operator so the window object can be printed with the cout object.
  * Parameters:
  * os: a reference to an ostream object
  * s: a reference to a window object
  * Returns:
  * A reference to the os ostream object.
  */
  friend ostream& operator<<(ostream& os, const Window& w);

private:
  /* Member variable: occupied_time_
  * An unsigned int representing the number of clock ticks it has left until it can help another student.
  */
  unsigned int occupied_time_;

  /* Member variable: key_
  * An unsigned int representing a unique number given to each window. This number is used to distinguish one
  * window from another since multiple windows could theoretically have the same occupied and idle times.
  */
  unsigned int key_;

  /* Member variable: idle_time_
  * An int representing the number of clock ticks the window spent not helping a student. 
  */
  int idle_time_;

};
#endif

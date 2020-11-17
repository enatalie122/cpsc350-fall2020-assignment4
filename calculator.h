/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//calculator.h is the header file for the Calculator class.

#ifndef CALCULATOR
#define CALCULATOR

#include "simulator.h"

//The Calculator class computes summary statistics based on a registrar office simulation.
class Calculator{
public:

  /* Default constructor: Calculator
  * Instantiates a new Simulator and empty DoublyLinkedLists of ints. Sets ints and doubles to 0 and 0.0 respectivly.
  */
  Calculator();

  /* Overloaded constructor: Calculator
  * Points simulator to a given simulator object. Instantiates empty DoublyLinkedLists of ints. Sets ints and doubles to 0 and 0.0 respectivly.
  */
  Calculator(Simulator *s);

  /* Destructor: ~Calculator
  * Deletes all DoublyLinkedLists.
  */
  ~Calculator();

  /* Member function: Calculate
  * Calls numerous helper functions to calculate and print all the summary statistics at once.
  */
  void Calculate();

private:

  /* Helper function: CalculateWaitTimes
  * Calculates how long each student waited in the registrar's office.
  */
  void CalculateWaitTimes();

  /* Helper function: CalculateIdleTimes
  * Adds each window idle time to a DoublyLinkedList.
  */
  void CalculateIdleTimes();

  /* Helper function: CalculateStudentMean
  * Calculates the average time each student waited in line.
  */
  void CalculateStudentMean();

  /* Helper function: CalculateWindowMean
  * Calculates the average amount of time the windows were idle during the simulation.
  */
  void CalculateWindowMean();

  /* Helper function: CalculateMedian
  * Calculates the median wait time for students.
  */
  void CalculateMedian();

  /* Helper function: FindLongestTime
  * Finds the max value in a given DoublyLinkedList of ints.
  * Parameters:
  * times: a pointer to a DoublyLinkedList of ints representing a list of wait times or idle times
  */
  int FindLongestTime(DoublyLinkedList<int> *times);

  /* Helper function: FindWaitTimes
  * Calculates how many times in a list are over a specified number.
  * Parameters:
  * times: a pointer to a DoublyLinkedList of ints representing a list of wait times or idle times
  * wait_length: an int representing an amount of time
  */
  int FindWaitTimes(DoublyLinkedList<int> *times, int wait_length);

  /* helper function: PrintCalculations
  * Prints out summary statistics in a neat format.
  */
  void PrintCalculations();

  /* Member variable: simulator
  * A pointer to a Simulator object that represents a finished simulation.
  */
  Simulator *simulator;

  /* Member variable: student_wait_times_
  * A pointer to a DoublyLinkedList of ints representing how long each student waited in line.
  */
  DoublyLinkedList<int> *student_wait_times_;

  /* Member variable: window_idle_times_
  * A pointer to a DoublyLinkedList of int representing how long each window was idle.
  */
  DoublyLinkedList<int> *window_idle_times_;

  /* Member variable: mean_student_wait_time_
  * A double representing the average amount of time a student waited in line.
  */
  double mean_student_wait_time_;

  /* Member variable: median_student_wait_time_
  * A double representing the median amount of time a student waited in line.
  */
  double median_student_wait_time_;

  /* Member variable: longest_student_wait_time_
  * An int representing the longest student wait time.
  */
  int longest_student_wait_time_;

  /* Member variable: wait_times_over_ten_
  * An int representing how many students waited in line over 10 minutes.
  */
  int wait_times_over_ten_;

  /* Member variable: mean_window_idle_time_
  * A double representing the average amount of time a window was idle.
  */
  double mean_window_idle_time_;

  /* Member variable: longest_window_idle_time_
  * An int representing the longest window idle time.
  */
  int longest_window_idle_time_;

  /* Member variable: idle_times_over_5_
  * An int representing how many windows were idle over 5 minutes. 
  */
  int idle_times_over_5_;

};
#endif

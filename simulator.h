/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//simulator.h is the header file for the Simulator class.

#ifndef SIMULATOR
#define SIMULATOR

#include "gen_queue.h"
#include "window.h"
#include "student.h"

//The Simulator class simulates a window of time at the registrar's office where students are arriving for help.
class Simulator{
public:

  /* Default constructor: Simulator
  * Instantiates empty GenQueues and DoublyLinkedLists, and sets int values to 0.
  */
  Simulator();

  /* Overloaded constructor: Simulator
  * Sets clock_ to 0. Copies the contents of a provided list to file_. Sets the number of windows to the
  * data from the first node in file_. Instantiates an empty GenQueue and empty DoublyLinkedLists.
  * Parameters:
  * file: A DoublyLinkedList of ints representing the contents of a user file.
  */
  Simulator(DoublyLinkedList<int> *file);

  /* Destructor: ~Simulator
  * Deletes all GenQueues and DoublyLinkedLists.
  */
  ~Simulator();

  /* Accessor method: get_helped_students
  * Returns a list of the students who were helped during the simulation.
  * Returns:
  * A pointer to a DoublyLinkedList of Students representing all of the students who were helped.
  */
  DoublyLinkedList<Student>* get_helped_students();

  /* Accessor method: get_windows
  * Returns a list of the windows in the registrar's office.
  * Returns:
  * A pointer to a DoublyLinkedList of Windows representing all of the windows open at the registrar's office,
  */
  DoublyLinkedList<Window>* get_windows();

  /* Member function: Simulate
  * Runs the simulation of students arriving and receiving help at the registrar's office.
  */
  void Simulate();

private:
  /* Helper function: SetWindows
  * Creates and adds the number of windows specified in the user file to windows_.
  */
  void SetWindows();

  /* Helper function: SetData
  * Allocates the data specified in the user file to Student objects.
  */
  void SetData();

  /* Helper function: AllWindowsIdle
  * Indicates whether or not all of the windows are idle at once.
  * Returns:
  * A bool represtenting whether or not all of the windows in the office are idle at the same time.
  */
  bool AllWindowsIdle();

  /* Helper function: AccessStudent
  * Retrieves all the data from one Student object and allocates it to a new Student object.
  * Parameters:
  * stu: a Student object whose information will be copied to a new object
  * Returns:
  * A pointer to a new Student object.
  */
  Student* AccessStudent(Student stu);

  /* Helper function: AccessWindow
  * Retrieves all the data from one Window object and allocates it to a new Window object.
  * Parameters:
  * stu: a Window object whose information will be copied to a new object
  * Returns:
  * A pointer to a new Window object.
  */
  Window* AccessWindow(Window window);

  /* Member variable: student_queue_
  * A pointer to a GenQueue of students representing all of the students waiting to receive help.
  */
  GenQueue<Student> *student_queue_;

  /* Member variable: file_
  * A pointer to a DoublyLinkedList of ints representing the contents of a user file.
  */
  DoublyLinkedList<int> *file_;

  /* Member variable: windows_
  * A pointer to a DoublyLinkedList of Windows representing all of the open windows in the registrar's office.
  */
  DoublyLinkedList<Window> *windows_;

  /* Member b=variable: helped_students_
  * A pointer to a DoublyLinkedList of Students representing all of Student objects after they have received help.
  */
  DoublyLinkedList<Student> *helped_students_;

  /* Member variable: number_of_windows_
  * An int representing the number of open windows at the registrar's office.
  */
  int number_of_windows_;

  /* Member variable: clock_
  * An int representing the current clock tick. 
  */
  int clock_;

};
#endif

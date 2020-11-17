/* Natalie Ewing
 * 2313895
 * ewing@chapman.edu
 * CPSC 350-01
 * Assignment 4: Registrar's Office Simulation
*/

//main.cpp contains the main method for the Registrar's Office Simulation program. 

#include "file.h"
#include "simulator.h"
#include "doubly_linked_list.h"
#include "student.h"
#include "gen_queue.h"
#include "calculator.h"

int main(int argc, char** argv){

  File *file = new File();
  file->ProcessFile(argv[1]);

  Simulator *simulator = new Simulator(file->get_file_contents());
  simulator->Simulate();

  Calculator *c = new Calculator(simulator);
  c->Calculate();

  delete file;
  delete simulator;
  delete c;
}

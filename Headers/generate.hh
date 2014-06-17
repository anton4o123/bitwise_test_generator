#ifndef GENERATE_HH__
#define GENERATE_HH__

#include "basic.hh"

extern vector<string> task_rows;

//---------------------
// name-generate
//---------------------
void generate_a_b(bool a);
void generate_two_easy_hex();
void generate_logic_and_xor(bool AND);
void generate_bitwise_one();
void generate_if_statement();
void generate_result_tasks(bool INT, int down_boundary, int up_boundary, bool XOR);
void generate_gcc_test_file();

#endif

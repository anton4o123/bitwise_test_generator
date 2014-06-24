#ifndef GENERATE_HH__
#define GENERATE_HH__

#include "basic.hh"

extern vector<string> task_rows;
extern vector<string> results;

//---------------------
// name-generate
//---------------------
void generate_a_b(bool a);
void generate_two_easy_hex();
void generate_logic_and_xor(bool AND, short number);
void generate_bitwise_one();
void generate_if_statement(bool easy);
void generate_result_tasks(bool INT, int down_boundary, int up_boundary, bool XOR, short number);
string get_gcc_test_file_result(string variable_name);
void write_in_files(string filename);
void help_writing(int i, short question, string variable_name);
void write_files_for_ruby(int number_of_tests);

#endif

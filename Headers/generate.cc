#include "generate.hh"

void generate_two_easy_hex() {
	stringstream row;
	
	row << "int value1 = 0x";
	for(int i=0;i<4;++i) {
		if(rand()/(RAND_MAX/2)) {
			row << 'F';
		} else {
			row << '0';
		}
	}
	row << ";";
	task_rows.push_back(row.str());
	row.str("");
	row << "int value2 = 0x" << std::hex << rand()/(RAND_MAX/65536) << ";";
	task_rows.push_back(row.str());
}

void generate_a_b(bool a) {
	stringstream row;
	int not_mod_four;
	
	task_rows.clear();
	if(a) {
		task_rows.push_back("a=?      ........");
	} else {
		task_rows.push_back("b=?      ........");
	}
	
	generate_two_easy_hex();
	
	if(a) {
		row << std::dec << "int a = value1 | (value2<<" << (rand()/(RAND_MAX/3)+1)*4 << ");";
	} else {
		do {
			not_mod_four=(rand()/(RAND_MAX/10)+1);
		} while(not_mod_four%4==0);
		row << std::dec << "int b = value1 | (value2<<" << not_mod_four << ");";
	}
	task_rows.push_back(row.str());
}

void generate_logic_and_xor(bool AND) {
	string row_a, row_b;
	
	generate_a_b(true);
	row_a=task_rows.back();
	generate_a_b(false);
	row_b=task_rows.back();
	
	task_rows.clear();
	task_rows.push_back("AND=?    ........");
	generate_two_easy_hex();
	task_rows.push_back(row_a);
	task_rows.push_back(row_b);
	if(AND) {
		task_rows.push_back("int AND=a&b;");
	} else {
		task_rows.push_back("int AND=a^b;");
	}
}

void generate_bitwise_one() {
	stringstream row;
	
	task_rows.clear();
	task_rows.push_back("bit=?    ........");
	row << "int bit = 0x" << std::hex << (rand()/(RAND_MAX/65536)) << " | (1<<" << std::dec << (rand()/(RAND_MAX/14)+1) << ");";
	task_rows.push_back(row.str());
}

void generate_if_statement() {
	stringstream row;
	
	task_rows.clear();
	task_rows.push_back("a=?      ........");
	row << "long value=0x" << std::hex << (rand()) << ";";
	task_rows.push_back(row.str());
	row.str("");
	task_rows.push_back("int a=0;");
	row << "if(value & (1<<" << std::dec << (rand()/(RAND_MAX/14)+1) << ")) {";
	task_rows.push_back(row.str());
	task_rows.push_back("a=1;");
	task_rows.push_back("} else {");
	task_rows.push_back("a=2;");
	task_rows.push_back("}");
}

void generate_result_tasks(bool INT, int down_boundary, int up_boundary, bool XOR) {
	stringstream row;
	short shift_odd, shift_even;
	
	task_rows.clear();
	task_rows.push_back("result=? ........");
	if(!INT) {
		row << "long value1=0x" << std::hex << rand() << ";";
		task_rows.push_back(row.str());
		row.str("");
		row << "long value2=0x" << rand() << std::dec << ";";
	} else {
		row << "long value1=" << (rand()/(RAND_MAX/(up_boundary-down_boundary))+down_boundary) << ";";
		task_rows.push_back(row.str());
		row.str("");
		row << "long value2=" << (rand()/(RAND_MAX/(up_boundary-down_boundary))+down_boundary) << ";";
	}
	task_rows.push_back(row.str());
	row.str("");
	do {
		shift_odd=rand()/(RAND_MAX/14)+1;
		shift_even=rand()/(RAND_MAX/14)+1;
	} while(shift_odd%2==0 || shift_even%2==1);
	if(XOR) {
		row << "int result=(value1<<" << shift_odd << ")^(value2>>" << shift_even << ");";
	} else {
		row << "int result=(value1<<" << shift_odd << ")|(value2>>" << shift_even << ");";
	}
	task_rows.push_back(row.str());
}

void get_gcc_test_file_result() {
	ofstream out("test.c");
	
	out << "#include <stdio.h>\nvoid main() {" << endl;
	for(short i=1;i<task_rows.size();++i) {
		out << task_rows[i] << endl;
	}
	out << "}" << endl;
}

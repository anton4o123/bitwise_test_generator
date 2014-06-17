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

#include "generate.hh"

void generate_a_b(bool a) {
	stringstream row;
	int not_mod_four;
	
	if(a) {
		task_rows.push_back("a=?      ........");
	} else {
		task_rows.push_back("b=?      ........");
	}
	row << "int orig = 0x";
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
	row << "int insert = 0x" << std::hex << rand()/(RAND_MAX/65536) << ";";
	task_rows.push_back(row.str());
	row.str("");
	if(a) {
		row << std::dec << "int a = orig | (insert<<" << (rand()/(RAND_MAX/3)+1)*4 << ");";
	} else {
		do {
			not_mod_four=(rand()/(RAND_MAX/10)+1);
		} while(not_mod_four%4==0);
		row << std::dec << "int a = orig | (insert<<" << not_mod_four << ");";
	}
	task_rows.push_back(row.str());
}

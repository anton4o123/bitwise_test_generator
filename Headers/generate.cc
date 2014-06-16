#include "generate.hh"

void generate_a() {
	stringstream row;
	
	task_rows.push_back("a=?      ........");
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
	row << "int a = orig | (insert<<" << (rand()/(RAND_MAX/3)+1)*4 << ");";
	task_rows.push_back(row.str());
}

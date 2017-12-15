#include "mc.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int vars_[32] = {};
char vars_c[32] = {};

void error_(errors_type t_e);
void read_lines();

using namespace std;

int main() {
	if (err_ = fopen_s(&file_, "script.mc", "r") != 0) {
		error_(errors_type::ERROR_FILE_NO_EXISTS);
	}
	else {
		read_lines();
	}
	system("pause");
	return 0;
}

/*codes*/

void mc_print(string line__) {
	int ok = 0;
	if (line__[5] != '(') {
		error_(errors_type::FUNCTION_NO_EXISTS);
	}
	if (line__[6] != '"') {
		error_(errors_type::FUNCTION_NO_EXISTS);
	}
	for (int i = 0; i <= line__.length(); i++) {
		if (line__[i] != ';') {
			if (line__[i] != '(' && line__[i] != ')' && line__[i] != '"')
			{
				for (int c = 0; c < 5; c++) {
					{
						line__[c] = '\0';

					}
				}
				if (i >= 5) {
					printf("%c", line__[i]);
				}

			}
		}
		else {
			if (line__[line__.length() - 1] == ';' && line__[line__.length() - 2] == ')' && line__[line__.length() - 3] == '"') {
				ok = 1;
				printf("\n");
			}
			break;
		}
	}
	if (ok <= 0) {
		error_(errors_type::SEMICOLON_NO_EXISTS);
	}
}
void mc_for(string line__) {
	int a = line__[6] + line__[7] - 87;
	for (int i = 0; i < a; i++) {
		vars_c[0] = i + '0';
			if (line__[12] == 'p' && line__[13] == 'r' && line__[14] == 'i' && line__[15] == 'n' && line__[16] == 't') {
				for (int x = 18; x < line__.length(); x++) {				
					if (line__[x] == ';') {
						printf("\n");
					}
					if (line__[x] == '%') {
						line__[x + 1] = vars_c[0];
					}
					if (line__[x] != '"' && line__[x] != ')' && line__[x] != ';' && line__[x] != '%') {
						printf("%c", line__[x]);
					}
				}
			}		


	}	
}

/*/*//*/*/

void interpreter(string line__)
{
	if (line__[0] == 'p' && line__[1] == 'r' && line__[2] == 'i' && line__[3] == 'n' && line__[4] == 't') {
		mc_print(line__);
	}
	if (line__[0] == 'f' && line__[1] == 'o' && line__[2] == 'r') {
		mc_for(line__);
	}
}
void read_lines() {
	string line;
	ifstream file__(file_);
	if (file__.is_open()) {
		while (file__.good()) {
			getline(file__, line);
			interpreter(line);

		}
		file__.close();
	}
}
void error_(errors_type t_e) {
	system("cls");
	printf("Error code:[%i], press one key to exit.", t_e);
	char p_te;
	p_te = getchar();
	if (p_te != NULL) {
		exit(0);
	}
}

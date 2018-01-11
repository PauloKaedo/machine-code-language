#include "mc.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//int vars_[128] = {}; OBSELETE
//char vars_c[128] = {}; OBSELETE

using namespace std;

short *vars_c = (short *)malloc(128 * sizeof(short));; // new

void error_(errors_type t_e);
void read_lines();


int main() {
	if (err_ = fopen_s(&file_, "script.mc", "r") != 0) {
		error_(errors_type::ERROR_FILE_NO_EXISTS);
	}
	else {
		read_lines();
	}
	return 0;
}

/*codes*/

void mc_var(string line__)
{
	for (int i = 5; i < line__.length(); i++) {
		if (line__[i] != '(' && line__[i] != ')' && line__[i] != ';' && line__[i] != ',' && line__[i] != '"') {

			int pos = line__[4] - '0';
			vars_c[pos] = line__[i];

		}
	}
}
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
			if (line__[i] != '(' && line__[i] != ')' && line__[i] != '"' && line__[i] != '&')
			{
				for (int c = 0; c < 5; c++) {
					{
						line__[c] = '\0';

					}
				}
				if (i >= 5) {
					if (line__[i - 1] == '&') {
						int a = line__[i] - '0';
						printf("%c", vars_c[a]);
					}
					else {
						printf("%c", line__[i]);
					}
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

	int a = line__[6] - '0';
	int c = line__[7] - '0';

	if (c < 0) {
		c = 0;
	}
	if (a < 0) {
		a = 0;
	}

	a = a * 10 + c;


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
		if (line__[12] == 'v' && line__[13] == 'a' && line__[14] == 'r') {
			for (int x = 18; x < line__.length(); x++) {
				if (line__[x] != '(' && line__[x] != ',' && line__[x] != '"' && line__[x] != ')' && line__[x] != ';') {
					for (int a = 0; a < sizeof(vars_c) / sizeof(vars_c[0]); a++) {
						vars_c[a] = line__[x];
					}
				}
			}
		}


	}
}
void mc_close()
{
	exit(0);
}
void mc_pause()
{
	system("pause");
}
void mc_clear()
{
	system("cls");
}
void mc_if(string line__)
{
	int tempVar=0;
	int tempVarB = 0;
	for (int i = 0; i < line__.length(); i++) {
		if (i >= 2 && i <5) {
			if (line__[i-1] == '&') {
				tempVar = vars_c[line__[i] - '0'];
			}
		}
		if (i >= 8 && i<12) {
			if (line__[i - 1] == '&') {
				tempVarB = vars_c[line__[i] - '0'];
				//printf("%i", tempVarB);
			}
		}
	}
	if (tempVar == tempVarB) {
		vars_c[line__[16] - '0'] = '1';
	}
	else {
		vars_c[line__[16] - '0'] = '0';
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
	if (line__ == "close();" || line__ == "exit();") {
		mc_close();
	}
	if (line__ == "pause();" || line__ == "stop();") {
		mc_pause();
	}
	if (line__ == "clear();" || line__ == "cls();") {
		mc_clear();
	}
	if (line__[0] == 'v' && line__[1] == 'a' && line__[2] == 'r') {
		mc_var(line__);
	}
	if (line__[0] == 'i' && line__[1] == 'f') {
		mc_if(line__);
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
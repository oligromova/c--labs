#include "field-checker.h"

bool check_field(const std::vector<std::vector<int>> &init_field, const std::vector<std::vector<int>> &solution) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (init_field[i][j] != 0 && init_field[i][j] != solution[i][j]) {
                return false;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
    	std::vector <bool> used_line(10, false);
    	std::vector <bool> used_column(10, false);
    	for (int j = 0; j < 9; ++j) {
    	    int current_num_i = solution[i][j];
    	    int current_num_j = solution[j][i];
    	    if (used_line[current_num_i] || used_column[current_num_j]) {
    	        return false;
    	    }
    	    used_line[current_num_i] = true;
    	    used_column[current_num_j] = true;
    	}
    }
    
    for (int square = 0; square < 9; ++square) {
    	std::vector <bool> used_square(10, false);
        for (int i = square / 3 * 3; i < square / 3 * 3 + 3; ++i) {
            for (int j = square / 3 * 3; j < square / 3 * 3 + 3; ++j) {
                int current_num = solution[i][j];
                if (used_square[current_num]) {
                	return false;
                }
                used_square[current_num] = true;
            }
        }
    }

    return true;
}

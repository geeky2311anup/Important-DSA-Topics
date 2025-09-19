#include <bits/stdc++.h>
using namespace std;

// Spreadsheet class as requested
class Spreadsheet {
    // rows is number of rows (1-indexed). 26 columns A..Z mapped to 0..25.
    int rows;
    vector<vector<int>> grid; // grid[row][col]

    // parse a cell reference like "A1" -> pair(colIndex, rowIndex)
    pair<int,int> parseCellRef(const string &s) {
        // s guaranteed to be like Letter(s) + number, but problem guarantees A-Z (single letter)
        int col = s[0] - 'A';                // 'A' -> 0, 'Z' -> 25
        int row = stoi(s.substr(1));         // convert row part (1-indexed)
        return {col, row};
    }

    // parse a token: either a non-negative integer string or a cell ref.
    // returns numeric value of token using current grid (cells default to 0).
    int parseTokenValue(const string &tok) {
        if (!tok.empty() && tok[0] >= 'A' && tok[0] <= 'Z') {
            // cell reference
            auto [col, row] = parseCellRef(tok);
            if (row < 1 || row > rows || col < 0 || col >= 26) return 0;
            return grid[row][col];
        } else {
            // numeric literal
            return stoi(tok);
        }
    }

public:
    // Constructor
    Spreadsheet(int rows_) : rows(rows_) {
        // rows indexed 1..rows; allocate rows+1 for convenience
        grid.assign(rows + 1, vector<int>(26, 0));
    }

    // Set value of a cell like "A1" to value
    void setCell(string cell, int value) {
        auto [col, row] = parseCellRef(cell);
        if (row >= 1 && row <= rows && col >= 0 && col < 26) {
            grid[row][col] = value;
        }
    }

    // Reset specified cell to 0
    void resetCell(string cell) {
        auto [col, row] = parseCellRef(cell);
        if (row >= 1 && row <= rows && col >= 0 && col < 26) {
            grid[row][col] = 0;
        }
    }

    // Evaluate formula "=X+Y" and return sum; X and Y are either integer or cell reference
    int getValue(string formula) {
        // formula guaranteed in "=X+Y" format
        if (formula.empty() || formula[0] != '=') return 0;
        string body = formula.substr(1); // remove '='
        // find '+'
        size_t plusPos = body.find('+');
        string left = (plusPos == string::npos) ? body : body.substr(0, plusPos);
        string right = (plusPos == string::npos) ? string() : body.substr(plusPos + 1);
        // trim (not necessary if inputs are clean)
        // compute values
        int v1 = parseTokenValue(left);
        int v2 = parseTokenValue(right);
        return v1 + v2;
    }
};

// Example usage (not part of the class):
// int main() {
//     Spreadsheet sp(3);
//     cout << sp.getValue("=5+7") << "\n"; // 12
//     sp.setCell("A1", 10);
//     cout << sp.getValue("=A1+6") << "\n"; // 16
//     sp.setCell("B2", 15);
//     cout << sp.getValue("=A1+B2") << "\n"; // 25
//     sp.resetCell("A1");
//     cout << sp.getValue("=A1+B2") << "\n"; // 15
//     return 0;
// }

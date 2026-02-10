#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    int totalRows;
    vector<vector<int>> sheet;   // sheet[row][column]

    // Convert "A1" -> (row, col)
    pair<int, int> decodeCell(const string &cell) {
        int column = cell[0] - 'A';        // column index
        int row = stoi(cell.substr(1));    // row index (1-based)
        return {row, column};
    }

    // Get value from token (either number or cell reference)
    int evaluateToken(const string &token) {
        if (!token.empty() && isalpha(token[0])) {
            auto [row, column] = decodeCell(token);
            if (row >= 1 && row <= totalRows && column >= 0 && column < 26)
                return sheet[row][column];
            return 0;
        }
        return stoi(token);
    }

public:
    Spreadsheet(int r) {
        totalRows = r;
        sheet.assign(totalRows + 1, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [row, column] = decodeCell(cell);
        if (row >= 1 && row <= totalRows && column >= 0 && column < 26) {
            sheet[row][column] = value;
        }
    }

    void resetCell(string cell) {
        auto [row, column] = decodeCell(cell);
        if (row >= 1 && row <= totalRows && column >= 0 && column < 26) {
            sheet[row][column] = 0;
        }
    }

    int getValue(string formula) {
        if (formula.empty() || formula[0] != '=')
            return 0;

        string expr = formula.substr(1);
        int pos = expr.find('+');

        string first = expr.substr(0, pos);
        string second = expr.substr(pos + 1);

        int val1 = evaluateToken(first);
        int val2 = evaluateToken(second);

        return val1 + val2;
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

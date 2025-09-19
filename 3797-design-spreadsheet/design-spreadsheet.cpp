#include <algorithm>

class Spreadsheet {
public:
    int arr[27][1001];

    Spreadsheet(int rows) {
        fill(&arr[0][0], &arr[26][1000], 0);
    }
    
    void setCell(string cell, int value) {
        int col = (int)(cell[0] - 'A');
        int row = stoi(cell.substr(1));
        arr[col][row] = value;
    }
    
    void resetCell(string cell) {
        int col = (int)(cell[0] - 'A');
        int row = stoi(cell.substr(1));
        arr[col][row] = 0;
    }
    
    int getValue(string formula) {
        int A = 0;
        int B = 0;

        int plus_idx = formula.find("+");

        // X가 정수 -> =5+A6
        if(formula[1] >= 'A' && formula[1] <= 'Z') {
            int col = (int)(formula[1] - 'A');
            int row = stoi(formula.substr(2));

            A = arr[col][row];
        }
        else {
            A = stoi(formula.substr(1));
        }

        if(formula[plus_idx+1] >= 'A' && formula[plus_idx+1] <= 'Z') {
            int col = (int)(formula[plus_idx+1] - 'A');
            int row = stoi(formula.substr(plus_idx+2));

            B = arr[col][row];
        }
        else {
            string sub = formula.substr(plus_idx+1);
            B = stoi(sub);
        }

        cout << A << ", " << B << endl;
        return A + B;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
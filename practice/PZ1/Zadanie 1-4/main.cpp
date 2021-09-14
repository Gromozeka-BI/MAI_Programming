#include <iostream>
using namespace std;

class massiv {
private:
    int val;
    int *mas;
public:

    massiv(int a) {
        mas = new int[a];
        val = a;
    };

    
    massiv(massiv& a) {
        mas = new int[a.getVal()];
        val = a.getVal();
        for (int i = 0; i < a.getVal(); i++) {
            input(i, a.outputMasI(i));
        }
    };

    massiv(massiv& a, massiv& b) {
        int minVal;
        if (a.getVal() < b.getVal()) {
            minVal = a.getVal();
        }
        else {
            minVal = b.getVal();
        }
        mas = new int[minVal];
        val = minVal;
        for (int i = 0; i < minVal; i++) {
            input(i, a.outputMasI(i) + b.outputMasI(i));
        }
    };
    

    ~massiv() {
        delete[] mas;
        cout << "dist" << endl;
    };

    void massivNew (int a) {
        mas = new int[a];
        val = a;
    }

    void inputZero() {
        for (int i = 0; i < val; i++) {
            mas[i] = 0;
        }
    }
    void input(int i, int n) {
        if ((i >= 0) && (i <= val))
            if ((n >= -100) && (n <= 100))
                mas[i] = n;
    }

    void output(int i) {
        if ((i >= 0) && (i <= val))
            cout << mas[i] << endl;
        
    }
    int outputMasI(int i) {
        if ((i >= 0) && (i <= val))
            return mas[i];

    }

    void outputAll() {
        for (int i = 0; i < val; i++) {
            cout << mas[i] << " ";
        }
        cout << endl;
    }

    void newValue(int value) {
        if ((value >= -100) && (value <= 100)) {
            int* copy = new int[val + 1];
            for (int i = 0; i < val; i++) {
                copy[i] = mas[i];
            }
            val += 1;
            mas = new int[val];
            for (int i = 0; i < val; i++) {
                mas[i] = copy[i];
            }
            mas[val - 1] = value;
        }
     }

    void setVal(int newVal) {
        val = newVal;
    }

    int getVal() {
        return val;
    }


};





int main(){

    massiv a(10);
    a.inputZero();
    a.input(0, 1);
    a.input(1, 1);
    a.input(3, 1);
    a.outputAll();

    massiv b(a);
    b.newValue(200);
    b.newValue(100);
    b.input(3, 4);
    b.outputAll();

    massiv c(b, a);
    c.outputAll();

    return 0;
}

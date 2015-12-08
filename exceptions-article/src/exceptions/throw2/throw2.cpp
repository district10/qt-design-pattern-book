#include <iostream>

void foo() {
    int  i, j;
    i = 14;
    j = 15;
    throw i;
}

void call_foo() {
    int  k;
    k  = 12;
    foo();
}

int main() {
    using namespace std;
    try {
        cout << "In the outer try block" << endl;
        try {
            call_foo(); /* foo exited with i and j destroyed */
        }
        catch(int n) {
            cout << "I can't handle this exception!" << endl;
            throw;
        }
    } 
    catch(float z) {
        cout << "Wrong catch!" << endl;
    }
    catch(char s) {
        cout << "This is also wrong!" << endl;
    }
    catch(int n) {
        cout << "\ncaught it " << n << endl;
    }
    cout << "Just below the outermost try block." << endl;
}
/*Out
In the outer try block
I can't handle this exception!
 
caught it 14
Just below the outermost try block.
*/

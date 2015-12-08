#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

void memoryEater() {
    int i = 0;
    double* ptr;
    while (1) {
        ptr = new double[50000000];
        cerr << ++i << '\t' ;
    }
}

void out_of_store() {
    cerr << "\noperator new failed: out of store\n";
    exit(1);
}

int main() {
    set_new_handler(out_of_store);
    memoryEater(); 
    cout << "Done!" << endl;
    return 0;
}
/*OUT
src/newfailure> g++ setnewhandler.cpp
src/newfailure> ./a.out
1       2       3       4       5       6       7
operator new failed: out of store
OOP>
*/


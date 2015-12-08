#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

void memoryEater() {
    int i = 0;
    double* ptr;
    try {
        while (1) {
            ptr = new double[50000000];
            cerr << ++i << '\t' ;
        }
    } catch(bad_alloc& excpt) {
        cerr << "\nException occurred: "
        << excpt.what() << endl;
    }
}

void out_of_store() {
    cerr << "\noperator new failed: out of store\n";
    throw bad_alloc();
}

int main() {
    set_new_handler(out_of_store);
    memoryEater(); 
    cout << "Done!" << endl;
    return 0;
}
/*OUT
src/newfailure> g++ bad-alloc2.cpp
src/newfailure> ./a.out
1       2       3       4       5       6       7
operator new failed: out of store
 
Exception occurred: St9bad_alloc
Done!
src/newfailure>
*/


#include <iostream>
#include <new>
using namespace std;

void memoryEater() {
    int i = 0;
    double* ptr;
    while (1) {
        ptr = new (nothrow) double[50000000];
        if (ptr == 0)
            return;
        cerr << ++i << '\t' ;
    }
}

int main() {
    memoryEater(); 
    cout << "Done!" << endl;
    return 0;
}
/*OUT
src/newfailure> g++ nullchecking.cpp
src/newfailure> ./a.out
1       2       3       4       5       6       7      Done!
src/newfailure>
*/


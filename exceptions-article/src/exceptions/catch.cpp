#include  <iostream>
#include  <cstdlib>

using namespace std;

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
    throw ("This is from call_foo");
}

void call_foo2() {
    double  x = 1.3;
    unsigned m = 1234;
    throw (x);
    throw m;
}

int main() {
    try {
      call_foo();
      call_foo2();
    } 
    catch(const char* message) { /* Is const necessary here? */
      cerr << message << endl;
      exit(1);
    }
    catch(int &n) {
      cout << "caught int " << n << endl;
    } 
    catch(double& d) { /* abstract parameter */
        cout << "caught a double:" << d <<  endl;
    }
    catch( ... ) { /* default action to be taken */
      cerr << "ellipsis catch" << endl;
      abort();
    }
}
/*OUT
# with the first throw commented out
src/generic> g++ catch.cpp
src/generic> ./a.out
This is from call_foo
src/generic>  

# with the first two throws commented out
src/generic> g++ catch.cpp
src/generic> ./a.out
caught a double
src/generic>  
 
# with the first three throws commented out
src/generic> g++ catch.cpp
src/generic> ./a.out
ellipsis catch
Aborted
src/generic>  

# with all the throws enabled
src/generic> g++ catch.cpp
src/generic> ./a.out
caught int 14
src/generic>  
*/

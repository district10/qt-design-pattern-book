#include "vector.h"
#include <QTextStream>
#include <QDebug>

QTextStream cout(stdout);


void g (int m) {
    static int counter(0);
    static const int BIGSIZE(50000000), WASTERS(6);
    ++counter;
    try {
        Vector<int>  a(m), b(m), c(m);
        qDebug() << "in try block, doing vector calculations. m= " 
             << m ;
        for (int i = 0; i < m; ++i) {
            a[i] = i;
            b[i] = 2 * i + 1;
        }
        c = a + b;
        qDebug() << c.toString();
        if (counter == 2) 
            int value = c[m];  /* Expect RangeError to be thrown. */
        if (counter ==3) {
            Vector<int> d(2*m);
            for (int i = 0; i < 2*m; ++i)
                d[i] = i * 3;
            c = a + d;  /* Expect SizeMatchError to be thrown.*/
        }
        if (counter == 4) {
            for (int i = 0; i < WASTERS; ++i) /* Use up most of the available  memory. */
                double* ptr = new double(BIGSIZE);
            Vector<int> d(100 * BIGSIZE);
            Vector<int> e(100 * BIGSIZE);  /* Expect bad_alloc to be thrown.*/
             for (int i = 0; i < BIGSIZE; ++i)
                 d[i] = 3 * i;
        }
    } 
    catch(BadSizeError& bse) { /* Always
        catch exception objects by reference. */
        qDebug() << bse.what() ;
    }
    catch(RangeError& rer) {
        qDebug() << rer.what() ;
    }
    catch(SizeMatchError& sme) {
        qDebug() << sme.what();
    }
    catch(...) {
        qDebug() << "Unhandled error! Aborting...";
        abort();
    }
    qDebug() << "This is what happens after the try block." ;
}


int main() {
    g(-5);    /* Expect BadSizeError to be thrown. */
    g(5);
    g(7);
    g(9);
}

/*OUT
src/exceptions/example> ./example
Invalid size for Vector: -5
This is what happens after the try block.
in try block, doing vector calculations. m= 5
<1, 4, 7, 10, 13>
Subscript out of range!
This is what happens after the try block.
in try block, doing vector calculations. m= 7
<1, 4, 7, 10, 13, 16, 19>
Size mismatch for Vector addition!
This is what happens after the try block.
in try block, doing vector calculations. m= 9
<1, 4, 7, 10, 13, 16, 19, 22, 25>
Unhandled error! Aborting...
Aborted
src/exceptions/example> 
*/


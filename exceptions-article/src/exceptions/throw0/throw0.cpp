#include <QString>
#include <QDebug>
#include <math.h>


//start
class NegArg {
  public:
    NegArg(double d) : m_Val(d), m_Msg("Negative value") {}
    QString getMsg() {
        return QString("%1: %2").arg(m_Msg).arg(m_Val);
    }
  private:
    double m_Val;
    QString m_Msg;
};

double discr(double a, double b, double c) {
    double d = b * b - 4 * a * c;
    if (d < 0)
        throw NegArg(d);
    return d;
}

double quadratic_root1(double a, double b, double c) {
    return (-b + sqrt(discr(a,b,c))/(2 * a));
}

int main() {
    try {
        qDebug() << quadratic_root1(1, 3, 1) ;
        qDebug() << quadratic_root1(1, 1, 1) ;
    }
    catch(NegArg& narg) {
        qDebug() << "Attempt to take square root of "
             << narg.getMsg() << endl;
    }
    qDebug() << "Just below the try block." ;
}
/*Out
-1.88197
Attempt to take square root of Negative value: -3
Just below the try block. */

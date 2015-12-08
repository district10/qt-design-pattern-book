#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <QString>
//start
/* a custom exception with no data */
class SizeMatchError {
  public:
    SizeMatchError() {}
    QString what() {
        return "Size mismatch for Vector addition!";
    }
};

/* a custom exception with data */
class BadSizeError {
  public:
    BadSizeError(int sz): m_Sz(sz) {}
    QString what() const {
        return QString("Invalid size for Vector: %1").arg(m_Sz);
    }
    int m_Sz;
};

#include <stdexcept>
using std::exception;

/* a custom exception extending from std::exception */
class RangeError : public exception { 
  public:
    RangeError() {}
    const char* what() const throw() { /* matches base class virtual signature */
        return "Subscript out of range!";
    }
};
//end
#endif 

/*  Selected implementation examples
    This file is not complete! */
#include "registrar.h"

namespace Registrar_Namespace {
    long Student::nextNumber() { /* Without the above using declaration,
         this would be "long Registrar_Namespace::Student::nextNumber" */
         static long number = 1000000;
         return ++number;
    }

    Registrar& Registrar::instance() { /* Implementation of
        Singleton factory method: this is the only way 
        clients can create instances of this Registrar. */
        
        static Registrar onlyInstance;
        return onlyInstance;
    }

    Exception::Exception(const QString& reason) 
        : m_Reason(reason) {}
    
    QString Exception::what() const {
        return m_Reason;
    }
    
    NoNumberException::NoNumberException(const QString& reason) 
        : Exception(reason) {}
    
    NoStudentException::NoStudentException(const QString& reason) 
        : Exception(reason) {}
    
    DupNumberException::DupNumberException(const QString& reason) 
        : Exception(reason) {}
}

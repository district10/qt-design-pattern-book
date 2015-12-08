#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <QString>

namespace Registrar_Namespace {

    class Exception {
    public:
        Exception (const QString& reason);
        virtual ~Exception () { }
        QString what () const;
    private:
        QString m_Reason;
    };

    class NoNumberException : public Exception {
    public:
        NoNumberException(const QString& reason);
    };

    class NoStudentException : public Exception {
    public:
        NoStudentException(const QString& reason);
    };

    class DupNumberException : public Exception {
    public:
        DupNumberException(const QString& reason);
    };

}

#endif        //  #ifndef EXCEPTIONS_H


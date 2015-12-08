#ifndef REGISTRAR_H
#define REGISTRAR_H

//start

#include "exceptions.h"
#include <QStringList>

namespace Registrar_Namespace {
    
    class Student {
    public:
        Student(const QString& name);
        long getNumber() const;
        QString getName() const;
        // other members as needed ...
    private:
        long m_Number; /* student number*/
        QString m_Name;
        static long nextNumber(); /* used by constructor */
    };

    class Registrar {
    public:
        static Registrar& instance();
        void insert(const Student& stu) throw (DupNumberException);
        void insert(const QString& name);
        void remove(const Student& stu) throw (NoStudentException);
        void remove(const long num)     throw (NoNumberException);
        bool isInList(const Student& stu) const;
        bool isInList(const QString& name) const;
        
        QStringList report(QString name="all");
        
        // other members as needed
    private:
        Registrar() {};
        Registrar(const Registrar&); /* private constructors*/
        Registrar& operator=(const Registrar&);
        QList<Student> m_List;

    };
}
//end

#endif        //  #ifndef REGISTRAR_H


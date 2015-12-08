#ifndef VECTOR_H
#define VECTOR_H

/**  Template based  array type with range checking, iterators
     and exception handling.
     Note that member function definitions are in the header file.
*/

//start id="classdef"
#include "exceptions.h"
using std::bad_alloc;
#include <QString>
#include <QStringList>
#include <QTextStream>

template <class T> class Vector {
 public:
    typedef T* iterator;
    explicit Vector(int n = 100) throw(BadSizeError, bad_alloc);
    Vector(const Vector & v) throw(bad_alloc);
    Vector(const T* a, int n) throw(BadSizeError, bad_alloc);
    ~Vector();
    QString toString() const;
    iterator begin() const {
        return m_P;
    }
    iterator end() const {
        return m_P + m_Size;
    }
    T& operator[](int i) throw(RangeError);
    Vector& operator=(const Vector& v) throw(bad_alloc);
    Vector operator+(const Vector& v) const throw(SizeMatchError);
 private:
    int m_Size;
    T* m_P;
    void copy(const T* a, int n) throw(BadSizeError, bad_alloc);
};
//end
//start id="impl"
template <class T> Vector<T>::
Vector(int n) throw(BadSizeError, bad_alloc) : m_Size(n) {
    if(n <= 0)
        throw BadSizeError(n);
    m_P = new T[m_Size];   /* new will throw bad_alloc if it fails. */
}
//end

template <class T> void Vector<T>::
copy(const T* a, int n) throw(BadSizeError, bad_alloc) {
    if(n <= 0)
        throw BadSizeError(n);
    m_Size = n;
    m_P = new T[m_Size];
    for (int i = 0; i < m_Size; ++i)
        m_P[i] = a[i];
}
 
template <class T> Vector<T>::
Vector(const T* a, int n) throw(BadSizeError, bad_alloc) {
    copy(a, n);
}

template <class T> Vector<T>::
Vector(const Vector& v) throw(bad_alloc) {
    copy(v.m_P, v.m_Size);
}

//start id="impl"
template <class T> T& Vector<T>::
operator[](int i) throw(RangeError) {
    if(i >= 0 && i < m_Size )
        return (m_P[i]);
    else
        throw RangeError();
}
//end

template <class T> Vector<T> & Vector<T>::
operator=(const Vector& v) throw(bad_alloc) {
    if(this != &v) {
        delete m_P;
        copy(v.m_P, v.m_Size);
    }
    return *this;
}


//start id="impl"
template <class T> Vector<T> Vector<T>::
operator+(const Vector& v) const throw(SizeMatchError) {
    if(m_Size != v.m_Size) {
        throw SizeMatchError();
    } else {
        Vector sum(m_Size);
        for(int i = 0; i < m_Size; ++i)
            sum.m_P[i] = m_P[i] + v.m_P[i];
        return sum;
    }
}
//end
template <class T> Vector<T>::
~Vector() {
    delete []m_P;
}

#endif

template <class T> QString Vector<T>::
toString() const {
    QString retval;
    QTextStream os(&retval);
    os << '<';
    for (iterator i=begin(); i != end(); ++i) {
        os << *i << ", ";
    }
    os << "\b\b>";
    return retval;
}

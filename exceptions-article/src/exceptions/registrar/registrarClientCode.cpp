#include "registrar.h"
#include <QDebug>

int main() {

    using namespace Registrar_Namespace;
    Registrar& reg = Registrar::instance();
    while (1) {
        try {
            reg.insert("George");
            reg.insert("Peter");
            reg.insert("Mildred");
            Student s("George");
            reg.insert(s);
            reg.remove(1000004);
            reg.remove(1000004);
            reg.remove(s);
            QStringList report = reg.report();
            qDebug() << report.join("\n");
        } catch (NoStudentException& nse) {
            qDebug() << nse.what() ;
        }
        catch (NoNumberException& nne) {
            qDebug() << nne.what() ;
        }
        catch (DupNumberException& dne) {
            qDebug() << dne.what() ;
        }
    }
}

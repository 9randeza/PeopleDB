#include <iostream>
#include "dbmanager.h"
#include "InterfaceDB.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    InterfaceDB object("C:/Users/geyda/Desktop/MyDB/My/people.db");
    object.show();
    return app.exec();
}

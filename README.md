
![](https://img.shields.io/badge/9randeza-%F000000.svg?style=for-the-badge&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Qt](https://img.shields.io/badge/Qt-%23217346.svg?style=for-the-badge&logo=Qt&logoColor=white)


# DATABase (people DB)
This program will help you work with databases. You can use it to store the names of people or the names of anything. You can also delete and search for the presence of a name in the database table.
____

## Let's take the files in order:
1. **My.pro** 

```cpp
TEMPLATE = app
CONFIG += console c++20
TARGET = APP

QT += core gui
QT += sql
QT += widgets

greaterThan(QT_MAJOR_VERSION,4):

SOURCES += dbmanager.cpp \
    interfacedb.cpp \
    main.cpp

HEADERS += \
    dbmanager.h \
    interfacedb.h
```
It is setting up a Qt project file (.pro) for a console application named APP that uses C++20. Here included the core, gui, sql, and widgets modules from the Qt library.
Also specifying that if the major version of Qt is greater than 4, the source files dbmanager.cpp, interfacedb.cpp, and main.cpp along with the header files dbmanager.h and interfacedb.h should be included in the project.
____
2. **main.cpp**
```cpp
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
```
This main file uses this code to create a window ***object*** sets the size and displays an intuitive interface

 ![](https://i.postimg.cc/bvS0j7m5/photo-2024-05-03-21-54-11.jpg):
____
3. **dbmanager.h**
> This is a header file for the `DBManager` class in ***C++***. The `DBManager` class is a subclass of `QWidget` and is designed to manage a database. Here’s a brief description of its functionality:
+ **Constructor:** There are two constructors available. One takes a QString path to the database, and the other is a default constructor.
+ **createTable():** This function is used to create a table in the database.
+ **addPerson(const QString& name):** This function adds a person to the database with the given name.
+ **personExists(const QString& name):** This function checks if a person with the given name exists in the database.
+ **removePerson(const QString& name):** This function removes a person with the given name from the database.
+ **printAll():** This function prints all the entries in the database.
+ **removeAll():** This function removes all entries from the database.
+ **Destructor:** The destructor for the DBManager class.
> The class also contains a protected member dataset, which is a vector of QString. This could be used to store data fetched from the database.
   The private member m_db is an instance of QSqlDatabase that represents the database connection.
   This class provides a simple and efficient way to perform basic database operations like adding, checking, and removing entries.
   It can be easily integrated into any Qt application that requires database management. Please note that the actual implementation of these functions is not provided in this header file.
   You’ll need to look at the corresponding .cpp file for the implementation details. 
  Remember to include the necessary Qt modules in your project file to use QSqlDatabase and related classes. In this case, you’ve already included the sql module in your Qt project file.
____
4. **dbmanager.cpp**
> Here you can see the implementation of all the methods of the class described above ^.
____
5.  **interfacedb.h**
>  Sure, here is a brief description of the InterfaceDB class for your README:
The InterfaceDB class is a subclass of DBManager. It provides an interface to interact with the database. Here are the main components and their functionalities:
+ *Private Members:*
  + `QLabel *label_1, *label_2, *labelName, *labelImage;`: These are labels used in the interface.
  + `QStandardItemModel *model;`: This is the data model for the `QTableView`.
  + `QTableView *tableView;`: This is the view that presents items from a model.
  +  `QGridLayout *grid;`: This is the layout used to arrange widgets in a grid.
  +  `QLineEdit *lineEdit;`: This is the input field in the interface.
+ *Public Members:*
  + `InterfaceDB(const QString& path);`: This is the constructor that takes a path to the database as an argument.
+ *Public Slots:*
  + `void Show();`: This function is used to show data in the interface.
  + `void Add();`: This function is used to add data to the database.
  + `void ExistFunc();`: This function checks if a certain data exists in the database.
  + `void ContinueProcessFunc();`: This function continues a certain process.
  + `void RemovePersonFunc();`: This function removes a person’s data from the database.
  + `void RemoveAllPersonFunc();`: This function removes all persons’ data from the database.
  + `void PrintAllFunc();`: This function prints all data from the database.
> This class provides a user-friendly interface to interact with the database, making it easier to perform operations like adding, removing, and viewing data.
 It’s designed to be intuitive and straightforward to use.
The `InterfaceDB` class is a crucial part of the application that ensures smooth and efficient database management.
____
6. **interfacedb.cpp**
> Here you can see the implementation of all the methods of the class described above ^.
____

7. **peopple.db**
 > File with the extension `.db` file are usually database file. They can contain data in a structured format created and managed by database applications.
  This file are used by many programs to store data that can be organized into tables, fields, columns, and indexes for quick search.
An example of such a file is **SQLite**, a lightweight database that stores all data in a single `.db` file.
This makes it convenient for embedded systems and small applications that do not require a full-fledged database server.
It is important to note that for working with files `.db` usually requires specialized software capable of interpreting the data structure internally.
#### Here's what you need to do to create a table in a file:
1. Go to the website [SQLite](https://www.sqlite.org/download.html) and download the necessary software.
2. After downloading, unzip it and create a file with the `.db` extension in this folder.
3. Go to the command line and write:
  ```cpp
    sqlite3 people.db
    sqlite> CREATE TABLE people(ids integer primary key, name text);
    sqlite> .quit
   ```
   > Here we create a table named *people* inside the database.
   You can copy this database to our project and use it.

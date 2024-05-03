#include "InterfaceDB.h"


InterfaceDB::InterfaceDB(const QString& path):DBManager(path)
{
    QPushButton *AddPerson = new QPushButton("Add Person",this);
    QPushButton *PersonExist = new QPushButton("Person Exist",this);
    QPushButton *RemovePerson = new QPushButton("Remove Person",this);
    QPushButton *PrintAll = new QPushButton("Print All",this);
    QPushButton *RemoveAll = new QPushButton("Remove All",this);
    QPushButton *ContinueProcess = new QPushButton("Continue",this);
    QPushButton *DataBase = new QPushButton("Check DB",this);

    grid = new QGridLayout(this);
    lineEdit = new QLineEdit(this);
    label_1 = new QLabel(this);
    label_2 = new QLabel(this);
    labelName = new QLabel(this);


    grid->addWidget(AddPerson, 1, 0);
    AddPerson->setFixedSize(100, 40);
    grid->addWidget(PersonExist, 1, 1);
    PersonExist->setFixedSize(100, 40);
    grid->addWidget(RemovePerson, 1, 2);
    RemovePerson->setFixedSize(100, 40);
    grid->addWidget(PrintAll, 1, 3);
    PrintAll->setFixedSize(100, 40);
    grid->addWidget(RemoveAll, 1, 4);
    RemoveAll->setFixedSize(100, 40);
    grid->addWidget(lineEdit, 0, 0);
    lineEdit->setFixedSize(390, 40);
    grid->addWidget(label_1,2,0);
    grid->addWidget(label_2,3,0);
    grid->addWidget(ContinueProcess,0,4);
    ContinueProcess->setFixedSize(100, 40);
    grid->addWidget(DataBase,9,3);
    DataBase->setFixedSize(200, 40);


    connect(AddPerson,&QPushButton::clicked, this,&InterfaceDB::Add);
    connect(ContinueProcess,&QPushButton::clicked, this,&InterfaceDB::ContinueProcessFunc);
    connect(PersonExist,&QPushButton::clicked, this,&InterfaceDB::ExistFunc);
    connect(RemovePerson,&QPushButton::clicked, this,&InterfaceDB::RemovePersonFunc);
    connect(PrintAll,&QPushButton::clicked, this,&InterfaceDB::PrintAllFunc);
    connect(RemoveAll,&QPushButton::clicked, this,&InterfaceDB::RemoveAllPersonFunc);
    connect(DataBase,&QPushButton::clicked, this,&InterfaceDB::PrintAllFunc);


    setFixedSize(500,250);


}

void InterfaceDB::Add()
{
    QString name;
    label_1->clear();
    label_2->clear();
    if (!lineEdit->text().isEmpty())
    {
        name = lineEdit->text();
        dataset.push_back(name);
        addPerson(name);
        lineEdit->clear();
        label_1->setText("the operation was successful");
        label_2->setText("to check the changes, log into the database");
        lineEdit->setDisabled(true);
    }

}
void InterfaceDB::ContinueProcessFunc()
{
    lineEdit->setDisabled(false);
    label_1->clear();
    label_2->clear();
    lineEdit->clear();
}

void InterfaceDB::ExistFunc()
{
    QString name;
    label_1->clear();
    label_2->clear();
    if (!lineEdit->text().isEmpty())
    {
        name = lineEdit->text();
        bool exists = personExists(name);
        lineEdit->clear();
        if(exists)
        {
            label_1->setText("there is such a person in the database");
        }
        else
        {
            label_1->setText("there is N0 such person in the database");
        }

        label_2->setText("to check the changes, log into the database");
        lineEdit->setDisabled(true);
    }
}

void InterfaceDB::RemovePersonFunc() {
    QString name = lineEdit -> text();
    if (!name.isEmpty()) {
        if ( DBManager::removePerson(name)) {
           label_1->setText("this person has been removed from the database");
            lineEdit->clear();
        }
    } else {
        label_1->setText("there is N0 such person in the database");
    }
    label_2->setText("to check the changes, log into the database");
}

void InterfaceDB::PrintAllFunc()
{
    lineEdit->clear();

    model = new QStandardItemModel();
    dataset.clear();
    printAll();
    if(!dataset.empty())
    {
        for(int i = 0; i < dataset.size();i++)
        {
            model->setItem(i, 0, new QStandardItem(dataset[i]));
            label_1->setText("the database is open");
        }
    }
    else
    {
        label_1->setText("the database is empty");
    }

    tableView = new QTableView();
    tableView->setModel(model);

    tableView->setFixedWidth(150);

    tableView->show();
    lineEdit->setDisabled(true);
}

void InterfaceDB::RemoveAllPersonFunc()
{
    label_1->clear();
    label_2->clear();

    bool dltPeople = removeAll();
    lineEdit->clear();
    if(dltPeople)
    {
        label_1->setText("the database has been deleted");
        dataset.clear();
    }
    else
    {
        label_1->setText("Error!");
    }
    label_2->setText("to check the changes, log into the database");
    lineEdit->setDisabled(true);

}

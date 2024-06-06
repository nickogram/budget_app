#include "OperationFile.h"

vector <Operation> OperationFile::loadOperationsFromFile(const int &loggedUserId) {
    Operation operation;
    vector <Operation> operations;

    bool fileExistStatus = xmlDoc.Load(getFileName());

    if (!fileExistStatus) {
        cout << "File not found: " << getFileName() << endl;
        cout << "To create new file - add new operation" << endl;
        system("pause");
    } else {
        xmlDoc.ResetPos();
        xmlDoc.FindElem();
        xmlDoc.IntoElem();

        while (xmlDoc.FindElem("Operation")) {
            xmlDoc.IntoElem();
            xmlDoc.FindElem("userId");

            if (loggedUserId == atoi(MCD_2PCSZ(xmlDoc.GetData()))) {
                xmlDoc.OutOfElem();
                xmlDoc.OutOfElem();
                xmlDoc.IntoElem();
                xmlDoc.IntoElem();

                xmlDoc.FindElem("id");
                operation.id = atoi(MCD_2PCSZ(xmlDoc.GetData()));

                xmlDoc.FindElem("userId");
                operation.userId = atoi(MCD_2PCSZ(xmlDoc.GetData()));

                xmlDoc.FindElem("date");
                operation.date = atoi(MCD_2PCSZ(xmlDoc.GetData()));

                xmlDoc.FindElem("item");
                operation.item = xmlDoc.GetData();

                xmlDoc.FindElem("amount");
                operation.amount = atof(MCD_2PCSZ(xmlDoc.GetData()));

                operations.push_back(operation);
            }
            xmlDoc.OutOfElem();
        }
    }

    std::sort( operations.begin(), operations.end(),
    []( const Operation &left, const Operation &right ) {
        return ( left.date < right.date );
    } );

    return operations;
}

bool OperationFile::addOperationToFile (const Operation &operation) {
    bool addOperationStatus = false;
    bool fileExistStatus = xmlDoc.Load(getFileName());

    if (!fileExistStatus) {
        xmlDoc.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlDoc.AddElem("Operations");
    }
    xmlDoc.ResetPos();
    xmlDoc.FindElem();
    xmlDoc.IntoElem();
    xmlDoc.AddElem("Operation");
    xmlDoc.IntoElem();
    xmlDoc.AddElem("id", operation.id);
    xmlDoc.AddElem("userId", operation.userId);
    xmlDoc.AddElem("date", operation.date);
    xmlDoc.AddElem("item", operation.item);
    xmlDoc.AddElem("amount", std::to_string(operation.amount));
    addOperationStatus = true;

    xmlDoc.Save(File::getFileName());

    return addOperationStatus;
}

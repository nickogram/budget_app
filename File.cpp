#include "File.h"

string File::getFileName() {
    return FILE_NAME;
}

int File::getLastId() {
    xmlDoc.Load(getFileName());
    xmlDoc.ResetPos();
    xmlDoc.FindElem();
    xmlDoc.IntoElem();

    while (xmlDoc.FindElem()) {
        xmlDoc.IntoElem();
        xmlDoc.FindElem("id");

        lastId = atoi(MCD_2PCSZ(xmlDoc.GetData()));
        xmlDoc.OutOfElem();
    }
    return lastId;
}

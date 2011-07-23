#include "addinxmler.h"

AddInXmler::AddInXmler()
{
}

bool AddInXmler::ParseFile(const QString& sFileName)
{
    QDomDocument oDoc("AddInDocument");
    QFile oFile(sFileName);
    if (!oFile.open(QIODevice::ReadOnly))
        return false;

    if (!oDoc.setContent(&oFile))
    {
        oFile.close();
        return false;
    }
    oFile.close();

    QDomElement oAddinsElement = oDoc.documentElement();
    if (oAddinsElement.tagName() != "AddIns")
    {
//        emit ParseFileFailed(sFileName);
        return false;
    }

    QDomNode n = oAddinsElement.firstChild();
    QString message;
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            message += e.tagName() + "\n"; // the node really is an element.
        }
        n = n.nextSibling();
    }

//    QMessageBox::information(NULL, "OK", message);

//    // Here we append a new element to the end of the document
//    QDomElement elem = oDoc.createElement("img");
//    elem.setAttribute("src", "myimage.png");
//    oAddinsElement.appendChild(elem);

    return true;
}

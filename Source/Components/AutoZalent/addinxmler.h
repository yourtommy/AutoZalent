#ifndef ADDINXMLER_H
#define ADDINXMLER_H

#include "addin.h"

class Exception
{
public:
    virtual QString GetMessage() = 0;
};

class AddInXmler : public QObject
{
    Q_OBJECT

public:
    AddInXmler();

    typedef QList<QSharedPointer<AddIn> > AddInList;
    QSharedPointer<AddInList> ParseFile(const QString& sFileName) throw (Exception);
    void FillCommands(QSharedPointer<AddIn>& oAddIn, const QDomElement &oCommandsElement);
    void FillHandlers(QSharedPointer<AddIn>& oAddIn, const QDomElement &oHanldersElement);

//signals:
//    void FileNotFound(const QString& sFileName);
//    void InvalidContent(const QString& sFileName);
//    void ElementNotFound(const QString& sFileName, const QString& sElement);

private:
    QSharedPointer<AddIn> ParseAddIn(const QDomElement& oElement);
    QSharedPointer<Command> ParseCommand(const QDomElement& oElement);
};

#endif // ADDINXMLER_H

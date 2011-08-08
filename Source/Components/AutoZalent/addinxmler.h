#ifndef ADDINXMLER_H
#define ADDINXMLER_H

#include "addin.h"
#include "exception.h"

class AddInXmler : public QObject
{
    Q_OBJECT

public:
    AddInXmler(const QString& sFileName);

    typedef QList<QSharedPointer<AddIn> > AddInList;
    QSharedPointer<AddInList> Parse() throw (Exception);

private:
    QSharedPointer<AddIn> ParseAddIn(const QDomElement& oElement);
    QSharedPointer<Command> ParseCommand(const QDomElement& oElement);

    void FillCommands(QSharedPointer<AddIn>& oAddIn, const QDomElement &oCommandsElement);
    void FillHandlers(QSharedPointer<AddIn>& oAddIn, const QDomElement &oHanldersElement);

private:
    QString msFileName;

};


#endif // ADDINXMLER_H

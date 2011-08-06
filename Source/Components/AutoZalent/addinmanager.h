#ifndef ADDINMANAGER_H
#define ADDINMANAGER_H

#include "addin.h"

class AddInManager : public QObject
{
    Q_OBJECT

public:
    static AddInManager* GetInstance();

    bool LoadAddIns();
    bool RegisterAddIn(const AddIn& oAddin);
    bool RegisterCommand(const QString& sCommandId);
    Command GetCommand(const QString& sCommandId);
    bool ExecuteCommand(const QString& sCommandId);

private:
    AddInManager();
    static QSharedPointer<AddInManager> soAddInManager;
};

#endif // ADDINMANAGER_H

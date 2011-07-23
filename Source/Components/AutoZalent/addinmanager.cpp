#include "addinmanager.h"

QSharedPointer<AddInManager> AddInManager::soAddInManager;

AddInManager::AddInManager()
{
}

AddInManager* AddInManager::GetInstance()
{
    if (soAddInManager.isNull())
        soAddInManager = QSharedPointer<AddInManager>(new AddInManager);

    return soAddInManager.data();
}

bool AddInManager::LoadAddIns()
{
    // TODO:
    return false;
}

bool AddInManager::RegisterAddIn(const AddIn &oAddin)
{
    // TODO:
    return false;
}

bool AddInManager::RegisterCommand(const QString &sCommandId)
{
    // TODO:
    return false;
}

Command AddInManager::GetCommand(const QString &sCommandId)
{
    // TODO:
    return Command();
}

bool AddInManager::ExecuteCommand(const QString &sCommandId)
{
    // TODO:
    return false;
}

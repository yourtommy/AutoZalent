#include "addin.h"

AddIn::AddIn(const QString& sFileName)
{
}

AddIn::AddIn(const QString& sFileName, const QString& sExecuteHandler,
                  const QString& sIsCheckableHandler, const QString& sIsCheckedHandler,
                  const QString& sIsEnabledHanlder, const QString& sIsVisibleHandler)
{
    // TODO:
}

bool AddIn::IsValid()
{
    // TODO:
    return false;
}

bool AddIn::Execute(const QString &sCommandId)
{
    // TODO:
    return false;
}

bool AddIn::IsCheckable(const QString &sCommandId)
{
    // TODO:
    return false;
}

bool AddIn::IsChecked(const QString &sCommandId)
{
    // TODO:
    return false;
}

bool AddIn::IsEnabled(const QString &sCommandId)
{
    // TODO:
    return false;
}

bool AddIn::IsVisible(const QString &sCommandId)
{
    // TODO:
    return false;
}

bool AddIn::RegisterCommand(const QString &sCommandId, bool bStartup)
{
    // TODO:
    return false;
}

bool AddIn::SetExecuteHandler(const QString &sExecuteHandler)
{
    // TODO:
    return false;
}

bool AddIn::SetIsCheckableHandler(const QString &sIsCheckableHandler)
{
    // TODO:
    return false;
}

bool AddIn::SetIsCheckedHandler(const QString &sIsCheckedHandler)
{
    // TODO:
    return false;
}

bool AddIn::SetIsEnabledHanlder(const QString &sIsEnabledHanlder)
{
    // TODO:
    return false;
}

bool AddIn::SetIsVisibleHandler(const QString &sIsVisibleHandler)
{
    // TODO:
    return false;
}


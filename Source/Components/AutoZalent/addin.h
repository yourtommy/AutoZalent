#ifndef ADDIN_H
#define ADDIN_H

struct Command
{
    QString msId;
    bool mbStartup;
    bool mbIsCheckable;
    bool mbIsChecked;
    bool mbIsEnabled;
    bool mbIsVisible;
};

class AddIn : public QObject
{
    Q_OBJECT

public:
    AddIn(const QString& sFileName);
    AddIn(const QString& sFileName, const QString& sExecuteHandler,
          const QString& sIsCheckableHandler, const QString& sIsCheckedHandler,
          const QString& sIsEnabledHanlder, const QString& sIsVisibleHandler);

    bool IsValid();

    bool RegisterCommand(const QString& sCommandId, bool bStartup);
    //bool RemoveCommand();
    bool SetExecuteHandler(const QString& sExecuteHandler);
    bool SetIsCheckableHandler(const QString& sIsCheckableHandler);
    bool SetIsCheckedHandler(const QString& sIsCheckedHandler);
    bool SetIsEnabledHanlder(const QString& sIsEnabledHanlder);
    bool SetIsVisibleHandler(const QString& sIsVisibleHandler);

    bool Execute(const QString& sCommandId);
    bool IsCheckable(const QString& sCommandId);
    bool IsChecked(const QString& sCommandId);
    bool IsEnabled(const QString& sCommandId);
    bool IsVisible(const QString& sCommandId);

    QList<Command> moCommands;

private:
    QLibrary moLibrary;

    typedef bool (*CommandHandler)(wchar_t* szCommandId);
    CommandHandler mpExecuteHandler;
    CommandHandler mpIsCheckableHandler;
    CommandHandler mpIsCheckedHandler;
    CommandHandler mpIsEnabledHandler;
    CommandHandler mpIsVisibleHandler;
};

#endif // ADDIN_H

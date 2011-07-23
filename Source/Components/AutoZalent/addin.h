#ifndef ADDIN_H
#define ADDIN_H

class AddIn : public QObject
{
    Q_OBJECT

public:
    AddIn(const QString& sFileName, const QString& sExecuteHandler,
          const QString& sIsCheckableHandler, const QString& sIsCheckedHandler,
          const QString& sIsEnabledHanlder, const QString& sIsVisible);

    bool IsValid();

    bool Execute(const QString& sCommandId);
    bool IsCheckable(const QString& sCommandId);
    bool IsChecked(const QString& sCommandId);
    bool IsEnabled(const QString& sCommandId);
    bool IsVisible(const QString& sCommandId);

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

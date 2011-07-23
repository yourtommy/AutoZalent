#ifndef ADDINXMLER_H
#define ADDINXMLER_H

class AddInXmler : public QObject
{
    Q_OBJECT

public:
    AddInXmler();

    bool ParseFile(const QString& sFileName);
};

#endif // ADDINXMLER_H

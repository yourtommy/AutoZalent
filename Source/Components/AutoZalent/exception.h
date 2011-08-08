#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
public:
    virtual QString GetDescription() = 0;
};

class XmlException : public Exception
{
public:
    XmlException(const QString& sFileName);
    QString msFileName;
};

class MissingFileException : public XmlException
{
public:
    MissingFileException(const QString& sFileName);
    virtual QString GetDescription();
};

class InvalidContentException : public XmlException
{
public:
    InvalidContentException(const QString& sFileName);
    virtual QString GetDescription();
};

class XmlElementException : public XmlException
{
public:
    XmlElementException(const QString& sFileName, int nLine, int nColumn);
    int mnLine;
    int mnColumn;
};

class UnexpectedElementException : public XmlElementException
{
public:
    UnexpectedElementException(const QString& sFileName, int nLine, int nColumn,
                               const QString& sExpectedElement, const QString& sUnexpectedElement);
    virtual QString GetDescription();

public:
    QString msExpectedElement;
    QString msUnexpectedElement;
};


class MissingAttributeException : public XmlElementException
{
public:
    MissingAttributeException(const QString& sFileName, int nLine, int nColumn,
                              const QString& sMissingAttribute, const QString& sElement);
    virtual QString GetDescription();

public:
    QString msMissingAttribute;
    QString msElement;
};

#endif // EXCEPTION_H

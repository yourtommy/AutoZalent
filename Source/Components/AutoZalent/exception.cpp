#include "pch.h"
#include "exception.h"

XmlException::XmlException(const QString &sFileName)
 : msFileName(sFileName)
{
}

MissingFileException::MissingFileException(const QString& sFileName)
    : XmlException(sFileName)
{
}

QString MissingFileException::GetDescription()
{
    return QObject::tr("%1 is not found").arg(msFileName);
}

InvalidContentException::InvalidContentException(const QString &sFileName)
    : XmlException(sFileName)
{
}

QString InvalidContentException::GetDescription()
{
    return QObject::tr("%1 is not a valid addin file").arg(msFileName);
}

XmlElementException::XmlElementException(const QString &sFileName, int nLine, int nColumn)
    : XmlException(sFileName), mnLine(nLine), mnColumn(nColumn)
{
}

UnexpectedElementException::UnexpectedElementException(
    const QString &sFileName, int nLine, int nColumn,
    const QString &sExpectedElement, const QString &sUnexpectedElement)
    : XmlElementException(sFileName, nLine, nColumn),
      msExpectedElement(sExpectedElement), msUnexpectedElement(sUnexpectedElement)
{
}

QString UnexpectedElementException::GetDescription()
{
    return QObject::tr("Unexpected element <%1> found at line %2, column %3 in file %4. Expected element: <%5>")
            .arg(msUnexpectedElement).arg(mnLine).arg(mnColumn).arg(msFileName).arg(msExpectedElement);
}

MissingAttributeException::MissingAttributeException(
    const QString &sFileName, int nLine, int nColumn,
    const QString &sMissingAttribute, const QString& sElement)
    : XmlElementException(sFileName, nLine, nColumn),
      msMissingAttribute(sMissingAttribute), msElement(sElement)
{
}

QString MissingAttributeException::GetDescription()
{
    return QObject::tr("Attribute [%1] is not found in element <%2> at line %3, column %4 in file %5").
            arg(msMissingAttribute).arg(msElement).arg(mnLine).arg(mnColumn).arg(msFileName);
}


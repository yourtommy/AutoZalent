/* AddIn xml structure
<AddIns>
    <AddIn FileName=”FileName” >
        <Commands>
            <Command Id=”CommandId” Startup=”True” />
            <Command Id=”CommandId2” Startup=”False” />
            <Command Starup=”True”>ID_Command3</Command>
            <Command>ID_Command4</Command> <!--startup is fasle by default-->
        </Commands>
        <Handlers>
            <Execute>Execute</Execute>
            <IsCheckable /> <!--default value: false-->
            <IsChecked /> <!--default value: false-->
            <IsEnabled /> <!--default value: true-->
            <IsVisible /> <!--default value: true-->
        </Handlers>
    </AddIn>
    <AddIn>
        <Commands>
            <Command Id=”ID_Command5”/>
        </Commands>
    </AddIn>
</AddIns>
*/

#include "addinxmler.h"

AddInXmler::AddInXmler(const QString& sFileName)
    : msFileName(sFileName)
{
}

QSharedPointer<AddInXmler::AddInList> AddInXmler::Parse() throw(Exception)
{
    QFile oFile(msFileName);
    if (!oFile.open(QIODevice::ReadOnly))
        throw MissingFileException(msFileName);

    QDomDocument oDoc("AddInDocument");
    if (!oDoc.setContent(&oFile))
        throw InvalidContentException(msFileName);

    QDomElement oAddInsElement = oDoc.documentElement();
    if (oAddInsElement.tagName().compare("AddIns", Qt::CaseInsensitive) != 0)
        throw UnexpectedElementException(msFileName, oAddInsElement.lineNumber(), oAddInsElement.columnNumber(), "AddIns", oAddInsElement.tagName());

    QSharedPointer<AddInList> oAddIns(new AddInList);
    QDomNode oAddInNode = oAddInsElement.firstChild();
    while(!oAddInNode.isNull()) {
        QSharedPointer<AddIn> oAddIn = ParseAddIn(oAddInNode.toElement());
        oAddIns->append(oAddIn);
        oAddInNode = oAddInNode.nextSibling();
    }    

    return oAddIns;
}

QSharedPointer<AddIn> AddInXmler::ParseAddIn(const QDomElement &oAddInElement)
{
    QSharedPointer<AddIn> oAddIn;

    if(oAddInElement.isNull())
        throw UnexpectedElementException(msFileName, oAddInElement.lineNumber(), oAddInElement.columnNumber(), "AddIn", "");

    if (oAddInElement.tagName().compare("AddIn", Qt::CaseInsensitive) != 0)
        throw UnexpectedElementException(msFileName, oAddInElement.lineNumber(), oAddInElement.columnNumber(), "AddIn", oAddInElement.tagName());

    QString sAddInFileName = oAddInElement.attribute("FileName");
    if (sAddInFileName.isEmpty())
        throw MissingAttributeException(msFileName, oAddInElement.lineNumber(), oAddInElement.columnNumber(), "FileName", "AddIn");

    oAddIn = QSharedPointer<AddIn>(new AddIn(sAddInFileName));

    QDomNode oNode = oAddInElement.firstChild();
    while(!oNode.isNull())
    {
        QDomElement oElement = oNode.toElement();
        if (!oElement.isNull())
        {
            if (oElement.tagName().compare("Commands", Qt::CaseInsensitive) == 0)
                FillCommands(oAddIn, oElement);
            else if (oElement.tagName().compare("Hanlders", Qt::CaseInsensitive) == 0)
                FillHandlers(oAddIn, oElement);
        }
        oNode = oNode.nextSibling();
    }

    return oAddIn;
}

void AddInXmler::FillCommands(QSharedPointer<AddIn>& oAddIn, const QDomElement &oCommandsElement)
{
    QDomNode oCommandNode = oCommandsElement.firstChild();
    while(!oCommandNode.isNull())
    {
        QDomElement oCommandElement = oCommandNode.toElement();
        if (!oCommandElement.isNull())
        {
            if (oCommandElement.tagName().compare("Command", Qt::CaseInsensitive) == 0)
            {
                QString sCommandId = oCommandElement.attribute("Id");
                if (sCommandId.isEmpty())
                    throw MissingAttributeException(msFileName, oCommandElement.lineNumber(), oCommandElement.columnNumber(), "Id", oCommandElement.tagName());
                QString sStartup = oCommandElement.attribute("Startup");
                bool bStartup = !sStartup.isEmpty() && sStartup.compare("True", Qt::CaseInsensitive) == 0;
                oAddIn->RegisterCommand(sCommandId, bStartup);
            }
        }
        oCommandNode = oCommandNode.nextSibling();
    }
}

void AddInXmler::FillHandlers(QSharedPointer<AddIn>& oAddIn, const QDomElement &oHanldersElement)
{
    QDomNode oHnadlerNode = oHanldersElement.firstChild();
    while(!oHnadlerNode.isNull())
    {
        QDomElement oHandlerElement = oHnadlerNode.toElement();
        if (!oHandlerElement.isNull() && !oHandlerElement.text().isEmpty())
        {
            QString sHandler = oHandlerElement.tagName();
            if (sHandler.compare("Execute", Qt::CaseInsensitive) == 0)
                oAddIn->SetExecuteHandler(sHandler);
            else if (sHandler.compare("IsCheckable", Qt::CaseInsensitive) == 0)
                oAddIn->SetIsCheckableHandler(sHandler);
            else if (sHandler.compare("IsChecked", Qt::CaseInsensitive) == 0)
                oAddIn->SetIsCheckedHandler(sHandler);
            else if (sHandler.compare("IsEnabled", Qt::CaseInsensitive) == 0)
                oAddIn->SetIsEnabledHanlder(sHandler);
            else if (sHandler.compare("IsVisible", Qt::CaseInsensitive) == 0)
                oAddIn->SetIsVisibleHandler(sHandler);
        }
        oHnadlerNode = oHnadlerNode.nextSibling();
    }
}

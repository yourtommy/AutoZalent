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

AddInXmler::AddInXmler()
{
}

QSharedPointer<AddInXmler::AddInList> AddInXmler::ParseFile(const QString& sFileName) throw(Exception)
{
    QSharedPointer<AddInList> oAddIns;

    QDomDocument oDoc("AddInDocument");
    QFile oFile(sFileName);
    if (!oFile.open(QIODevice::ReadOnly))
    {
//        throw FileNotFound(sFileName);
        return oAddIns;
    }

    if (!oDoc.setContent(&oFile))
    {
        oFile.close();
//        throw InvalidContent(sFileName);
        return oAddIns;
    }
    oFile.close();

    QDomElement oAddInsElement = oDoc.documentElement();
    if (oAddInsElement.tagName() != "AddIns")
    {
//        throw ElementNotFound(sFileName, "AddIns");
        return oAddIns;
    }

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

    Q_ASSERT(!oAddInElement.isNull());
    if(oAddInElement.isNull())
        return oAddIn;

    Q_ASSERT(oAddInElement.tagName() == "AddIn");
    if (oAddInElement.tagName() != "AddIn")
        return oAddIn;

    QString sFileName = oAddInElement.attribute("FileName");
    if (sFileName.isEmpty())
        return oAddIn;

    oAddIn = QSharedPointer<AddIn>(new AddIn(sFileName));

    QDomNode oNode = oAddInElement.firstChild();
    while(!oNode.isNull())
    {
        QDomElement oElement = oNode.toElement();
        if (!oElement.isNull())
        {
            if (oElement.tagName() == "Commands")
                FillCommands(oAddIn, oElement);
            else if (oElement.tagName() == "Hanlders")
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
            if (oCommandElement.tagName() == "Command")
            {
                QString sCommandId = oCommandElement.attribute("Id");
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
            if (sHandler == "Execute")
                oAddIn->SetExecuteHandler(sHandler);
            else if (sHandler == "IsCheckable")
                oAddIn->SetIsCheckableHandler(sHandler);
            else if (sHandler == "IsChecked")
                oAddIn->SetIsCheckedHandler(sHandler);
            else if (sHandler == "IsEnabled")
                oAddIn->SetIsEnabledHanlder(sHandler);
            else if (sHandler == "IsVisible")
                oAddIn->SetIsVisibleHandler(sHandler);
        }
        oHnadlerNode = oHnadlerNode.nextSibling();
    }
}

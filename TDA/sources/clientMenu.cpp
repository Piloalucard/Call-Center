#include "../headers/clientMenu.h"

using namespace std;

void ClientMenu::header()
{
    cout << "############################################################################################" << endl << endl;
    cout << "\t\t\t| ASTRO-MAN CALL CENTER |" << endl << endl;
    cout << "############################################################################################" << endl << endl;
}

void ClientMenu::mainMenu()
{
    system("cls");
    char op='0';
    while(op!='5')
    {

        header();
        cout << "\t\tCLIENTES" << endl << endl;
        cout << "\t[1] Nuevo Cliente " << endl;
        cout << "\t[2] Eliminar Cliente " << endl;
        cout << "\t[3] Cambiar datos de Cliente " << endl;
        cout << "\t[4] Mostrar todos los Cliente " << endl;
        cout << "\t[5] SALIR " << endl << endl;
        cout << "############################################################################################" << endl << endl;
        cout << "\tElija una opcion: ";

        cin >> op;
        cin.ignore();
        switch(op)
        {
        case '1':
            addClient();
            break;
        case '2':
            deleteClient();
            break;
        case '3':
            modifyClient();
            break;
        case '4':
            showClient();
            break;
        case '5':
            cout << "Saliendo..." << endl;
            pause();
            return;
            break;
        default:
            cout << "Opcion Invalida!" << endl;
            pause();
            break;
        }

        system("cls");
    }
}

void ClientMenu::pause()
{
    fflush(stdin);
    cout << " Press ENTER to continue..." ;
    getchar();

}


void ClientMenu::addClient()
{
    string aux;
    int auxi;
    ClientNode* pos;
    Client myClient;
    Time dur;
    Time hor;
    Date fecha;
    system("cls");
    header();
    cout << "\t\tNuevo Cliente" <<endl <<endl;
    cout << "\tNombre: ";
    getline(cin,aux);
    myClient.setName(aux);
    pos=clientListRef->findData(myClient);
    if(pos!=nullptr)
    {
        cout << "\tEste cliente ya esta registrado!" << endl << endl;
        pause();
        return;
    }

    char op;
    myClient.setTime(hor);
    myClient.setDate(fecha);

    cout << "\tDuracion de la llamada: " <<endl;
    cout << "\tIngrese la hora como ENTERO (HH): ";
    cin >> auxi;
    dur.setHour(auxi);
    cout << "\tIngrese los minutos como ENTERO (MM): ";
    cin >> auxi;
    dur.setMinute(auxi);


    myClient.setDuration(dur);
    try
    {
        clientListRef->insertOrdered(myClient);
    }
    catch(ListException ex)
    {
        cout << "\tHa ocurrido un error" << endl;
        cout << "\tSe ha reportado: "<<ex.what()<<endl;
        pause();
        return;
    }
    cout << "\n\tCliente Registrado!" << endl << endl;
    cout << "############################################################################################" << endl << endl;
    pause();


}

void ClientMenu::deleteClient()
{
    string aux;
    Client myClient;
    ClientNode* pos;
    system("cls");
    header();
    cout << "\t\tEliminando Cliente" <<endl <<endl;
    cout << "\tNombre: ";
    getline(cin,aux);
    myClient.setName(aux);
    pos=clientListRef->findData(myClient);
    if(pos==nullptr)
    {
        cout << "\tCliente no existente en la lista" << endl;
        cout << "############################################################################################" << endl << endl;
        pause();
        return;
    }
    clientListRef->deleteData(pos);
    cout << "\n\tCliente Eliminado!" << endl << endl;
    cout << "############################################################################################" << endl << endl;
    pause();

}

void ClientMenu::showClient()
{
    system("cls");
    header();
    cout << "\t\tListado de clientes" <<endl;
    cout << clientListRef->toString();
    cout << endl;
    cout << "############################################################################################" << endl << endl;
    pause();

}

void ClientMenu::modifyClient()
{
    string aux;
    bool band=false;
    int auxi;
    ClientNode* pos;
    Client myClient,realClient;
    Time dur;
    Time hor;
    Date fecha;
    system("cls");
    header();
    cout << "\t\tModificar Cliente" <<endl <<endl;
    cout << "\tDame el nombre del cliente: ";
    getline(cin,aux);
    myClient.setName(aux);
    pos=clientListRef->findData(myClient);
    if(pos!=nullptr)
    {
        band=true;
    }
    if(band==false)
    {
        cout << "\n\tNo se encontro el cliente!" << endl << endl;
        cout << "############################################################################################" << endl << endl;
        pause();
        return;
    }
    char op='0';
    realClient=clientListRef->retrieve(pos);
    cout << "\tSe encontro este cliente: ";
    cout << realClient.toString() << endl << endl;
    cout << "\tDesea modificar el Nombre (Y/Cualquier tecla): ";
    cin >> op;
    cin.ignore();
    op=toupper(op);
    if(op=='Y')
    {
        cout << "\tNuevo Nombre: ";
        getline(cin,aux);
        realClient.setName(aux);
    }
    cout << "\tDesea modificar la fecha (Y/Cualquier tecla): ";
    cin >> op;
    cin.ignore();
    op=toupper(op);
    if(op=='Y')
    {
        cout << "\tNuevo Dia: ";
        cin >> auxi;
        fecha.setDay(auxi);
        cout << "\tNuevo Mes: ";
        cin >> auxi;
        fecha.setMonth(auxi);
        cout << "\tNuevo Año: ";
        cin >> auxi;
        fecha.setYear(auxi);
        realClient.setDate(fecha);
    }

    cout << "\tDesea modificar la duracion de la llamada (Y/Cualquier tecla): ";
    cin >> op;
    cin.ignore();
    op=toupper(op);
    if(op=='Y')
    {
        cout << "\tDuracion de la llamada: " <<endl;
        cout << "\tIngrese la hora como ENTERO (HH): ";
        cin >> auxi;
        dur.setHour(auxi);
        cout << "\tIngrese los minutos como ENTERO (MM): ";
        cin >> auxi;
        dur.setMinute(auxi);
        realClient.setDuration(dur);
    }

    cout << "\tDesea modificar la hora de la llamada (Y/Cualquier tecla): ";
    cin >> op;
    cin.ignore();
    op=toupper(op);
    if(op=='Y')
    {
        cout << "\tHora a la que fue realizada: " <<endl;
        cout << "\tIngrese la hora como ENTERO (HH): ";
        cin >> auxi;
        hor.setHour(auxi);
        cout << "\tIngrese los minutos como ENTERO (MM): ";
        cin >> auxi;
        hor.setMinute(auxi);
        realClient.setTime(hor);
    }

    clientListRef->insertOrdered(realClient);
    clientListRef->deleteData(pos);
    cout << "\n\tModificaciones hechas con exito!" << endl << endl;
    cout << "############################################################################################" << endl << endl;
    pause();
}

ClientMenu::ClientMenu(ClientList* p) : clientListRef(p)
{
    mainMenu();
}

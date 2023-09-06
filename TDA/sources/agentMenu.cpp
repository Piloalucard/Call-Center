#include "../headers/agentMenu.h"

using namespace std;

//Entregable 9

agentMenu::agentMenu(AgentList* P) : agentListRef(P)
{
    pantalla();
    mainMenu();
}


void agentMenu::mainMenu()
{

    char op='0',op2='0';
    while(op!='8')
    {

        header();
        cout << "\t\tAGENTES :: MENU PRINCIPAL" << endl << endl;
        cout << "\t[1] Nuevo Agente " << endl;
        cout << "\t[2] Eliminar Agente(s) " << endl;
        cout << "\t[3] Cambiar datos de Agente " << endl;
        cout << "\t[4] Mostrar Agente(s) " << endl;
        cout << "\t[5] Ordenar Agentes " << endl;
        cout << "\t[6] Escribir al Disco" << endl;
        cout << "\t[7] Leer del Disco " << endl;
        cout << "\t[8] SALIR " << endl << endl;
        cout << "############################################################################################" << endl << endl;
        cout << "\tElija una opcion: ";

        cin >> op;
        cin.ignore();
        switch(op)
        {
        case '1':
            addAgent();
            break;

        case '2':
            do
            {
                system("cls");
                header();
                cout << "\t\tAGENTES :: Eliminando Agentes" << endl << endl;
                cout << "\t[1] Buscar y Eliminar " << endl;
                cout << "\t[2] Eliminar Todo " << endl;
                cout << "\t[3] Regresar " << endl << endl;
                cout << "############################################################################################" << endl << endl;
                cout << "\tElija una opcion: ";
                fflush(stdin);
                cin >> op2;
                switch(op2)
                {
                case '1':
                    deleteAgent();
                    break;
                case '2':
                    deleteAll();
                    break;
                case '3':
                    break;
                default:
                    cout << "Opcion Invalida!" << endl << endl;
                    pause();
                    break;
                }
            }while(op2!='3');
            break;

        case '3':
            modifyAgent();
            break;

        case '4':
            do
            {
                system("cls");
                header();
                cout << "\t\tAGENTES :: Mostrando Agentes" << endl << endl;
                cout << "\t[1] Buscar y Mostrar " << endl;
                cout << "\t[2] Mostrar Por Especialidad " << endl;
                cout << "\t[3] Mostrar Todo " << endl;
                cout << "\t[4] Regresar " << endl << endl;

                cout << "############################################################################################" << endl << endl;
                cout << "\tElija una opcion: ";
                fflush(stdin);
                cin >> op2;
                switch(op2)
                {
                case '1':
                    showAgent();
                    break;
                case '2':
                    showByWorkField();
                    break;
                case '3':
                    showAll();
                    break;
                case '4':
                    break;
                default:
                    cout << "Opcion Invalida!" << endl << endl;
                    pause();
                    break;
                }
            }while(op2!='4');
            break;
        case '5':
            sortAgent();
            break;
        case '6':
            writeToDisk();
            break;
        case '7':
            readFromDisk();
            break;
        case '8':
            cout << "Saliendo..." << endl;
            pause();
            break;
        default:
            cout << "Opcion Invalida!" << endl;
            pause();
            break;
        }

        system("cls");
    }

}

void agentMenu::header()
{
    cout << "############################################################################################" << endl << endl;
    cout << "\t\t\t| ASTRO-MAN CALL CENTER |" << endl << endl;
    cout << "############################################################################################" << endl << endl;
}

void agentMenu::pantalla()
{
    cout << endl << endl << endl;
    Sleep(1*SEG);
    cout << "..######.....###....##.......##................######..########.##....##.########.########.########." << endl;
    cout << ".##....##...##.##...##.......##...............##....##.##.......###...##....##....##.......##.....##" <<endl;
    Sleep(0.5*SEG);
    cout << ".##........##...##..##.......##...............##.......##.......####..##....##....##.......##.....##" << endl;
    cout << ".##.......##.....##.##.......##.......#######.##.......######...##.##.##....##....######...########." <<endl;
    Sleep(0.5*SEG);
    cout << ".##.......#########.##.......##...............##.......##.......##..####....##....##.......##...##.." << endl;
    cout << ".##....##.##.....##.##.......##...............##....##.##.......##...###....##....##.......##....##." <<endl;
    Sleep(0.5*SEG);
    cout << "..######..##.....##.########.########..........######..########.##....##....##....########.##.....##" << endl;
    cout << " " <<endl;
    Sleep(0.5*SEG);
    cout << "\t....###.....######..########.########...#######..##.....##....###....##....##                       " << endl;
    cout << "\t...##.##...##....##....##....##.....##.##.....##.###...###...##.##...###...## " <<endl;
    Sleep(0.5*SEG);
    cout << "\t..##...##..##..........##....##.....##.##.....##.####.####..##...##..####..## " << endl;
    cout << "\t.##.....##..######.....##....########..##.....##.##.###.##.##.....##.##.##.## " <<endl;
    Sleep(0.5*SEG);
    cout << "\t.#########.......##....##....##...##...##.....##.##.....##.#########.##..#### " << endl;
    cout << "\t.##.....##.##....##....##....##....##..##.....##.##.....##.##.....##.##...### " <<endl;
    cout << "\t.##.....##..######.....##....##.....##..#######..##.....##.##.....##.##....## " <<endl;
    Sleep(0.5*SEG);
    cout << endl << endl << "CALL-CENTER ASTROMAN 20XX©" << endl;
    cout << "Gustavo Padilla Valdez" << endl << endl;
    pause();
    system("cls");
}

void agentMenu::pause()
{
    fflush(stdin);
    cout << "Press ENTER to continue..." ;
    getchar();
}

void agentMenu::addAgent()
{

    string aux;
    int auxi;
    char auxc;
    bool auxb,cont=false;
    Agent myAgent;
    Schedule mySchedule;
    Time myTime;
    AgentNode* pos;
    system("cls");
    header();
    cout << "\t\tAGENTES :: Insertando Agente" << endl << endl;
    cout << " No. de Empleado: ";
    cin >> auxi;
    myAgent.setEmployeeNumber(auxi);
    pos= agentListRef->findData(myAgent);
    if(pos != nullptr)
    {
        cout << "Este No. de Empleado ya fue registrado!" << endl;
        cout << "Revise los datos" << endl;
        cout << "Regresando... " << endl;
        pause();
        return;
    }

    cout << endl <<" Nombre: ";
    fflush(stdin);
    getline(cin,aux);
    myAgent.setName(aux);
    cout  << endl<< " No. De Extension: ";
    cin >> auxi;
    myAgent.setExtension(auxi);
    cout << endl << " Especialidad:" << endl;
    cout << "   *[1]Servidores" <<endl;
    cout << "   *[2]Escritorio" <<endl;
    cout << "   *[3]Portatiles" <<endl;
    cout << "   *[4]Linux" <<endl;
    cout << "   *[5]Impresoras" <<endl;
    cout << "   *[6]Redes" <<endl;
    cout << "Elige la especialidad:";
    fflush(stdin);
    cin >> auxc;
    switch(auxc)
    {
    case '1':
        aux="Servidores";
        break;
    case '2':
        aux="Escritorio";
        break;
    case '3':
        aux="Portatiles";
        break;
    case '4':
        aux="Linux";
        break;
    case '5':
        aux="Impresoras";
        break;
    case '6':
        aux="Redes";
        break;
    default:
        cout << "Especialidad Invalida!" << endl;
        cout << "Registro abortado!" << endl;
        cout << "Regresando..." << endl;
        pause();
        return;
    }
    myAgent.setWorkField(aux);

    cout << endl << " Que Dias Trabajas?" << endl;
    cout << "   *'Y' o 'y': Trabaja" << endl;
    cout << "   *(Cualquier otra tecla): No trabaja" << endl;
    fflush(stdin);
    cout << "   Lunes: ";
    cin >> auxc;
    if(auxc=='Y' or auxc == 'y')
    {
        auxb=true;
        cont=true;
    }
    else
    {
        auxb=false;
    }
    mySchedule.setMonday(auxb);

    fflush(stdin);
    cout << "   Martes: ";
    cin >> auxc;
    if(auxc=='Y' or auxc == 'y')
    {
        auxb=true;
        cont=true;
    }
    else
    {
        auxb=false;
    }
    mySchedule.setTuesday(auxb);

    fflush(stdin);
    cout << "   Miercoles: ";
    cin >> auxc;
    if(auxc=='Y' or auxc == 'y')
    {
        auxb=true;
        cont=true;
    }
    else
    {
        auxb=false;
    }
    mySchedule.setWednesday(auxb);

    fflush(stdin);
    cout << "   Jueves: ";
    cin >> auxc;
    if(auxc=='Y' or auxc == 'y')
    {
        auxb=true;
        cont=true;
    }
    else
    {
        auxb=false;
    }
    mySchedule.setThursday(auxb);

    fflush(stdin);
    cout << "   Viernes: ";
    cin >> auxc;
    if(auxc=='Y' or auxc == 'y')
    {
        auxb=true;
        cont=true;
    }
    else
    {
        auxb=false;
    }
    mySchedule.setFriday(auxb);

    fflush(stdin);
    cout << "   Sabado: ";
    cin >> auxc;
    if(auxc=='Y' or auxc == 'y')
    {
        auxb=true;
        cont=true;
    }
    else
    {
        auxb=false;
    }
    mySchedule.setSaturday(auxb);

    if(cont==false)
    {
        cout << "Ingresaste que no trabajas ningun dia, Horario Invalido!" << endl;
        cout << "Regresando..." << endl;
        pause();
        return;
    }
    cout << endl << endl;
    cout << "Ingresa la hora a la que entras (HH): ";
    cin >> auxi;
    myTime.setHour(auxi);
    cout << "Ingresa el minuto al que entras (MM): ";
    cin >> auxi;
    myTime.setMinute(auxi);
    mySchedule.setStartTime(myTime);

    cout << "Ingresa la hora a la que sales (HH): ";
    cin >> auxi;
    myTime.setHour(auxi);
    cout << "Ingresa el minuto al que sales (MM): ";
    cin >> auxi;
    myTime.setMinute(auxi);
    mySchedule.setEndTime(myTime);
    myAgent.setSchedule(mySchedule);

    cout << endl << " Horas extras que trabaja: ";
    cin >> auxi;
    myAgent.setExtraHours(auxi);

    cout  << endl << "Desea añadir Clientes al Agente?" << endl;
    cout << "  *'Y' o 'y': Si" << endl;
    cout << "  *Cualquier otro: No" << endl;
    cout << "  Su opcion: ";
    fflush(stdin);
    cin >> auxc;
    if(auxc=='Y' or auxc=='y')
    {
        new ClientMenu(&myAgent.getClientList());
    }
    try
    {
        agentListRef->insertData(agentListRef->getLastPos(),myAgent);
    }
    catch(ListException ex)
    {
        cout << "Hubo un problema insertando al agente " << endl;
        cout << "El sistema informa: " <<ex.what()<<endl;
        cout << "Regresando..." << endl;
        pause();
        return;
    }
    cout << endl << endl << "Se inserto al nuevo agente con exito!" << endl << endl;
    pause();


}

void agentMenu::modifyAgent()
{
    string aux;
    Agent myAgent,auxAgent;
    Time myTime;
    Schedule mySchedule;
    AgentNode* pos;
    AgentNode* auxpos;
    int auxi;
    bool auxb,cont=false;
    char op,auxc;
    fflush(stdin);
    system("cls");
    header();
    cout << "\t\tAGENTES :: Modificando Agente" << endl << endl;
    cout << "Deme el Numero de empleado al que desea modificar: ";
    cin >> auxi;
    myAgent.setEmployeeNumber(auxi);
    pos=agentListRef->findData(myAgent);
    if(pos==nullptr)
    {
        cout << endl << "No se encontro a ningun Agente con ese No. De Empleado." << endl;
        cout << "Corrobore sus datos y vuelva a intentar!" << endl << endl;
        pause();
        return;
    }
    myAgent=agentListRef->retrieve(pos);

    do
    {
        system("cls");
        header();
        cout << "\t\tAGENTES :: Modificando Agente" << endl << endl;
        cout << "\t[0] Mostrar los datos actuales del agente " << endl;
        cout << "\t[1] Cambiar Nombre" << endl;
        cout << "\t[2] Cambiar No. De Extension" << endl;
        cout << "\t[3] Cambiar No. De Empleado" << endl;
        cout << "\t[4] Cambiar Horario " << endl;
        cout << "\t[5] Cambiar Especialidad" << endl;
        cout << "\t[6] Cambiar Horas Extra" << endl;
        cout << "\t[7] Modificar Lista de Clientes " << endl;
        cout << "\t[8] Guardar y Regresar " << endl;
        cout << "\t[9] Abortar y Regresar " << endl << endl;
        cout << "############################################################################################" << endl << endl;
        cout << "\tElija una opcion: ";
        fflush(stdin);
        cin >> op;

        system("cls");
        header();
        cout << "\t\tAGENTES :: Modificando Agente" << endl << endl;
        switch(op)
        {
        case '0':
            cout << endl << myAgent.toString(true) << endl ;
            pause();
            break;
        case '1':
            cout << "Dame el nuevo nombre: ";
            fflush(stdin);
            getline(cin,aux);
            myAgent.setName(aux);
            break;
        case '2':
            cout << "Dame el nuevo No. de Extension: ";
            cin >> auxi;
            myAgent.setExtension(auxi);
            break;
        case '3':
            cout << "Dame el nuevo No. de Empleado: ";
            cin >> auxi;
            auxAgent.setEmployeeNumber(auxi);
            auxpos=agentListRef->findData(auxAgent);
            if(auxpos==nullptr)
            {
                myAgent.setEmployeeNumber(auxi);
            }
            else
            {
                cout << "Numero de empleado ya existente! Intente con otro!" << endl << endl;
                pause();
            }
            break;
        case '4':
            mySchedule=myAgent.getSchedule();
            cout << endl << " Cambiar:" << endl << endl ;
            cout << "   *[1]Dias que trabaja" <<endl;
            cout << "   *[2]Hora de Entrada" <<endl;
            cout << "   *[3]Hora de Salida" <<endl << endl ;
            cout << "Elige tu opcion: ";
            cin >> auxi;
            switch(auxi)
            {
            case 1:
                cout << endl << " Que Dias Trabajas?" << endl;
                cout << "   *'Y' o 'y': Trabaja" << endl;
                cout << "   *(Cualquier otra tecla): No trabaja" << endl;
                fflush(stdin);
                cout << "   Lunes: ";
                cin >> auxc;
                if(auxc=='Y' or auxc == 'y')
                {
                    auxb=true;
                    cont=true;
                }
                else
                {
                    auxb=false;
                }
                mySchedule.setMonday(auxb);

                fflush(stdin);
                cout << "   Martes: ";
                cin >> auxc;
                if(auxc=='Y' or auxc == 'y')
                {
                    auxb=true;
                    cont=true;
                }
                else
                {
                    auxb=false;
                }
                mySchedule.setTuesday(auxb);

                fflush(stdin);
                cout << "   Miercoles: ";
                cin >> auxc;
                if(auxc=='Y' or auxc == 'y')
                {
                    auxb=true;
                    cont=true;
                }
                else
                {
                    auxb=false;
                }
                mySchedule.setWednesday(auxb);

                fflush(stdin);
                cout << "   Jueves: ";
                cin >> auxc;
                if(auxc=='Y' or auxc == 'y')
                {
                    auxb=true;
                    cont=true;
                }
                else
                {
                    auxb=false;
                }
                mySchedule.setThursday(auxb);

                fflush(stdin);
                cout << "   Viernes: ";
                cin >> auxc;
                if(auxc=='Y' or auxc == 'y')
                {
                    auxb=true;
                    cont=true;
                }
                else
                {
                    auxb=false;
                }
                mySchedule.setFriday(auxb);

                fflush(stdin);
                cout << "   Sabado: ";
                cin >> auxc;
                if(auxc=='Y' or auxc == 'y')
                {
                    auxb=true;
                    cont=true;
                }
                else
                {
                    auxb=false;
                }
                mySchedule.setSaturday(auxb);

                if(cont==false)
                {
                    cout << "Ingresaste que no trabajas ningun dia, Horario Invalido!" << endl;
                    mySchedule=myAgent.getSchedule();
                    pause();

                }
                break;
            case 2:
                cout << "Ingresa la hora a la que entras (HH): ";
                cin >> auxi;
                myTime.setHour(auxi);
                cout << "Ingresa el minuto al que entras (MM): ";
                cin >> auxi;
                myTime.setMinute(auxi);
                mySchedule.setStartTime(myTime);
                break;
            case 3:
                cout << "Ingresa la hora a la que sales (HH): ";
                cin >> auxi;
                myTime.setHour(auxi);
                cout << "Ingresa el minuto al que sales (MM): ";
                cin >> auxi;
                myTime.setMinute(auxi);
                mySchedule.setEndTime(myTime);
                break;
            default:
                cout << "Opcion Invalida!" << endl << endl;
                pause();
                break;

            }
            myAgent.setSchedule(mySchedule);
            break;
        case '5':
            cout << endl << " Especialidad:" << endl;
            cout << "   *[1]Servidores" <<endl;
            cout << "   *[2]Escritorio" <<endl;
            cout << "   *[3]Portatiles" <<endl;
            cout << "   *[4]Linux" <<endl;
            cout << "   *[5]Impresoras" <<endl;
            cout << "   *[6]Redes" <<endl;
            cout << "Elige la especialidad: ";
            cin >> auxi;
            switch(auxi)
            {
            case 1:
                aux="Servidores";
                myAgent.setWorkField(aux);
                break;
            case 2:
                aux="Escritorio";
                myAgent.setWorkField(aux);
                break;
            case 3:
                aux="Portatiles";
                myAgent.setWorkField(aux);
                break;
            case 4:
                aux="Linux";
                myAgent.setWorkField(aux);
                break;
            case 5:
                aux="Impresoras";
                myAgent.setWorkField(aux);
                break;
            case 6:
                aux="Redes";
                myAgent.setWorkField(aux);
                break;
            default:
                cout << "Especialidad Invalida!" << endl;
                pause();
                break;
            }

            break;
        case '6':
            cout << "Dame las Horas extra: ";
            cin >> auxi;
            myAgent.setExtraHours(auxi);
            break;
        case '7':
            new ClientMenu(&myAgent.getClientList());
            break;
        case '8':
            try
            {

                agentListRef->insertData(pos,myAgent);
                agentListRef->deleteData(pos);
                cout << endl << "Los cambios se han realizado con exito!" << endl << endl;
            }
            catch(ListException ex)
            {
                cout << "Hubo un problema haciendo las modificaciones " << endl;
                cout << "El sistema informa: " <<ex.what()<<endl;
                cout << "Regresando..." << endl;
            }
            pause();
            break;
        case '9':
            cout << endl << "No se ha realizado ningun cambio." << endl << endl;
            pause();
            break;
        default:
            cout << "Opcion Invalida!" << endl << endl;
            pause();
            break;
        }

    }while(op!='8' and op!='9');

}

void agentMenu::deleteAgent()
{
    fflush(stdin);
    system("cls");
    header();
    Agent myAgent;
    string aux;
    bool auxb;
    cout << "\t\tAGENTES :: Eliminando :: Buscar y Eliminar" << endl << endl;
    cout << "Deme el nombre a Buscar: ";
    getline(cin,aux);
    myAgent.setName(aux);
    cout << endl;
    auxb=agentListRef->deleteDataByName(myAgent);


    if(auxb)
    {
        cout << endl << "Eliminacion Exitosa!" << endl << endl;
    }
    else
    {
        cout << endl << "(Ya) No hubo coincidencias!" << endl << endl;
    }
    pause();
}

void agentMenu::deleteAll()
{
    fflush(stdin);
    system("cls");
    header();
    cout << "\t\tAGENTES :: Eliminando Agentes :: Eliminar Todo" << endl << endl;
    agentListRef->deleteAll();
    cout << "Se ha eliminado completamente la lista de Agentes !" << endl << endl;
    pause();
}

void agentMenu::showAgent()
{
    fflush(stdin);
    system("cls");
    header();
    char op;
    string aux;
    bool auxb;
    Agent myAgent;
    cout << "\t\tAGENTES :: Mostrando Agentes :: Buscar y Mostrar" << endl << endl;
    cout << "Deme el nombre a Buscar: ";
    getline(cin,aux);
    myAgent.setName(aux);
    do
    {
        cout << "Desea incluir la lista de Clientes (Y/N) : ";
        fflush(stdin);
        cin >> op;
        cin.ignore();
        op=toupper(op);
    }while(op != 'Y' and op != 'N');
    if(op=='Y')
    {
        auxb=true;
    }
    else
    {
        auxb=false;
    }
    cout << endl << endl;
    cout << agentListRef->toStringByName(myAgent,auxb) << endl << endl;
    pause();
}

void agentMenu::showByWorkField()
{
    system("cls");
    header();
    char auxc,op;
    string aux;
    bool auxb;
    cout << "\t\tAGENTES :: Mostrando Agentes :: Mostrando Por Especialidad" << endl << endl;
    cout << endl << " Elige la especialidad a mostrar:" << endl;
    cout << "   *[1]Servidores" <<endl;
    cout << "   *[2]Escritorio" <<endl;
    cout << "   *[3]Portatiles" <<endl;
    cout << "   *[4]Linux" <<endl;
    cout << "   *[5]Impresoras" <<endl;
    cout << "   *[6]Redes" <<endl;
    cout << "Elige la especialidad: ";
    fflush(stdin);
    cin >> auxc;
    switch(auxc)
    {
    case '1':
        aux="Servidores";
        break;
    case '2':
        aux="Escritorio";
        break;
    case '3':
        aux="Portatiles";
        break;
    case '4':
        aux="Linux";
        break;
    case '5':
        aux="Impresoras";
        break;
    case '6':
        aux="Redes";
        break;
    default:
        cout << "Especialidad Invalida!" << endl;
        cout << "Regresando..." << endl << endl;
        pause();
        return;
    }
    do
    {
        cout << endl << "Desea incluir la lista de Clientes (Y/N) : ";
        fflush(stdin);
        cin >> op;
        cin.ignore();
        op=toupper(op);
    }while(op != 'Y' and op != 'N');
    if(op=='Y')
    {
        auxb=true;
    }
    else
    {
        auxb=false;
    }

    system("cls");
    header();
    cout << "\t\tAGENTES :: Mostrando Agentes :: Mostrando Por Especialidad" << endl << endl;
    cout << agentListRef->toStringByWorkField(aux,auxb) <<endl << endl;
    pause();

}

void agentMenu::showAll()
{
    system("cls");
    header();
    char op;
    bool aux;
    cout << "\t\tAGENTES :: Mostrando Agentes :: Mostrando Todo" << endl << endl;
    do
    {
        cout << "Desea incluir la lista de Clientes (Y/N) : ";
        fflush(stdin);
        cin >> op;
        cin.ignore();
        op=toupper(op);
    }while(op != 'Y' and op != 'N');
    if(op=='Y')
    {
        aux=true;
    }
    else
    {
        aux=false;
    }
    cout << endl << endl;
    cout << agentListRef->toString(aux) <<endl << endl;
    pause();
}

//Entregable 10

void agentMenu::sortAgent()
{
    char op2;
    do
    {
        system("cls");
        header();
        cout << "\t\tAGENTES :: Ordenando Agentes" << endl << endl;
        cout << "\t[1] Por Nombre" << endl;
        cout << "\t[2] Por Especialidad" << endl;
        cout << "\t[3] Regresar " << endl << endl;
        cout << "############################################################################################" << endl << endl;
        cout << "\tElija una opcion: ";
        fflush(stdin);
        cin >> op2;
        switch(op2)
        {
        case '1':
            agentListRef->sortByName();
            cout << endl << "Se ha ejecutado el ordenamiento por nombre!" << endl<<endl;
            pause();
            break;
        case '2':
            agentListRef->sortByWorkField();
            cout << endl << "Se ha ejecutado el ordenamiento por especialidad!" << endl<<endl;
            pause();;
            break;
        case '3':
            break;
        default:
            cout << "Opcion Invalida!" << endl << endl;
            pause();
            break;
        }
    }while(op2!='1' and op2!='2' and op2!='3');
}

//Entregable 11

void agentMenu::writeToDisk()
{
    string aux;

    system("cls");
    header();
    cout << "\t\tAGENTES :: Escribiendo al disco" << endl << endl;
    cout << "############################################################################################" << endl << endl;
    cout << "Ingresa el nombre del archivo: ";
    fflush(stdin);
    getline(cin,aux);
    try
    {
        agentListRef->writeToDisk(aux);
    }
    catch(ListException ex)
    {
        cout << "Hubo un problema! "<<endl;
        cout << ex.what() << endl << endl;
        pause();
        return;
    }
    cout << "Escritura exitosa! "<<endl <<endl;
    pause();
}

void agentMenu::readFromDisk()
{
    string aux;

    system("cls");
    header();
    cout << "\t\tAGENTES :: Leyendo desde el disco" << endl << endl;
    cout << "############################################################################################" << endl << endl;
    cout << "Ingresa el nombre del archivo: ";
    fflush(stdin);
    getline(cin,aux);
    try
    {
        agentListRef->readFromDisk(aux);
    }
    catch(ListException ex)
    {
        cout << "Hubo un problema! "<<endl;
        cout << ex.what() << endl << endl;
        pause();
        return;
    }
    cout << "La lectura finalizo con exito! "<<endl <<endl;
    pause();
}




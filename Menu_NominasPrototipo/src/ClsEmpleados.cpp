//clase
#include "ClsEmpleados.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

//constructor
ClsEmpleados::ClsEmpleados(int valorClave, const string &m_sNombreEmpleado) : m_iClave(valorClave)
{
    mestablecerNombre(m_sNombreEmpleado);
}

//obtiene la clave
int ClsEmpleados::mobtenerClave() const
{
    return m_iClave;
}

void ClsEmpleados::mestablecerClave (int valorClave)
{
    m_iClave = valorClave;
}

//obtiene el nombre completo
string ClsEmpleados::mobtenerNombre() const
{
    return m_sNombreEmpleado;
}

//establecer nombre
void ClsEmpleados::mestablecerNombre(const string &cadenaNombreEmpleado)
{
    int longitud = cadenaNombreEmpleado.size();
    longitud = ( longitud < 40 ? longitud : 39);
    cadenaNombreEmpleado.copy(m_sNombreEmpleado, longitud);
    m_sNombreEmpleado[longitud]='\0';
}

//Ingreso de datos de un uevo empleado
ClsEmpleados::mAgregarEmpleado()
{
	int iespacios=0;
	system("cls");
	ofstream archivoEmpleados("registrosempleados.dat", ios::out | ios::binary);
	if( !archivoEmpleados )
    {
        cerr << "No se pudo abrir el archivo registro empleados." << endl;
        exit( EXIT_FAILURE );
    }
	ClsEmpleados empleado;
	cout<<"ingrese clave: ";
	cin>>m_iClave;
	ClsEmpleados empleadoEnBlanco;
	for(int iespacios= 0; iespacios < 100; ++iespacios)
    {
        archivoEmpleados.write(reinterpret_cast<const char* > (&empleadoEnBlanco), sizeof(ClsEmpleados));
    }
	while (m_iClave>0 && m_iClave<100)
    {
        cout<<"Agregar nuevo Empleado"<<endl;
        cout<<"Ingresa el nombre del empleado: " << endl;
        cin>> m_sNombreEmpleado;
        cout<<"Ingresa el numero de DPI del empleado: ";
        cin>>m_sDpiEmpleado;
        cout<<"Ingresa la direcci�n de residencia del empleado: ";
        cin>>m_sDireccionEmpleado;
        cout<<"Ingresa el n�mero de telefono del empleado: ";
        cin>>m_sTelefonoEmpleado;
        cout<<"Ingresa el correo electronico del empleado: ";
        cin>>m_sCorreoEmpleado;
        empleado.mestablecerClave(m_iClave);
        empleado.mestablecerNombre(m_sNombreEmpleado);
        archivoEmpleados.seekp((empleado.mobtenerClave() - 1 ) * sizeof(ClsEmpleados));
        archivoEmpleados.write(reinterpret_cast<const char * > (&empleado), sizeof (ClsEmpleados));
        cout<<"ingrese clave: ";
        cin>>m_iClave;
    }
	cout<<"Ingresa el numero de DPI del empleado: ";
	cin>>m_sDpiEmpleado;
	cout<<"Ingresa la direcci�n de residencia del empleado: ";
	cin>>m_sDireccionEmpleado;
	cout<<"Ingresa el n�mero de telefono del empleado: ";
	cin>>m_sTelefonoEmpleado;
	cout<<"Ingresa el correo electronico del empleado: ";
	cin>>m_sCorreoEmpleado;
	archivoEmpleados.close();
}

//Agregar un nuevo empleado
/*ClsEmpleados::mIngresarEmpleado()
{
    char cDecisionNuevoEmpleado;
do
    	{
    		mAgregarEmpleado();
    		cout<<"Desea agregar otra empleado?(Y,N): ";
    		cin>>cDecisionNuevoEmpleado;
		}while(cDecisionNuevoEmpleado=='y'||cDecisionNuevoEmpleado=='Y');
}*/

ClsEmpleados::mDespliegueEmpleados()
{
	system("cls");
	ifstream archivoEmpleados("registrosempleados.dat", ios::in | ios:: binary);
	int total=0;
	cout<<"Tabla de Detalles de Personas"<<endl;
	if(!archivoEmpleados)
	{
		cerr << "No se pudo abrir el archivo registro empleados." << endl;
        exit( EXIT_FAILURE );
	}
	else
	{
		ClsEmpleados empleado;
		while(!archivoEmpleados.eof())
		{
			total++;
			cout<<"Nombre: "<<empleado.mobtenerNombre() <<endl;
			cout<<"Clave: "<<empleado.mobtenerClave() <<endl;
		}
		if(total==0)
		{
			cout<<"No hay informacion...";
		}
	}
	archivoEmpleados.close();
}
/*Empleados::modify()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
	file.open("ParticipantRecordEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la personas que quiere modificar: ";
		cin>>participant_id;
		file1.open("RecordEmpleados.txt",ios::app | ios::out);
		file >> id >> name >> phone >> mail >> affiliation;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< affiliation << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese DPI Empleado: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre y Apellido Empleado: ";
				cin>>name;
				cout<<"\t\t\tIngrese Telefono Empleado: ";
				cin>>phone;
				cout<<"\t\t\tIngrese Correo Empleado: ";
				cin>>mail;
				cout<<"\t\t\tIngrese No.Afiliacion Persona: ";
				cin>>affiliation;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< affiliation << "\n";
				found++;
			}
			file >> id >> name >> phone >> mail >> affiliation;

		}
		file1.close();
		file.close();
		remove("ParticipantRecordEmpleados.txt");
		rename("RecordEmpleados.txt","ParticipantRecordEmpleados.txt");
	}
}

Empleados::searchE()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecordEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Empleado buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_idEmpleado;
		cout<<"\n-------------------------Datos del Empleado buscado------------------------"<<endl;
		cout<<"\nIngrese DPI del Empleado que quiere buscar: ";
		cin>>participant_idEmpleado;
		file >> id >> name >> phone >> mail >> affiliation;
		while(!file.eof())
		{
			if(participant_idEmpleado==id)
			{
				cout<<"\n\n\t\t\t DPI Empleado: "<<id<<endl;
				cout<<"\t\t\t Nombre y Apellido Empleado: "<<name<<endl;
				cout<<"\t\t\t Telefono Empleado: "<<phone<<endl;
				cout<<"\t\t\t Correo Empleado: "<<mail<<endl;
				cout<<"\t\t\t No.Afiliacion Empleado: "<<affiliation<<endl;
				found++;
			}
			file >> id >> name >> phone >> mail >> affiliation;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Empleado no encontrado...";
		}
		file.close();
	}
}
Empleados::deletE()
{
	system("cls");
	fstream file,file1;
	string participant_idEmpleado;
	int found=0;
	cout<<"\n-------------------------Detalles Empleado a Borrar-------------------------"<<endl;
	file.open("ParticipantRecordEmpleados.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el DPI del Empleado que quiere borrar: ";
		cin>>participant_idEmpleado;
		file1.open("RecordEmpleados.txt",ios::app | ios::out);
		file >> id >> name >> phone >> mail >> affiliation;
		while(!file.eof())
		{
			if(participant_idEmpleado!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< mail <<std::left<<std::setw(15)<< affiliation << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name >> phone >> mail >> affiliation;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t DPI Empleado no encontrado...";
			getch();
		}
		file1.close();
		file.close();
		remove("ParticipantRecordEmpleados.txt");
		rename("RecordEmpleados.txt","ParticipantRecordEmpleados.txt");
	}
}
*/
//Menu de gestion de los datos de empleado
ClsEmpleados::mMenuEmpleados()
{
    ClsEmpleados empleado;
    int iSeleccionMenuEmpleados;
	do
    {
	system("cls");

	cout<<"-------------------------------"<<endl;
	cout<<"|   SISTEMA GESTION EMPLEADOS  |"<<endl;
	cout<<"-------------------------------"<<endl;
	cout<<"1. Ingreso Empleados"<<endl;
	cout<<"2. Despliegue Empleados"<<endl;
	cout<<"3. Modifica Empleados"<<endl;
	cout<<"4. Busca Empleados"<<endl;
	cout<<"5. Borra Empleados"<<endl;
	cout<<"6. Volver al menu superior"<<endl;

	cout<<"-------------------------------"<<endl;
	cout<<"Opcion a escoger:[1/2/3/4/5/6]"<<endl;
	cout<<"------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>iSeleccionMenuEmpleados;

    switch(iSeleccionMenuEmpleados)
    {
    case 1:
        empleado.mAgregarEmpleado();
        break;
	case 2:
		empleado.mDespliegueEmpleados();
		break;
	/*case 3:
		modificarE.modify();
		getch();
		break;
	case 4:
		buscarE.searchE();
		getch();
		break;
	case 5:
		borrarE.deletE();
		break;*/
	case 6:
		break;
	default:
		cout<<"Opcion invalida...Por favor prueba otra vez..";
		getch();
	}
    }while(iSeleccionMenuEmpleados!= 6);
}
ClsEmpleados::~ClsEmpleados()
{
    //dtor
}

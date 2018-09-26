#include <iostream>
#include <conio.h>
using namespace std;
struct Nodo{
	int dato;
	struct Nodo *siguiente;
}*inicio,*aux,*actual,*anterior;

void insertarNodo(int);
void eliminarNodo(int);
void mostrarNodos();
void ordenarNodos();
int main(int argc, char** argv) {
	inicio=NULL;
	int opcion=1;
	int valor=0;
	do{
		cout<<"\n Menu "<<endl;
		cout<<"1.- insertar nodo"<<endl;
		cout<<"2.- eliminar nodo"<<endl;
		cout<<"3.- Mostrar nodos"<<endl;
		cout<<"4.- ordenar nodos"<<endl;
		cout<<"5.- salir"<<endl;
		cin>>opcion;
		if(opcion==1){
			cout<<"Valor del nodo a insertar: ";
			cin>>valor;
			insertarNodo(valor);
		}else if(opcion==2){
			cout<<"Valor del nodo a borrar: ";
			cin>>valor;
			eliminarNodo(valor);
		}else if(opcion==3){
			mostrarNodos();
		}else if(opcion==4){
			ordenarNodos();
		}else{	
			cout<<"terminado\n\n";
		}
		
	}while(opcion!=5);

	mostrarNodos();
		
	cin.get();
	return 0;
}
void insertarNodo(int valor){
	actual=inicio;
	if(actual==NULL){
			aux=new Nodo();
			aux->dato=valor;
			aux->siguiente=NULL;
			inicio=aux;
	}else{
		while(actual->siguiente!=NULL)
		{
			actual=actual->siguiente;
			}		
		aux=new Nodo();
		aux->dato=valor;
		aux->siguiente=NULL;
		actual->siguiente=aux;
	}
}

void eliminarNodo(int valor){
	if(inicio!=NULL){
		aux=NULL;
		actual=inicio;
		while((actual!=NULL) && (actual->dato!=valor)){
			aux=actual;
			actual=actual->siguiente;
		}
		if(actual==NULL){
			cout<<"no encontrado"<<endl;
		}else if(aux==NULL){
			inicio=inicio->siguiente;
			delete actual;
		}else{
			aux->siguiente=actual->siguiente;
			delete actual;
		}
	}
}
void mostrarNodos(){
	actual=inicio;
	cout<<" \nMostrar\n ";
	while(actual!=NULL){
		cout<<" -> "<<actual->dato<<" ";
		actual=actual->siguiente;
	}
	cout<<"\n";
}
void ordenarNodos(){
	if(inicio!=NULL){		
		anterior=NULL;
		aux=NULL;
		actual=inicio;
		while((actual->siguiente!=NULL) && (actual->dato < actual->siguiente->dato)){							
				anterior=actual;
				actual=actual->siguiente;
		}
			if (actual->siguiente==NULL)
			{
				cout<<"\nordenamiento terminado\n";
			}else if(anterior==NULL){
				aux=actual;
				actual=actual->siguiente;
				inicio=actual;
				aux->siguiente=actual->siguiente;
				actual->siguiente=aux;
			}else{
				aux=actual;
				actual=actual->siguiente;
				anterior->siguiente=actual;
				aux->siguiente=actual->siguiente;
				actual->siguiente=aux;
			}
	}
}

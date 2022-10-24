#include <iostream>
using namespace std;


struct Persona {
string nombre;
bool capitan;
int poder;
};

struct tNodo{
 Persona info;
 tNodo* sig;
};

class Equipo {
	private:
		tNodo* head;
		tNodo* tail;
		tNodo* curr;
		unsigned int listSize;
		unsigned int pos; // posicion actual en la lista
	public:

		Equipo() {
		head = tail = curr = new tNodo;
		listSize = 0;
		pos = 0;
		}

		int insert(Persona item) {
			moveToEnd();
			tNodo* aux = curr->sig;
			curr->sig = new tNodo;
			curr->sig->info = item;
			curr->sig->sig = aux;
			if (curr == tail) tail = curr->sig;
			listSize++;
			return pos;
		}

		void moveToStart() { curr = head; pos = 0; }
		void moveToEnd() { curr = tail; pos = listSize; }
		void next() { if (curr != tail) { curr = curr->sig; pos++; } }

		void prev() {
			tNodo* temp;
			if (curr == head) return;
			temp = head;
			while (temp->sig != curr) temp = temp->sig;
			curr = temp;
			pos--;
			}

		void moveToPos(unsigned int posicion) {
			unsigned int i;
			if (posicion < 0 || posicion > listSize) return;
			curr = head;
			pos = 0;
			for (i = 0; i < posicion; i++) {
			curr = curr->sig;
			pos++;
			}
		}
		void tamano(){
			cout << listSize;
		}
		int agregar_companero(string nombre, int poder){
			Persona a;
			a.nombre = nombre;
			a.poder = poder;
			a.capitan = false;
			return insert(a);
		}
		int calcular_poder(){

			int suma = 0;
			moveToStart();
			for(unsigned int i=0;i<=listSize;i++){
				if (curr != tail) { 
					suma =suma + curr->info.poder;
					curr = curr->sig;
					pos++; 
				}
				else{
					suma = suma + curr->info.poder;
				}
			}
			return suma;
		}
		
		void imprimir_equipo(){
			moveToStart();
			cout << "Equipo:" << endl;
			for(unsigned int i=0;i<listSize;i++){

				if (curr != tail) { 
					if (curr != head){
					cout << "Persona"<<i-1<<": "<< curr->info.nombre<<curr->info.capitan << curr->info.poder<<endl;
					}
					curr = curr->sig;
					pos++; 
				}
				if (curr == tail){
					i++;
					cout << "Persona"<<i-1<<": "<< curr->info.nombre<<curr->info.capitan << curr->info.poder<<endl;
				}
			}
		}
	};

int main(){
	Equipo team;

	return 0;
};
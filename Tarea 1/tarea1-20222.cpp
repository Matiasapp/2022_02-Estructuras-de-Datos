#include <iostream>
#include <fstream>
using namespace std;

struct estudiante{
    string rol;
    string nombre;
    string apellido;
    int paralelo;
};

struct Registro {
    int dia;
    int mes;
    int anio;
    char rol[12];
    int ppm;
    float precision;
};

estudiante* read_estu(int& n_estu){
    ifstream fe;
    long unsigned int i;
    string text,line;
    fe.open("estudiantes.txt");
    i=0;
	while(getline(fe, line)) {
		text = text + line + "\n";
        i++;
	}
    fe.close();
    n_estu = i;
    estudiante* e = new estudiante[n_estu];
    i=0;
    int st=0;
    int espacio=0;
    int z = 0;
    bool flag = false;
    while (i<text.size()-1){

        if (text[i] == ' ') espacio++;
        if (espacio == 1 && flag == 0){
            e[z].rol = text.substr(st,i-st);
            flag = 1;
            st = i;
        }
        if (espacio == 2 && flag == 1){
            e[z].nombre = text.substr(st+1,i-st-1);
            flag=0;
            st=i;
        }
        if (espacio == 3 && flag == 0){
            e[z].apellido = text.substr(st+1,i-st-1);
            e[z].paralelo = stoi(text.substr(i,4));
            flag=1; 
        }
        if (text[i] == '\n'){
            z++;
            st=i+1;
            espacio = 0;
            flag=0;
        }
        i++;
    }
    fe.close();
    return e;
}

Registro* read_reg(int &n_reg){
    ifstream freg;
    freg.open("registros.dat",ios::binary);
    freg.read((char*) &n_reg, sizeof(int));
    Registro* reg = new Registro[n_reg];
    freg.read((char*) reg, sizeof(Registro)*n_reg);
    freg.close();
    return reg;
}

string preguntas(int& n_reg,Registro* reg){
    int t,d,m,a;
    string thebest;
    int ppm = 0;
    float precision=0;
    int i=0;
    bool igmes = 0,igdia=0;

    cin>>t>>d>>m>>a;
    if(d==-1)   igdia=true;
    if(m==-1)   igmes=true;
    for (i=0;i<n_reg;i++){
        if(d==reg[i].dia || igdia == true){
            if (m==reg[i].mes || igmes == true){
                if(a==reg[i].anio){
                    if(t==0){  
                        if(reg[i].precision > precision){
                            thebest = string(reg[i].rol);
                            precision = reg[i].precision;
                        }
                    }
                    else{
                        if(reg[i].ppm > ppm){
                            thebest = string(reg[i].rol);
                            ppm = reg[i].ppm;
                        }
                    }
                }
            }
        }
    }
    return thebest;
}
string nombrebuscado(string rol_buscado,int n_estu,estudiante* estudiantes){
    int i =0;
    string nombreapellido;
    for(i=0;i<n_estu;i++){
        if (estudiantes[i].rol == rol_buscado){
            nombreapellido = estudiantes[i].nombre +" "+estudiantes[i].apellido;
            return nombreapellido;
        }
    }
    return "No existe";
}

int main(){
    int n_estu,n_reg,n_consultas,i;
    string rol_buscado;
    string nombre,textfin;

    estudiante* estudiantes = read_estu(n_estu);
    Registro* registros = read_reg(n_reg);

    cout<<"Ingrese cantidad de consultas: ";
    cin >> n_consultas;

    for (i=0;i<n_consultas;i++){
        rol_buscado=preguntas(n_reg,registros);
        nombre = nombrebuscado(rol_buscado,n_estu,estudiantes);
        textfin=textfin + nombre + '\n';
    }
    cout<<textfin;
    
    delete[] registros;
    delete[] estudiantes;
    return 0;
}
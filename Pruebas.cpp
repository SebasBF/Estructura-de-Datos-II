#include <iostream>
#include <dirent.h>

using namespace std;

void list_dir(string dir){
    DIR * directorio;
    struct dirent * elemento;
    string elem;

    if(directorio = opendir(dir.c_str())){

        while (elemento = readdir(directorio)){
            elem = elemento->d_name;
            cout << elem << endl;
        }
        
    }
    closedir(directorio);
      
}

void init(){
    cout << "Ruta del directorio a listar: ";
    string dir;
    getline(cin,dir);
    list_dir(dir);

    init();
}

int main(){
    init();

    return 0;
}
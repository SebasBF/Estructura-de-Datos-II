#include <iostream>
#include <dirent.h>
#include <sys/stat.h>

using namespace std;

bool esDirectorio(const string& path) {
    struct stat info;
    if (stat(path.c_str(), &info) != 0) {
        cerr << "Error al acceder a la ruta: " << path << endl;
        return false;
    }
    return S_ISDIR(info.st_mode);
}

void list_dir(string dir, string extention){
    DIR * directorio;
    struct dirent* elemento;
    string elem;

    if(directorio = opendir(dir.c_str())){

        while (elemento = readdir(directorio)){
            
            elem = elemento -> d_name;
            size_t posicionPunto = elem.find_last_of(".");
            string extension = elem.substr(posicionPunto + 1);
            string fullPath = dir + "\\" + elem; 

            if (elem == "." || elem == "..") {
                continue;
            }

            if (esDirectorio(fullPath)) {
                
                list_dir(fullPath, extension); 

            } else {
                size_t posicionPunto = elem.find_last_of(".");
                
                    string fileExtension = elem.substr(posicionPunto + 1);
                    if (fileExtension == extension) {
                        cout << "Archivo encontrado: " << fullPath << endl;
                    }
                
            }
            
        }
        
    }
    closedir(directorio);
      
}

void init(){
    string extension;
    string dir = "C:\\Users\\1122881\\Desktop\\Directories";
    cout << "Ruta del directorio a listar: " << dir;
    cout << "\nIndique la extension a listar: ";
    cin >> extension;

    list_dir(dir, extension);

   
}

int main(){
    init();

    return 0;
}
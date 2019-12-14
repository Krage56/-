#include <iostream>
#include <fstream>
using namespace std;
const size_t mem_block = 1024;

bool is_empty_file(fstream *file){
    long file_size;
    file->seekg(0, ios::end);
    file_size = file->tellg();
    if(file_size == 0){
        return true;
    }
    else{
        return false;
    }
}

void return_in_pos(fstream *file, bool pos){
    file->clear();
    pos ? file->seekg(0, ios_base::beg): file->seekg(0, ios_base::end);
}

void return_in_pos(fstream *file, int pos){
    file->clear();
    file->seekg(pos, ios_base::beg);
}

void filePrint(fstream *file){
    return_in_pos(file, true);
    char buf[mem_block];
    size_t i = 1;
    while(!file->eof()){
        file->getline(buf, mem_block, '\n');
        cout << i << " ";
        ++i;
        cout << buf << endl;
    }
}

void fileAppend(fstream *file, char *str){
    return_in_pos(file, false);
    if(!(is_empty_file(file))){
        *file << endl;
    }
    while(*str) {
        *file << *(str);
        ++str;
    }
}
/*вести строки
 * с их номерами, в которыхесть указанная подстрока;
 * указанную подстроку в строке выводить в ВЕРХНЕМ регистре.*/
/*void fileSearch(fstream *file, char *needle){

}*/

int main() {
    fstream file;
    file.open("ex.txt", ios_base::in | ios_base::out);
    if(!file.is_open()){
        cout << "error" << endl;
        return -1;
    }
    else{
        char *str = new char[mem_block];
        cin.getline(str, (mem_block - 1));
        fileAppend(&file, str);
        filePrint(&file);
    }
    file.close();
    return 0;
}
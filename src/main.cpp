#include <iostream>
#include <fstream>
#include <string>
#include "queens.h"

int main(){
    std::string filename;
    std::ifstream file;
    std::string line;
    int x, y;
    char c;
    int boardWidth;
    bool isValid;
    char color;
    std::vector<coordinates> coords;

    //=====================================INPUT=====================================

    std::cout << "Masukkan nama file (.txt): ";
    std::cin >> filename;

    if(filename.size() < 4 || filename.substr(filename.size() - 4) != ".txt"){
        std::cerr << "error: file tidak berekstensi .txt!" << std::endl;
        return 1;
    }

    file.open(filename);
    if(!file.is_open()){
        std::cerr << "error: tidak dapat membuka file!" << filename << std::endl;
        return 1;
    }

    //=====================================BACA FILE=====================================
    y = 0;
    boardWidth = -1;
    isValid = true;


    while(std::getline(file, line)){
        //trim trailing whitespace (spasi, tab, \r, \n)
        while(!line.empty() && (line.back() == ' ' || line.back() == '\t' || line.back() == '\r' || line.back() == '\n')){
            line.pop_back();
        }
        
        //skip baris kosong
        if(line.empty()){
            continue;
        }

        board.push_back(line);

        //hitung lebar papan
        int charCount = 0;
        for(int i = 0; i < static_cast<int>(line.size()); i++){
            if(line[i] != ' ' && line[i] != '\t'){
                charCount++;
            }
        }

        if(boardWidth == -1){
            boardWidth = charCount;
        }
        else if(charCount != boardWidth){
            std::cerr << "error: ukuran papan tidak konsisten" << std::endl;
            isValid = false;
            return 1;
        }

        //simpan koordinat karakter non spasi
        int colIdx = 0;
        for(int x = 0; x < static_cast<int>(line.size()); x++){
            char c = line[x];
            if(c != ' ' && c != '\t'){
                colors_coordinate[c].push_back({colIdx, y});
                colIdx++;
            }
        }
        ++y;
    }

    file.close();
    //=====================================VALIDASI INPUT=====================================
    if(board.empty()){
        std::cerr << "error: papan tidak boleh kosong!" << std::endl;
        return 1;
    }

    if(board.size() != static_cast<size_t>(boardWidth)){
        std::cerr << "error: papan harus persegi" << std::endl;
        return 1;
    }

    if(colors_coordinate.size() != board.size()){
        std::cerr << "error: jumlah warna harus sama dengan ukuran papan" << std::endl;
        return 1;
    }

    std::cout << "input valid" << std::endl;
    std::cout << "jumlah warna: " << colors_coordinate.size() << std::endl;

    //=====================================ALGORITMA INTI=====================================

    //taruh queens di koordinat awal dari setiap warna
    for(const auto& pair : colors_coordinate){
        char color = pair.first;
        const std::vector<coordinates>& coords = pair.second;
        if(!coords.empty()){
            queens_position[color] = coords[0];
        }
    }

    ShiftQueens(queens_position);
    
}
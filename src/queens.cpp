#include "queens.h"

std::map<char, std::vector<coordinates>> colors_coordinate;
std::map<char, coordinates> queens_position;
std::vector<std::string> board;

void clearScreen(){
    system("cls");
}

void ShiftQueens(std::map<char,coordinates>& queens_position){
    //array of char untuk menyimpan warna-warna yang ada
    std::vector<char> colors;
    int n, carry, iterationCount = 0;
    //array of int untuk menyimpan index koordinat yang dipilih untuk setiap warna
    std::vector<int> indices;
    std::vector<int> maxIndices;
    coordinates posA, posB;
    std::map<char, coordinates> tempPos;
    bool found, allValid;
    float waktuMs;

    //buat daftar warna dari colors_coordinate
    for(const auto& pair : colors_coordinate){
        colors.push_back(pair.first);
    }
    n = colors.size();

    //inisialisasi indices dengan 0 untuk semua warna
    indices.resize(n, 0);

    //hitung jumlah koordinat max setiap warna
    for(int i = 0; i < n; i++){
        maxIndices.push_back(colors_coordinate[colors[i]].size());
    }
    found = false;

    //algoritma brute force: coba semua kombinasi
    auto startTime = std::chrono::high_resolution_clock::now();
    while(!found){
        iterationCount++;

        for(int i = 0; i < n; i++){
            tempPos[colors[i]] = colors_coordinate[colors[i]][indices[i]];
        }
        
        clearScreen();
        std::cout << "konfigurasi ke-" << iterationCount << ":" << std::endl;
        printBoard(tempPos);
        std::this_thread::sleep_for(std::chrono::milliseconds(300)); //tunggu 0.3 detik

        //cek apakah ada konflik antara queen
        allValid = true;
        for(int i = 0; i < n && allValid; i++){
            for(int j = i + 1; j < n && allValid; j++){
                posA = tempPos[colors[i]];
                posB = tempPos[colors[j]];

                //cek baris, kolom, diagonal bersentuhan (jarak 1)
                if(posA.x == posB.x || posA.y == posB.y ||
                   (abs(posA.x - posB.x) == 1 && abs(posA.y - posB.y) == 1)){
                    allValid = false;
                }
            }
        }

        if(allValid){
            queens_position = tempPos;
            found = true;
        }
        else{
            //increment indices
            carry = n - 1;
            while(carry >= 0){
                indices[carry]++;
                if(indices[carry] < maxIndices[carry]){
                    break;
                }
                indices[carry] = 0; //reset dan carry ke digit berikutnya
                carry--;
            }

            if(carry < 0){
                //sudah mencoba semua kombinasi
                std::cout << "Tidak ada solusi" << std::endl;
                break;
            }
        }
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    waktuMs = std::chrono::duration<float, std::milli>(endTime - startTime).count();

    std::cout << "hasil akhir: " << std::endl;
    printBoard(queens_position);

    std::cout << "jumlah konfigurasi yg telah ditinjau: " << iterationCount << std::endl;
    std::cout << "waktu eksekusi: " << waktuMs << " ms" << std::endl;
    
}

void printBoard(const std::map<char, coordinates>& queens_pos){
    //buat salinan board untuk dimodifikasi
    std::vector<std::string> output = board;

    //tandai posisi queen dengan '#'
    for(const auto& pair : queens_pos){
        coordinates pos = pair.second;
        if(pos.y >= 0 && pos.y < static_cast<int>(output.size())){
            int colIdx = 0;
            for(int i = 0; i < static_cast<int>(output[pos.y].size()); i++){
                if(output[pos.y][i] != ' ' && output[pos.y][i] != '\t'){
                    if(colIdx == pos.x){
                        output[pos.y][i] = '#';
                        break;
                    }
                    colIdx++;
                }
            }
        }
    }

    //cetak board
    for(const auto& line : output){
        std::cout << line << std::endl;
    }
}
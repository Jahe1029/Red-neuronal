//#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>
#include <iostream>
#include "lib/eigen-3.4.0/Eigen/Dense"
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

void parseCSVLine(const std::string& line, Eigen::VectorXd& values);
void read_csv();
using Eigen::MatrixXd;

class layer{
public:
    //En cada fila, sus elementos son los pesos y cada a_i del input se multiplica por un w_i de la fila
    MatrixXd L;
    Eigen::VectorXd b;
    layer(int n, int w){           
        L = MatrixXd::Random(n, w).cwiseAbs();
        b = Eigen::VectorXd::Random();

        //L.cwiseAbs();
    }
    void print(){
    std::cout << L << "\n\n\n";
    }

    
    

};
 
int main()
{   
    std::ifstream file ("mnist_test.csv");
    std::string line;

    Eigen::VectorXd pixels(784);
    std::getline(file, line);
    std::cout << line;
    int i = 0;
    while (file >> line){
        

        
        parseCSVLine(line.substr(2), pixels);
        std::cout << pixels;
        
        i++;
        if(i == 784){break;}
    }

    return 0;
}

// Leer una línea del CSV y convertirla a vector de enteros
void parseCSVLine(const std::string& line, Eigen::VectorXd& values){
    std::stringstream ss(line);
    std::string item;
    int i = 0;
    while (getline(ss, item, ',')) {
        std::cout << item;
        values[i] = std::stoi(item);
        i++;
    }
}

/*
void read_csv(){

    std::ifstream file ("mnist_train.cvs");
    std::string line;
    int lineCount = 0;

    // Almacenar etiquetas e imágenes
    std::vector<std::vector<int>> images;
    std::vector<int> labels;

    while (getline(file, line)) {
        std::vector<int> values = parseCSVLine(line);

        if (values.size() != 785) continue;  // Validación

        labels.push_back(values[0]);  // La primera columna es la etiqueta

        // Los 784 píxeles siguientes son la imagen
        std::vector<int> image(values.begin() + 1, values.end());
        images.push_back(image);

        // Mostrar solo las primeras 5 líneas
        if (++lineCount <= 5) {
            std::cout << "Etiqueta: " << labels.back() << ", Primeros 5 píxeles: ";
            for (int i = 0; i < 5; ++i) std::cout << image[i] << " ";
            std::cout << "...\n";
        }
    }

    std::cout << "Total de imágenes cargadas: " << images.size() << std::endl;

    file.close();

}
    */

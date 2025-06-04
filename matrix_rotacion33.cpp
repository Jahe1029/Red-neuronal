#include <cmath>
#include <iostream>
#include <vector>

std::vector<double>matrix_x(double thetax);
std::vector<double>matrix_y(double thetay);
std::vector<double>matrix_z(double thetaz);

//std::vector<double>product_matrix(std::vector<double>&A, std::vector<double>&B, int fil_A, int col_A, int fil_B, int col_B);

void print_matrix(const std::vector<double> & data, int m, int n);

std::vector<double> product_matrix(const std::vector<double> & A,
    const std::vector<double> & B,
    const int nrows, const int ncols);

int main(int argc, char **argv){
    const double vx = std::stod(argv[1]);
    const double vy = std::stod(argv[2]);
    const double vz = std::stod(argv[3]);
    const double thetax = std::stod(argv[4]);
    const double thetay = std::stod(argv[5]);
    const double thetaz = std::stod(argv[6]);
    std::vector<double>V = {vx, vy, vz};
    std::vector<double>m_x = matrix_x(thetax);
    std::cout << "m_x\n"; print_matrix(m_x, 3, 3);
    std::vector<double>m_y =matrix_y(thetay);
    std::cout << "m_y\n"; print_matrix(m_y, 3, 3);
    std::vector<double>m_z =matrix_z(thetaz);
    std::cout << "m_z\n"; print_matrix(m_z, 3, 3);
    std::vector<double>m_zy =product_matrix(m_z, m_y, 3, 3);
    std::cout << "m_zy\n"; print_matrix(m_zy, 3, 3);
    std::vector<double>m_zyx =product_matrix(m_zy, m_x, 3,3);
    std::cout << "\n\nm_zyx\n"; print_matrix(m_zyx, 3, 3);
    std::vector<double>m_zyxv =product_matrix(m_zyx, V, 3,1);

    print_matrix(m_zyxv, 3, 1);
    std::cout << "\n\nsize: " << m_zyxv.size();
    return 0;

}



std::vector<double>matrix_x(double thetax){
    std::vector<double> m_x={
        1.0,       0.0,             0.0, 
        0.0, std::cos(thetax), -std::sin(thetax), 
        0.0, std::sin(thetax), std::cos(thetax) };
        return m_x;

}

std::vector<double>matrix_y(double thetay){
    std::vector<double> m_y={
        std::cos(thetay), 0.0, std::sin(thetay), 
             0.0,         1.0,       0.0, 
        -std::sin(thetay), 0.0, std::cos(thetay) };
    return m_y;

}


std::vector<double>matrix_z(double thetaz){
    std::vector<double> m_z={
        std::cos(thetaz), -std::sin(thetaz), 0.0, 
        std::sin(thetaz), std::cos(thetaz),  0.0, 
              0.0,             0.0,          1.0 };
        return m_z;

}

std::vector<double>product_matrix(const std::vector<double> & A,
    const std::vector<double> & B,
    const int nrows, const int ncols) {
    std::vector<double> C(nrows *ncols);
    for (int ii = 0; ii < nrows; ++ii){
        for (int jj = 0; jj < nrows; ++jj) {
            C[ii*nrows + jj] = 0;
            for (int kk = 0; kk < ncols; ++kk) {
                C[ii*nrows + jj] += A[ii*ncols + kk] * B[kk*nrows + jj];
            }
        }
    }
    return C;
}


void print_matrix(const std::vector<double> & data, int m, int n)
{
  for (int ii = 0; ii < m; ++ii) {
    for (int jj = 0; jj < n; ++jj) {
      std::cout << data[ii*n + jj] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
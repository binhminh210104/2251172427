#include <iostream>
#include <vector>
#include <string>

class Matrix {
private:
    std::vector<std::vector<int> > mat;
    int rows, cols;

public:
    Matrix(int r, int c) : rows(r), cols(c), mat(r, std::vector<int>(c)) {}

    friend std::istream& operator>>(std::istream& in, Matrix& m) {
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                in >> m.mat[i][j];
            }
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Matrix& m) {
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) {
                out << m.mat[i][j] << " ";
            }
            out << std::endl;
        }
        return out;
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.mat[i][j] = mat[i][j] - other.mat[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

};

class Logger {
public:
    static void log(const std::string& message) {
        std::cout << "LOG: " << message << std::endl;
    }
};

int main() {
    int r, c;
    std::cout << "Nhap hang va cot cho ma tran: ";
    std::cin >> r >> c;

    Matrix m1(r, c), m2(r, c);
    std::cout << "Nhap ma tran thu nhat:\n";
    std::cin >> m1;
    std::cout << "Nhap ma tran thu hai:\n";
    std::cin >> m2;

    Matrix sum = m1 + m2;
    Matrix diff = m1 - m2;
    Matrix prod = m1 * m2;

    Logger::log("Ma tran thu nhat:");
    std::cout << m1;
    Logger::log("Ma tran thu hai:");
    std::cout << m2;
    Logger::log("Tong hai ma tran:");
    std::cout << sum;
    Logger::log("Hieu hai ma tran:");
    std::cout << diff;
    Logger::log("Tich hai ma tran:");
    std::cout << prod;

    return 0;
}


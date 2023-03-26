// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №6. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


#include <iostream>
#include <cmath>

// Ваші файли загловки 
//
class DataSet {
public:
    virtual double norm() const = 0;
};

class ComplexNumber : public DataSet {
private:
    double real_;
    double imag_;
public:
    ComplexNumber(double real, double imag) : real_(real), imag_(imag) {}
    double norm() const override {
        return real_ * real_ + imag_ * imag_;
    }
};

class Vector : public DataSet {
private:
    double elements_[10];
public:
    Vector(double e0, double e1, double e2, double e3, double e4,
        double e5, double e6, double e7, double e8, double e9) {
        elements_[0] = e0;
        elements_[1] = e1;
        elements_[2] = e2;
        elements_[3] = e3;
        elements_[4] = e4;
        elements_[5] = e5;
        elements_[6] = e6;
        elements_[7] = e7;
        elements_[8] = e8;
        elements_[9] = e9;
    }
    double norm() const override {
        double sum_of_squares = 0.0;
        for (int i = 0; i < 10; ++i) {
            sum_of_squares += elements_[i] * elements_[i];
        }
        return std::sqrt(sum_of_squares);
    }
};

class Matrix : public DataSet {
private:
    double elements_[2][2];
public:
    Matrix(double e00, double e01, double e10, double e11) {
        elements_[0][0] = e00;
        elements_[0][1] = e01;
        elements_[1][0] = e10;
        elements_[1][1] = e11;
    }
    double norm() const override {
        double sum_of_squares = 0.0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                sum_of_squares += elements_[i][j] * elements_[i][j];
            }
        }
        return std::sqrt(sum_of_squares);
    }
};

int main() {
    ComplexNumber c(3.0, 4.0);
    Vector v(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0);
    Matrix m(1.0, 2.0, 3.0, 4.0);
    std::cout << "Norm of c: " << c.norm() << std::endl;
    std::cout << "Norm of v: " << v.norm() << std::endl;
    std::cout << "Norm of m: " << m.norm() << std::endl;
    return 0;
}

#include <iostream>
#include "forUI/arrayIO.h"
#include "Complex.h"
#include <vector>

template <class T> void actions() {
    std::vector<Polynomial<T> > v;
    int tempCode = 1, len, p1, p2, optionType;
    while (tempCode) {
        try {
            std::cout << "0 - new Polynomial input; 1 - Sum; 2 - Minus; 3 - Mult; 4 - Composition; 5 - MultScal ; 6 - print; 7 - print one; 8 - exit; 9 - calculation" << '\n'<< '\n';
            checkInput(&optionType);
            switch (optionType) {
                case 0:
                    std::cout << "Degree: ";
                    checkInput(&len);
                    v.push_back(inputP<T>(len));
                    break;
                case 1:
                    try {
                        std::cout << "Input first polyn: ";
                        checkInput(&p1);
                        std::cout << "Input first polyn: ";
                        checkInput(&p2);
                        v.push_back(v.at(p1)+v.at(p2));
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 2:
                    try {
                        std::cout << "Input first polyn: ";
                        checkInput(&p1);
                        v.push_back(-v.at(p1));
                    } catch (const std::exception &e) { std::cout << e.what() << '\n'; }
                    break;
                case 3:
                    try {
                        std::cout << "Input first polyn: ";
                        checkInput(&p1);
                        std::cout << "Input first polyn: ";
                        checkInput(&p2);
                        v.push_back(v.at(p1)*v.at(p2));
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 4:
                    try {
                        std::cout << "Input first polyn: ";
                        checkInput(&p1);
                        std::cout << "Input first polyn: ";
                        checkInput(&p2);
                        v.push_back(v.at(p1).Composition(v[p2]));
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 5:
                    try {
                        std::cout << "Input first polyn: ";
                        checkInput(&p1);
                        std::cout << "Input value: ";
                        T val;
                        checkInput(&val);
                        v.push_back(v.at(p1) * val);
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 6:
                    try {
                        for(auto it = v.begin() ; it != v.end(); ++it) {
                            std::cout << *it << '\n';
                        }
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 7:
                    try{
                        std::cout << "Input polyn: ";
                        checkInput(&p1);
                        std::cout << v.at(p1) << '\n';
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 8:
                    tempCode = 0;
                    break;
                case 9:
                        try {
                            std::cout << "Input polyn: ";
                            checkInput(&p1);
                            std::cout << "Input value: ";
                            T val;
                            checkInput(&val);
                            std::cout << v.at(p1).Calculation(val) << '\n';
                        }
                        catch (const std::exception &e) {
                            std::cout << e.what() << '\n';
                        }
                        break;
            }
        }
        catch (const std::exception &e) {
            std::cout << e.what() << '\n';
            tempCode = 0;
        }
    }
}

template <class T> void actionsM() {
    std::vector<Matrix<T> > v;
    int tempCode = 1, len, p1, p2, optionType, h;
    while (tempCode) {
        try {
            std::cout << "0 - new matrix input; 1 - Sum; 2 - Minus; 3 - Mult; 4 - MultScal ; 5 - print; 6 - print one; 7 - exit;" << '\n'<< '\n';
            checkInput(&optionType);
            switch (optionType) {
                case 0:
                    std::cout << "length: ";
                    checkInput(&len);
                    std::cout << "hight: ";
                    checkInput(&h);
                    v.push_back(inputM<T>(len, h));
                    break;
                case 1:
                    try {
                        std::cout << "Input first matrix: ";
                        checkInput(&p1);
                        std::cout << "Input first matrix: ";
                        checkInput(&p2);
                        v.push_back(v.at(p1)+v.at(p2));
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 2:
                    try {
                        std::cout << "Input first matrix: ";
                        checkInput(&p1);
                        v.push_back(-v.at(p1));
                    } catch (const std::exception &e) { std::cout << e.what() << '\n'; }
                    break;
                case 3:
                    try {
                        std::cout << "Input first matrix: ";
                        checkInput(&p1);
                        std::cout << "Input first matrix: ";
                        checkInput(&p2);
                        v.push_back(v.at(p1)*v.at(p2));
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 4:
                    try {
                        std::cout << "Input first matrix: ";
                        checkInput(&p1);
                        std::cout << "Input value: ";
                        T val;
                        checkInput(&val);
                        v.push_back(v.at(p1) * val);
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 5:
                    try {
                        for(auto it = v.begin() ; it != v.end(); ++it) {
                            std::cout << *it << '\n';
                        }
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 6:
                    try{
                        std::cout << "Input matrix: ";
                        checkInput(&p1);
                        std::cout << v.at(p1) << '\n';
                    }
                    catch (const std::exception &e) {
                        std::cout << e.what() << '\n';
                    }
                    break;
                case 7:
                    tempCode = 0;
                    break;

            }
        }
        catch (const std::exception &e) {
            std::cout << e.what() << '\n';
            tempCode = 0;
        }
    }
}


int main(int argc, char const *argv[]) {
    int code = 1;
    try {
        int optionType, tempCode;
        std::cout << "test type: 0 - Polynomial<int>; 1 - Polynomial<double>; 2 - Polynomial<Complex>; 3 - Matrix<int>; 4 - Matrix<double> ; 5 - Matrix<Complex>; 6 - exit" << '\n';
        checkInput(&optionType);
        switch (optionType) {
            case 0:
                actions<int>();
            break;
            case 1:
                actions<double>();
            break;
            case 2:
                actions<Complex>();
            break;
            case 3:
                actionsM<int>();
            break;
            case 4:
                actionsM<double>();
            break;
            case 5:
                actionsM<Complex>();
            break;
            case 6:
            break;
        }
    }
    catch (const std::exception &e) {
        std::cout << e.what() << '\n';
    }
    return 0;
}

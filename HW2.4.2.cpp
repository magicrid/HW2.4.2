#include <iostream>

class Figure
{
public:
    virtual void print_info()const {};
};

class Triangle : public Figure // Базовый класс для треугольника
{
protected:
    double a, b, c;
    double A, B, C;
public:
    Triangle(double a, double b, double c, double A, double B, double C) 
        : a(a), b(b), c(c), A(A), B(B), C(C) {}

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }

    virtual std::string get_type() const { return "Треугольник"; }

    void print_info()const override
    {
        std::cout << get_type() << ":" << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << std::endl;
        std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << std::endl;
        std::cout << std::endl;
    }
};

class RightTriangle : public Triangle // Прямоугольный треугольник (угол C = 90)
{ 
public:
    RightTriangle(double a, double b, double c, double A, double B)
        : Triangle(a, b, c, A, B, 90.0f) {}

    std::string get_type() const override { return "Прямоугольный треугольник"; }
};

class IsoscelesTriangle : public Triangle // Равнобедренный треугольник (a = c, A = C)
{
public:
    IsoscelesTriangle(double a, double b, double A, double B)
        : Triangle(a, b, a, A, B, A) {}

    std::string get_type() const override { return "Равнобедренный треугольник"; }
};

class EquilateralTriangle : public Triangle // Равносторонний треугольник (все стороны равны, все углы = 60)
{
public:
    EquilateralTriangle(double side)
        : Triangle(side, side, side, 60.0f, 60.0f, 60.0f) {
    }

    std::string get_type() const override { return "Равносторонний треугольник"; }
};

class Quadrilateral : public Figure // Базовый класс для четырёхугольника
{
protected:
    double a, b, c, d;
    double A, B, C, D;

public:
    Quadrilateral(double a, double b, double c, double d, double A, double B, double C, double D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    }

    double get_a() const { return a; }
    double get_b() const { return b; }
    double get_c() const { return c; }
    double get_d() const { return d; }
    double get_A() const { return A; }
    double get_B() const { return B; }
    double get_C() const { return C; }
    double get_D() const { return D; }

    virtual std::string get_type() const { return "Четырёхугольник"; }

    void print_info()const override
    {
        std::cout << get_type() << ":" << std::endl;
        std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c() << std::endl;
        std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C() << std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrilateral // Параллелограмм (a = c, b = d, A = C, B = D)
{
public:
    Parallelogram(double a, double b, double A, double B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {}

    std::string get_type() const override { return "Параллелограмм"; }
};

class Rectangle : public Parallelogram // Прямоугольник (a = c, b = d, все углы = 90)
{
public:
    Rectangle(double a, double b)
        : Parallelogram(a, b, 90.0, 90.0) {
    }

    std::string get_type() const override { return "Прямоугольник"; }
};

class Square : public Rectangle // Квадрат (все стороны равны, все углы = 90)
{
public:
    Square(double side)
        : Rectangle(side, side) {
    }

    std::string get_type() const override { return "Квадрат"; }
};

class Rhombus : public Parallelogram // Ромб (все стороны равны, A = C, B = D)
{
public:
    Rhombus(double side, double A, double B)
        : Parallelogram(side, side, A, B) {
    }

    std::string get_type() const override { return "Ромб"; }
};

void print_figure(Figure* base)
{
    base->print_info();
}


int main()
{
    setlocale(LC_ALL, "RU");

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    print_figure(&triangle);
    print_figure(&right_triangle);
    print_figure(&isosceles_triangle);
    print_figure(&equilateral_triangle);

    print_figure(&quadrilateral);
    print_figure(&rectangle);
    print_figure(&square);
    print_figure(&parallelogram);
    print_figure(&rhombus);

    return EXIT_SUCCESS;
}

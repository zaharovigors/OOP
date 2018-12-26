#include <cstdlib>
#include "triangle.h"
#include "square.h"
#include "octagon.h"

using namespace std;

void print_menu(){
		cout << "Выберие фигуру:" << endl;
		cout << 1 << '\t' << "Восьмиугольник" << endl;
		cout << 2 << '\t' << "Треугольник" << endl;
		cout << 3 << '\t' << "Квадрат" << endl;
	}

int main(int argc, char** argv) {
	int c;
	Figure *ptr;
	print_menu();
	
	while (cin >> c){
		
			
		switch (c){
			case 1:
				
				cout << "Введите сторону правильного восьмиугольника" << endl;
				ptr = new Octagon(cin);
				
			case 2:
			
				cout << "Введите стороны треугольника" << endl;
				ptr = new Triangle(cin);
			case 3:

				cout << "Введите сторону квадрата" << endl;
				ptr = new FSquare(cin);
				
			default:
				print_menu();
				continue();
				
		}
		ptr->Print();
		cout << "S = " << ptr->Square() << endl;
		delete ptr;
		break;
	}
			

    return 0;
}

#include <iostream>
using namespace std;

class EmployeeInfo {
  protected:
    const int maxLength = 80;
    char answer;
  public:
    void set_values (int a, int b)
      {


        char first_string[maxLength];
		char second_string[maxLength];

	    do{


           	cout << "Enter Full name: ";
		    cin.getline(first_string,MAXIMUM_LENGTH);
		    cout << "Enter Status: ";
		    cin.getline(second_string,MAXIMUM_LENGTH);
            cout << "Enter Hours: ";
		    cin.getline(second_string,MAXIMUM_LENGTH);
            cout << "Enter Sales: ";
		    cin.getline(second_string,MAXIMUM_LENGTH);
            cout << "Enter Wages: ";
		    cin.getline(second_string,MAXIMUM_LENGTH);


	        cout << "Do you want to calculate more lumberyard?" << endl;
            cout << "If yes, please type Y" << endl;
            cout << "If no, please type any key" << endl;
            cin >> Answer;

        }while((answer=='y')||(answer=='Y'));





      }



};

class Rectangle: public Polygon {
  public:
    int area()
      { return width*height; }
};

class Triangle: public Polygon {
  public:
    int area()
      { return width*height/2; }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';



            if (Status[i].substr(0,1) == "S")
            {
            }
            else if Status[i].substr(0,1) == "H")
            {
            }
            else if Status[i].substr(0,1) == "C")
            {
            }






  return 0;
}

 // Fig. 13.23: fig13_23.cpp
 // Processing Employee derived-class objects individually
 // and polymorphically using dynamic binding.

 #include <iostream>
 using std::cout;
 using std::endl;
 using std::fixed;
 #include <iomanip>
 using std::setprecision;
 #include <vector>
 using std::vector;

 // include definitions of classes in Employee hierarchy
 #include "Employee.h"
 #include "SalariedEmployee.h"
 #include "HourlyEmployee.h"
 #include "CommissionEmployee.h" 20 #include "BasePlusCommissionEmployee.h" 21 22 void virtualViaPointer( const Employee * const ); // prototype 23 void virtualViaReference( const Employee & ); // prototype 24 25 int main() 26 { 27 // set floating-point output formatting 28 cout << fixed << setprecision( 2 ); 29 30 // create derived-class objects 31 SalariedEmployee salariedEmployee( 32 "John", "Smith", "111-11-1111", 800 ); 33 HourlyEmployee hourlyEmployee( 34 "Karen", "Price", "222-22-2222", 16.75, 40 ); 35 CommissionEmployee commissionEmployee( 36 "Sue", "Jones", "333-33-3333", 10000, .06 ); 37 BasePlusCommissionEmployee basePlusCommissionEmployee( 38 "Bob", "Lewis", "444-44-4444", 5000, .04, 300 ); 39 40 cout << "Employees processed individually using static binding:\n\n"; 41 42 // output each Employee's information and earnings using static binding 43 salariedEmployee.print(); 44 cout << "\nearned $" << salariedEmployee.earnings() << "\n\n"; 45 hourlyEmployee.print(); 46 cout << "\nearned $" << hourlyEmployee.earnings() << "\n\n"; 47 commissionEmployee.print(); 48 cout << "\nearned $" << commissionEmployee.earnings() << "\n\n"; 49 basePlusCommissionEmployee.print(); 50 cout << "\nearned $" << basePlusCommissionEmployee.earnings() 51 << "\n\n"; 52 53 // create vector of four base-class pointers 54 vector < Employee * > employees( 4 );  55 56 // initialize vector with Employees  57 employees[ 0 ] = &salariedEmployee;  58 employees[ 1 ] = &hourlyEmployee;  59 employees[ 2 ] = &commissionEmployee;  60 employees[ 3 ] = &basePlusCommissionEmployee; 61 62 cout << "Employees processed polymorphically via dynamic binding:\n\n"; 63 64 // call virtualViaPointer to print each Employee's information 65 // and earnings using dynamic binding 66 cout << "Virtual function calls made off base-class pointers:\n\n"; 67 68 for ( size_t i = 0; i < employees.size(); i++ ) 69 virtualViaPointer( employees[ i ] );  70 71 // call virtualViaReference to print each Employee's information 72 // and earnings using dynamic binding 73 cout << "Virtual function calls made off base-class references:\n\n"; 74 75 for ( size_t i = 0; i < employees.size(); i++ )  76 virtualViaReference( *employees[ i ] ); // note dereferencing 77 78 return 0; 79 } // end main 80 81 // call Employee virtual functions print and earnings off a  82 // base-class pointer using dynamic binding  83 void virtualViaPointer( const Employee * const baseClassPtr )  84 {  85 baseClassPtr->print();  86 cout << "\nearned $" << baseClassPtr->earnings() << "\n\n"; 87 } // end function virtualViaPointer  88 89 // call Employee virtual functions print and earnings off a  90 // base-class reference using dynamic binding  91 void virtualViaReference( const Employee &baseClassRef )  92 {  93 baseClassRef.print(); ' 94 cout << "\nearned $" << baseClassRef.earnings() << "\n\n"; 95 } // end function virtualViaReference

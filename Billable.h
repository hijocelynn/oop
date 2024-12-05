#ifndef BILLABLE_H
#define BILLABLE_H
#include <iostream>
#include <cstring>
using namespace std;
namespace seneca {
    class Billable {
    protected:
            char* m_name;    
            double m_price;  
            void price(double value) { m_price = value; }
            void name(const char* name);

        public:
            // Constructor, Copy constructor, Assignment Operator, Virtual Destructor
            Billable();
            Billable(const Billable& other);  
            Billable& operator=(const Billable& other);  
            virtual ~Billable();

            //Virtual methods
            virtual double price() const;  

            //Pure virtual methods
            virtual ostream& print(ostream& ostr = cout) const = 0;  
            virtual bool order() = 0;  
            virtual bool ordered() const = 0;  
            virtual ifstream& read(ifstream& file) = 0;  

            // Operator overloads
            friend double operator+(double money, const Billable& B);
            friend double& operator+=(double& money, const Billable& B);
            operator const char*() const;
    };
}

#endif

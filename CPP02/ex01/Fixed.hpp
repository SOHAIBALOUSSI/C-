#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int              _value;
        static const int _fracBits;
        
    public:
        Fixed();
        Fixed(const int Value);
        Fixed(const float fValue);

        ~Fixed();
        Fixed(const Fixed &other); // copy constractor
        Fixed& operator = (const Fixed &other); // copy assignment operator
        
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );

};

std::ostream&    operator<<(std::ostream& out, const Fixed& fp);


#endif /* FIXED_HPP */
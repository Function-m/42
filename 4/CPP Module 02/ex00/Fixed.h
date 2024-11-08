#ifndef FIXED_H
#define FIXED_H

class Fixed {
 private:
  int fixedPointValue;
  static const int fractionalBits = 8;

 public:
  Fixed();                               // Default constructor
  Fixed(const Fixed& other);             // Copy constructor
  Fixed& operator=(const Fixed& other);  // Copy assignment operator
  ~Fixed();                              // Destructor

  int getRawBits(void) const;
  void setRawBits(const int raw);
};

#endif

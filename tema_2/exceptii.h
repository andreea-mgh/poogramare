#ifndef _EXCEPTII_H_
#define _EXCEPTII_H_

#include <exception>
#include <string>

class ExceptieOptiuneInvalida : public std::exception {
public:
    const char* what() const noexcept override;
};
class ExceptiePretNegativ : public std::exception {
public:
    const char* what() const noexcept override;
};
class ExceptieCantitateNegativa : public std::exception {
public:
    const char* what() const noexcept override;
};
class ExceptieIDDuplicat : public std::exception {
public:
    const char* what() const noexcept override;
};
class ExceptieIDInexistent : public std::exception {
public:
    const char* what() const noexcept override;
};

#endif

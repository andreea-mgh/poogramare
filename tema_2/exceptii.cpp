#include "exceptii.h"

const char* ExceptieOptiuneInvalida::what() const noexcept {
    return "Optiune invalida.";
}

const char* ExceptiePretNegativ::what() const noexcept {
    return "Pretul nu poate fi negativ.";
}

const char* ExceptieCantitateNegativa::what() const noexcept {
    return "Cantitatea nu poate fi negativa.";
}

const char* ExceptieIDDuplicat::what() const noexcept {
    return "Un produs cu ID-ul dat exista deja.";
}

const char* ExceptieIDInexistent::what() const noexcept {
    return "Nu exista niciun produs cu ID-ul dat in inventar.";
}
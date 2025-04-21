#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell;
using std::cout;
typedef std::string str;

class ATarget {
protected:
    str type;

    ATarget(ATarget const &copy);
    ATarget &operator=(ATarget const &copy);
public:
    ATarget(str const &Type);
    virtual ~ATarget();

    str const &getType() const;

    virtual ATarget *clone() = 0;

    void getHitBySpell (ASpell const &spell) const;
};

#endif
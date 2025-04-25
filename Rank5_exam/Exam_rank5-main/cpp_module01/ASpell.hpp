#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget;
using std::cout;
typedef std::string str;

class ASpell {
protected:
    str name;
    str effects;

    ASpell(ASpell const &copy);
    ASpell &operator=(ASpell const &copy);
public:
    ASpell(str const &Name, str const &Effects);
    virtual ~ASpell();

    str const &getName() const;
    str const &getEffects() const;

    virtual ASpell *clone() = 0;
    
    void launch(ATarget const &target) const;
};

#endif
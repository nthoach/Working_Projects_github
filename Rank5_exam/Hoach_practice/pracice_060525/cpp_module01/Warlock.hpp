#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
# include "ASpell.hpp"
# include "ATarget.hpp"
# include <map>

typedef std::string str;
typedef std::map<std::string, ASpell *> spell_map;
typedef spell_map::iterator spell_it;

class Warlock
{
    private:
        str _name;
        str _title;

        Warlock();
        Warlock(Warlock& other);
        Warlock& operator=(Warlock& other);

        spell_map _book;

    public:
        Warlock(str name, str title);
        ~Warlock();

        str const& getName() const;
        str const& getTitle() const;

        void setTitle(str const& title);
        void introduce() const; 

        void learnSpell(ASpell * spell_ptr);
        void forgetSpell(str const& name);
        void launchSpell(str const& name,  ATarget const& Target);
};

#endif

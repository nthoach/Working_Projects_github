#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <map>
# include "ASpell.hpp"
# include "SpellBook.hpp"

class SpellBook;

class Warlock
{
    private:
        std:: string _name;
        std:: string _title;
        Warlock();
        Warlock(Warlock const &other);
        Warlock & operator=(Warlock const &other);
        SpellBook _spellbook;

    public:
        Warlock(str const &name, str const &title);
        ~Warlock();

        const str  & getName()  const;
        const str  & getTitle() const;
        void setTitle(const str &title);
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(str const &spellname);
        void launchSpell(str const &spellname, ATarget const& target);
            
};

# endif
#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <map>
# include "ASpell.hpp"

typedef std::map<str, ASpell * > spell_map;
typedef spell_map::iterator spell_it;
typedef std::pair<str, ASpell *> spell_pair;

class Warlock
{
    private:
        std:: string _name;
        std:: string _title;
        Warlock();
        Warlock(Warlock const &other);
        Warlock & operator=(Warlock const &other);
       spell_map _spells; 

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
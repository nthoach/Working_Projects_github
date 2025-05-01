#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <map>
# include "ASpell.hpp"

typedef std::map<std::string, ASpell * > spell_map;
typedef spell_map::iterator spell_it;
typedef std::pair<std::string, ASpell *> spell_pair;

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
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        const std::string  & getName()  const;
        const std::string  & getTitle() const;
        void setTitle(const std::string &title);
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &spellname);
        void launchSpell(std::string const &spellname, ATarget const& target);
            
};

# endif
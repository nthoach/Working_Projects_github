#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <map>
# include "ASpell.hpp"

class Warlock
{
    private:
        std:: string _name;
        std:: string _title;
        Warlock();
        Warlock(Warlock const &other);
        Warlock & operator=(Warlock const &other);
        std::map<std::string, ASpell *> _spells; 

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
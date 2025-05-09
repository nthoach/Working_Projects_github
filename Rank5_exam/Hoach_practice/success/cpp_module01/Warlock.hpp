#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
//
# include <map>

# include "ASpell.hpp"
# include "ATarget.hpp"

typedef std::string str;
typedef std::map<str, ASpell *> spell_map;
typedef spell_map::iterator spell_it;

class Warlock
{
    private:
        std::string _name;
        std::string _title;

        Warlock();
        Warlock(Warlock& other);
        Warlock& operator=(Warlock& other);
//
		spell_map book;

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
 
        std::string getName() const;
        std::string getTitle() const;

        void setTitle(std::string const& title);
        void introduce() const;
		//
		void learnSpell(ASpell* ptr);
		void forgetSpell(str const& name);
		void launchSpell(str const& name, ATarget & target);
};

#endif
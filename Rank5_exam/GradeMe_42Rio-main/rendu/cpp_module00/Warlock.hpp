#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>
// # include <map>

// typedef std::map<std::string, ASpell *> spell_map;
// typedef spell_map::iterator spell_it;
// typedef std::pair<std::string, ASpell *> spell_pair;

// typedef std::map<std::string, ATarget *> target_map;
// typedef target_map::iterator target;
// typedef std::pair<std::string, ASpell *> target_pair;

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        Warlock();
        Warlock(Warlock& other);
        Warlock& operator=(Warlock& other);

    public:
        Warlock(std::string name, std::string title);
        ~Warlock();
        //getter
        std::string getName() const;
        std::string getTitle() const;

        void setTitle(std::string const& title);
        void introduce() const;

};

#endif
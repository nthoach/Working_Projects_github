#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>

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
 
        std::string getName() const;
        std::string getTitle() const;

        void setTitle(std::string const& title);
        void introduce() const;

};

#endif
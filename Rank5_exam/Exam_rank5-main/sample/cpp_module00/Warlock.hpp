#pragma once

#include <iostream>

class Warlock
{
	private:
		str _name;
		str _title;
	public:
        Warlock(const str& name, const str& title);
	    ~Warlock();
		const str &getName() const;
		const str &getTitle() const;
		void setTitle(const str &title);
		void introduce() const;
};

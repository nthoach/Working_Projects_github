

typedef std::map<std::string, ASpell * > spell_map;
typedef spell_map::iterator spell_it;
typedef std::pair<std::string, ASpell *> spell_pair;

spell_map _spells;

void forgetSpell(std::string const& name)
{
    spell_it it = _spells.find(name);
    if (it != _spells.end())
    {
        delete it->second;
        _spells.erase(it);
    }
}
/*
    This file is part of Ellerre

    Ellerre is free software: you can redistribute it and/or modify
    it under the terms of the GNU Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Ellerre is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Public License for more details.

    You should have received a copy of the GNU Public License
    along with Ellerre. If not, see <http://www.gnu.org/licenses/>.
*/
#include "grammar.h"

Grammar::Grammar()
{
}

Grammar::~Grammar()
{
  rules.clear();
}

void Grammar::addRule(Rule *rule)
{
  rule->head->terminal = false;
  rules.push_back(rule);
}

Symbol *Grammar::getSymbol(char *str)
{
//  std::cout << "Trying to get symbol [" << std::string(str) << "] from grammar." << std::endl;
  
  std::map<std::string,Symbol*>::iterator it = symbols.find(std::string(str));
  if (it != symbols.end()){
    return (*it).second;
  }else{
    Symbol *newSymbol = new Symbol(str, true);
    symbols[str] = newSymbol;
    return newSymbol;
  }
}

std::ostream &operator<< (std::ostream &output, const Grammar &grammar)
{
  //count number of non-terminals
  int ntc = 0;
  std::map<std::string,Symbol*>::iterator itmap;
  std::map<std::string,Symbol*> map = grammar.symbols;
  for (itmap = map.begin(); itmap != map.end(); itmap++){
    if (!((*itmap).second)->terminal){
      ntc++;
    }
  }

  output << "Grammar with " << grammar.rules.size() << " rules and " << grammar.symbols.size() << " symbols (" << ntc << " non-terminals):" << std::endl;
  std::vector<Rule*>::iterator it;
  std::vector<Rule*> r = grammar.rules;
  for (it = r.begin(); it != r.end(); it++){
    output << *(*it);
    if ((it+1) != r.end()){
      output << std::endl;
    }
  }
  return output;
}

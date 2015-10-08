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
#include "symbol.h"

Symbol::Symbol(char *str)
{
  this->str = strdup(str);
}

Symbol::Symbol(char *str, bool terminal)
{
  this->str = strdup(str);
  this->terminal = terminal;
}

Symbol::~Symbol()
{
  free(str);
}

std::ostream &operator<< (std::ostream &output, const Symbol &symbol)
{
//  output << "{"<<symbol.str << "," << symbol.terminal<<"}";
  output << symbol.str;
}

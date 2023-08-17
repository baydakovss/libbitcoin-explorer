/**
 * Copyright (c) 2011-2023 libbitcoin developers (see AUTHORS)
 *
 * This file is part of libbitcoin.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <bitcoin/explorer/config/language.hpp>

#include <iostream>
#include <sstream>
#include <string>
#include <bitcoin/system.hpp>
#include <bitcoin/explorer/utility.hpp>

namespace libbitcoin {
namespace explorer {
namespace config {

language::language()
  : value_(type::none)
{
}

language::language(const language& other)
  : value_(other.value_)
{
}

language::language(const std::string& token)
{
    std::stringstream(token) >> *this;
}

language::language(const type& value)
  : value_(value)
{
}

language::operator const type&() const
{
    return value_;
}

std::istream& operator>>(std::istream& input, language& argument)
{
    std::string text;
    input >> text;

    argument = system::wallet::languages::from_name(text);
    return input;
}

std::ostream& operator<<(std::ostream& output, const language& argument)
{
    const auto text = system::wallet::languages::to_name(argument);

    if (text.empty())
        throw system::ostream_exception("language");

    output << text;
    return output;
}

} // namespace config
} // namespace explorer
} // namespace libbitcoin

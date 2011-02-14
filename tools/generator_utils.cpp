/*
 *
 *  D-Bus++ - C++ bindings for D-Bus
 *
 *  Copyright (C) 2005-2007  Paolo Durante <shackan@gmail.com>
 *
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <iostream>
#include <cstdlib>

#include "generator_utils.h"

using namespace std;

const char *tab = "    ";

const char *header = "\n\
/*\n\
 *	This file was automatically generated by dbusxx-xml2cpp; DO NOT EDIT!\n\
 */\n\
\n\
";

const char *dbus_includes = "\n\
#include <dbus-c++/dbus.h>\n\
#include <cassert>\n\
";

void underscorize(string &str)
{
	for (unsigned int i = 0; i < str.length(); ++i)
	{
		if (!isalpha(str[i]) && !isdigit(str[i])) str[i] = '_';
	}
}

string stub_name(string name)
{
	underscorize(name);

	return "_" + name + "_stub";
}

const char *atomic_type_to_string(char t)
{
	static struct { char type; const char *name; } atos[] =
	{
		{ 'y', "uint8_t" },
		{ 'b', "bool" },
		{ 'n', "int16_t" },
		{ 'q', "uint16_t" },
		{ 'i', "int32_t" },
		{ 'u', "uint32_t" },
		{ 'x', "int64_t" },
		{ 't', "uint64_t" },
		{ 'd', "double" },
		{ 's', "std::string" },
		{ 'o', "::DBus::Path" },
		{ 'g', "::DBus::Signature" },
		{ 'v', "::DBus::Variant" },
		{ '\0', "" }
	};
	int i;

	for (i = 0; atos[i].type; ++i)
	{
		if (atos[i].type == t) break;
	}
	return atos[i].name;
}

void _parse_signature(const string &signature, string &type, unsigned int &i)
{
  cout << "signature: " << signature << endl;
  cout << "type: " << type << endl;
  cout << "i: " << i << ", signature[i]: " << signature[i] << endl;
  
	for (; i < signature.length(); ++i)
	{    
		switch (signature[i])
		{
			case 'a':
			{
				switch (signature[++i])
				{
					case '{':
					{
						type += "std::map< ";
            ++i;
            _parse_signature(signature, type, i);
            type += " >";
            
						break;
					}
					case '(':
					{
						type += "std::vector< ::DBus::Struct< ";
            ++i;
            _parse_signature(signature, type, i);
            type += " > >";

						break;
					}            
					default:
					{
						type += "std::vector< ";
            _parse_signature(signature, type, i);

            type += " >";
              
						break;
					}
				}

				if (i+1 < signature.length() && signature[i+1] != ')' && signature[i+1] != '}')
				{
					type += ", ";
				}

				break;
			}
			case ')':
			case '}':	
			{        
        return;
			}
			default:
			{
				const char *atom = atomic_type_to_string(signature[i]);
				if (!atom)
				{
					cerr << "invalid signature" << endl;
					exit(-1);
				}
				type += atom;

				if (i+1 < signature.length() && signature[i+1] != ')' && signature[i+1] != '}')
				{
					type += ", ";
				}
				break;
			}
		}
	}
}

/*{
	for (; i < signature.length(); ++i)
	{
    cout << "i: " << i << ", sig(i): " << signature[i] << endl;
    cout << "Type: " << type << endl;
    
		switch (signature[i])
		{
			case 'a':
			{
        bool multi = false;
				switch (signature[++i])
				{
					case '{':
					{
						type += "std::map< ";

						const char *atom = atomic_type_to_string(signature[++i]);
						if (!atom)
						{
							cerr << "invalid signature" << endl;
							exit(-1);
						}
						type += atom;
						type += ", ";
						++i;
            _parse_signature(signature, type, i);
            multi = true;
						break;
					}
					default:
					{
						type += "std::vector< ";
            _parse_signature(signature, type, i);
            type += " >V";
            multi = true;
						break;
					}
				}
        if (!multi)
        {
          _parse_signature(signature, type, i);
        }
        cout << "signature1: " << signature << endl;
        cout << "type1: " << type << endl;
        cout << "i1: " << i << ", sig(i): " << signature[i-1] << endl;
			  
				continue;
			}
			case '(':	
			{
				type += "::DBus::Struct< ";
				++i;
				_parse_signature(signature, type, i);
				type += " >S";
        cout << "signature2: " << signature << endl;
        cout << "type2: " << type << endl;
        cout << "i2: " << i << ", sig(i): " << signature[i] << endl;
				if ((i+1 < signature.length()) && (signature[i+1] != ')') )
        {
					type += ", ";
				}
				continue;
			}
			case ')':
			case '}':	
			{
        type += " >?";
        cout << "close tag>" << endl;
        cout << "type3: " << type << endl;

        return;
			}
			default:
			{
				const char *atom = atomic_type_to_string(signature[i]);
				if (!atom)
				{
					cerr << "invalid signature" << endl;
					exit(-1);
				}
				type += atom;

				if (i+1 < signature.length() && signature[i+1] != ')' && signature[i+1] != '}')
				{
					type += ", ";
				}
				break;
			}
		}
	}
}*/

string signature_to_type(const string &signature)
{
	string type;
	unsigned int i = 0;
	_parse_signature(signature, type, i);
	return type;
}

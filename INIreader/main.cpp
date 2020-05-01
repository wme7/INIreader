//
//  main.cpp
//  INIreader
//
//  Created by Manuel Diaz on 5/1/20.
//  Copyright © 2020 WME7. All rights reserved.
//

// Example that shows simple usage of the INIReader class

#include <iostream>
#include "INIreader.hpp"

int main()
{
    INIReader reader("test.ini");

    if (reader.ParseError() < 0) {
        std::cout << "Can't load 'test.ini'\n";
        return 1;
    }
    std::cout << "Config loaded from 'test.ini': version="
              << reader.GetInteger("protocol", "version", -1) << ", name="
              << reader.Get("user", "name", "UNKNOWN") << ", email="
              << reader.Get("user", "email", "UNKNOWN") << ", pi="
              << reader.GetReal("user", "pi", -1) << ", active="
              << reader.GetBoolean("user", "active", true) << "\n";

    std::cout<<"Found sections and fields:"<<std::endl;
    std::set<std::string> sections = reader.GetSections();
    for(std::set<std::string>::iterator sectionsIt = sections.begin();
        sectionsIt!=sections.end();
        sectionsIt++)
    {
        std::cout << "  [" << *sectionsIt << "]: ";
        std::set<std::string> fields = reader.GetFields(*sectionsIt);
        for(std::set<std::string>::iterator fieldsIt = fields.begin();
            fieldsIt!=fields.end();
            fieldsIt++)
        {
            if(fieldsIt!=fields.begin())
                std::cout << ", ";
            std::cout << *fieldsIt;
        }
        std::cout << std::endl;
    }

    return 0;
}

//
//  main.cpp
//  argparse
//
//  Created by Melissa Cell on 2/20/17.
//  Copyright © 2017 Melissa Cell. All rights reserved.
//

#include <iostream>
#include <string>
#include "cxxopts.hpp"

void greet(const cxxopts::Options & options){
    
    std::string output;
    
    /*
    if (!options.count("g")){
        std::cout << "Missing some required flags." << std::endl;
        return;
    }
    */
    
    output = options["g"].as<std::string>();
    output += ", ";
    output += options["n"].as<std::string>();
    output += "!";
    
    if (options["caps"].as<bool>()){
        transform(output.begin(), output.end(), output.begin(),::toupper);
    }
    
    std::cout << output << std::endl;
}


int main(int argc, char * argv[]) {
    
    // cxxopts
    // https://github.com/jarro2783/cxxopts
    
    cxxopts::Options options("Greeter", " - A greeting program.");
    bool caps_default = false;
    
    options.add_options()
    ("g,greeting", "Greeting to give", cxxopts::value<std::string>()->default_value("Hello"))
    ("n,name", "Name of person", cxxopts::value<std::string>()->default_value("World"))
    ("caps", "Greet in capital letters", cxxopts::value<bool>(caps_default))
    ("help", "Print help")
    ;
    
    options.parse(argc, argv);
    
    greet(options);
    
    return 0;
}

// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// jsonsample.cpp
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Read from file
    std::ifstream ifs("video.json");
    json data = json::parse(ifs);

    // Extract numeric fields
    unsigned int width = data["width"];
    unsigned int height = data["height"];
    std::cout << width << "x" << height << std::endl;

    // Extract string field
    std::string shape = data["scene"]["shape"];
    std::cout << shape << std::endl;

    // Manipulate an array field
    std::cout << data["scene"]["children"].size() << std::endl;
    for (const json& child : data["scene"]["children"]) {
        std::cout << child["shape"] << std::endl;
    }

    // Set fields
    data["width"] = 600;  // Modify field
    data["name"] = "My first movie";  // New field

    // Check for fields:
    std::cout << std::boolalpha;
    std::cout << "Has name: " << data.contains("name") << std::endl;
    std::cout << "Has bgm: " << data.contains("bgm") << std::endl;

    // Get with defaults
    float angle = data.value("theta", 90);
    std::cout << angle << std::endl;

    // Convert to string with nice formatting and 2-space indentation
    // std::string str = data.dump(2);
    // std::cout << str << std::endl;
}

// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// Component.cpp

#include "Component.hpp"

namespace AP {

sf::Color parseColor(const std::string& hex) {
    std::string cleanHex = hex;
    std::string temp = hex;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    if (temp == "black") return sf::Color::Black;
    if (temp == "white") return sf::Color::White;
    if (temp == "red") return sf::Color::Red;
    if (temp == "green") return sf::Color::Green;
    if (temp == "blue") return sf::Color::Blue;
    if (temp == "yellow") return sf::Color::Yellow;
    if (temp == "magenta") return sf::Color::Magenta;
    if (temp == "cyan") return sf::Color::Cyan;
    if (temp == "transparent") return sf::Color::Transparent;

    if (!cleanHex.empty() && cleanHex[0] == '#') {
        cleanHex = cleanHex.substr(1);
    }
    if (cleanHex.length() == 6) {
        cleanHex += "FF";
    }

    try {
        unsigned int value = std::stoul(cleanHex, nullptr, 16);
        uint8_t r = (value >> 24) & 0xFF;
        uint8_t g = (value >> 16) & 0xFF;
        uint8_t b = (value >> 8) & 0xFF;
        uint8_t a = value & 0xFF;
        return sf::Color(r, g, b, a);
    } catch (const std::exception& e) {
        std::cerr << "Warning: Could not parse color '" << hex << std::endl;
        return sf::Color::White;
    }
}


Component::Component(const Json& data) {
  std::string compColor = data.value("color", "FFFFFFFF");
  color_ = parseColor(compColor);

  if (data.contains("keyframes")) {
    for (const auto& k : data["keyframes"]) {
      keyFrames_.push_back(KeyFrame(k));
    }
  }

  if (keyFrames_.empty()) keyFrames_.push_back(KeyFrame());
  playbgm(data);
}

KeyFrame Component::currFrame() const {
    if (keyFrames_.empty()) {
      return KeyFrame();
    }
    return keyFrames_[0];  // default to first frame for part A
}

void Component::tween(sf::Time time) {
    // For part B
}
std::unique_ptr<Component> Component::fromJson(const Json& data) {
    std::string shape = data.value("shape", "null");

    if (shape == "circle") return std::make_unique<CircleComponent>(data);
    if (shape == "composite") return std::make_unique<CompositeComponent>(data);
    if (shape == "rect") return std::make_unique<RectangleComponent>(data);
    if (shape == "image") return std::make_unique<ImageComponent>(data);
    if (shape == "text") return std::make_unique<TextComponent>(data);

    throw std::runtime_error("Component::fromJson, Unknown component: " + shape);
}

void Component::playbgm(const Json& data) {
    std::string bgm = data.value("bgm", "");
    if (bgm.empty()) return;
    if (!music_.openFromFile(bgm)) {
        return;
    }
    music_.play();
}

}  // namespace AP

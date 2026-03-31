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
  loop_ = data.contains("loop") &&
  !data["loop"].is_null() && data["loop"].get<bool>();

  if (data.contains("keyframes")) {
    for (const auto& k : data["keyframes"]) {
      Json patched = k;
      if (!keyFrames_.empty()) {
        const KeyFrame& prev = keyFrames_.back();
        if (!patched.contains("x")) patched["x"] = prev.getX();
        if (!patched.contains("y")) patched["y"] = prev.getY();
        if (!patched.contains("scale-x")) patched["scale-x"] = prev.getXScale();
        if (!patched.contains("scale-y")) patched["scale-y"] = prev.getYScale();
        if (!patched.contains("theta")) patched["theta"] = prev.theta();
      }
      keyFrames_.push_back(KeyFrame(patched));
    }
  }

  if (keyFrames_.empty()) keyFrames_.push_back(KeyFrame());
}

KeyFrame Component::currFrame() const {
  if (keyFrames_.empty()) return KeyFrame();
  if (currentTime_ <= keyFrames_[0].time()) return keyFrames_[0];
  if (currentTime_ >= keyFrames_.back().time()) return keyFrames_.back();

  for (size_t i = 0; i + 1 < keyFrames_.size(); ++i) {
    if (currentTime_ >= keyFrames_[i].time() &&
        currentTime_ <= keyFrames_[i + 1].time()) {
      return keyFrames_[i].tween(keyFrames_[i + 1], currentTime_);
        }
  }
  return keyFrames_.back();
}

void Component::tween(sf::Time time) {
    if (loop_ && !keyFrames_.empty()) {
        float start = keyFrames_.front().time().asSeconds();
        float end = keyFrames_.back().time().asSeconds();
        float duration = end - start;
        if (duration > 0.0f) {
            float t = time.asSeconds();
            t = start + std::fmod(t - start, duration);
            currentTime_ = sf::seconds(t);
            return;
        }
    }
    currentTime_ = time;
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

}  // namespace AP

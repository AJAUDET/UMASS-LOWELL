// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// Component.hpp

#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <optional>

#include <nlohmann/json.hpp>
using Json = nlohmann::json;
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "KeyFrame.hpp"

namespace AP {
class Component: public sf::Drawable {
 public:
    /**
     * Advances this component to the state appropriate to the given time
     * @param time The Time to move to
     */
    virtual void tween(sf::Time time);  // For part B

    /**
     * Constructs a Component from the Json object
     * @param data A Json object containing Component data
     * @return A new Component
     */
    static std::unique_ptr<Component> fromJson(const Json& data);  // Factor

 protected:
    /**
     * Initializes base class components from the Json object
     * @param data A Json object containing Component data
     */
    explicit Component(const Json& data);  // Abstract class

    virtual void draw(sf::RenderTarget& target,
      sf::RenderStates states) const = 0;  // Defined in subclasses
    /**
     * Gets the current frame for the time set in tween(t)
     * @return The current frame
     */
    KeyFrame currFrame() const;  // For part B

    /**
     * Gets this Component's color
     * @return The color
     */
    sf::Color color() const { return color_; }
    void playbgm(const Json& data);

 private:
    std::vector<KeyFrame> keyFrames_;
    sf::Color color_;
    sf::Time currentTime_;
    KeyFrame currentFrame_;
    sf::Music music_;
};  // class Component

class NullComponent: public Component {
 public:
    explicit NullComponent(const Json& data);

 protected:
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
};

class CircleComponent: public Component {
 public:
    explicit CircleComponent(const Json& data): Component(data),
    circle_(data.value("radius", 0.0f)) {
        circle_.setFillColor(color());
    }

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
      sf::Transform transform_;
      currFrame().transform(transform_);
      states.transform *= transform_;
      states.transform.translate({-circle_.getRadius(), -circle_.getRadius()});
      target.draw(circle_, states);
    }
 private:
    sf::CircleShape circle_;
};

class RectangleComponent: public Component {
 public:
    explicit RectangleComponent(const Json& data): Component(data),
    rect_({data.value("width", 0.0f), data.value("height", 0.0f)}) {
    rect_.setFillColor(color());
    rect_.setPosition({data.value("x", 0.0f), data.value("y", 0.0f)});
    }
 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
      sf::Transform transform_;
      currFrame().transform(transform_);
      states.transform *= transform_;
      target.draw(rect_, states);
    }
 private:
    sf::RectangleShape rect_;
};

class ImageComponent: public Component {
 public:
    explicit ImageComponent(const Json& data): Component(data), sprite_() {
        std::string filename = data.value("file", "");
        if (!texture_.loadFromFile(filename))
         throw std::runtime_error("Could not load texture: " + filename);
        if (filename.empty()) {
            throw std::runtime_error("No filename provided for image component");
        }
        if (!texture_.loadFromFile(filename)) {
          throw std::runtime_error("Could not load texture: " + filename);
        }
        sprite_ = sf::Sprite(texture_);
        sprite_->setColor(color());
    }

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
      sf::Transform transform_;
      currFrame().transform(transform_);
      states.transform *= transform_;
      states.transform.translate(sf::Vector2f{
         static_cast<float>(-sprite_->getTextureRect().size.x) / 2,
         static_cast<float>(-sprite_->getTextureRect().size.y) / 2
      });
      target.draw(*sprite_, states);
    }

 private:
    std::optional<sf::Sprite> sprite_;
    sf::Texture texture_;
};

class TextComponent: public Component {
 public:
  explicit TextComponent(const Json& data) : Component(data), font_(), text_(font_) {
    std::string fontFile = data["font"];
    if (!font_.openFromFile(fontFile)) {
      throw std::runtime_error("TextComponent: Error opening font " + fontFile);
    }
    text_.setFont(font_);

    std::string msg = data.value("text", "");
    text_.setString(msg);
    text_.setCharacterSize(data.value("size", 30));
    text_.setFillColor(color());
  }

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
      sf::Transform transform_;
      currFrame().transform(transform_);
      states.transform *= transform_;
      target.draw(text_, states);
    }

 private:
    sf::Font font_;
    sf::Text text_;
};

class CompositeComponent: public Component {
 public:
    explicit CompositeComponent(const Json& data): Component(data) {
        if (data.contains("children")) {
            for (const auto& c : data["children"]) {
                components_.push_back(Component::fromJson(c));
            }
        }
    }

    void tween(sf::Time time) override {
      Component::tween(time);
      for (const auto& component : components_) {
         component->tween(time);
      }
    }

 protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
      sf::Transform transform_;
      currFrame().transform(transform_);
      states.transform *= transform_;
      for (const auto& component : components_) {
        target.draw(*component, states);
      }
    }
 private:
    std::vector<std::unique_ptr<Component>> components_;
};

}  // namespace AP

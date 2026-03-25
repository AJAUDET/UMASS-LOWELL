// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// KeyFrame.hpp

#pragma once

#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>
using Json = nlohmann::json;

namespace AP {
class KeyFrame {
 public:
    /**
     * Default constructs this KeyFrame
     */
    KeyFrame();
    /**
     * Constructs this KeyFrame by extracting data from a Json object
     * @param json A Json object containing KeyFrame data
     */
    explicit KeyFrame(const Json& json);

    /**
     * Gets the time at this KeyFrame
     */
    sf::Time time() const { return time_; }

    /**
     * Computes the frame between this frame and the other one using linear interpolation
     * @param alt Another KeyFrame
     * @param t The time between the two KeyFrames to tween to
     */
    KeyFrame tween(KeyFrame alt, sf::Time t) const;  // For part B
    /**
     * Applies the transform information in this keyframe to the given Transform.
     * @param state A Transform object that will be modified
     */
    void transform(sf::Transform& state) const;

    float getX() const { return x_; }
    float getY() const { return y_; }
    float getXScale() const { return xScale_; }
    float getYScale() const { return yScale_; }
    float theta() const { return theta_; }

 private:
    sf::Time time_;
    float x_;
    float y_;
    float xScale_;
    float yScale_;
    float theta_;
};  // class KeyFrame
}  // namespace AP

// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// KeyFrame.cpp

#include <SFML/Graphics.hpp>
#include "KeyFrame.hpp"

namespace AP {

KeyFrame::KeyFrame():
    time_(sf::seconds(0)),
    x_(0), y_(0),
    xScale_(1), yScale_(1),
    theta_(0) {}

KeyFrame::KeyFrame(const Json& json):
    time_(sf::seconds(json.value("t", 0.0f))),
    x_(json.value("x", 0.0f)),
    y_(json.value("y", 0.0f)),
    xScale_(json.value("scale-x", 1.0f)),
    yScale_(json.value("scale-y", 1.0f)),
    theta_(json.value("theta", 0.0f)) {}

void KeyFrame::transform(sf::Transform& state) const {
    state.translate({x_, y_});
    state.rotate(sf::degrees(theta_));
    state.scale({xScale_, yScale_});
}

KeyFrame KeyFrame::tween(KeyFrame alt, sf::Time t) const {
  float frameDuration = (alt.time() - time()).asSeconds();
  if (frameDuration <= 0.0f) return alt;

  float frameElapsed = (t - time()).asSeconds();
  float timeDifference = frameElapsed / frameDuration;
  timeDifference = std::max(0.0f, std::min(1.0f, timeDifference));
  
  KeyFrame newFrame;
  newFrame.time_ = t;
  newFrame.x_ = x_ + (alt.x_ - x_) * timeDifference;
  newFrame.y_ = y_ + (alt.y_ - y_) * timeDifference;
  newFrame.xScale_ = xScale_ + (alt.xScale_ - xScale_) * timeDifference;
  newFrame.yScale_= yScale_ + (alt.yScale_ - yScale_) * timeDifference;
  newFrame.theta_ = theta_ + (alt.theta_ - theta_) * timeDifference;

  return newFrame;
}

}  // namespace AP

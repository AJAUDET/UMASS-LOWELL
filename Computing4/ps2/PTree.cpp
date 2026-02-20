// Copyright (c) 2026 AJ Audet

#include "PTree.hpp"

PTree::PTree(double length, int depth): depth_(depth) {
    sf::Vector2f base(0.f, 0.f);
    pTree(base, static_cast<float>(length), 0.f, depth);
}

void PTree::pTree(sf::Vector2f position, float size, float angle, int depth) {
    float treeDepth = 1.f - static_cast<float>(depth) / depth_;
    treeDepth += std::abs(angle) / 180.f * 0.1f;

    std::uint8_t r = static_cast<std::uint8_t>(150 - treeDepth * 105);
    std::uint8_t g = static_cast<std::uint8_t>(0);
    std::uint8_t b = static_cast<std::uint8_t>(200 - treeDepth * 55);

    sf::RectangleShape base({size, size});
    base.setOrigin({0.f, size});
    base.setPosition(position);
    base.setRotation(sf::degrees(angle));
    base.setFillColor(sf::Color(r, g, b));

    branches_.push_back(base);

    if (depth == 0) return;

    float branch = size / std::sqrt(2.f);

    sf::Transform parent;
    parent.translate(position);
    parent.rotate(sf::degrees(angle));

    sf::Transform left = parent;
    left.translate({0.f, -size});
    left.rotate(sf::degrees(-45.f));

    sf::Transform right = parent;
    right.translate({size, -size});
    right.rotate(sf::degrees(45.f));

    sf::Vector2f leftPos = left.transformPoint({0.f, 0.f});
    sf::Vector2f rightPos = right.transformPoint({-branch, 0.f});

    pTree(leftPos,  branch, angle - 45.f, depth - 1);
    pTree(rightPos, branch, angle + 45.f, depth - 1);
}

void PTree::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& branch : branches_) {
        target.draw(branch, states);
    }
}

sf::FloatRect PTree::getBounds() const {
    if (branches_.empty())
        return {};

    float minX = branches_[0].getGlobalBounds().position.x;
    float minY = branches_[0].getGlobalBounds().position.y;
    float maxX = minX + branches_[0].getGlobalBounds().size.x;
    float maxY = minY + branches_[0].getGlobalBounds().size.y;

    for (const auto& branch : branches_) {
        auto subBranch = branch.getGlobalBounds();
        minX = std::min(minX, subBranch.position.x);
        minY = std::min(minY, subBranch.position.y);
        maxX = std::max(maxX, subBranch.position.x + subBranch.size.x);
        maxY = std::max(maxY, subBranch.position.y + subBranch.size.y);
    }

    return sf::FloatRect({minX, minY}, {maxX - minX, maxY - minY});
}

void PTree::move(sf::Vector2f position) {
    for (auto& branch : branches_) {
        branch.move(position);
    }
}

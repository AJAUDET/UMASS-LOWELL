// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// test.cpp

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE AniPlayerTests

#include <cmath>
#include <SFML/Graphics.hpp>
#include <boost/test/unit_test.hpp>
#include <nlohmann/json.hpp>

#include "Component.hpp"
#include "KeyFrame.hpp"
using Json = nlohmann::json;

static bool nearEq(float a, float b, float eps = 0.001f) { return std::fabs(a - b) < eps; }

static Json keyFrameJson(float t, float x, float y,
    float sx = 1.0f, float sy = 1.0f, float theta = 0.0f) {
    return {{"t", t}, {"x", x}, {"y", y},
            {"scale-x", sx}, {"scale-y", sy}, {"theta", theta}};
}

static sf::Vector2f applyToOrigin(const AP::KeyFrame& kf) {
    sf::Transform t;
    kf.transform(t);
    return t.transformPoint({0.0f, 0.0f});
}

static sf::Vector2f applyToPoint(const AP::KeyFrame& kf, sf::Vector2f pt) {
    sf::Transform t;
    kf.transform(t);
    return t.transformPoint(pt);
}

static Json rectJson(Json keyframes) {
    return {{"shape", "rect"}, {"width", 10.0f}, {"height", 10.0f},
            {"color", "FF0000FF"}, {"keyframes", keyframes}};
}

BOOST_AUTO_TEST_CASE(TestPartialTween) {
    AP::KeyFrame kf0(keyFrameJson(0.0f,   0.0f,   0.0f, 1.0f, 1.0f,  0.0f));
    AP::KeyFrame kf1(keyFrameJson(4.0f, 400.0f, 200.0f, 3.0f, 3.0f, 90.0f));

    sf::Vector2f pos = applyToOrigin(kf0.tween(kf1, sf::seconds(1.0f)));
    BOOST_CHECK(nearEq(pos.x, 100.0f));
    BOOST_CHECK(nearEq(pos.y, 50.0f));

    AP::KeyFrame s0(keyFrameJson(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f));
    AP::KeyFrame s1(keyFrameJson(4.0f, 0.0f, 0.0f, 3.0f, 3.0f, 0.0f));
    sf::Vector2f scaled = applyToPoint(s0.tween(s1, sf::seconds(1.0f)), {1.0f, 0.0f});
    BOOST_CHECK(scaled.x > 1.0f && scaled.x < 3.0f);

    AP::KeyFrame r0(keyFrameJson(0.0f, 0.0f, 0.0f, 1.0f, 1.0f,  0.0f));
    AP::KeyFrame r1(keyFrameJson(4.0f, 0.0f, 0.0f, 1.0f, 1.0f, 90.0f));
    sf::Vector2f rotated = applyToPoint(r0.tween(r1, sf::seconds(1.0f)), {1.0f, 0.0f});
    BOOST_CHECK(rotated.y > 0.0f && rotated.y < 1.0f);
}

BOOST_AUTO_TEST_CASE(TestFixedKeyframe) {
    AP::KeyFrame kf1(keyFrameJson(0.0f, 0.0f, 0.0f));
    AP::KeyFrame kf2(keyFrameJson(4.0f, 500.0f, 400.0f));

    sf::Vector2f atStart = applyToOrigin(kf1.tween(kf2, sf::seconds(0.0f)));
    BOOST_CHECK(nearEq(atStart.x, 0.0f));
    BOOST_CHECK(nearEq(atStart.y, 0.0f));

    sf::Vector2f atEnd = applyToOrigin(kf1.tween(kf2, sf::seconds(4.0f)));
    BOOST_CHECK(nearEq(atEnd.x, 500.0f));
    BOOST_CHECK(nearEq(atEnd.y, 400.0f));
}

BOOST_AUTO_TEST_CASE(TestTweenDirection) {
    AP::KeyFrame kf0(keyFrameJson(0.0f,   0.0f,   0.0f));
    AP::KeyFrame kf1(keyFrameJson(6.0f, 600.0f, 300.0f));

    sf::Vector2f early = applyToOrigin(kf0.tween(kf1, sf::seconds(1.0f)));
    sf::Vector2f late  = applyToOrigin(kf0.tween(kf1, sf::seconds(5.0f)));

    BOOST_CHECK(late.x > early.x);
    BOOST_CHECK(late.y > early.y);
    BOOST_CHECK(nearEq(early.x, 100.0f));
    BOOST_CHECK(nearEq(late.x,  500.0f));
}

BOOST_AUTO_TEST_CASE(TestBadBoundary) {
    Json data = rectJson({
        {
            {"t", 1.0f},
            {"x", 100.0f},
            {"y", 50.0f},
            {"scale-x", 1.0f},
            {"scale-y", 1.0f},
            {"theta", 0.0f}
        },
        {
            {"t", 3.0f},
            {"x", 300.0f},
            {"y", 150.0f},
            {"scale-x", 1.0f},
            {"scale-y", 1.0f},
            {"theta", 0.0f}
        }});

    auto comp = AP::Component::fromJson(data);

    sf::RenderTexture rt;
    BOOST_CHECK(rt.resize({400, 400}));

    comp->tween(sf::seconds(0.0f));
    rt.clear(sf::Color::Black);
    rt.draw(*comp);
    rt.display();
    {
        sf::Image img = rt.getTexture().copyToImage();
        BOOST_CHECK(img.getPixel({102, 52}).r > 0);
        BOOST_CHECK(img.getPixel({302, 152}).r == 0);
    }

    comp->tween(sf::seconds(99.0f));
    rt.clear(sf::Color::Black);
    rt.draw(*comp);
    rt.display();
    {
        sf::Image img = rt.getTexture().copyToImage();
        BOOST_CHECK(img.getPixel({302, 152}).r > 0);
        BOOST_CHECK(img.getPixel({102, 52}).r == 0);
    }
}

BOOST_AUTO_TEST_CASE(TestOnlyKeyframes) {
    Json data = rectJson({
        {{"t",  0.0f}, {"x",   0.0f}, {"y",   0.0f},
         {"scale-x", 1.0f}, {"scale-y", 1.0f}, {"theta", 0.0f}},
        {{"t", 10.0f}, {"x", 500.0f}, {"y", 500.0f},
         {"scale-x", 1.0f}, {"scale-y", 1.0f}, {"theta", 0.0f}}
    });
    auto comp = AP::Component::fromJson(data);

    sf::RenderTexture rt;
    BOOST_CHECK(rt.resize({600, 600}));

    comp->tween(sf::seconds(5.0f));
    rt.clear(sf::Color::Black);
    rt.draw(*comp);
    rt.display();

    sf::Image img = rt.getTexture().copyToImage();
    BOOST_CHECK(img.getPixel({250, 250}).r > 0);
    BOOST_CHECK(img.getPixel({0, 0}).r == 0);
    BOOST_CHECK(img.getPixel({500, 500}).r == 0);
}

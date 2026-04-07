// Copyright 2026 AJ Audet & Hoang Bach Nguyen
// test.cpp

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EDistanceTests

#include <boost/test/unit_test.hpp>
#include "EDistance.hpp"

BOOST_AUTO_TEST_CASE(TestMin3) {
    BOOST_CHECK(EDistance::min3(1, 2, 3) == 1);
    BOOST_CHECK(EDistance::min3(1, 3, 2) == 1);
    BOOST_CHECK(EDistance::min3(2, 1, 3) == 1);
    BOOST_CHECK(EDistance::min3(2, 3, 1) == 1);
    BOOST_CHECK(EDistance::min3(3, 1, 2) == 1);
    BOOST_CHECK(EDistance::min3(3, 2, 1) == 1);

    BOOST_CHECK(EDistance::min3(1, 2, 2) == 1);
    BOOST_CHECK(EDistance::min3(2, 1, 2) == 1);
    BOOST_CHECK(EDistance::min3(2, 2, 1) == 1);

    BOOST_CHECK(EDistance::min3(1, 1, 2) == 1);
    BOOST_CHECK(EDistance::min3(1, 2, 1) == 1);
    BOOST_CHECK(EDistance::min3(2, 1, 1) == 1);

    BOOST_CHECK(EDistance::min3(5, 5, 5) == 5);

    BOOST_CHECK(EDistance::min3(10, 3, 7) == 3);
    BOOST_CHECK(EDistance::min3(6, 4, 5) == 4);
    BOOST_CHECK(EDistance::min3(6, 5, 4) == 4);

    BOOST_CHECK(EDistance::min3(0, 1, 2) == 0);
    BOOST_CHECK(EDistance::min3(-1, 0, 1) == -1);
    BOOST_CHECK(EDistance::min3(0, 0, 1) == 0);
    BOOST_CHECK(EDistance::min3(1, 0, 0) == 0);
}

BOOST_AUTO_TEST_CASE(TestPenalty) {
    BOOST_CHECK(EDistance::penalty('A', 'A') == 0);
    BOOST_CHECK(EDistance::penalty('T', 'T') == 0);
    BOOST_CHECK(EDistance::penalty('G', 'G') == 0);
    BOOST_CHECK(EDistance::penalty('C', 'C') == 0);
    BOOST_CHECK(EDistance::penalty('A', 'T') == 1);
    BOOST_CHECK(EDistance::penalty('G', 'C') == 1);
    BOOST_CHECK(EDistance::penalty('T', 'A') == 1);
}

BOOST_AUTO_TEST_CASE(TestOptDistanceExample) {
    EDistance ed("AACAGTTACC", "TAAGGTCA");
    BOOST_CHECK(ed.optDistance() == 7);
}

BOOST_AUTO_TEST_CASE(TestOptDistanceIdentical) {
    EDistance ed("ACGT", "ACGT");
    BOOST_CHECK(ed.optDistance() == 0);
}

BOOST_AUTO_TEST_CASE(TestOptDistanceOneEmpty) {
    EDistance ed("ACGT", "");
    BOOST_CHECK(ed.optDistance() == 8);

    EDistance ed2("", "ACGT");
    BOOST_CHECK(ed2.optDistance() == 8);
}

BOOST_AUTO_TEST_CASE(TestOptDistanceAllMismatch) {
    EDistance ed("AAAA", "TTTT");
    BOOST_CHECK(ed.optDistance() == 4);
}

BOOST_AUTO_TEST_CASE(TestOptDistanceSmall) {
    EDistance ed("A", "T");
    BOOST_CHECK(ed.optDistance() == 1);

    EDistance ed2("A", "A");
    BOOST_CHECK(ed2.optDistance() == 0);

    EDistance ed3("A", "");
    BOOST_CHECK(ed3.optDistance() == 2);
}

BOOST_AUTO_TEST_CASE(TestAlignmentLength) {
    EDistance ed("AAAAG", "AAAAT");
    ed.optDistance();
    std::string result = ed.alignment();
    BOOST_CHECK(!result.empty());

    std::string lastLine;
    std::string line;
    for (char c : result) {
        if (c == '\n') {
            if (!line.empty()) lastLine = line;
            line.clear();
        } else {
            line += c;
        }
    }
    if (!line.empty()) lastLine = line;

    BOOST_CHECK(lastLine.find('G') < lastLine.size());
    BOOST_CHECK(lastLine.find('T') < lastLine.size());
}

BOOST_AUTO_TEST_CASE(TestAlignmentLength2) {
    std::string s1 = "AAAAAA";
    std::string s2 = "AAA";

    EDistance ed(s1, s2);
    ed.optDistance();
    std::string result = ed.alignment();
    BOOST_CHECK(!result.empty());

    std::size_t lineCount = 0;
    for (char c : result) {
        if (c == '\n') {
            lineCount++;
        }
    }

    BOOST_CHECK(lineCount >= s1.size());
}

BOOST_AUTO_TEST_CASE(TestAlignmentIdentical) {
    EDistance ed("ACGT", "ACGT");
    ed.optDistance();
    std::string result = ed.alignment();
    BOOST_CHECK(!result.empty());
}

BOOST_AUTO_TEST_CASE(TestAlignmentDirection) {
    EDistance ed("ACGT", "TGCA");
    int dist = ed.optDistance();
    std::string result = ed.alignment();
    BOOST_CHECK(!result.empty());
    BOOST_CHECK(dist >= 0);
}

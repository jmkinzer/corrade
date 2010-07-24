/*
    Copyright © 2007, 2008, 2009, 2010 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Map2X.

    Map2X is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Map2X is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include "UtilitiesTest.h"

#include <string>
#include <QtTest/QTest>

#include "Utility/utilities.h"

using namespace std;

QTEST_APPLESS_MAIN(Map2X::Utility::Test::UtilitiesTest)
Q_DECLARE_METATYPE(std::string)

namespace Map2X { namespace Utility { namespace Test {

void UtilitiesTest::trim_data() {
    QTest::addColumn<QString>("in");
    QTest::addColumn<QString>("out");

    QTest::newRow("spaces at the end") << "abc  " << "abc";
    QTest::newRow("spaces at beginning") << "  abc" << "abc";
    QTest::newRow("no spaces") << "abc" << "abc";
    QTest::newRow("all spaces") << "    " << "";
    QTest::newRow("different kinds of spaces") << "\t\r\n\f\v " << "";
}

void UtilitiesTest::trim() {
    QFETCH(QString, in);
    QFETCH(QString, out);

    QCOMPARE(QString::fromStdString(Utility::trim(in.toStdString())), out);
}

}}}
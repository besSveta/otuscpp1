/*
 * test_build.cpp
 *
 *  Created on: 9 апр. 2019 г.
 *      Author: sveta
 */

#define BOOST_TEST_MODULE helloworld_test_module
#include <boost/test/included/unit_test.hpp>
#include "buildNumber.h"

BOOST_AUTO_TEST_SUITE(helloworld_test_suite)

BOOST_AUTO_TEST_CASE(helloworld_test_build)
{
	BOOST_CHECK(GetBuildNumber() > 0);
}

BOOST_AUTO_TEST_SUITE_END()

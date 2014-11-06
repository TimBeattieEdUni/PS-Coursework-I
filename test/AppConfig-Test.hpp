//////////////////////////////////////////////////////////////////////////////
/// @file     AppConfig-Test.hpp
///
/// @brief    Unit test for class AppConfig.
///
/// @todo     Test failure modes for class AppConfig.
///

#ifndef PSCOURSEWORKI_APPCONFIG_TEST_HPP
#define PSCOURSEWORKI_APPCONFIG_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "AppConfig.hpp"


//////////////////////////////////////////////////////////////////////////////
/// @brief  First test for class AppConfig.
///
/// @test   AppConfig can be constructed from valid arguments.
///
TEST(AppConfig)
{
	using namespace PsCourseworkI;

	AppConfigReader appConfig("inputs/AppConfig-Test.cfg");
	AppConfig testConfig;

    //  these must match "inputs/AppConfig-Test.cfg"
	testConfig.m_Nx = 200;
	testConfig.m_Ny = 200;
	testConfig.m_T  = 50;
	testConfig.m_TT = 1250;
	testConfig.m_r  = 0.08;
	testConfig.m_a  = 0.04;
	testConfig.m_b  = 0.02;
	testConfig.m_m  = 0.06;
	testConfig.m_k  = 0.2;
	testConfig.m_l  = 0.2;
	testConfig.m_dt = 0.4;

	CHECK(appConfig.GetConfig().m_Nx    == testConfig.m_Nx);
	CHECK(appConfig.GetConfig().m_Ny    == testConfig.m_Ny);
	CHECK(appConfig.GetConfig().m_T     == testConfig.m_T);
	CHECK(appConfig.GetConfig().m_r     == testConfig.m_r);
	CHECK(appConfig.GetConfig().m_a     == testConfig.m_a);
	CHECK(appConfig.GetConfig().m_b     == testConfig.m_b);
	CHECK(appConfig.GetConfig().m_m     == testConfig.m_m);
	CHECK(appConfig.GetConfig().m_k     == testConfig.m_k);
	CHECK(appConfig.GetConfig().m_l     == testConfig.m_l);
	CHECK(appConfig.GetConfig().m_dt    == testConfig.m_dt);
}


#endif  //  #ndef PSCOURSEWORKI_APPCONFIG_TEST_HPP

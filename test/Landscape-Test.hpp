//////////////////////////////////////////////////////////////////////////////
/// @file     Landscape-Test.hpp
///
/// @brief    Unit test for class Landscape.
///


#ifndef PSCOURSEWORKI_LANDSCAPE_TEST_HPP
#define PSCOURSEWORKI_LANDSCAPE_TEST_HPP


//////////////////////////////////////////////////////////////////////////////
//  Header for class being tested.
#include "Landscape.hpp"
//  local headers for classes needed to test the class Landscape
#include "AppConfig.hpp"
#include "Landscape.hpp"
#include "BmpFile.hpp"

//////////////////////////////////////////////////////////////////////////////
//  Standard headers.
#include <stdexcept>
#include <cmath>
#include <iostream>

////////////////////////////////////////////////////////////////////////////
/// @brief  First test for class Landscape.
///
/// @test   Landscape can be constructed from valid arguments.
///
TEST(Landscape)
{
	using repo::classes::Landscape;

	CHECK(false);
}


//////////////////////////////////////////////////////////////////////////////
/// @brief  Test evolution of landscape.
///
/// @test   test if landscape routine "update()" evoloves a landscape correctly on small 2x2 landscape
///
TEST(LandscapeUpdateOn2x2Grid)
{
    using namespace PsCourseworkI;

    double epsilon=10^-8; // error tolerance for comparison

    //  load 4x4 test configuration from file
		AppConfig cfg2x2("landscape_2x2_test.cfg");

    // get the parameters for the system:
        double r=cfg2x2.Getr();
        double a=cfg2x2.Geta();
        double b=cfg2x2.Getb();
        double m=cfg2x2.Getm();
        double k=cfg2x2.Getk();
        double l=cfg2x2.Getl();
        double dt=cfg2x2.Getdt();

        std::cout<<"value for dt= "<<dt<<std::endl;

    //  load land/water (1,0;1,1)   map from file
		BmpFile map_bmp2x2("landscape_2x2_test.dat");

    //  initialise the landscape
		Landscape landscape2x2(cfg2x2, map_bmp2x2);
	// set random values for Hare and Pumas
		landscape2x2.ApplyRandomPumas();
		landscape2x2.ApplyRandomHares();

    //  get reference to the array of the landscape
        Landscape::LsArray const& landscape = landscape2x2.GetArray();

    // read out the explicit initial values for the Hares
        double H_11=landscape(1,1).m_hares;
        double H_12=landscape(1,2).m_hares;
        double H_21=landscape(2,1).m_hares;
        double H_22=landscape(2,2).m_hares;
    // read out the explicit initial values for the Pumas
        double P_11=landscape(1,1).m_pumas;
        double P_12=landscape(1,2).m_pumas;
        double P_21=landscape(2,1).m_pumas;
        double P_22=landscape(2,2).m_pumas;

        std::cout<<"inital value H_11= "<<H_11<<std::endl;
        std::cout<<"inital value P_11= "<<P_11<<std::endl;


    //calculate the evolved values explicitely
        H_11=H_11+dt*(H_11*(r-a*P_11)+k*(H_21+H_12-2*H_11));
        H_12=H_12+dt*(H_12*(r-a*P_12)+k*(H_11-H_12));
        H_21=H_21+dt*(H_21*(r-a*P_21)+k*(H_11-H_21));
        H_22=0; //this gridcell is water

        P_11=P_11+dt*(P_11*(b*H_11-m)+l*(P_21+P_12-2*P_11));
        P_12=P_12+dt*(P_12*(b*H_12-m)+l*(P_11-P_12));
        P_21=P_21+dt*(P_21*(b*H_21-m)+l*(P_11-P_21));
        P_22=0;

        std::cout<<"explicit updated value H_11= "<<H_11<<std::endl;
        std::cout<<"explicit updated value P_11= "<<P_11<<std::endl;

    //update the landscape via the lanscape class
        landscape2x2.Update();

    //read out the evolved values for Hares
        double H_11_evo=landscape(1,1).m_hares;
        double H_12_evo=landscape(1,2).m_hares;
        double H_21_evo=landscape(2,1).m_hares;
        double H_22_evo=landscape(2,2).m_hares;
    // read out the evolved values for Pumas
        double P_11_evo=landscape(1,1).m_pumas;
        double P_12_evo=landscape(1,2).m_pumas;
        double P_21_evo=landscape(2,1).m_pumas;
        double P_22_evo=landscape(2,2).m_pumas;

        std::cout<<"class updated value H_11= "<<H_11<<std::endl;
        std::cout<<"class updated value P_11= "<<P_11<<std::endl;

    //check if the values agree in tolerance interval

        CHECK(fabs(H_11-H_11_evo) <= epsilon);
        CHECK(fabs(H_12-H_12_evo) <= epsilon);
        CHECK(fabs(H_21-H_21_evo) <= epsilon);
        CHECK(fabs(H_22-H_22_evo) <= epsilon);

        CHECK(fabs(P_11-P_11_evo) <= epsilon);
        CHECK(fabs(P_12-P_12_evo) <= epsilon);
        CHECK(fabs(P_21-P_21_evo) <= epsilon);
        CHECK(fabs(P_22-P_22_evo) <= epsilon);

}



#endif  //  #ndef PSCOURSEWORKI_LANDSCAPE_TEST_HPP

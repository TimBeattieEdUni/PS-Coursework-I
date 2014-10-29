//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///		file:	PopulationCompute.hpp
///		author:	Márton Feigl
///		date:	27/10/2014
///		ver:	1.0
///		description: includes class PopulationCompute definitions that calculates hare and puma population within 2D grid
///
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PopulationCompute.hpp"

PopulationCompute::PopulationCompute()
{
	// Constructor
}

PopulationCompute::~PopulationCompute()
{
	// Destructor
}

void PopulationCompute::CalcNewPopulation()
{
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
		{
			m_temp_hare[i][j] = m_curr_prop[i][j].hare_density + m_time_step*(HareCalculation(i,j));
			m_temp_puma[i][j] = m_curr_prop[i][j].puma_density + m_time_step*(PumaCalculation(i,j));
		}

	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
		{
			m_curr_prop[i][j].hare_density	=	m_temp_hare[i][j];
			m_curr_prop[i][j].puma_density	=	m_temp_puma[i][j];
		}

}

float PopulationCompute::HareCalculation(int i, int j)
{
	return (
        ( m_curr_prop[i][j].hare_birth * m_curr_prop[i][j].hare_density ) -
		( m_curr_prop[i][j].puma_predation * m_curr_prop[i][j].hare_density *  m_curr_prop[i][j].puma_density ) +
		( m_curr_prop[i][j].hare_diffusion * HareSurrounding(i,j) )
            );
}

float PopulationCompute::HareSurrounding(int i, int j)
{
    BorderControl.m_N = 0;
    if(0 != m_curr_prop[i-1][j].type) BorderControl.m_N++;
    if(0 != m_curr_prop[i+1][j].type) BorderControl.m_N++;
    if(0 != m_curr_prop[i][j-1].type) BorderControl.m_N++;
    if(0 != m_curr_prop[i][j+1].type) BorderControl.m_N++;

	if(i-1 < 0)		BorderControl.m_border[0] = 0.0; else BorderControl.m_border[0] = m_curr_prop[i-1][j].hare_density;
	if(i+1 > MAX)	BorderControl.m_border[1] = 0.0; else BorderControl.m_border[1] = m_curr_prop[i+1][j].hare_density;
	if(j-1 < 0)		BorderControl.m_border[2] = 0.0; else BorderControl.m_border[2] = m_curr_prop[i][j-1].hare_density;
	if(j+1 > MAX)	BorderControl.m_border[3] = 0.0; else BorderControl.m_border[3] = m_curr_prop[i][j+1].hare_density;

	return (
				(BorderControl.m_border[0] + 
				 BorderControl.m_border[1] + 
				 BorderControl.m_border[2] + 
				 BorderControl.m_border[3]) - 
				(BorderControl.m_N * m_curr_prop[i][j].hare_density )
         ) ;
}


float PopulationCompute::PumaCalculation(int i, int j)
{
	return (
		(m_curr_prop[i][j].puma_birth * m_curr_prop[i][j].hare_density * m_curr_prop[i][j].puma_density ) -
		( m_curr_prop[i][j].puma_mortal * m_curr_prop[i][j].puma_density  ) + 
		( m_curr_prop[i][j].puma_diffusion * PumaSurrounding(i,j) )
	);
}

float PopulationCompute::PumaSurrounding(int i, int j)
{
	/* === Here it is not needed, since it is the same from previous sequential calculation in PopulationCompute::HareSurrounding() ===  
	BorderControl.m_N = 0;
    if(0 != m_curr_prop[i-1][j].type) BorderControl.m_N++;
    if(0 != m_curr_prop[i+1][j].type) BorderControl.m_N++;
    if(0 != m_curr_prop[i][j-1].type) BorderControl.m_N++;
    if(0 != m_curr_prop[i][j+1].type) BorderControl.m_N++;
	*/

	if(i-1 < 0)		BorderControl.m_border[0] = 0.0; else BorderControl.m_border[0] = m_curr_prop[i-1][j].puma_density;
	if(i+1 > MAX)	BorderControl.m_border[1] = 0.0; else BorderControl.m_border[1] = m_curr_prop[i+1][j].puma_density;
	if(j-1 < 0)		BorderControl.m_border[2] = 0.0; else BorderControl.m_border[2] = m_curr_prop[i][j-1].puma_density;
	if(j+1 > MAX)	BorderControl.m_border[3] = 0.0; else BorderControl.m_border[3] = m_curr_prop[i][j+1].puma_density;

	return (
				(BorderControl.m_border[0] + 
				 BorderControl.m_border[1] + 
				 BorderControl.m_border[2] + 
				 BorderControl.m_border[3]) - 
				(BorderControl.m_N * m_curr_prop[i][j].puma_density )
         ) ;
}
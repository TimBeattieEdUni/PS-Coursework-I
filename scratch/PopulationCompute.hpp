//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
///		file:	PopulationCompute.cpp
///		author:	Márton Feigl
///		date:	27/10/2014
///		ver:	1.0
///		description: includes class PopulationCompute that calculates hare and puma population within 2D grid
///                     the progam assumes that for water territories all the Poperty-ies are zero-ed out
///
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef POPULATION_COMPUTE_H
#define POPULATION_COMPUTE_H


class PopulationCompute
{
public:
	PopulationCompute();
	~PopulationCompute();

	void CalcNewPopulation();

private:
	int static const MAX = 2000; // might be useful, but only static because otherwise it cannot be initialised
	float m_time_step;
	struct Property
	{ // the letters are referencing the brief spec
	    int   type;                 // 0 - water, 1 - land
		float hare_density;			// H - hare density
		float hare_birth;   		// r - hare birth rate
		float hare_diffusion;   	// k - hare diffusion rate
		float puma_density;			// P - puma density
		float puma_predation;       // a - puma predation rate at which hares are eaten
		float puma_birth;		    // b - puma birth rate per one hare eaten
		float puma_mortal;  		// m - puma mortality rate
		float puma_diffusion;   	// l - puma diffusion rate
	};
	Property m_curr_prop[MAX][MAX];
	float m_temp_hare[MAX][MAX];
	float m_temp_puma[MAX][MAX];

	struct
	{
		int m_N; // the number of non-water gid squares which suound the currently observed grid square
		float m_border[4]; // the Halo around the grid
	}BorderControl;

	float HareCalculation(int i, int j);
	float HareSurrounding(int i, int j);

	float PumaCalculation(int i, int j);
	float PumaSurrounding(int i, int j);
};

#endif

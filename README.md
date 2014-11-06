PS-Coursework-I
===============

Programming Skills Coursework I


To get started, run "make" in the top-level directory.  Once make has completed, if you just want to run the application, type the following command, still in the top-level directory:

	app/popsim config/popsim.cfg landscapes/small.dat


To use an alternative configuration and land bitmask, type:

	app/popsim <cfgfile> <mapfile>

where:

	<cfgfile> is a suitable configuration file (examples can be found in directory "config")
	<mapfile> is a land/water bitmask file (examples can be found in directory "landscapes")


For faster builds, set the environment variable MAKEFLAGS as follows:

export MAKEFLAGS="-j 8"

This has been found to reduce build times by approximately 25% on the CP Labs machines and by approximatley 75% on laptops running OS X.

PS-Coursework-I
===============

Programming Skills Coursework I

To get started, run "make" in the top-level directory.  This will perform the following steps:

	Build the popsim class library: classes/libpopsim-classes.a.
	Build the popsim application: app/popsim.
	Unpack and build the unit test framework: UnitTest++.
	Build the unit test application: test/popsim-test.
	Run the unit test application.
	Generate source code documentation: doc/doxygen/index.html.
	Generate the LaTeX group coursework report: report/report.pdf.	

Failure at any stage will halt the make process.

For faster builds, set the environment variable MAKEFLAGS as follows:

export MAKEFLAGS="-j 8"

This has been found to reduce build times by approximately 25% on the CP Labs machines and by approximatley 75% on laptops running OS X.
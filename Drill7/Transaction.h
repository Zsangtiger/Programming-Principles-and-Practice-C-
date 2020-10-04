#pragma once
#include "Book.h"
#include "Patron.h"
#include "Date.h"


struct Transaction
{
	Book tbook;
	Chrono::Date tdate;
	Patron tpatron;
};


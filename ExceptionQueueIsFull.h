#pragma once

class ExceptionQueueIsFull : public std::exception
{
public:

/*************************************************************************
 * Override Virtual Function what()
 *------------------------------------------------------------------------
 * This function returns the message of the exception
 *------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 * 
 * POST-CONDITIONS
 * 		will return the message of the exception
 *************************************************************************/
	virtual const char* what() const noexcept
	{
		return "Queue is full";
	}
};
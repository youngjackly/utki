#include "../../src/utki/debug.hpp"

#include "testso.hpp"
#include "TestSingleton.hpp"



int& GetA(){
	ASSERT_ALWAYS(TestSingleton::isCreated())
	return TestSingleton::inst().a;
}



void IncA(){
	ASSERT_ALWAYS(TestSingleton::isCreated())
	++(TestSingleton::inst().a);
}



void PrintA(){
	ASSERT_ALWAYS(TestSingleton::isCreated())
	TRACE_ALWAYS(<< "PrintA(): a = " << TestSingleton::inst().a << std::endl)
}

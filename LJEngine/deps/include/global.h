#include <boost\shared_ptr.hpp>
//#include <glm\glm.hpp>

//-- Boost shared pointer typedef
//-- usage: 
//-- class testClass;
//-- BOOST_PTR_DEF( testClass );
//-- testClassPtr instance = testClassPtr( new testClass() );
#define BOOST_PTR_DEF( typeName ) \
typedef boost::shared_ptr<typeName> typeName##Ptr
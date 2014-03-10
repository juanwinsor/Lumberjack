//-- boost
#include "../../../deps/include/boost/shared_ptr.hpp"

//-- glm and extensions
#include "../../../deps/include/glm/glm.hpp"
#include "../../../deps/include/glm\gtc\matrix_transform.hpp"

//-- Boost shared pointer typedef
//-- usage: 
//-- class testClass;
//-- BOOST_PTR_DEF( testClass );
//-- testClassPtr instance = testClassPtr( new testClass() );
#define BOOST_PTR_DEF( typeName ) \
typedef boost::shared_ptr<typeName> typeName##Ptr
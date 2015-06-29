#ifndef _WEAK_TEST__
#define _WEAK_TEST__

#include <boost/smart_ptr.hpp>
using namespace boost;

class node{
public:
    typedef shared_ptr<node> ptr_type;
    ptr_type next;
};

class weak_node{
public:
    typedef weak_ptr<weak_node> weak_ptr_type;
    weak_ptr_type next;
};

#endif

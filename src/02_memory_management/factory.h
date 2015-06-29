#include <boost/smart_ptr.hpp>
using namespace boost;

class abstract{
public:
    virtual int f() = 0;
protected:
    virtual ~abstract() {};
};


class impl: public abstract{
public:
    impl() {};
    virtual ~impl(){};
public:
    virtual int f(){
        return 1;
    }
};

shared_ptr<abstract> create();

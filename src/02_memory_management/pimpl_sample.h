#include <boost/smart_ptr.hpp>
using namespace boost;

class pimpl_sample{
private:
    class impl;
    shared_ptr<impl> p;

public:
    pimpl_sample();
    int getIndex();

};

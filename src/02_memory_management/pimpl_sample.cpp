#include "pimpl_sample.h"

class pimpl_sample::impl{
public:
    int getIndex(){
        return 1; 
    }
};


pimpl_sample::pimpl_sample():p(new impl){}

int pimpl_sample::getIndex(){
    return p->getIndex();
}

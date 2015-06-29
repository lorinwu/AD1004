#include "factory.h"


shared_ptr<abstract> create(){
    return make_shared<impl>();
}

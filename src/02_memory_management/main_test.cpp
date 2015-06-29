// Note, only one file can define BOOST_TEST_MODULE, which will define main and init function
#define BOOST_TEST_MODULE test
#include "pimpl_sample.h"
#include "factory.h"
#include "weak_test.h"
#include "objectpool_test.h"
#include "weak_test.h"
#include "misc.h"
#include <ctime>
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <boost/smart_ptr.hpp>
#define BOOST_SYSTEM_NO_DEPRECATED
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>
using namespace boost;

BOOST_AUTO_TEST_CASE( scoped_ptr_test ) {
    scoped_ptr<std::string> sp(new std::string("scoped_ptr_test"));

    BOOST_ASSERT(sp != 0);
    BOOST_ASSERT(*sp == "scoped_ptr_test");
    BOOST_ASSERT(sp->size() > 0);

}


BOOST_AUTO_TEST_CASE( scoped_array_test ) {
    int *arr = new int[100];
    scoped_array<int> sa(arr);

    std::fill_n(&sa[0], 100, 5);
    BOOST_ASSERT(sa[10] == 5);

}


BOOST_AUTO_TEST_CASE( shared_ptr_test ) {
    shared_ptr<int> sp(new int(10));

    BOOST_ASSERT(sp.unique());

    shared_ptr<int> sp2 = sp;

    BOOST_ASSERT(sp == sp2 && sp.use_count() == 2);

    *sp2 = 100;
    
    BOOST_ASSERT(*sp == 100);

}


BOOST_AUTO_TEST_CASE( make_shared_test ) {
    auto sp = make_shared<std::string>("make_shared_test"); 
    //shared_ptr<std::string> sp = make_shared<std::string>("make_shared_test"); 

    BOOST_ASSERT(sp->size() == 16);

}


BOOST_AUTO_TEST_CASE( vector_shared_test ) {
    typedef std::vector <shared_ptr<int> > vs;
    vs v(10);

    int i = 0;
    for (auto pos = v.begin(); pos != v.end(); ++pos) {
        (*pos) = make_shared<int>(++i);
    }

    
    BOOST_ASSERT(*v[9] == 10);

}


BOOST_AUTO_TEST_CASE( pimpl_test ) {
    pimpl_sample s; 
    BOOST_ASSERT(s.getIndex() == 1);

}


BOOST_AUTO_TEST_CASE( factory_test ) {
    auto p = create(); 
    BOOST_ASSERT(p->f() == 1);

}


BOOST_AUTO_TEST_CASE( shared_array_test ) {
    int *p = new int[10];
    shared_array<int> sa(p);
    BOOST_ASSERT(sa.unique());

    shared_array<int> sa2 = sa;
    BOOST_ASSERT(sa.use_count() == 2);

    sa[3] = 10;
    BOOST_ASSERT(sa2[3] == 10);
}


BOOST_AUTO_TEST_CASE( weak_ptr_test ) {
    shared_ptr<int> sp(new int(10));

    weak_ptr<int> wp(sp);
    BOOST_ASSERT(wp.use_count() == 1);

    sp.reset();
    BOOST_ASSERT(wp.expired());
}


BOOST_AUTO_TEST_CASE( weak_node_test ) {
    auto p1 = make_shared<node>();
    auto p2 = make_shared<node>();

    p1->next = p2;
    p2->next = p1;

    BOOST_ASSERT(p1.use_count() == 2);
    BOOST_ASSERT(p2.use_count() == 2);
}


BOOST_AUTO_TEST_CASE( weak_node_test2 ) {
    auto p1 = make_shared<weak_node>();
    auto p2 = make_shared<weak_node>();

    p1->next = p2;
    p2->next = p1;

    BOOST_ASSERT(p1.use_count() == 1);
    BOOST_ASSERT(p2.use_count() == 1);
}


BOOST_AUTO_TEST_CASE( pool_test ) {
    pool<> pl(sizeof(int));
    int *p = static_cast<int*>(pl.malloc());

    BOOST_ASSERT(pl.is_from(p));

    int *p1 = new int(2);
    BOOST_ASSERT(!pl.is_from(p1));
}


BOOST_AUTO_TEST_CASE( object_pool_test ) {
    object_pool<demo_class> pl;
    auto p = pl.malloc();
    BOOST_ASSERT(pl.is_from(p));

    p = pl.construct(7, 8, 9);

    BOOST_ASSERT(p->a == 7);
}

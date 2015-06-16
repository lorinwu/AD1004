Prepare
1) Install VS2012 for windows
2) copy boost.tar.gz from \\nj-fs\home\AD1004\boost_1_58_0\headers to 3rd_party and unzip it. boost.tar.gz contains boost header files mainly. (You should find '3rd_party/boost/include/boost/any.hpp' after unzip)
3) copy relative boost library from \\nj-fs\home\AD1004\boost_1_58_0\libraries to 3rd_party/boost/lib and unzip it according to your platform. (You should find '3rd_party/boost/lib/windows/win32/libboost_thread-vc100-mt-1_58.lib' on windows, '3rd_party/boost/lib/centos/x64/release/libboost_thread.a' on centos)

Compile & run
1) Windows
open all.sln, compile it and run

2) Non-windows
go to src folder in terminal. type 'make test' to compile & run
